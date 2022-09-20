/*
- Name: Greg Chinnici
- Student Id: 2398362
- Chapman Email: chinnici@chapman.edu
- Course: CPSC 350 - 02
- Assignment: Robber Language Translation
*/
#ifndef Translator_H
#define Translator_H
#include "Model.h"


class Translator{
public:
    Translator();
    virtual ~Translator();
    std::string translateEnglishWord(std::string englishWord);
    std::string translateEnglishSentence(std::string englishSentence);
private:
    bool VowelCheck(char letter);

};
#endif