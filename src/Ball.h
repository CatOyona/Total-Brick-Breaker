#ifndef _BALL
#define _BALL

#include "Level.h"

class Ball {
    private:
        int x, y;
        int radius;
        int angle; //Angle entre 0 et 359 (degrés)
        const int BASE_VELOCITY = 6;
        const int FLUCTUATION_DELTA = 15;
        float velocityMultiplier = 1.0f;
    public:

        //Constructeur par défaut
        Ball(Level * level, int r = 5);

        //Définir une position
        void setPos(int newX, int newY, Level * level);

        //Getters
        int getX();
        int getY();
        int getRadius();

        void update(Level * level);

        //Fonction test
        static void test();
};

#endif