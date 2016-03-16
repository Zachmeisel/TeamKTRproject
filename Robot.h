#pragma once
#include "Item.h"


ref class Robot: public Item {

protected:
	static System::Drawing::Icon^ robotup;
	static System::Drawing::Icon^ robotright;
	static System::Drawing::Icon^ robotleft;

public:
	Robot(void) { setIcon(); }
    
    Robot(int row, int col);

	System::Drawing::Icon^ RobotLocation::getIcon();

void Robot::setIcon()override;

	void robotup() 
    {
        row--;
        icon = 2;   
	}
	void robotright() 
    {
         col ++;
         icon =0;
	}
	void robotleft() 
    {
        col--;
        icon = 1;
        
	}
	



};
