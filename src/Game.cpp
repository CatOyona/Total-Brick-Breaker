#include "Game.h"
#include <cassert>
#include <iostream>

using namespace std;

Game::Game() {
    int h, w;
    //cout << "Veuillez entrer la taille de la fenêtre désirée (minimum 100 par 100):" << endl;
    //cin >> h >> w;
    h = 800;
    w = 800;
    assert (h >= 100 && w >= 100);
    level = new Level(h, w);
    ball = new Ball(level, h/HEIGHT_TO_BALL_FACTOR);
    sender = new Sender(level);

    init();
}

void Game::init() {
    InitWindow(level->getWidth(), level->getHeight(), "Total Brick Breaker");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        update();
    }

    CloseWindow();
}

void Game::update() {
    bool lifeLost = ball->update(level, sender);
    //if (lifeLost)
        //lifeDown();

    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawCircle(ball->getX(), ball->getY(), ball->getRadius(), RED);
    DrawRectangle(sender->getX() - 0.5 * sender->getWidth(), sender->getY() - 0.5 * sender->getHeight(), sender->getWidth(), sender->getHeight(), BLACK);
    DrawText(TextFormat("Lives: %d", level->getLives()), 10, 10, 20, BLACK);

    if (IsKeyDown(KEY_RIGHT)) {
        sender->updatePos(1, level, ball);
    }
    if (IsKeyDown(KEY_LEFT)) {
        sender->updatePos(-1, level, ball);
    }
    if (IsKeyDown(KEY_SPACE)) {
        ball->setActive(true);
    }
    EndDrawing();
}

void Game::lifeDown() {
    ball->setActive(false);
    sender->setPos(level->getWidth() * 0.5, level);
    int lives = level->getLives();
    if (lives - 1 == 0)
        lost = true;
    level->setLives(lives - 1);
}

Game::~Game() {
    delete level;
    delete ball;
    delete sender;
}

void Game::test() {
    Game g1;
}