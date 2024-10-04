  cmake_minimum_required(VERSION 3.30)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(text-rendering)

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Find FreeType (which includes OpenType support)
find_package(Freetype REQUIRED)
include_directories(${FREETYPE_INCLUDE_DIRS})

function(add_exercise EXERCISE_NAME)
  add_executable(${EXERCISE_NAME} exercises/${EXERCISE_NAME}/main.cpp)
  target_link_libraries(${EXERCISE_NAME} 
        ${SDL2_LIBRARIES}
        ${FREETYPE_LIBRARIES}
    )
endfunction()

add_exercise(ex1)
add_exercise(ex2)