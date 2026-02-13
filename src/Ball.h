#ifndef _BALL
#define _BALL

#include "Level.h"
#include "Sender.h"

class Ball {
    private:
        int x, y;
        int radius;
        int angle; //Angle entre 0 et 359 (degrés)
        const int BASE_VELOCITY = 5;
        const int FLUCTUATION_DELTA = 20;
        float velocityMultiplier = 1.0f;
        bool active = false;

        //Teste une collision avec un rectangle de centre (centerXPos, centerYPos), de largeur width, et de hauteur height,
        //avec une balle à la position (x, y).
        bool collidesWith(int centerXPos, int centerYPos, int width, int height, int x, int y);

    public:
        //Constructeur par défaut
        Ball(Level * level, int r = 5);

        //Définir une position
        void setPos(int newX, int newY, Level * level);

        //Getters
        int getX();
        int getY();
        int getRadius();

        bool update(Level * level, Sender * sender);

        void setActive(bool active);

        //Fonction test
        static void test();
};

#endif