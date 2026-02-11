#ifndef _GAME
#define _GAME

#include "Level.h"
#include "Ball.h"

class Game {
    private:
        Level * level;
        Ball * ball;
        const int HEIGHT_TO_BALL_FACTOR = 40;
    public:

        //Constructeur par défaut
        Game();

        //Getters
        int getHeight();
        int getWidth();
        Ball * getBall();

        //Destructeur
        ~Game();

        //Fonction test
        static void test();
};

#endif