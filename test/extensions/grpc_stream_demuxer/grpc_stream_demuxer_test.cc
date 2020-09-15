#include "envoy/extensions/grpc_stream_demuxer/v3alpha/grpc_stream_demuxer.pb.h"

#include "common/config/utility.h"

#include "extensions/grpc_stream_demuxer/config.h"

#include "test/test_common/utility.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

namespace Envoy {
namespace Extensions {
namespace GrpcStreamDemuxer {

// Basic test to make sure GrpcStreamDemuxer initialization from yaml config is successful.
TEST(GrpcStreamDemuxerTest, CreateGrpcStreamDemuxer) {
  const std::string yaml = R"EOF(
  subscription: "test_subscription_1"
  address: 0.0.0.1
  port: 10001
  )EOF";
  envoy::extensions::grpc_stream_demuxer::v3alpha::GrpcStreamDemuxer demuxer_config;
  TestUtility::loadFromYaml(yaml, demuxer_config);
  auto& factory =
      Config::Utility::getAndCheckFactoryByName<GrpcStreamDemuxerFactory>("grpc_stream_demuxer");
  GrpcStreamDemuxerPtr demuxer = factory.createGrpcStreamDemuxer(demuxer_config);
  EXPECT_THAT(demuxer, testing::NotNull());
}

} // namespace GrpcStreamDemuxer
} // namespace Extensions
} // namespace Envoy
