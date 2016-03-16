#include "Robot.h"

Robot::Robot(int newRow, int Col) : Item(newRow,newCol)
{
    setIcon();
}

void Robot::setIcon()
{
    icon = 0;
    robotup = gcnew System::Drawing::Icon("robotup.icon");
    robotright = gcnew System::Drawing::Icon("robotright.icon");
    robotleft = gcnew System::Drawing::Icon("robotleft.icon");
}
System::Drawing::Icon^ Robot::getIcon()
{
    if (icon == 0)
        return robotright;
    else if (icon == 1)
        return robotleft;
    else (icon == 2)
        return robotup;        
}