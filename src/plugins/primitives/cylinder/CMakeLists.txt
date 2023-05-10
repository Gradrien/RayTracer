add_library(
        cylinder SHARED
        Cylinder.cpp
        CylinderEntry.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins/primitives)

target_include_directories(cylinder PRIVATE include)
target_compile_options(cylinder PRIVATE ${WARNING_FLAGS})
target_link_libraries(cylinder PRIVATE raytracer-interface nlohmann_json::nlohmann_json)
set_property(TARGET cylinder PROPERTY CXX_STANDARD 20)
set_property(TARGET cylinder PROPERTY CXX_STANDARD_REQUIRED ON)
