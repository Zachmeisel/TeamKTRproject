#pragma once
#include "Cell.h"
#include "Robot.h"
#include "Beeper.h"

ref class World
{
private:
	//Beeper^ myBeeper;
	Robot^ myRobot;
	array <Cell^, 2>^ grid;
public:
	static const int NUMROWS = 8;
	static const int NUMCOLS = 8;
	World()
	{
		//Create cheese
		//myBeeper = gcnew Beeper();

		//Create mouse
		//myRobot = gcnew Robot();

		//Construct grid array
		grid = gcnew array<Cell^, 2>(NUMROWS, NUMCOLS);
		for (int row = 0; row < NUMROWS; row++)
		{
			for (int col = 0; col < NUMCOLS; col++)
			{
				grid[row, col] = gcnew Cell(row, col, true);
			}
		}
	};
	//Beeper^ getBeeper() { return myBeeper; };
	Robot^ getRobot() { return myRobot; };
	array <Cell^, 2>^ getGrid() { return grid; };
};
