#include "Ball.h"
#include <cassert>
#include <iostream>
#include <random>
#include <time.h>

using namespace std;

Ball::Ball(int r): x(0), y(0), radius(r) {
    assert(r > 0);
    srand(time(NULL));
    angle = rand()%121 + 30;
    cout << "Ball successfully created, radius: "<< r << ", angle: " << angle << endl;
}

void Ball::setPos(int newX, int newY, Level * level) {
    assert (newX > 0 && newX < level->getWidth() && newY > 0 && newY < level->getHeight());
    x = newX; y = newY;
}

int Ball::getX() {return x;}

int Ball::getY() {return y;}

int Ball::getRadius() {return radius;}

void Ball::test() {
    Ball b1;
}