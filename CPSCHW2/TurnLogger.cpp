#include "TurnLogger.h"
#include <iostream>
#include <fstream>

TurnLogger::TurnLogger(char* outputFile){//! not right
    ofstream fileOut;
    fileOut.open(outputFile, std::ios_base::app); // this is for appending to the end of a file

}

TurnLogger::~TurnLogger()
{
}