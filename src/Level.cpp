#include "Level.h"
#include <cassert>
#include <iostream>

using namespace std;

Level::Level(): height(0), width(0) {
    cout << "Level successfully created, size: 0*0" << endl;
}

Level::Level(int h, int w): height(h), width(w) {
    assert(h > 0 && w > 0);
    bricks.push_back(Brick(100, 100, 80, 50, this, 4));
    cout << "Level successfully created, size: " << h << '*' << w << endl;
}

int Level::getHeight() const {return height;}

int Level::getWidth() const {return width;}

int Level::getLives() const {return lives;}

vector<Brick>& Level::getBricks() {return bricks;}

void Level::setLives(int n) {
    assert (n >= 0);
    lives = n;
}

void Level::test() {
    Level l1;
    assert (l1.height == 0 && l1.width == 0);
    Level l2(100, 50);
    assert (l2.height == 100 && l2.width == 50);
    cout << "Level class clear" << endl;
}