load(
    "//bazel:envoy_build_system.bzl",
    "envoy_cc_extension",
    "envoy_cc_library",
    "envoy_extension_package",
)

licenses(["notice"])  # Apache 2

# On-demand RDS update HTTP filter

envoy_extension_package()

envoy_cc_library(
    name = "on_demand_update_lib",
    srcs = ["on_demand_update.cc"],
    hdrs = ["on_demand_update.h"],
    deps = [
        "//include/envoy/event:dispatcher_interface",
        "//include/envoy/http:filter_interface",
        "//include/envoy/server:filter_config_interface",
        "//source/common/common:assert_lib",
        "//source/common/common:enum_to_int",
        "//source/common/http:codes_lib",
        "//source/common/http:header_map_lib",
    ],
)

envoy_cc_extension(
    name = "config",
    srcs = ["config.cc"],
    hdrs = ["config.h"],
    security_posture = "robust_to_untrusted_downstream",
    # TODO(#9953) classify and clean up.
    visibility = [
        "//:extension_config",
        "//test/common/access_log:__subpackages__",
        "//test/integration:__subpackages__",
    ],
    deps = [
        "//include/envoy/registry",
        "//source/extensions/filters/http:well_known_names",
        "//source/extensions/filters/http/common:factory_base_lib",
        "//source/extensions/filters/http/on_demand:on_demand_update_lib",
        "@envoy_api//envoy/config/filter/http/on_demand/v2:pkg_cc_proto",
    ],
)
