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

bool Ball::update(Level * level, Sender * sender) {
    if (active) {
        double tangle = angle * 3.14159 / 180;
        int tx = (int) x + cos(tangle) * BASE_VELOCITY * velocityMultiplier;
        int ty = (int) y + sin(tangle) * BASE_VELOCITY * velocityMultiplier;
        if ((tx > radius) && (tx < level->getWidth() - radius) && !collidesWith(sender->getX(), sender->getY(), sender->getWidth(), sender->getHeight(), tx, ty))
            x = tx;
        else {
            srand(time(NULL));
            angle = (180 - angle + rand()%(2 * FLUCTUATION_DELTA + 6) - FLUCTUATION_DELTA)%360;
        }
        if ((ty > radius) && (ty < level->getHeight() - radius) && !collidesWith(sender->getX(), sender->getY(), sender->getWidth(), sender->getHeight(), tx, ty))
            y = ty;
        else {
            /*
            if (ty >= level->getHeight() - 0.5 * radius) {
                return true;
            } else {
                srand(time(NULL));
                angle = ((-1) * angle + rand()%(2 * FLUCTUATION_DELTA + 1) - FLUCTUATION_DELTA)%360;
            }
            */
            srand(time(NULL));
            angle = ((-1) * angle + rand()%(2 * FLUCTUATION_DELTA + 1) - FLUCTUATION_DELTA)%360;
            
        }
    } else {
            x = sender->getX();
            y = sender->getY() - 0.02 * level->getHeight();
        }
        return false;
}

bool Ball::collidesWith(int centerXPos, int centerYPos, int width, int height, int x, int y) {
    cout << 0.5 * height - radius << endl;
    return ((x > centerXPos - (0.5 * width + radius)) &&
    (x < centerXPos + (0.5 * width + radius)) &&
    (y > centerYPos - (0.5 * height + radius)) &&
    (y < centerYPos + (0.5 * height + radius)));
}

void Ball::setActive(bool active) {this->active = active;}

void Ball::test() {
    Level * l = new Level(100, 100);
    Ball b1(l);
    delete l;
}