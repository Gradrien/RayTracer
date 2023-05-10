add_library(
        directional SHARED
        DirectionalLight.cpp
        DirectionalEntry.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins/lights)

target_include_directories(directional PRIVATE include)
target_compile_options(directional PRIVATE ${WARNING_FLAGS})
target_link_libraries(directional PRIVATE raytracer-interface nlohmann_json::nlohmann_json)
set_property(TARGET directional PROPERTY CXX_STANDARD 20)
set_property(TARGET directional PROPERTY CXX_STANDARD_REQUIRED ON)
