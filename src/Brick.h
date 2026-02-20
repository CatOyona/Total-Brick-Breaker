#ifndef _BRICK
#define _BRICK

#include "Level.h"
#include "raylib.h"

class Level;

class Brick {
    private:
        int x, y;
        int width, height;
        //const float SIZE_FACTOR = 512.0f;
        const unsigned int MAX_HARDNESS = 6;
        unsigned int hardnessLevel;

    public:
        //Constructeur par défaut
        Brick(int x, int y, int width, int height, Level * level, unsigned int hardness);

        //Getters
        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        Color getColor() const;

        void hit();
        bool isAlive() const;

        //Fonction test
        static void test();
};

#endif