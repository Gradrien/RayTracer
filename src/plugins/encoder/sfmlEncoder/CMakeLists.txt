add_library(
        sfmlEncoder SHARED
        Encoder.cpp
        EncoderEntry.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins/encoder)

target_include_directories(sfmlEncoder PRIVATE include)
target_compile_options(sfmlEncoder PRIVATE ${WARNING_FLAGS})
target_link_libraries(sfmlEncoder PRIVATE raytracer-interface sfml-graphics sfml-window sfml-system)
set_property(TARGET sfmlEncoder PROPERTY CXX_STANDARD 20)
set_property(TARGET sfmlEncoder PROPERTY CXX_STANDARD_REQUIRED ON)
