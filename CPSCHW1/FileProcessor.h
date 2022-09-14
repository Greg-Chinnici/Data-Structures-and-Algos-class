/*
- Name: Greg Chinnici
- Student Id: 2398362
- Chapman Email: chinnici@chapman.edu
- Course: CPSC 350 - 02
- Assignment: Robber Language Translation
*/
#ifndef FileProcessor_H
#define FileProcessor_H
#include "Translator.h"
#include <fstream>


class FileProcessor{
public:
    FileProcessor();
    virtual ~FileProcessor();
    void processFile(char* inputFile , char* outputFile);
private:
    std::string ConcatHTML(std::string title, std::string outgoingEnglish, std::string outgoingTranslated);
    bool SentenceCheck(char punctuation , bool endOfLine);
    std::string makeSentence(std::string lineText);
};
#endif