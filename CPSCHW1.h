#include <string>

//using namespace std

class Model{
public:
    Model();
    ~Model();
    string translateSingleConsonant(char consonant);
    string translateSingleVowel(char vowel);
private:
    bool isVowel(char letter);
}



class Translator{
public:
    Translator();
    ~Translator();
    string translateEnglishWord(string englishWord);
    string translateEnglishSentence(string englishSentence);
private:
}



class FileProcessor{
public:
    FileProcessor();
    ~FileProcessor();
    void processFile();
private:
}