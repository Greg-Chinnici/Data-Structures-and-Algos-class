#include <iostream>
#include <string>
using namespace::std

class StudentRecord{
private:
    int quiz1, quiz2, quiz3;
    int midterm;
    int finalExam;

    double FinalGradeNum;
    char FinalGradeChar;

    StudentRecord(){
        quiz1 = 10, quiz2 = 10, quiz3 = 10;
        midterm = 100;
        finalExam = 100;

        FinalGradeNum = 100;
        FinalGradeChar = 'A';
    };
    StudentRecord(int quizScore1, int quizScore2, int quizScore3, int midtermScore, int finalExamScore){
        quiz1 = quizScore1, quiz2 = quizScore2, quiz3 = quizScore3;
        midterm = midtermScore;
        finalExam = finalExamScore;

    //? idk what to do to calc these, do i just make the method go here?
        FinalGradeNum = computeNumericScore();
        FinalGradeChar = computeLetterGrade();
    };
public:
    double computeNumericScore(){
        return (((quiz1 + quiz2 + quiz3) * 0.25) + (midterm * 0.35) + (finalExam * 0.40))/1.0;
    }
    char computeLetterGrade(){
        //tried to use a switch case but i dont think itll work
        if (FinalgradeNum > 90){
            return 'A';
        }if else(FinalgradeNum > 80){
            return 'B';
        }if else (FinalGradeNum > 70){
            return 'C';
        }if else (FinalGradeNum > 60){
            return 'D';
        }else{
            return 'F';
        }
    }
    //setters
    void setQuiz1(int quizScore1){quiz1 = quizScore1}
    void setQuiz2(int quizScore2){quiz2 = quizScore2}
    void setQuiz3(int quizScore3){quiz3 = quizScore3}
    void setMidterm(int midtermScore){midterm = midtermScore}
    void setFinalExam(int FinalExamScore){finalExam = FinalExamScore}
    //getters
    int getQuiz1(){return quiz1}
    int getQuiz2(){return quiz2}
    int getQuiz3(){return quiz3}
    int getMidterm(){return midterm}
    int getFinalExam(){return finalExam}

    //need toString and Equals
    string toString(){
        string s = '';
        s += "Quiz 1 Grade: " << quiz1;
        s += "Quiz 2 Grade: " << quiz2;
        s += "Quiz 3 Grade: " << quiz3;
        s += "Midterm Grade: " << midterm;
        s += "Final Exam Grade: " << finalExam;

        s += "Final Course Grade: " << FinalGradeChar << ": " << FinalGradeNum;

        return s
    }
};

int main() {
    grades1 = StudentRecord(10 , 9, 7 , 90 , 80)
    cout << grades1.toString()
    return 0;
}
