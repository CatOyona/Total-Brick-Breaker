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
)

add_executable(executable ${SOURCES})

# === Détection automatique Windows / Linux ===
if(WIN32)

    target_include_directories(executable PRIVATE
        /home/ismae/raylib/src
    )

    target_link_libraries(executable PRIVATE
        /home/ismae/raylib/build-windows/raylib/libraylib.a
        -lopengl32
        -lgdi32
        -lwinmm
        -static
        -static-libgcc
        -static-libstdc++
    )

else()

    target_include_directories(executable PRIVATE
        /home/ismae/raylib/src
    )

    target_link_libraries(executable PRIVATE
        /home/ismae/raylib/build/raylib/libraylib.a
        m pthread dl GL
    )

endif()

#Dans build-windows
#cmake .. -DCMAKE_TOOLCHAIN_FILE=../mingw-toolchain.cmake

#Dans build-linux
#cmake