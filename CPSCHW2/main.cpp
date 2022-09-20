#include <iostream>
#include <fstream>
#include "World.h"
#include "TurnLogger.h"
#include "mario.h"

//* need to make a game loop that logs the data after each turn
int main(int argc,char* argv[]){
    World* game = new World(argv[1]); //only need to take in the string for the data loggin file
    TurnLogger* logger = new TurnLogger(argv[2]);
    mario* mario = new mario(logger, game);
    game.~World();
    logger.~TurnLogger();
    
while(mario.lives > 0 && World.currentLevel <= World.levelCount || World.isGameOver()){

}

    return 1;
}