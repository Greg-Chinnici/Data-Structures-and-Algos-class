/*
- Name: Greg Chinnici
- Student Id: 2398362
- Chapman Email: chinnici@chapman.edu
- Course: CPSC 350 - 02
- Assignment: Robber Language Translation
*/
#include "FileProcessor.h"
#include <iostream>
#include <string>
using namespace std;
 
 
/*
@param int argc: amount of command line args including the file name
@param char* argv[]: array of command line args
@func this starts the fileprocessor and gives it the name of files to translate and output to
@note the destructors are not necessary because all of the classes have no member variables
*/
int main(int argc,char* argv[]){
 
   FileProcessor processor = FileProcessor();   
   processor.processFile(argv[1] , argv[2]);
   processor.~FileProcessor();
 
   return 0;
}
