cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
add_library(TextRenderer STATIC TextRenderer/TextRenderer.cpp)
include_directories(${CMAKE_SOURCE_DIR}/TextRenderer)

function(add_exercise EXERCISE_NAME)
    add_executable(${EXERCISE_NAME} ${EXERCISE_NAME}/main.cpp)
    target_link_libraries(${EXERCISE_NAME} sfml-graphics sfml-window sfml-system TextRenderer)
endfunction()

add_exercise(ex1)