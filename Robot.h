#pragma once
#include "Item.h"


ref class Robot: public Item {

protected:
	static System::Drawing::Icon^ robotup;
	static System::Drawing::Icon^ robotright;
	static System::Drawing::Icon^ robotleft;
    int dir, beep, row, col;

public:
	Robot(void) { setIcon(); } 
	System::Drawing::Icon^ RobotLocation::getIcon() override;

    void Robot::setIcon() override;
   
    Robot(int,int,int,int);
    
    void turnLeft();
    void move();
    void placeBeeper();
    void pickBeeper();
    int getRow();
    int getCol();
    int getbeepercount();
    int getDirc();

};
