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
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(736, 427);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
int numofCommands;
int lineofCommand = 0;
int worldWidth, worldHeight;
int cellWidth, cellHeight;
World^ world;
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
        array <Cell^,2>^ world = gcnew array<Cell^, 2> (worldWidth, worldHeight);
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
};
}
