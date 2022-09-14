#include <iostream>
#include <fstream>
#include "World.h"
#include "TurnLogger.h"

//* need to make a game loop that logs the data after each turn
int main(int argc,char* argv[]){
    World* game = new World(argv[1]); //only need to take in the string for the data loggin file
    TurnLogger* logger = new TurnLogger(argv[2]);


    return 1;
}