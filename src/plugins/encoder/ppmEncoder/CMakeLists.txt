add_library(
        ppmEncoder SHARED
        Encoder.cpp
        EncoderEntry.cpp
)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins/encoder)

target_include_directories(ppmEncoder PRIVATE include)
target_compile_options(ppmEncoder PRIVATE ${WARNING_FLAGS})
target_link_libraries(ppmEncoder PRIVATE raytracer-interface)
set_property(TARGET ppmEncoder PROPERTY CXX_STANDARD 20)
set_property(TARGET ppmEncoder PROPERTY CXX_STANDARD_REQUIRED ON)
