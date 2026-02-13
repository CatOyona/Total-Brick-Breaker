#ifndef _GAME
#define _GAME

#include "Level.h"
#include "Ball.h"
#include "Sender.h"
#include "raylib.h"

class Game {
    private:
        Level * level;
        Ball * ball;
        Sender * sender;
        const int HEIGHT_TO_BALL_FACTOR = 40;
        bool lost = false;

        void init();
        void update();
        void lifeDown();

    public:
        //Constructeur par défaut
        Game();

        //Destructeur
        ~Game();

        //Fonction test
        static void test();
};

#endif