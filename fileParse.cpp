#include "fileParse.h"


fileParse::fileParse()
{
    //finds number of lines in the file
  numberofCommands = getNumLines(); 
  //initialize array 
  comArray = new char* [numberofCom];
  //add loop
  for (int i = 0; i < numberofCom; i+=)
  {
      comArray[i] = new char[5];
  }
  
}

int fileParse::getNumLines()
{
    inputFile.open(FILENAME);
    int lines = 0; //hold number of lines
    std::string tempHolder;
    
    //Steps through file line by line
    while(std::getlines(inputFile, tempHolder))
    {
        lines++; 
    }
   
   inputFile.close();
   
   return lines; 
    
}
int fileParse::getnumberofCom()
{
  return numberofCom;  
}
//rename
char** fileParse::parsing()
{
   //busniess end
   std::string currentLine; //buffer for reading lines and parsing
   std::string words[5]; //array of words of the current line
   std::string currentWord; 
   inputsFile.open(FILENAME);
   
   int l = 0;
   while(std::getline(inputFile, currentLine))
   {
       std::transform(currentLine.begin(), currentLine.end(). currentline.begin(), ::tolower);
       std::stringstream sstream(currentLine);
       int i =0;
      
       while (sstream.good() && i <5)
       {
           sstream >> words[i];
           i++;
       }
    //different command options
    
    /* word, beepers, wall, robot, 
       move, turn, turn left, 
       pick beeper, place beeper
       and turn off  */
       
       currentWord = words[0];
        if(currentWord = "world")
        {
            comArray[l][0] = 'world';
            comArray[l][1] = words[1][0];
            comArray[l][2] = words[2][0];
        }       
       else if (currentWord == "beepers")
       {  
           comArray[l][0] =  'beeper';
           comArray[l][1] = word[1][0];
           comArray[l][2] = word[2][0];
           comArray[l][3] = word[3][0];
       }
       else if (currentWord == "wall")
       {
           comArray[l][0] = 'wall'; 
           comArray[l][1] = word[1][0];
           comArray[l][2] = word[2][0];
           comArray[l][3] = word[3][0];
           
       }
       else if (currentWord == "robot")
       {
           comArray[l][0] = 'robot'; 
           comArray[l][1] = word[1][0];
           comArray[l][2] = word[2][0];
           comArray[l][3] = word[3][0];
           comArray[l][4] = word[4][0];
       }
       else if (currentWord == "move")
       {
           comArray[l][0] = 'move';
       }
       else if (currentWord == "turnleft")
       {
           comArray[l][0] = 'left' ;
       }
       else if (currentWord == "pickbeeper")
       {
           comArray[l][0] = 'pick';
       }
       else if (currentWord == "placebeeper")
       {
           comArray[l][0] = 'place';
       }
       else if (currentWord == "turnoff")
       {
           comArray[l][0] == 'off';
       }
       
       l++
   }
  
  inputFile.close();
  return comArray;
  
}




