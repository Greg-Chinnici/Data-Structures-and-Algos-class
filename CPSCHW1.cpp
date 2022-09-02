#include <iostream>
#include "CPSCHW1.h"
//using namespace std


/*
The Model Class
You will build a class named Model that will encode the rules of the Robber language. The class will contain the following public methods:
A default constructor
A default destructor
translateSingleConsonant– takes a single consonant character as input and returns a string representing its encoding in Rövarspråket. Capitalization should be preserved.
translateSingleVowel – takes a single vowel character as input and returns a string representing its encoding in Rövarspråket. Capitalization should be preserved.
*/

class Model{
public:
    Model(){

    }
    ~Model(){
        delete[] Model;
    }
    string translateSingleConsonant(char consonant){ //keep capitals uppercase
        char vowel = 'o';
        if (isalpha(consonant)){//if it is a letter be normal, vowels have already been checked
            return consonant << vowel << consonant; //?concat
        }else{//this means that it is punction so just return it
            return consonant;
        }
    }
    string translateSingleVowel(char vowel){
        return vowel;
    }
private:
    bool isVowel(char letter){
        switch(tolower(letter)){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                return false;
        }
        //not sure which one looks better
        //return(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' ||);
        
    }
}

/*
The Translator Class
You will build a class named Translator that will translate English sentences to Rövarspråket sentences using the Model class. The class will contain the following public methods:
A default constructor
A default destructor
translateEnglishWord – takes a single string representing a single English word as input and returns a string representing the Rövarspråket translation.
translateEnglishSentence – takes a single string representing a single English sentence as input and returns a string representing the Rövarspråket translation. Make sure to account for punctuation.
*/

class Translator{
public:
    Translator(){

    }
    ~Translator(){
        delete[] Translator;
    }
    string translateEnglishWord(string englishWord){
        string translatedWord = "";
        bool isUppercase;

        for (int letterIndex = 0 ; letterIndex < len(englishWord) ; letterIndex++){//for every letter in the word
            isUppercase = (englishWord[letterIndex])
            translatedWord += Model.isVowel(char(englishWord[letterIndex])) ? Model.translateSingleVowel(char(englishWord[letterIndex])) : Model.translateSingleConsonant(char(englishWord[letterIndex]));
        }
        return translatedWord
    }
    string translateEnglishSentence(string englishSentence){
        string translatedSentence = "";
        for (string word : englishSentence){ //? idk if this works
            translatedSentence += translateEnglishWord(word) + " ";
        }
        return translatedSentence;
    }
private:
}

/*
The FileProcessor Class
You will build a class named FileProcessor that will take txt files containing English text and produce a html file containing the equivalent Rövarspråket translation that can be viewed in a standard web browser. The class will contain the following public methods:
A default constructor
A default destructor
processFile – takes a string representing the input file  (English) and a string representing the output file (where the Rövarspråket translation will be written). This method has a void return type. The method should produce a html file that has the original English text in bold followed by an empty line, followed by the Rövarspråket translation in italics. If you are not familiar with html, a simple tutorial is available here: https://html.com/#Creating_Your_First_HTML_Webpage
*/

class FileProcessor{
public:
    FileProcessor(){

    }
    ~FileProcessor(){

    }
    void processFile(string inputFile , string outputFile){
//take in the txt file
//technically i can just put the whole file into the sentence translator
//overwrite the ouput file with the new stuff
    }
private:
}
