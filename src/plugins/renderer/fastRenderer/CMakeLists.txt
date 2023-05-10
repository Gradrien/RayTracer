add_library(
        fastRenderer SHARED
        Renderer.cpp
        RendererEntry.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins/renderer)

target_include_directories(fastRenderer PRIVATE include)
target_compile_options(fastRenderer PRIVATE ${WARNING_FLAGS})
target_link_libraries(fastRenderer PRIVATE raytracer-interface nlohmann_json::nlohmann_json)
set_property(TARGET fastRenderer PROPERTY CXX_STANDARD 20)
set_property(TARGET fastRenderer PROPERTY CXX_STANDARD_REQUIRED ON)
