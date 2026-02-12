#include "Ball.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

Ball::Ball(Level * level, int r): x(0), y(0), radius(r) {
    assert(r > 0);
    srand(time(NULL));
    angle = rand()%121 + 30;
    velocityMultiplier = level->getHeight() / 512.0f;
    cout << velocityMultiplier << endl;
    cout << "Ball successfully created, radius: "<< r << ", angle: " << angle << endl;
}

void Ball::setPos(int newX, int newY, Level * level) {
    assert (newX > 0 && newX < level->getWidth() && newY > 0 && newY < level->getHeight());
    x = newX; y = newY;
}

int Ball::getX() {return x;}

int Ball::getY() {return y;}

int Ball::getRadius() {return radius;}

void Ball::update(Level * level) {
    double tangle = angle * 3.14159 / 180;
    int tx = (int) x + cos(tangle) * BASE_VELOCITY * velocityMultiplier;
    int ty = (int) y + sin(tangle) * BASE_VELOCITY * velocityMultiplier;
    if (tx > radius && tx < level->getWidth() - radius)
        x = tx;
    else {
        srand(time(NULL));
        angle = 180 - angle + rand()%(2 * FLUCTUATION_DELTA + 1) - FLUCTUATION_DELTA;
    }
    if (ty > radius && ty < level->getHeight() - radius)
        y = ty;
    else {
        srand(time(NULL));
        angle = (-1) * angle + rand()%(2 * FLUCTUATION_DELTA + 1) - FLUCTUATION_DELTA;
    }
}

void Ball::test() {
    Level * l = new Level(100, 100);
    Ball b1(l);
    delete l;
}