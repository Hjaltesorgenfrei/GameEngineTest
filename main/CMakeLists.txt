cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
project (main)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE shared)
target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/shared)


add_custom_target(copy-runtime-files ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/resources)
add_dependencies(main copy-runtime-files)

if(MSVC)
    # target_compile_options(main PRIVATE /W4 /WX)
else()
    # target_compile_options(main PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()

