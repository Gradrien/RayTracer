add_library(
        plane SHARED
        Plan.cpp
        PlanEntry.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins/primitives)

target_include_directories(plane PRIVATE include)
target_compile_options(plane PRIVATE ${WARNING_FLAGS})
target_link_libraries(plane PRIVATE raytracer-interface nlohmann_json::nlohmann_json)
set_property(TARGET plane PROPERTY CXX_STANDARD 20)
set_property(TARGET plane PROPERTY CXX_STANDARD_REQUIRED ON)
