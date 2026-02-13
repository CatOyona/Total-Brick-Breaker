cmake_minimum_required(VERSION 3.16)

project(JeuTBB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dossier des headers
include_directories(include)

# Dossier de sortie pour tous les exécutables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# --- 1️⃣ Executable Linux (.out) ---
add_executable(executable.out
    src/main.cpp
    src/Game.cpp
    src/Ball.cpp
    src/Sender.cpp
    src/Level.cpp
)

target_link_libraries(executable.out PRIVATE raylib)

add_executable(executable.exe
    src/main.cpp
    src/Game.cpp
    src/Ball.cpp
    src/Sender.cpp
    src/Level.cpp
)

set(RAYLIB_WIN_PATH /home/ismae/raylib/build-windows/raylib)
target_link_libraries(executable.exe PRIVATE ${RAYLIB_WIN_PATH}/libraylib.a)