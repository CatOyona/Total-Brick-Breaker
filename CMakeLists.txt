cmake_minimum_required(VERSION 3.16)
project(JeuTBB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(SOURCES
    src/main.cpp
    src/Game.cpp
    src/Ball.cpp
    src/Sender.cpp
    src/Level.cpp
    src/Brick.cpp
)

add_executable(executable ${SOURCES})

if(WIN32)

    target_include_directories(executable PRIVATE
        ${CMAKE_SOURCE_DIR}/raylib/src
    )

    target_link_libraries(executable PRIVATE
        ${CMAKE_SOURCE_DIR}/raylib/build-windows/raylib/libraylib.a
        -lopengl32
        -lgdi32
        -lwinmm
        -static
        -static-libgcc
        -static-libstdc++
    )

else()

    target_include_directories(executable PRIVATE
        ${CMAKE_SOURCE_DIR}/raylib/src
    )

    target_link_libraries(executable PRIVATE
        ${CMAKE_SOURCE_DIR}/raylib/build/raylib/libraylib.a
        m pthread dl GL
    )

endif()

#In build-windows
#cmake .. -DCMAKE_TOOLCHAIN_FILE=../mingw-toolchain.cmake

#In build-linux
#cmake