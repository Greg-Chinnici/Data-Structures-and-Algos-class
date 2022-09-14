
class mario{
    public:
        char getNewDirection();
        void moveMario();


    private:
        int killStreak;
        int lives;
        int position[2]; //keep track of current x and y values of mario

        void moveNorth();
        void moveSouth();
        void moveWest();
        void moveEast();

        void checkForItem();
        void checkForEnemy();

        void attackGoomba();
        void attackKoopa();
        void attackBoss();

        void winBattle();
        void loseBattle();
        void gameOver();

};