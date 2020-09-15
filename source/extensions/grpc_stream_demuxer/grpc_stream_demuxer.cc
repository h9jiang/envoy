#include "extensions/grpc_stream_demuxer/grpc_stream_demuxer.h"

namespace Envoy {
namespace Extensions {
namespace GrpcStreamDemuxer {

GrpcStreamDemuxer::GrpcStreamDemuxer(const std::string& subscription, const std::string& address,
                                     int port)
    : subscription_(subscription), address_(address), port_(port) {}

void GrpcStreamDemuxer::start() {
  // TODO (vmunukutla): Implement so that it forms a streaming pull connection
  // to subscription_, waits for messages to be published to subscription_, and
  // sends unary gRPC requests to address:port when messages are published to
  // subscription_.
  ENVOY_LOG(debug, "Subscription: {}", subscription_);
  ENVOY_LOG(debug, "Address: {}", address_);
  ENVOY_LOG(debug, "Port: {}", port_);
}

} // namespace GrpcStreamDemuxer
} // namespace Extensions
} // namespace Envoy
