load(
    "//bazel:envoy_build_system.bzl",
    "envoy_package",
)
load(
    "//test/extensions:extensions_build_system.bzl",
    "envoy_extension_cc_test",
)

licenses(["notice"])  # Apache 2

envoy_package()

envoy_extension_cc_test(
    name = "grpc_stream_demuxer_test",
    srcs = ["grpc_stream_demuxer_test.cc"],
    extension_name = "envoy.grpc_stream_demuxer",
    deps = [
        "//source/common/config:utility_lib",
        "//source/extensions/grpc_stream_demuxer:config",
        "//test/test_common:utility_lib",
        "@envoy_api//envoy/extensions/grpc_stream_demuxer/v3alpha:pkg_cc_proto",
    ],
)
