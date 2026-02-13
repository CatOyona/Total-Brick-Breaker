#ifndef _LEVEL
#define _LEVEL

class Level {
    private:
        int height, width;
        int lives = 5;

    public:
        //Constructeur par défaut
        Level();

        //Constructeur avec données
        Level(int h, int w);

        //Getters
        int getHeight();
        int getWidth();
        int getLives();

        //Setters
        void setLives(int n);

        //Fonction test
        static void test();
};

#endif