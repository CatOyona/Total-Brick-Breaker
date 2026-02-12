#include "Game.h"
#include <cassert>
#include <iostream>

using namespace std;

Game::Game() {
    int h, w;
    cout << "Veuillez entrer la taille de la fenêtre désirée (minimum 100 par 100):" << endl;
    //cin >> h >> w;
    h = 512;
    w = 512;
    assert (h >= 100 && w >= 100);
    level = new Level(h, w);
    ball = new Ball(level, h/HEIGHT_TO_BALL_FACTOR);
    ball->setPos(w/2, h/2, level);
    //cout << h/2 << " " << w/2 << endl;
}

int Game::getHeight() {return level->getHeight();}

int Game::getWidth() {return level->getWidth();}

Ball * Game::getBall() {return ball;}

Level * Game::getLevel() {return level;}

Game::~Game() {
    delete level;
    delete ball;
}

void Game::test() {
    Game g1;
}