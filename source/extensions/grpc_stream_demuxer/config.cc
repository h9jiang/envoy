#include "extensions/grpc_stream_demuxer/config.h"

namespace Envoy {
namespace Extensions {
namespace GrpcStreamDemuxer {

GrpcStreamDemuxerPtr GrpcStreamDemuxerFactoryImpl::createGrpcStreamDemuxer(const envoy::extensions::grpc_stream_demuxer::v3alpha::GrpcStreamDemuxer& demuxer_config, Event::Dispatcher& dispatcher) {
  return std::make_unique<GrpcStreamDemuxer>(demuxer_config.subscription(), demuxer_config.address(), demuxer_config.port(), dispatcher);
}

REGISTER_FACTORY(GrpcStreamDemuxerFactoryImpl, GrpcStreamDemuxerFactory);

} // namespace GrpcStreamDemuxer
} // namespace Extensions
} // namespace Envoy
