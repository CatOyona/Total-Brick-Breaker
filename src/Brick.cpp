#include "Brick.h"
#include "raylib.h"

#include <cassert>
#include <iostream>

using namespace std;

Brick::Brick(int x, int y, int width, int height, Level * level, unsigned int hardness): x(x), y(y), width(width), height(height), hardnessLevel(hardness) {
    assert (x - (width / 2) > 0 && x + (width / 2) < level->getWidth()
            && y - (height / 2) > 0 && y + (height / 2) < level->getHeight()
            && hardness >= 0 && hardness <= MAX_HARDNESS);
}

int Brick::getX() const {return x;}

int Brick::getY() const {return y;}

int Brick::getWidth() const {return width;}

int Brick::getHeight() const {return height;}

Color Brick::getColor() const {
    switch(hardnessLevel) {
        case 6:
            return DARKPURPLE;
        case 5:
            return VIOLET;
        case 4:
            return PURPLE;
        case 3:
            return RED;
        case 2:
            return YELLOW;
        default:
            return GREEN;
    }
}

void Brick::hit() {
    assert(hardnessLevel > 0);
    hardnessLevel--;
    cout << hardnessLevel << endl;
}

bool Brick::isAlive() const {
    return (hardnessLevel > 0);
}