#ifdef StudentRecord_h
#define StudentRecord_h

#include <stdio.h>

class StudentRecord{
private:
    StudentRecord();
    StudentRecord(int quizScore1, int quizScore2, int quizScore3, int midtermScore, int finalExamScore);

public:

    computeNumericScore();
    computeLetterGrade();

    void setQuiz1(int quizScore1);
    void setQuiz2(int quizScore2);
    void setQuiz3(int quizScore3);
    void setMidterm(int midtermScore);
    void setFinalExam(int FinalExamScore);

    int getQuiz1();
    int getQuiz2();
    int getQuiz3();
    int getMidterm();
    int getFinalExam();
};
#endif //StudentRecord_h