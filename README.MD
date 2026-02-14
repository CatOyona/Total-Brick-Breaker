# Total Brick Breaker

This project aims to recreate a basic Brick Breaker game.
Certainly not a very originla idea, the idea is to practice C++, git and real projet managing for the first time.
It'll probably not look like much, but at least I'll learn new things.

**Contributor :**  
 - CatOyona

## How to play
Simply use the executable files in bin (both Windows and Linux files are pre-compiled and ready to play).

## Dependencies
 - raylib installed in /home/user/raylib if you want to compile

## How to compile

### For Windows
Get in the `build-windows` folder.
1. If you have edited the `CMakeLists.txt` in root folder,  run:
```
cmake .. -DCMAKE_TOOLCHAIN_FILE=../mingw-toolchain.cmake
```
2. Compile the code:
```
make
```

### For linux
Get in the `build-linus` folder.
1. If you have edited the `CMakeLists.txt` in root folder,  run:
```
cmake ..
```
2. Compile the code:
```
make
```


## Bugs