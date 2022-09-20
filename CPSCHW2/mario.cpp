#include "mario.h"
#include "TurnLogger.h"
#include "World.h"
#include <random>
#include <time.h>

mario::mario(TurnLogger* lg, World* w){
    int killStreak = 0;
    World* wrld = w;
    int lives = wrld.marioLives //! not connected yet
    int position[] = {0,0}; //{posx , posy} in the code, i should convert it eventually
    int wallet = 0;
    int powerLevel = 0;
    TurnLogger* logger = lg;
}
mario::~mario(){
    
}

char mario::getNewDirection(){
    char dirs[] = {'n', 's', 'e', 'w'};
    srand(time(0));
    return dirs[rand() % 4];
}
void mario::moveMario(){
    char direction = getNewDirection();
    // add the direction to the move logs

    switch (direction){
    case 'n':
        moveNorth();
        break;
    case 's':
        moveSouth();
        break;
    case 'e':
        moveEast();
        break;
    case 'w':
        moveWest();
        break;
    default:
        break;
    }
}

//* they all have torous properties, only one direction per turn
void mario::moveNorth(){
    if (position[1] == 0){ 
        position[1] = 9;
    }else{
        position[1] += 1;
    }
    logger.logInfo("Direction: move up \n");
}
void mario::moveSouth(){
    if (position[1] == 9){ 
        position[1] == 0;
    }else{
        position[1] -= 1;
    }
    logger.logInfo("Direction: move down \n");
}
void mario::moveEast(){
    if (position[0] == 9){ 
        position[0] == 0;
    }else{
        position[0] -= 1;
    }
    logger.logInfo("Direction: move left \n");
}
void mario::moveWest(){
    if (position[0] == 0){
        position[0] == 9;
    }else{
        position[0] += 1;
    }
    logger.logInfo("Direction: move right \n");

}

//* after every move these need to process / check stuff
void mario::checkForItem(){
    if ([wrld.currentLevel][position[0]][position[1]] == 'c'){
        wallet += 1;
        if (wallet >= 20){
            wallet = 0;
            lives += 1;
            logger.logInfo("Action at Position: found coin and gained a life");
        }else{
            logger.logInfo("Action at Position: found coin");
        }
        [wrld.currentLevel][position[0]][position[1]] = 'x';
    }
    if ([wrld.currentLevel][position[0]][position[1]] == 'm'){
        powerLevel += (powerLevel += 1 >= 2) ? 2 : powerLevel += 1;
        logger.logInfo("Action at Position: found mushroom");
        [wrld.currentLevel][position[0]][position[1]] = 'x';
    }
    if ([wrld.currentLevel][position[0]][position[1]] == 'x'){
        logger.logInfo("Action at Position: blank space");
    }
    if ([wrld.currentLevel][position[0]][position[1]] == 'w'){
        logger.logInfo("Action at Position: used warp pipe");
        wrld.nextLevel(); //! mkae this move mario into a random spot in the next level
    }
}
void mario::checkForEnemy(){
    if ([wrld.currentLevel][position[0]][position[1]] == 'g'){
        attackGoomba();
    }
    if ([wrld.currentLevel][position[0]][position[1]] == 'k'){
        attackKoopa();
    }
    if ([wrld.currentLevel][position[0]][position[1]] == 'b'){
        attackBoss();
    }
}
//! do i make logs for each mob encounter adn type
void mario::attackGoomba(){
    ((rand() % 100 + 1) > 20) ? winBattle() : loseBattle();
}
void mario::attackKoopa(){
    ((rand() % 100 + 1) > 35) ? winBattle() : loseBattle();
}
/*
Mario defeats the enemy with a 50% probability, the position becomes empty, and Mario moves on to the next level. 
If Mario is in the last level, the princess is saved, the game is won, and the simulation is over. If Mario loses (50% probability), 
his power level is decreased by 2, and Mario attempts to defeat the boss again. The exception is if Mario loses while at PL0 or PL1, 
in which case a life is lost. If Mario has another life, he continues at the same location, with PL0. Otherwise,
the simulation ends, and the game is lost.*/ //! need to add this 
void mario::attackBoss(){
    ((rand() % 100 + 1) > 50) ? winBattle() : loseBattle();
}

void mario::winBattle(){
    killStreak++;
    if (killStreak >= 7){
        lives += 1;
        killStreak = 0;
    }
   [wrld.currentLevel][position[0]][position[1]] = 'x';
}
void mario::loseBattle(){
    killStreak = 0;
    ((powerLevel - 1 < 0) && (lives - 1 <= 0)) ? gameOver() : powerLevel -= 1;
}

void mario::gameOver(){
    // print out how far mario got
    // add the final log info to the output file
    std::string message = "game over" << "mario got to level 1-" << std::string(World.currentLevel + 1);
    logger.logInfo(message);
    logger.~TurnLogger();
}

//! need to implement pipes and wining agaist a boss moves to the next level
