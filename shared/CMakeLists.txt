cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
project (shared)

include(FetchContent) 
FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG        9.0.0
)

FetchContent_MakeAvailable(fmt)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "*.cpp")

add_library(shared ${SOURCES}) 
target_include_directories(shared PUBLIC include)
add_library(${CMAKE_PROJECT_NAME}::shared ALIAS shared)
target_link_libraries(shared PRIVATE fmt)

if(MSVC)
    target_compile_options(shared PRIVATE /W4 /WX)
else()
    target_compile_options(shared PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
