#include "Sender.h"
#include <cassert>
#include <iostream>

using namespace std;

Sender::Sender(Level * level) {
    x = level->getWidth() / 2;
    y = level->getHeight() * 0.9;
    width = level->getWidth() * 0.2;
    height = level->getHeight() * 0.02;
    velocityMultiplier = level->getHeight() / 512.0f;
    cout << "Sender's velocity: " << BASE_VELOCITY * velocityMultiplier << endl;
}

int Sender::getX() const {return x;}

int Sender::getY() const {return y;}

int Sender::getWidth() const {return width;}

int Sender::getHeight() const {return height;}

void Sender::updatePos(int delta, Level * level, Ball * ball) {
    int tx;
    if (delta > 0)
        tx = x + BASE_VELOCITY * velocityMultiplier;
    else
        tx = x - BASE_VELOCITY * velocityMultiplier;
    if (((y - (height / 2) > ball->getY() + ball->getRadius()) //Checking collision with Ball
        || (y + (height / 2) < ball->getY() - ball->getRadius())
        || (tx - (width / 2) > ball->getX() + ball->getRadius()) 
        || (tx + (width / 2) < ball->getX() - ball->getRadius()))) {
            if ((tx - (width / 2) > 0)) //Checking if walls are near (left)
                if ((tx + (width / 2) < level->getWidth())) //(right)
                    x = tx;
                else
                    x = level->getWidth() - (width / 2) - 1;
            else
                x = 0 + (width / 2) + 1;
    }
}

void Sender::setPos(int newX, Level * level) {
    assert (newX > 0 + 0.5 * width && newX < level->getWidth() - 0.5 * width);
    x = newX;
}