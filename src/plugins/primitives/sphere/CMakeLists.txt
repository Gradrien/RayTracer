add_library(
        sphere SHARED
        Sphere.cpp
        SphereEntry.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins/primitives)

target_include_directories(sphere PRIVATE include)
target_compile_options(sphere PRIVATE ${WARNING_FLAGS})
target_link_libraries(sphere PRIVATE raytracer-interface nlohmann_json::nlohmann_json)
set_property(TARGET sphere PROPERTY CXX_STANDARD 20)
set_property(TARGET sphere PROPERTY CXX_STANDARD_REQUIRED ON)
