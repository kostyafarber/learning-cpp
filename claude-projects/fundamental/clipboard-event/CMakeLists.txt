cmake_minimum_required(VERSION 3.10)
project(clipboard_watcher)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_custom_target(ClipboardBridgeTarget ALL
    COMMAND rm -rf .build && swift build
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/swift-clipboard-bridge
)

add_executable(clipboard_watcher
    src/event_emitter.cpp
    src/clipboard_watcher.cpp
    main.cpp
)

target_include_directories(clipboard_watcher
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

add_dependencies(clipboard_watcher ClipboardBridgeTarget)

target_link_directories(clipboard_watcher PRIVATE
    ${CMAKE_SOURCE_DIR}/swift-clipboard-bridge/.build/debug
)

target_link_libraries(clipboard_watcher PRIVATE
    libClipboardBridge.dylib
)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)