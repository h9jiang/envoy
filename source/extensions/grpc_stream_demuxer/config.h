#pragma once

#include "envoy/registry/registry.h"

#include "extensions/grpc_stream_demuxer/grpc_stream_demuxer_factory.h"

namespace Envoy {
namespace Extensions {
namespace GrpcStreamDemuxer {

class GrpcStreamDemuxerFactoryImpl : public GrpcStreamDemuxerFactory {
public:
  GrpcStreamDemuxerPtr createGrpcStreamDemuxer(const envoy::extensions::grpc_stream_demuxer::v3alpha::GrpcStreamDemuxer& demuxer_config, Event::Dispatcher& dispatcher) override;
  std::string name() const override { return "grpc_stream_demuxer"; }
};

DECLARE_FACTORY(GrpcStreamDemuxerFactoryImpl);

} // namespace GrpcStreamDemuxer
} // namespace Extensions
} // namespace Envoy
