/*
- Name: Greg Chinnici
- Student Id: 2398362
- Chapman Email: chinnici@chapman.edu
- Course: CPSC 350 - 02
- Assignment: Robber Language Translation
*/
#include "Translator.h"
using namespace std;
 
Translator::Translator(){
}
Translator::~Translator(){
}
/*
@param string englishWord: full sentence that gets all of its letters translated accordingly
@return translatedWord: full line of translated text
*/
string Translator::translateEnglishWord(string englishWord){
   string translatedWord = "";
   Model m = Model();
   for (int letterIndex = 0 ; letterIndex < englishWord.length() ; letterIndex++){
       char letter = englishWord[letterIndex];
       translatedWord += VowelCheck(letter) ? m.translateSingleVowel(letter) : m.translateSingleConsonant(letter);
   }
   m.~Model();
   return translatedWord;
}
/*
@param string englishSentence: full line of text from the txt input file
@return translatedSentence: fully translated string of the txt file line
*/
string Translator::translateEnglishSentence(string englishSentence){
   string translatedSentence = "";
   string word = "";
   int charCount = 0;
   for (char letter : englishSentence){
       if (letter == ' ' || charCount == englishSentence.length() - 1){
           word += letter;
           translatedSentence += translateEnglishWord(word);
           word = "";
       }else{
           word += letter;
       }
       charCount++;
   }
   return translatedSentence;
}
/*
@param char vowel: letter to be compared to actual vowels for the boolean
@return bool: true if the letter is equal to any of the vowels, false if else
*/
bool Translator::VowelCheck(char letter){
   return (tolower(letter) == 'a' || tolower(letter) == 'e' || tolower(letter) == 'i' || tolower(letter) == 'o' || tolower(letter) == 'u');
}
 
 
 

