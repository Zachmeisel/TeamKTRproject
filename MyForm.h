#pragma once
#include "Item.h"
#include "World.h"
#include "Robot.h"
#include "Cell.h"

#include "fileParse.h"


namespace KTRproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
	
		Graphics^ g;
		Brush^ grayBrush;
		Brush^ whiteBrush;
		Brush^ burlyBrush;
		Brush^ paleTurquoiseBrush;

		Pen^ blackPen;

		//Static constants
		/*static const int NUMROWS = 16;
		static const int NUMCOLS = 20;*/
		static const int CELLSIZE = 25;
	private: System::Windows::Forms::Panel^  panel1;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panel2;
			 /// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(28, 32);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(583, 288);
			this->panel1->TabIndex = 0;
            //
            // timer1
            this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(736, 427);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
int numofCommands;
int comline = 0;
int worldWidth, worldHeight;
int cellWidth, cellHeight;
//World^ world;
Robot^ robot;
fileParse *parse;
char **commands;

		

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
    {
		g = panel1->CreateGraphics();
		
        initalize();
	}
    
    
    // initalize all varibale form text file using fileParse object
    
    private: System::Void initalize()
    {
        parse = new fileParse();
        
        commands = parse->parsingCom();
        numofCommands = parse->getnumberofCom();
        int args = 5;
        
        
       //loop to initlize wolrdWidth and wolrdHeight
        
        for (int u = 0; u < numofCommands; u++)
        {
            if (tolower(commands[u][0] == 'wor'))
            {
            worldWidth = commands[u][1] - '0';
            worldHeight = commands[u][2] - '0';
            }
        } 
        world = gcnew array<Cell^, 2> (worldWidth, worldHeight);
        cellWidth = panel1->Width / worldWidth;
        cellHeight = panel1->Height / worldHeight;
        
        
        for (int q = 0; q < worldWidth; q++)
        {
            for(int k = 0; k < worldHeight; k++)
            {
                world[q,k] = gcnew Cell(q,k);
            }
        }
        
        
        for (int i = 0; i < numofCommands; i++)
        {
            for(int j = 0; j < args; j++)
            {
                if (commands[i][j] == 'wall'){
                     world[commands[i][j + 1] - '0', commands[i][j+3] - '0']->setWalls(commands[i][j+3] - '0');
                } else if (commands[i][j] == 'bee'){
                     world[commands[i][j + 1] - '0', commands[i][j+2] - '0']->setBeeper(commands[i][j+3] - '0');
                } else  if (commands[i][j] == 'rob'){
                    robot = gcnew Robot(commands[i][j+1] - '0', commands[i][j+2] - '0', commands[i][j+3] - '0', commands[i][j+4]-'0');
                }
                
            }
        }
        
    }



	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//creating robot, using cheese icon as placeholder
		int x, y;
		Drawing::Icon^ beeper = gcnew System::Drawing::Icon("beeper.ico");
		

		int robotRow = 3;
		int robotCol = 3;
		
		//direction = 'r';

		x = robotCol * CELLSIZE;
		y = robotRow * CELLSIZE;
		Rectangle beeperRect = Rectangle(x, y, CELLSIZE, CELLSIZE);
		g->DrawIcon(beeper, beeperRect);

		//world->getRobot()->MoveTo(robotRow, robotCol);

		x = robotCol * CELLSIZE;
		y = robotRow * CELLSIZE;
		Rectangle robotRect = Rectangle(x, y, CELLSIZE, CELLSIZE);
		g->DrawIcon(world->getRobot()->getIcon(), robotRect);

		drawWorld();
	}

	private: void drawWorld() {
		//Declare local variables;
		//		int row, col;
		int x, y;

		//Refresh the panel
		panel1->Refresh();

		Drawing::Icon^ street = gcnew System::Drawing::Icon("street.ico");

		//Draw the empty maze
		for (int row = 0; row < world->wHeight; row++)
		{
			for (int col = 0; col < world->wWidth; col++)
			{
				x = col * CELLSIZE;
				y = row * CELLSIZE;
				Rectangle gridRect = Rectangle(x, y, CELLSIZE - 1, CELLSIZE - 1);
				g->DrawIcon(street, gridRect);
				g->DrawRectangle(blackPen, gridRect);
			}
		}
	}
    private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
        comline++;
        if(comline < numofCommands)
        {
            if(commands[comline][0] == 'm')
            {
                switch (robot->getDirc()){
                    case 1:
                    //not the top
                    //Checks for wall ahead(up) or if the next cell behind(down) is open
                            if(robot->getCol() != 0)
                                {
                                if(world[robot->getRow(),robot->getCol]->canmoveUp() &&
                                    wolrd[robot->getRow(),getCol() - 1]->canmoveDown())
                                    {
                                        robot->move();
                                    } 
                            }
                    break;
                    
                    case 2:
                    //not at right side
                    //Checks for wall to the right or if the next cell to the left is open
                            if (robot->getRow() != worldWidth)
                                {
                                if(world[robot->getRow(),robot->getCol]->canmoveRight() &&
                                    wolrd[robot->getRow(),getCol() + 1]->canmoveLeft())
                                    {
                                        robot->move();
                                    }
                            }
                    
                    break;
                    
                    case 3:
                    //not at bottom 
                    //checks for wall behind(down) or if the cell ahead is open(up)
                            if (robot->getCol != wolrdHeight)
                                {
                                if(world[robot->getRow(),robot->getCol]->canmoveDown() &&
                                    wolrd[robot->getRow(),getCol() + 1]->canmoveUp())
                                    {
                                        robot->move();
                                    }   
                                }
                    break;
                    
                    case 4:
                    //not at left side 
                    //cheack for wall to the left or if the next cell to the right is open
                            if (robot->getRow() != 0)
                                {
                                if(world[robot->getRow(),robot->getCol]->canmoveLeft() &&
                                    wolrd[robot->getRow(),getCol() - 1]->canmoveRight())
                                    {
                                        robot->move();
                                    }   
                                }
                    break;
                }
            }
            if (commands[comline][0] = 'left')
            {
                robot->turnleft();
            }
            if(commands[comline][0] == 'pick')
            {
                if(world[k->getRow(),robot->getCol()]->getBeeper() > 0)
                    {
                        robot->pickBeeper();
                        wolrd[robot->getRow(),robot->getCol()]->setBeeper
                        (world[roobot->getRow(),robot->getCol]->getBeeper() - 1);
                    }
            }
            if(commands[comline][0] == 'place')
            {
                if(robot->getbeeperCount() > 0)
                    {
                        robot->placeBeeper();
                        wolrd[robot->getRow(0,robot->getCol())]->setBeeper
                        (world[robot->getRow(),robot->getCol()]->getBeepers() + 1);
                    }
            }
            if(commands[curmine][0] == 'off')
            {
                timer1->stop();
            }
            
            
 
        }
        Message::Box("Number of Beeper in Karel's Bag is" + robot->getbeeperCount());
        drawWorld();
    }
    
};
}
