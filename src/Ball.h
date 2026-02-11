#ifndef _BALL
#define _BALL

#include "Level.h"

class Ball {
    private:
        int x, y;
        int radius;
        int angle; //Angle entre 0 et 359 (degrés)
        int velocity = 3;
    public:

        //Constructeur par défaut
        Ball(int r = 5);

        //Définir une position
        void setPos(int newX, int newY, Level * level);

        //Getters
        int getX();
        int getY();
        int getRadius();

        //Fonction test
        static void test();
};

#endif