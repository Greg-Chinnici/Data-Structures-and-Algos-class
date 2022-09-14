#include "mario.h"
#include <random>

mario::mario(){
    int killStreak = 0;
    int lives = // get the info from the config;
    int[] position[2] = {0,0}; //{posx , posy} in the code, i should convert it eventually
}
mario::~mario(){
    delete killStreak;
    delete lives;
}

char mario::getNewDirection(){
    return random.choice({'n', 's', 'e', 'w'});
}
void mario::moveMario(){
    int posx = pos[0];
    int posy = pos[1];

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

void mario::moveNorth(){
    if (posy == 0){ // if you are at the top adn go north >> go to the bottom
        posy == 9;
    }else{
        posy += 1;
    }
}
void mario::moveSouth(){
    if (posy == 9){ // if you are at the top adn go north >> go to the bottom
        posy == 0;
    }else{
        posy -= 1;
    }
}
void mario::moveEast(){
    if (posx == 9){ // if you are at the top adn go north >> go to the bottom
        posx == 0;
    }else{
        posx -= 1;
    }
}
void mario::moveWest(){
    if (posx == 0){ // if you are at the top adn go north >> go to the bottom
        posx == 9;
    }else{
        posx += 1;
    }
}

//* after every move these need to process / check stuff
void mario::checkForItem(){
    if (Level[posx][posy] == 'c'){
        wallet += 1;
        if (wallet >= 20){
            wallet = 0;
            lives += 1;
        }
        Level[posx][posy] = 'x';
    }
    if (Level[posx][posy] == 'm'){
        powerLevel += (powerLevel += 1 >= 2) ? 2 : powerLevel += 1;
        Level[posx][posy] = 'x';
    }
}
void mario::checkForEnemy(){
    if (Level[posx][posy] == 'g'){
        attackGoomba();
    }
    if (Level[posx][posy] == 'k'){
        attackKoopa();
    }
    if (Level[posx][posy] == 'b'){
        attackBoss();
    }
}
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
    Level[posx][posy] = 'x';
}
void mario::loseBattle(){
    killStreak = 0;
    ((powerLevel - 1 < 0) && (lives - 1 <= 0)) ? gameOver() : powerLevel -= 1;
}

void mario::gameOver(){
    // print out how far mario got
    // add the final log info to the output file
}

//! need to implement pipes and wining agaist a boss moves to the next level
