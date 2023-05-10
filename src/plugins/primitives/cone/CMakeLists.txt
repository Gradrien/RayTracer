add_library(
        cone SHARED
        Cone.cpp
        ConeEntry.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins/primitives)

target_include_directories(cone PRIVATE include)
target_compile_options(cone PRIVATE ${WARNING_FLAGS})
target_link_libraries(cone PRIVATE raytracer-interface nlohmann_json::nlohmann_json)
set_property(TARGET cone PROPERTY CXX_STANDARD 20)
set_property(TARGET cone PROPERTY CXX_STANDARD_REQUIRED ON)
