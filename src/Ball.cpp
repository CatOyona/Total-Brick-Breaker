#include "Ball.h"
#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <time.h>
#include <algorithm>

using namespace std;

Ball::Ball(Level * level, int r): x(0), y(0), radius(r) {
    assert(r > 0);
    srand(time(NULL));
    angle = rand()%61 - 120;
    velocityMultiplier = level->getHeight() / 512.0f;
    cout << "Ball's velocity: " << BASE_VELOCITY * velocityMultiplier << endl;
    cout << "Ball successfully created, radius: "<< r << ", angle: " << angle << endl;
}

void Ball::setPos(int newX, int newY, Level * level) {
    assert (newX > 0 && newX < level->getWidth() && newY > 0 && newY < level->getHeight() );
    x = newX; y = newY;
}

int Ball::getX() const {return x;}

int Ball::getY() const {return y;}

int Ball::getRadius() const {return radius;}

bool Ball::update(Level * level, Sender * sender) {
    if (active) {
        double tangle = angle * 3.14159 / 180;
        int tx = (int) x + cos(tangle) * BASE_VELOCITY * velocityMultiplier;
        int ty = (int) y + sin(tangle) * BASE_VELOCITY * velocityMultiplier;
        bool horizontalCollision = false;
        bool verticalCollision = false;
        
        for (auto& brick : level->getBricks()) {
            if (brick.isAlive()) {
                bool hittenBrick = false;
                if (brick.isAlive() && collidesWith(brick.getX(), brick.getY(), brick.getWidth(), brick.getHeight(), tx, y)) {
                    horizontalCollision = true;
                    hittenBrick = true;
                }
                if (brick.isAlive() && collidesWith(brick.getX(), brick.getY(), brick.getWidth(), brick.getHeight(), x, ty)) {
                    verticalCollision = true;
                    hittenBrick = true;
                }
                if (hittenBrick)
                    brick.hit();
            }
        }
        
        if ((tx <= radius) || (tx >= level->getWidth() - radius) || collidesWith(sender->getX(), sender->getY(), sender->getWidth(), sender->getHeight(), tx, y))
            horizontalCollision = true;

        if ((ty <= radius) || (ty >= level->getHeight() - radius) || collidesWith(sender->getX(), sender->getY(), sender->getWidth(), sender->getHeight(), x, ty))
            verticalCollision = true;

        if (!horizontalCollision)
            x = tx;
        else {
            srand(time(NULL));
            angle = (180 - angle + rand()%(2 * FLUCTUATION_DELTA + 6) - FLUCTUATION_DELTA)%360;
        }
        if (!verticalCollision)
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
            y = sender->getY() - 0.5 * sender->getHeight() - radius - 1;
        }
        return false;
}

bool Ball::collidesWith(int centerXPos, int centerYPos, int width, int height, int x, int y) const {
    float rectLeft   = centerXPos - width / 2.0f;
    float rectRight  = centerXPos + width / 2.0f;
    float rectTop    = centerYPos - height / 2.0f;
    float rectBottom = centerYPos + height / 2.0f;
    float closestX = std::max(rectLeft, std::min((float)x, rectRight));
    float closestY = std::max(rectTop, std::min((float)y, rectBottom));
    float dx = x - closestX;
    float dy = y - closestY;
    return (dx * dx + dy * dy) <= (radius * radius);
}

void Ball::setActive(bool active) {this->active = active;}

void Ball::test() {
    Level * l = new Level(100, 100);
    Ball b1(l);
    delete l;
}