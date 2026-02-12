#include "Game.h"
#include "raylib.h"
#include <iostream>

using namespace std;

int main() {
    Game game;
    InitWindow(game.getWidth(), game.getHeight(), "Total Brick Breaker");
    ClearWindowState(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        game.getBall()->update(game.getLevel());

        BeginDrawing();
        ClearBackground(RAYWHITE);
        //cout << game.getBall()->getX() << " " << game.getBall()->getY() << endl;
        DrawCircle(game.getBall()->getX(), game.getBall()->getY(), game.getBall()->getRadius(), BLACK);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}