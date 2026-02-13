#ifndef _SENDER
#define _SENDER

#include "Level.h"

class Sender {
    private:
        int x, y;
        int width, height;

    public:

        //Constructeur par défaut
        Sender(Level * level);

        //Getters
        int getX();
        int getY();
        int getWidth();
        int getHeight();

        void updatePos(int delta, Level * level);
        void setPos(int newX, Level * level);

        //Fonction test
        static void test();
};

#endif