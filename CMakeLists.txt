# #
# # CMakeLists: Arcade / Arcade
# #

cmake_minimum_required(VERSION 3.16)

# standard version cpp
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

# project name
set(BIN_NAME "raytracer")
project($(BIN_NAME))

set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/)
set(LIGHTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/lights)
set(PARSER_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/parser)
set(UTILS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/utils)
set(MATHS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/maths)

set(SRC_LIGHTS
    ${LIGHTS_DIR}/ALight.cpp
)

set(SRC_UTILS
    ${UTILS_DIR}/Color.cpp
    ${UTILS_DIR}/Material.cpp
    ${UTILS_DIR}/Primitives.cpp
    ${UTILS_DIR}/Scene.cpp
    ${UTILS_DIR}/Camera.cpp
)

set(SRC_MATHS
    ${MATHS_DIR}/Point3D.cpp
    ${MATHS_DIR}/Ray.cpp
    ${MATHS_DIR}/Rectangle3D.cpp
    ${MATHS_DIR}/Vector3D.cpp
)

set(SRC_PARSER
    ${PARSER_DIR}/CheckArgs.cpp
    ${PARSER_DIR}/CheckJsonExistence.cpp
    ${PARSER_DIR}/Error.cpp
    ${PARSER_DIR}/ParseImportedScene.cpp
    ${PARSER_DIR}/Parser.cpp
    ${PARSER_DIR}/ParseLight.cpp
    ${PARSER_DIR}/ParsePrimitive.cpp
)

set(SRC_CORE
    ${SOURCE_DIR}/Core.cpp
)
set(RAYTRACER_SOURCE_FILES
    ${SRC_LIGHTS} ${SRC_UTILS} ${SRC_PARSER} ${SRC_CORE} ${SRC_MATHS}
)

set(SOURCE_FILES ${RAYTRACER_SOURCE_FILES})

# change library prefix to none
set(CMAKE_SHARED_LIBRARY_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# for library compilation => shared libraries of games and graphics
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/plugins)

# include directories
include_directories(include/ include/lights include/encoder include/material include/maths include/parser include/primitives include/renderer)

# add a subdirectory to compile, to uncomment when CMakeLists will be complete
add_subdirectory(src/plugins)

# add_subdirectory(Graphics)

# Warning flags
set(GCC_WARNING_FLAGS
    -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches
    -Wlogical-op -Wnull-dereference -Wuseless-cast -fno-gnu-unique)

set(CLANG_WARNING_FLAGS
    -Weverything
    -Wno-c++20-compat
    -Wno-c++98-c++11-compat-binary-literal
    -Wno-c++98-compat
    -Wno-c++98-compat-pedantic
    -Wno-c99-extensions
    -Wno-disabled-macro-expansion
    -Wno-documentation-unknown-command
    -Wno-exit-time-destructors
    -Wno-global-constructors
    -Wno-implicit-int-float-conversion
    -Wno-return-std-move
    -Wno-return-type-c-linkage
    -Wno-signed-enum-bitfield
    -Wno-weak-vtables)

if(${CMAKE_CXX_COMPILER_VERSION} VERSION_LESS 13.0.0)
    set(CLANG_WARNING_FLAGS ${CLANG_WARNING_FLAGS} -Wno-return-std-move-in-c++11)
endif()

set(WARNING_FLAGS
    -Wall
    -Wextra
    -pedantic
    -Wold-style-cast
    -Wcast-align
    -Wunused
    -Woverloaded-virtual
    -Wpedantic
    -Wconversion
    -Wsign-conversion
    -Wdouble-promotion
    -Wformat=2
    -Wno-padded
    -Wno-ctad-maybe-unsupported)

# set different flags
set(CMAKE_BUILD_TYPE
    ${CMAKE_BUILD_TYPE}
    CACHE
    STRING
    "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel"
    FORCE)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb3")
endif()

# Clang-tidy
if(USE_CLANG_TIDY)
    find_program(
        CLANG_TIDY_EXE
        NAMES "clang-tidy"
        DOC "Path to clang-tidy executable")

    if(CLANG_TIDY_EXE)
        if(DEFINED arcade_CLANG_TIDY_FLAGS)
            set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}"
                "${raytracer_CLANG_TIDY_FLAGS}")
        else()
            set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
        endif()

        message("-- Found clang-tidy: ${CLANG_TIDY_EXE}")
    else()
        message("-- Failed to find clang-tidy")
    endif()
endif()

# set warning flags
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(WARNING_FLAGS ${WARNING_FLAGS} ${CLANG_WARNING_FLAGS})
elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    set(WARNING_FLAGS ${WARNING_FLAGS} ${GCC_WARNING_FLAGS})
else()
    error("${CMAKE_CXX_COMPILER_ID}: Unsupported compiler.")
endif()

message("Warning flags: ${WARNING_FLAGS}")

add_library(raytracer-interface INTERFACE)

# link shared libraries and compile them
set_property(TARGET raytracer-interface PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer-interface PROPERTY CXX_STANDARD_REQUIRED ON)

add_library(
    raytracer-core INTERFACE
)

# target_compile_options(raytracer-core PRIVATE ${WARNING_FLAGS})
# target_include_directories(raytracer-core PUBLIC include)
# set_property(TARGET raytracer-core PROPERTY CXX_STANDARD 20)
# set_property(TARGET raytracer-core PROPERTY CXX_STANDARD_REQUIRED ON)
message("-- Loading library")
include(FetchContent)

FetchContent_Declare(nlohmann_json
    URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
    DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(nlohmann_json)
message("-- Finished loading library")

# adding executables
add_executable(
    raytracer
    ${SOURCE_DIR}/Main.cpp
    ${SOURCE_FILES}
)

# rules for arcade project
target_link_libraries(
    raytracer
    INTERFACE

    # raytracer-interface
    raytracer-core
    PRIVATE nlohmann_json::nlohmann_json
)

target_link_options(raytracer PRIVATE -rdynamic)
target_compile_options(raytracer PRIVATE ${WARNING_FLAGS})
set_property(TARGET raytracer PROPERTY CXX_STANDARD 20)
set_property(TARGET raytracer PROPERTY CXX_STANDARD_REQUIRED ON)
