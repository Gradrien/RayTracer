add_library(
        point SHARED
        PointLight.cpp
        PointEntry.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins/lights)

target_include_directories(point PRIVATE include)
target_compile_options(point PRIVATE ${WARNING_FLAGS})
target_link_libraries(point PRIVATE raytracer-interface nlohmann_json::nlohmann_json)
set_property(TARGET point PROPERTY CXX_STANDARD 20)
set_property(TARGET point PROPERTY CXX_STANDARD_REQUIRED ON)
