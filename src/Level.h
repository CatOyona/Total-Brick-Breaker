#ifndef _LEVEL
#define _LEVEL

#include "Brick.h"
#include <vector>

using namespace std;

class Brick;

class Level {
    private:
        int height, width;
        int lives = 5;
        vector<Brick> bricks;
    public:
        //Constructeur par défaut
        Level();

        //Constructeur avec données
        Level(int h, int w);

        //Getters
        int getHeight() const;
        int getWidth() const;
        int getLives() const;
        vector<Brick>& getBricks();

        //Setters
        void setLives(int n);

        //Fonction test
        static void test();
};

#endif