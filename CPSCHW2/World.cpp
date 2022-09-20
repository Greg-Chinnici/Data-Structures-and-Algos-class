#include "World.h"
using namespace std;


//* make an accesor (.atCoords(int x, int y)) to see what mario  is on

World::World(string gameConfig){
    int currentLevel = 0; //stater level index

    processConfig(gameConfig);
    //all dependent on the config
    int levelSize, levelCount;

    int percentCoins, percentNone, percentMushrooms;
    int percentGoombas, percentKoopas;
    int marioLives;

    char*** Levels = generateWorld(levelCount, levelSize, percentCoins, percentNone, percentGoombas, percentKoopas, percentMushrooms);

}

World::~World(){
    //just deletes for the levels array
    for (int i = 0; i < levelCount; i++){
        for (int j = 0; j < levelSize; j++){
            delete[] Levels[i][j];
        }
        delete[] Levels[i];
    }
    delete[] Levels;
}

void World::processConfig(string gameConfig){
    int *config = new int[8];

    ifstream fileInput;
    fileInput.open(gameConfig);
    string lineText;
    int cnt = 0;
    while(getline(fileInput , lineText)){
        config[cnt] = (stoi(lineText)); 
        cnt++;
    }
    levelCount = config[0];
    levelSize = config[1];
    marioLives = config[2];
    percentCoins = config[3];
    percentNone = config[4];
    percentGoombas = config[5];
    percentKoopas = config[6];
    percentMushrooms = config[7];

    delete[] config;

    fileInput.close();
    
}

//* clean up with helper methods
char*** World::generateWorld(int levelCount,int levelSize,int percentCoins,int percentNone ,int percentGoombas,int percentKoopas,int percentMushrooms){

    char*** Levels = new char**[levelCount];

    for (int i = 0; i < levelCount; i++){ //* allocate all the memory depending on the total size
        Levels[i] = new char*[levelSize]; //each level index
        for (int j = 0; j < levelSize; j++){
            Levels[i][j] = new char[levelSize];
        }
    }
//batch craft all levels at once
    srand(time(0)); //without this it will not be random
    for (int i = 0; i < levelCount; i++){
        for (int j = 0; j < levelSize; j++){
            for (int k = 0; k < levelSize; k++){
                int randNum = rand() % 100 + 1; //random number (1,100) inclusive
                //[levelindex][levelYvalue][levelXvalue]
                if (randNum <= percentNone){
                    Levels[i][j][k] = 'x';
                }else if(randNum <= percentNone + percentCoins){
                    Levels[i][j][k] = 'c';
                }else if(randNum <= percentNone + percentCoins + percentGoombas){
                    Levels[i][j][k] = 'g';
                }else if(randNum <= percentNone + percentCoins + percentGoombas + percentKoopas){
                    Levels[i][j][k] = 'k';
                }else if(randNum <= percentNone + percentCoins + percentGoombas + percentKoopas + percentMushrooms){
                    Levels[i][j][k] = 'm';
                }else{
                    Levels[i][j][k] = 'x'; //! if broken, it fills th rest with none tiles
                }
            }
        }
        
        // makes the bosses for each level
        srand(time(0));
        while(true){
            int j = rand() % levelSize;
            int k = rand() % levelSize;
            if (Levels[i][j][k] == 'x'){
                Levels[i][j][k] = 'b';
                break;
            }
        }

        //makes the pipes for each level exept the last
        if(i != levelCount - 1){
            while(true){
                srand(time(0));
                int j = rand() % levelSize;
                int k = rand() % levelSize;
                if (Levels[i][j][k] == 'x'){
                    Levels[i][j][k] = 'w';
                    break;
                }
            }
        }
    }

return Levels;
}

string World::displayLevel(){
    string s = "";
    //? do i make a copy and place mario on it?
    for (int row = 0; row < levelSize; row++){
        for (int col = 0; col < levelSize; col++){
            s += Levels[currentLevel][row][col] + " ";
        }
        s += "\n";
    }

    return s;
}

void World::nextLevel(){
    currentLevel++;
    srand(time(0));
    while(true){
        int row = rand() % levelSize;
        int col = rand() % levelSize;
        if (Levels[currentLevel][row][col] == 'x'){
            Levels[currentLevel][row][col] = 'H';
            break;
        }
    }
}
/*
int[2] World::findMario(){
    for (int row = 0 ; row < levelSize; row++){
            for (int col = 0 ; col < levelSize; col++){
                if (Level[row][col] == 'H'){
                    return {row, col};
                }
            }
        }
}
*/

