add_library(
        baseRenderer SHARED
        Renderer.cpp
        RendererEntry.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins/renderer)

target_include_directories(baseRenderer PRIVATE include)
target_compile_options(baseRenderer PRIVATE ${WARNING_FLAGS})
target_link_libraries(baseRenderer PRIVATE raytracer-interface nlohmann_json::nlohmann_json)
set_property(TARGET baseRenderer PROPERTY CXX_STANDARD 20)
set_property(TARGET baseRenderer PROPERTY CXX_STANDARD_REQUIRED ON)
