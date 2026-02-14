#ifndef _BRICK
#define _BRICK

#include "Level.h"

class Level;

class Brick {
    private:
        int x, y;
        int width, height;
        const float SIZE_FACTOR = 512.0f;
        unsigned int hardnessLevel;

    public:
        //Constructeur par défaut
        Brick(int x, int y, Level * level);

        //Fonction test
        static void test();
};

#endif