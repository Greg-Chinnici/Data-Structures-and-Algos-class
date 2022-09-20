
class mario{
    public:
        mario(TurnLogger lg);
        ~mario();

        char getNewDirection();
        void moveMario();
        TurnLogger logger;
        World wrld;

    private:
        int killStreak;
        int lives;
        int position[2]; //keep track of current x and y values of mario
        int wallet;
        int powerLevel;

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