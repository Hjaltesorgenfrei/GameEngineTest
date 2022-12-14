cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
project (shared)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
set(USE_SRE_EXAMPLES FALSE)
find_package(SDL2 REQUIRED)
set(SRE_INCLUDE_DIRS ${SDL2_INCLUDE_DIR})

find_package(OpenGL REQUIRED)
list(APPEND SRE_INCLUDE_DIRS ${OPENGL_INCLUDE_DIR})
IF(UNIX)
find_package(GLEW REQUIRED)
ELSE(UNIX)
find_package(glew REQUIRED)
ENDIF(UNIX)
list(APPEND SRE_INCLUDE_DIRS ${GLEW_INCLUDE_DIR})
SET(EXTRA_LIBS ${OPENGL_LIBRARY} ${GLEW_LIBRARY})

find_package(SDL2_IMAGE REQUIRED)
list(APPEND SRE_INCLUDE_DIRS ${SDL2_IMAGE_INCLUDE_DIRS})

find_package(SDL2_IMAGE REQUIRED)
list(APPEND SRE_INCLUDE_DIRS ${SDL2_IMAGE_INCLUDE_DIRS})

include(FetchContent) 
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG        9.0.0
)

FetchContent_Declare(
    SRE
    GIT_REPOSITORY https://github.com/mortennobel/SimpleRenderEngine
    GIT_TAG        1.1.4
    EXCLUDE_FROM_ALL    TRUE
)

FetchContent_MakeAvailable(fmt SRE)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")

add_library(shared ${SOURCES}) 
add_library(${CMAKE_PROJECT_NAME}::shared ALIAS shared)
target_link_libraries(shared PRIVATE fmt SRE)
target_include_directories(shared PRIVATE ${SRE_INCLUDE})

if(MSVC)
    # target_compile_options(shared PRIVATE /W4 /WX)
else()
    # target_compile_options(shared PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
