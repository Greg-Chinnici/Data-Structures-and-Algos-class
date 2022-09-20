#include <fstream>
#include <iostream>
#include <random>
#include <time.h>
#include <string>


//? do i make a subclass with .at() and  other accessor functions?

class World{
    public:
        World(std::string gameConfig);
        ~World();
        void nextLevel();
        std::string displayLevel();

        char*** Levels; //array of with all levels
        int currentLevel;
        int levelSize, levelCount;
        int percentCoins, percentNone, percentGoombas, percentKoopas, percentMushrooms;
        int marioLives;
        //int[2] findMario();
    private:
        void processConfig(std::string gameConfig); 
        char*** generateWorld(int levelCount, int levelSize, int percentCoins, int percentNone,int percentGoombas,int percentKoopas, int percentMushrooms);

};