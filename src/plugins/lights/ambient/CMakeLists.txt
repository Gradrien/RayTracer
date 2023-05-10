add_library(
        ambient SHARED
        AmbientLight.cpp
        AmbientEntry.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins/lights)

target_include_directories(ambient PRIVATE include)
target_compile_options(ambient PRIVATE ${WARNING_FLAGS})
target_link_libraries(ambient PRIVATE raytracer-interface nlohmann_json::nlohmann_json)
set_property(TARGET ambient PROPERTY CXX_STANDARD 20)
set_property(TARGET ambient PROPERTY CXX_STANDARD_REQUIRED ON)
