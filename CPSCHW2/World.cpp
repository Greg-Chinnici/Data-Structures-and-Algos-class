#include "World.h"
using namespace std;


World::World(std::string gameConfig){
    int currentLevel = 0;
    int config[7] = processConfig(gameConfig);

    //all dependent on the config
    int levelSize , levelCount;
    int percentCoins, percentNone, percentGoombas, percentKoopas;
    int marioLives;
    //independent technically
    char Levels[levelCount][levelSize][levelSize]; //array of with all levels

    for (int i = 0 ; i < levelCount - 1 ;i++){ //loop for al levels excpet the last one (boss level)
        Levels.append(generateLevel(levelSize, percentCoins, percentNone, percentGoombas, percentKoopas));
    }
    Levels.append(generateLastLevel(levelSize, percentCoins, percentNone, percentGoombas, percentKoopas));


}
World::~World(){

}

*int World::processConfig(string gameConfig){
    int *config;

    ifstream fileInput;
    fileInput.open(gameConfig);
    string lineText;
    while(getline(fileInput , lineText)){
        config.append(stoi(lineText)); //! no worky
    }
    
    levelCount = config[0];
    levelSize = config[1];
    marioLives = config[2];
    percentCoins = config[3];
    percentNone = config[4];
    percentGoombas = config[5];
    percentKoopas = config[6];

    fileInput.close();
    return config;
}

// probably need to restructure the arrays to be all pointers and stuff, //? needs to be 2d char array with pointers
char[[][]] World::generateLevel(levelSize, percentCoins, percentNone, percentGoombas, percentKoopas){
    char[][] Level = new char[levelSize][levelSize];
    for (int row = 0 ; row < levelSize; row++){
        char[] line = new char[levelSize];
        for (int col = 0 ; col < levelSize; col++){
            int randNum = rand() % 100 + 1; //random number (1,100) inclusive
            switch (randNum){
                case randNum < percentNone:
                    Level[row][col] = 'x';
                    break;
                case randNum < percentCoins + percentNone:
                    Level[row][col] = 'c';
                    break;
                case randNum < percentCoins + percentNone + percentGoombas:
                    Level[row][col] = 'g';
                    break;
                case randNum < percentCoins + percentNone + percentGoombas + percentKoopas:
                    Level[row][col] = 'k';
                    break;
                default:
                    Level[row][col] = '*'; //! if broken, error case testing the range
            }
        }
        Level.append(line);
    }
        // TODO adding the pipe to the level after generation , pipe =  'w'
        //* loop through the new level 2d array, look for 'x' and add the indeces to a list
        //* choose a random pair and replace it with a 'w' (tuples?)

        // TODO add a boss to a random open space , boss = 'b'
        //* loop through the new level 2d array, look for 'x' and add the indeces to a list
        //* choose a random pair and replace it with a 'b' (tuples?)
   
    return Level;
}
*char[] World::generateLastLevel(levelSize, percentCoins, percentNone, percentGoombas, percentKoopas){
    char[][] bossLevel generateLevel(levelSize, percentCoins, percentNone, percentGoombas, percentKoopas);

        // TODO remove the pipe to the level after generation , pipe =  'w'
        //* loop through the new level 2d array, look for 'w' and replace it with 'x' , THIS IS INEFFIENT 

    return bossLevel;
}