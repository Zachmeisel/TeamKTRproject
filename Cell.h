#pragma once
ref class Cell
{
private:
	//Date Memebers;
	int row;
	int col;
	bool access;
	bool hasBeeper;

public:
	//Default Constructor
	/*
	Cell(void) {};*/

public:
	//Initializing Constructor
	Cell(int r, int c, bool a) {};

	//Accessors 
	bool getAccess() { return access; }
	int getRow() { return row; }
	int getCol() { return col; }
	bool getBeeper() { return hasBeeper; }

	//Mutators 
	void setAccess(bool a) { access = a; }
	void setBeeper(bool beeper) { hasBeeper = true; }
};
