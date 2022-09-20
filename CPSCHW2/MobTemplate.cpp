#include <random>
#include "mario.h"

//mario lands on a mob >> mario fights mob >> mario sins or loses >> 

class MobTemplate(){
    MobTemplate(mario mm){
        mario m = mm;
    }
    void attack();
    void winBattle(){
        mario.killStreak++;
        if (mario.killStreak >= 7){
            mario.lives += 1;
            mario.killStreak = 0;
        }
       Level[posx][posy] = 'x';
    }
    void loseBattle(){
        ((mario.powerLevel - 1 < 0) && (mario.lives - 1 <= 0)) ? gameOver() : mario.powerLevel -= 1;
    }
    void gameOver(){
        // print out how far mario got
        // add the final log info to the output file
        logger.log("game over");
        logger.~TurnLogger();
    }
    void winGame(){
        logger.log("game won");
        logger.~TurnLogger();
    }
}


class Goomba{
    void Goomba::attack(){
        if (rand() % 100 + 1) > 20){
            winBattle();
        }else{
            loseBattle();
        }
    }
    void Goomba::winBattle(){};
    void Goomba::loseBattle();
}

class Koopa : public MobTemplate{
    void Koopa::attack(){
        if (rand() % 100 + 1) > 35){
            winBattle();
        }else{
            loseBattle();
        }
    }
    void Koopa::winBattle();
    void Koopa::loseBattle();
}

/*
Mario defeats the enemy with a 50% probability, the position becomes empty, and Mario moves on to the next level. 
If Mario is in the last level, the princess is saved, the game is won, and the simulation is over. If Mario loses (50% probability), 
his power level is decreased by 2, and Mario attempts to defeat the boss again. The exception is if Mario loses while at PL0 or PL1, 
in which case a life is lost. If Mario has another life, he continues at the same location, with PL0. Otherwise,
the simulation ends, and the game is lost.*/ //! need to add this 
class Boss : public MobTemplate{
    void Boss::attackBoss(){
        if (rand() % 100 + 1) > 50){
            winBattle();
        }else{
            loseBattle();
        }
    }
    void Boss::winBattle(){
        mario.killStreak++;
        if (mario.killStreak >= 7){
            mario.lives += 1;
            mario.killStreak = 0;
        }
       Level[posx][posy] = 'x';

        if(Levels.indexof(Level) == levelCount){
            wingame();
        }else{
            World.NextLevel(); //! make this a thing, also make it output the level number to start the logger
        }
        //! movem to the  next level
    }
    void loseBattle(){
        if ((mario.powerLevel - 2 < 0) && (mario.lives - 1 <= 0)){
            gameOver();
        }else{
            mario.powerLevel -= 2;
        }
        attackBoss();
        }
}