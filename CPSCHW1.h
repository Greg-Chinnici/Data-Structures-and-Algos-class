#include <string>
#include <fstream>
#include <iostream>



class Model{
public:
    Model();
    ~Model();
    std::string translateSingleConsonant(char consonant);
    std::string translateSingleVowel(char vowel);
private:
    bool isVowel(char letter);
};



class Translator{
public:
    Translator();
    ~Translator();
    std::string translateEnglishWord(std::string englishWord);
    std::string translateEnglishSentence(std::string englishSentence);
private:
};



class FileProcessor{
public:
    FileProcessor();
    ~FileProcessor();
    void processFile();
private:
};