/*
- Name: Greg Chinnici
- Student Id: 2398362
- Chapman Email: chinnici@chapman.edu
- Course: CPSC 350 - 02
- Assignment: Robber Language Translation
*/
#include "Model.h"
using namespace std;
 
Model::Model(){
}
Model::~Model(){
}
/*
@param char consonant: it's the current character, not a vowel but anything else
@return if it is a letter it returns the letter with a vowel and the same letter
@return if it is punctuation it returns itself
*/
string Model::translateSingleConsonant(char consonant){
       char vowel = 'o';
       string s;
       if (isalpha(consonant)){
           s += consonant;
           s += vowel;
           s += tolower(consonant);
           return s;
       }else{
           return s = consonant;
       }
   }
/*
@param char vowel: it's the current character, always a vowel, thanks to the ternary condition in translateEnglishWord
@return vowel by itself
*/
string Model::translateSingleVowel(char vowel){
       string s;
       return s = vowel;
   }
 

