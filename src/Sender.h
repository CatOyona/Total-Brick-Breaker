#ifndef _SENDER
#define _SENDER

#include "Level.h"
#include "Ball.h"

class Ball;

class Sender {
    private:
        int x, y;
        int width, height;
        int BASE_VELOCITY = 7;
        float velocityMultiplier = 1.0f;

    public:

        //Constructeur par défaut
        Sender(Level * level);

        //Getters
        int getX();
        int getY();
        int getWidth();
        int getHeight();

        void updatePos(int delta, Level * level, Ball * ball);
        void setPos(int newX, Level * level);

        //Fonction test
        static void test();
};

#endif