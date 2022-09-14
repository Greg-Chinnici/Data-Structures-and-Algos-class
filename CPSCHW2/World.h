#include <fstream>
#include <string>
#include <iostream>
#include <random>

class World{
    public:
        World(std::string gameConfig);
        ~World();
        
        int currentLevel;
        int levelSize, levelCount;
        int percentCoins, percentNone, percentGoombas, percentKoopas;
        int marioLives;
    private:
        int[] processConfig(std::string gameConfig); 
        **char[] Levels; //array of with all levels
        char[][] generateLevel(int levelSize, int percentCoins, int percentNone,int percentGoombas,int percentKoopas);
        char[][] generateLastLevel(int levelSize, int percentCoins, int percentNone,int percentGoombas,int percentKoopas);

};