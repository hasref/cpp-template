cmake_minimum_required(VERSION 3.20)
project(cpp LANGUAGES CXX)

find_package(fmt REQUIRED)
find_package(Catch2 REQUIRED)

add_executable(cpp src/main.cpp)
target_include_directories(cpp PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_compile_options(cpp PRIVATE -Wall -Werror -Wpedantic)
target_compile_features(cpp PUBLIC cxx_std_20)
target_link_options(cpp PRIVATE)
target_link_libraries(cpp PRIVATE fmt::fmt)

# tests
add_executable(test test/test.cpp)
target_include_directories(test PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_compile_options(test PRIVATE -Wall -Werror -Wpedantic)
target_compile_features(test PRIVATE cxx_std_20)
target_link_options(test PRIVATE)
target_link_libraries(test PRIVATE fmt::fmt Catch2::Catch2WithMain)

# lsp: copy compile_commands.json to root folder
add_custom_target(
    copy-compile-commands ALL
    ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_LIST_DIR}
    )

