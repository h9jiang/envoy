#include "extensions/grpc_stream_demuxer/grpc_stream_demuxer.h"

#include "google/pubsub/v1/pubsub.grpc.pb.h"
#include "grpc++/grpc++.h"

using grpc::ClientContext;
using grpc::ClientReaderWriter;
using google::pubsub::v1::Subscriber;
using google::pubsub::v1::StreamingPullRequest;
using google::pubsub::v1::StreamingPullResponse;

namespace Envoy {
namespace Extensions {
namespace GrpcStreamDemuxer {

GrpcStreamDemuxer::GrpcStreamDemuxer(const std::string& subscription, const std::string& address, int port, Event::Dispatcher& dispatcher) 
  : subscription_(subscription), address_(address), port_(port) {   	
  interval_timer_ = dispatcher.createTimer([this]() -> void { start(); });
  interval_timer_->enableTimer(std::chrono::milliseconds(5000));
}

void GrpcStreamDemuxer::start() {
  auto creds = grpc::GoogleDefaultCredentials();
  auto stub = Subscriber::NewStub(
    grpc::CreateChannel("pubsub.googleapis.com", creds));      

  // Open up the stream.
  ClientContext ctx;
  unsigned int client_connection_timeout = 2;
  std::chrono::system_clock::time_point deadline = 
	  std::chrono::system_clock::now() + std::chrono::seconds(client_connection_timeout);
  ctx.set_deadline(deadline);
  std::unique_ptr<ClientReaderWriter
    <StreamingPullRequest, StreamingPullResponse>> 
      stream(stub->StreamingPull(&ctx));
  
  // Send initial message.
  StreamingPullRequest request;
  request.set_subscription(subscription_);
  request.set_stream_ack_deadline_seconds(10);
  stream->Write(request);
  // Receive messages.
  StreamingPullResponse response;
  while (stream->Read(&response)) {
    // Ack messages.
    StreamingPullRequest ack_request;
    for (const auto &message : response.received_messages()) {
      // Print the data from the message.
      ENVOY_LOG(info, "Pubsub message data: {}", message.message().data());
      ack_request.add_ack_ids(message.ack_id());
    }
    stream->Write(ack_request);
  }  
  ENVOY_LOG(debug, "Address: {}", address_);
  ENVOY_LOG(debug, "Port: {}", port_);
  interval_timer_->enableTimer(std::chrono::milliseconds(5000));
}

} // namespace GrpcStreamDemuxer
} // namespace Extensions
} // namespace Envoy
