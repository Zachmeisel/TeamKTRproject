#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

class fileParse {

private:
    char **comArray; //array that holds the number of commands from the file
    std::ifstram inputFile;
    const std::string FILENAME = ""//file name when we get one
    int numberofCom;


public:
    file();
    int getNumLines(); //gets number of line is file
    char **parsingComs(); //parse through file and stores commands
    int getnumberofCom(); //gets the number of commands
    
    
};