#pragma once

#include "envoy/config/typed_config.h"
#include "envoy/extensions/grpc_stream_demuxer/v3alpha/grpc_stream_demuxer.pb.h"

#include "extensions/grpc_stream_demuxer/grpc_stream_demuxer.h"

namespace Envoy {
namespace Extensions {
namespace GrpcStreamDemuxer {

class GrpcStreamDemuxerFactory : public Config::UntypedFactory {
public:
  ~GrpcStreamDemuxerFactory() override = default;

  virtual GrpcStreamDemuxerPtr createGrpcStreamDemuxer(
      const envoy::extensions::grpc_stream_demuxer::v3alpha::GrpcStreamDemuxer& demuxer_config)
      PURE;
  std::string category() const override { return "envoy.grpc_stream_demuxer"; }
};

} // namespace GrpcStreamDemuxer
} // namespace Extensions
} // namespace Envoy
