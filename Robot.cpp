#include "Robot.h"

Robot::Robot(int newDir, int newBeep, int newRow, int newCol) : Item(newRow,newCol)
{
    setIcon();
    dir = newDir;
    beep = newBeep;
    row = newRow;
    col = newCol;
   
}

void Robot::setIcon()
{
    
    robotup = gcnew System::Drawing::Icon("robotup.ico");
    robotright = gcnew System::Drawing::Icon("robotright.ico");
    robotleft = gcnew System::Drawing::Icon("robotleft.ico");
    icon = 0;
}
System::Drawing::Icon^ Robot::getIcon()
{
	
    if (icon == 0)
        return robotright;
    else if (icon == 1)
        return robotleft;
	else (icon == 2);
	{
		return robotup;
	}
            
}

void Robot::move()
{
    switch(dir)
    {
        case 1:
            col--;
            break;
        case 2:
            row++;
            break;
        case 3:
            col++;
            break;
        case 4:
            row--;
            break;   
    }
}

void Robot::pickBeeper()
{
    beep++;
}
void Robot::placeBeeper()
{
    beep--;
}
int Robot::getRow()
{
    return row;
}
int Robot::getCol()
{
    return col;
}
void Robot::turnLeft()
{
    if (dir = 1)
         dir = 4;
    else 
          dir--;
}
int Robot::getbeepercount()
{
    return beep;
}
int Robot::getDirc()
{
    return dir;
}
