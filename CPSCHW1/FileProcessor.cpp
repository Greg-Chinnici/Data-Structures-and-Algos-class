/*
- Name: Greg Chinnici
- Student Id: 2398362
- Chapman Email: chinnici@chapman.edu
- Course: CPSC 350 - 02
- Assignment: Robber Language Translation
*/
#include "FileProcessor.h"
using namespace std;
 
FileProcessor::FileProcessor(){
}
FileProcessor::~FileProcessor(){
}
/*
@param char* inputFile: name of the txt file that has the incoming text to be translated
@param char* outputFile: name of the html file that will be produced after translation
@func in the while loop, it checks for a 0 width line (aka just a newline) and inserts a newline html tag so it won't have to process it
@func takes in the translated text and makes it html compatible, separating the english and robber lang
*/
void FileProcessor::processFile(char* inputFile , char* outputFile){
   ifstream fileInput;
   fileInput.open(inputFile);
   ofstream fileOutput;
   fileOutput.open(outputFile);
   if (fileInput.is_open() && fileOutput.is_open()){
       string lineText;
       string title = "Greg's English to Robber Lang Translator";
       string outgoingEnglish = "";
       string outgoingRobber = "";
       while(getline(fileInput , lineText)){
            outgoingEnglish += (lineText.length()==0) ? "<br>\n" : "<p><b>" + lineText + "</b></p>\n";
            string translatedLine = makeSentence(lineText);
            outgoingRobber += (lineText.length()==0) ? "<br>\n" : "<p><i>" + translatedLine + "</i></p>\n";
       }
       fileOutput << ConcatHTML(title, outgoingEnglish, outgoingRobber);
       fileInput.close();
       fileOutput.close();
   }
}
 
/*
@param string title: name of the html page, shows in the tab
@param string outgoingEnglish: entire string of the english txt
@param string outgoingRobber: entire string of the  robber lang
return string s: full html string that is formatted and ready to write to a file
*/
string FileProcessor::ConcatHTML(string title, string outgoingEnglish, string outgoingRobber){
   string s = "";
   s += "<!DOCTYPE html>\n<html>\n<head><title>";
   s += title + "</title></head>\n<body>\n";
   s += outgoingEnglish + "<br>\n";
   s += outgoingRobber + "</body>\n</html>";
   return s;
}
/*
@param char punctuation: the character from the sentence, can be any char but if true is it punctuation
@param bool endOfLine: if the character is  at the end of a line with no punctuation it is true
@return bool , if true it sends the sentence off to be translated
*/
bool FileProcessor::SentenceCheck(char punctuation , bool endOfLine){
   return (punctuation == '.' || punctuation == '?' || punctuation == '!' || endOfLine );
}
/*
@func it loops through the whole line and translates each sentence individually
@param string lineText: full line of english from the txt file
@return string tl: tl is the full translated line of english into robber lang
*/
string FileProcessor::makeSentence(string lineText){
   Translator t = Translator();
   string sentence = "";
   string tl = "";
   for (int letterIndex = 0 ; letterIndex < lineText.length(); letterIndex++){
           if (SentenceCheck(lineText[letterIndex] , letterIndex == lineText.length() - 1)){
               sentence += lineText[letterIndex];
               tl += t.translateEnglishSentence(sentence) + ' ';
               sentence = "";
           }else{
               sentence += lineText[letterIndex];
           }
       }
   t.~Translator();
   return tl;
}

