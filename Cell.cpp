#include "Cell.h"

using namespace System::Drawing;
 
Cell::Cell(int r , int c)
{
    row = r;
    col = c;
}
void Cell::setWalls(int w)
    {
      switch(w)
      {
          case 1:
                 moveUp = false;
                 break;
          case 2:
                moveRight = false;
                break;
          case 3:
                moveLeft = false;
                break;
          case 4: 
                moveDown = false;
                break;
      }  
    }
    /*
    void Cell::Walls(Graphics^ g, Rectangle^ rec)
    {
        if (!moveDown)
        {
            g->DrawLine(wall, rec->Left,rec->Bottom,rec->Right,rec->Bottom);
        }
        if(!moveLeft)
        {
            g->DrawLine(wall, rec->Left,rec->Top,rec->Left, rec->Bottom);
        }
        if(!moveUp)
        {
            g->DrawLine(wall,rec->Left, rec->Top,rec->Right, rec->Top);
        }
        if(!moveRight)
        {
            g->DrawLine(wall, rec->Right,rec->Top,rec->Right,rec->Bottom)
        }
    }
    
    void Cell::DrawCells(Graphics^ g, Rectangle^ rec)
    {
        g->FillRectangle(cellColor,rec->X,rec->Y,rec->Width, rec->Height);
        Walls(g,rec);
    }
   */ 
    void Cell::setBeeper(int b)
    {
        beeperCount = b;
       if (b > 0)
       hasBeeper = true;
    }
    
    bool Cell::canmoveUp()
    {
        return moveUp;
    }
    bool Cell::canmoveRight()
    {
        return moveRight;
    }
    bool Cell::canmoveDown()
    {
        return moveDown;
    }
    bool Cell::canmoveLeft()
    {
        return moveLeft;
    }
    int Cell::getBeepers()
    {
        return beeperCount;
    }
    int Cell::getRow()
    { return row; }
	int Cell::getCol() 
    { return col; }
