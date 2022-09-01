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

    }
    string translateSingleConsonant(char consonant){ //keep capitals uppercase
//?concat
        char vowel = 'o'
        return consonant << vowel << consonant
    }
    string translateSingleVowel(char vowel){
        return vowel
    }
private:
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

    }
    string translateEnglishWord(string englishWord){

    }
    string translateEnglishSentence(string englishSentence){
        for (string word : englishSentence){ //? idk if this works
            translateEnglishWord(word)
        }
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

    }
private:
}