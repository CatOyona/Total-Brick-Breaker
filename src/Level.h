#ifndef _LEVEL
#define _LEVEL

class Level {
    private:
        int height, width;
    public:

        //Constructeur par défaut
        Level();

        //Constructeur avec données
        Level(int h, int w);

        //getters
        int getHeight();
        int getWidth();

        //Fonction test
        static void test();
};

#endif