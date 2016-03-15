#pragma once

ref class RobotLocation {

protected:
	static System::Drawing::Icon^ robotup;
	static System::Drawing::Icon^ robotright;
	static System::Drawing::Icon^ robotleft;
	static System::Drawing::Icon^ robotrdown;

public:
	RobotLocation(void) { setIcon(); }

	RobotLocation(x, y);

	System::Drawing::Icon^ RobotLocation::getIcon();


	void getLocation()
	{

	}
	void getcol() 
	{

	}
	void getrow()
	{

	}
	void RobotLocation::setIcon();

	void robotup() {

	}
	void robotright() {

	}
	void robotleft() {

	}
	void robotdown()
	{

	}



};
