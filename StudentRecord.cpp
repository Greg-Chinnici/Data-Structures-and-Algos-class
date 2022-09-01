#include "StudentRecord.h"
#include <iostream>
#include <string>
using namespace std

//promt: https://canvas.chapman.edu/courses/44377/pages/c++-sample-problem?module_item_id=1437872

class StudentRecord{
private:
    int quiz1, quiz2, quiz3;
    int midterm;
    int finalExam;

    //needs to be processed
    double finalGradeNum;
    char finalGradeChar;

    StudentRecord(){//initial constructor
        quiz1 = 10, quiz2 = 10, quiz3 = 10;
        midterm = 100;
        finalExam = 100;

        FinalGradeNum = 100;
        FinalGradeChar = 'A';
    };
    StudentRecord(int quizScore1, int quizScore2, int quizScore3, int midtermScore, int finalExamScore){//overloaded constructor
        quiz1 = quizScore1, quiz2 = quizScore2, quiz3 = quizScore3;
        midterm = midtermScore;
        finalExam = finalExamScore;

    //? idk what to do to calc these, do i just make the method go here?
        FinalGradeNum = computeNumericScore();
        FinalGradeChar = computeLetterGrade();
    };
public:
    double computeNumericScore(){
        return ((((this->quiz1 + this->quiz2 + this->quiz3)/30.0) * 0.25) + ((this->midterm/100.0) * 0.35) + ((this->finalExam/100.0) * 0.40)) * 100;
    }
    char computeLetterGrade(){
        //tried to use a switch case but i dont think itll work
        if (this->finalgradeNum > 90){
            return 'A';
        }if else(this->finalgradeNum > 80){
            return 'B';
        }if else (this->finalGradeNum > 70){
            return 'C';
        }if else (this->finalGradeNum > 60){
            return 'D';
        }else{
            return 'F';
        }
    }
    //setters
    void setQuiz1(int quizScore1){this->quiz1 = quizScore1};
    void setQuiz2(int quizScore2){this->quiz2 = quizScore2};
    void setQuiz3(int quizScore3){this->quiz3 = quizScore3};
    void setMidterm(int midtermScore){this->midterm = midtermScore};
    void setFinalExam(int finalExamScore){this->finalExam = finalExamScore};
    //getters
    int getQuiz1(){return this->quiz1};
    int getQuiz2(){return this->quiz2};
    int getQuiz3(){return this->quiz3};
    int getMidterm(){return this->midterm};
    int getFinalExam(){return this->finalExam};

    //need toString and Equals
    string toString(){
        string s = '';
        s += "Quiz 1 Grade: " << quiz1;
        s += "Quiz 2 Grade: " << quiz2;
        s += "Quiz 3 Grade: " << quiz3;
        s += "Midterm Grade: " << midterm;
        s += "Final Exam Grade: " << finalExam;

        s += "Final Course Grade: " << finalGradeChar << ": " << finalGradeNum;

        return s
    }
    bool isEqual(StudentRecord s1 , Studentrecord s2){
       return ((s1.quiz1 == s2.quiz1) && (s1.quiz2 == s2.quiz2) && (s1.quiz3 == s2.quiz3) && (s1.midterm == s2.midterm) && (s1.finalExam == s2.finalExam))
       }
};

int main() {
    StudentRecord grades1 = StudentRecord(10 , 9 , 7 , 90 , 80)
    cout << grades1.toString()
    return 0;
}
