/*
- Name: Greg Chinnici
- Student Id: 2398362
- Chapman Email: chinnici@chapman.edu
- Course: CPSC 350 - 02
- Assignment: Robber Language Translation
*/
#ifndef Model_H
#define Model_H
#include <iostream>
#include <string>


class Model{
public:
    Model();
    virtual ~Model();
    std::string translateSingleConsonant(char consonant);
    std::string translateSingleVowel(char vowel);
private:
};
#endif