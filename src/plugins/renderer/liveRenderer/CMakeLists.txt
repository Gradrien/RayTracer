add_library(
        liveRenderer SHARED
        Renderer.cpp
        RendererEntry.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins/renderer)

target_include_directories(liveRenderer PRIVATE include)
target_compile_options(liveRenderer PRIVATE ${WARNING_FLAGS})
target_link_libraries(liveRenderer PRIVATE raytracer-interface nlohmann_json::nlohmann_json)
set_property(TARGET liveRenderer PROPERTY CXX_STANDARD 20)
set_property(TARGET liveRenderer PROPERTY CXX_STANDARD_REQUIRED ON)
