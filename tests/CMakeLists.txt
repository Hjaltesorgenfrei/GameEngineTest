cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
project (tests)

include(FetchContent) 

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG        release-1.12.1  
)
include(GoogleTest)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")

add_executable(tests ${SOURCES}) 
target_link_libraries(tests PRIVATE gtest_main shared)
target_include_directories(tests PRIVATE ${CMAKE_SOURCE_DIR}/shared)
gtest_discover_tests(tests)

if(MSVC)
    set(build-output-path ${CMAKE_BINARY_DIR}/${CMAKE_BUILD_TYPE_INIT})
    target_compile_options(tests PRIVATE /W4 /WX)
else()
    set(build-output-path ${CMAKE_BINARY_DIR})
    target_compile_options(tests PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

install(TARGETS tests DESTINATION bin)