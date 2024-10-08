cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_library(TextRenderer STATIC TextRenderer/TextRenderer.cpp)
include_directories(${CMAKE_SOURCE_DIR}/TextRenderer)

add_library(Painter STATIC Painter/Painter.cpp)
include_directories(${CMAKE_SOURCE_DIR}/Painter)

add_library(BlockContainer STATIC  Layout/BlockContainer.cpp)
include_directories(${CMAKE_SOURCE_DIR}/Layout)

target_link_libraries(Painter sfml-graphics sfml-window sfml-system)
target_link_libraries(TextRenderer sfml-graphics sfml-window sfml-system)
target_link_libraries(BlockContainer sfml-graphics sfml-window sfml-system)


function(add_exercise EXERCISE_NAME)
    add_executable(${EXERCISE_NAME} ${EXERCISE_NAME}/main.cpp)
    target_link_libraries(${EXERCISE_NAME} PRIVATE BlockContainer TextRenderer Painter sfml-graphics sfml-window sfml-system )
endfunction()

add_exercise(ex1)
add_exercise(ex2)
add_exercise(ex3)
add_exercise(ex4)