#include "Sender.h"
#include <cassert>

Sender::Sender(Level * level) {
    x = level->getWidth() / 2;
    y = level->getHeight() * 0.9;
    width = level->getWidth() * 0.2;
    height = level->getHeight() * 0.02;
}

int Sender::getX() {return x;}

int Sender::getY() {return y;}

int Sender::getWidth() {return width;}

int Sender::getHeight() {return height;}

void Sender::updatePos(int delta, Level * level) {
    if (x + delta + (0.5 * width) < level->getWidth() && x + delta - (0.5 * width) > 0) {
        x += delta;
    }
}

void Sender::setPos(int newX, Level * level) {
    assert (newX > 0 + 0.5 * width && newX < level->getWidth() - 0.5 * width);
    x = newX;
}