#include <iostream>

class StudentRecord{
private:
    int quiz1, quiz2, quiz3;
    int midterm;
    int finalExam;

    double FinalGradeNum;
    char FinalGradeChar;

    StudentRecord(){
        int quiz1 = 10, quiz2 = 10, quiz3 = 10;
        int midterm = 100;
        int finalExam = 100;

        double FinalGradeNum = 100;
        char FinalGradeChar = 'A';
    }
    StudentRecord(int quizScore1, int quizScore2, int quizScore3, int midtermScore, int finalExamScore){
        int quiz1 = quizScore1, quiz2 = quizScore2, quiz3 = quizScore3;
        int midterm = midtermScore;
        int finalExam = finalExamScore;

    //? idk what to do to calc these, do i just make the method go here?
        double FinalGradeNum = computeNumericScore();
        char FinalGradeChar = computeLetterGrade();
    }
public:
    double computeNumericScore(){//! not done
        return (quiz1 + quiz2 + quiz3) * 0.25 + midterm * 0.35 + finalExam * 0.40
    }
    char computeLetterGrade(){
        //tried to use a switch case but i diont think itll work
        if (FinalgradeNum > 90){
            return 'A'
        }if else(FinalgradeNum > 80){
            return 'B'
        }if else (FinalGradeNum > 70){
            return 'C'
        }if else (FinalGradeNum > 60){
            return 'D'
        }else{
            return 'F'
        }
    }
    //need mutators an acessors

    //need toString and Equals
}

int main() {

    return 0;
}
//does this work?