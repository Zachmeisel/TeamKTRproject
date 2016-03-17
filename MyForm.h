#pragma once
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
		World^ world;
		Robot^ robot();
        fileParse *parse;
        char **commands;
       
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
	private: System::Windows::Forms::Button^  button1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Move = (gcnew System::Windows::Forms::Button());
			this->Turn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Move
			// 
			this->Move->Location = System::Drawing::Point(547, 71);
			this->Move->Name = L"Move";
			this->Move->Size = System::Drawing::Size(85, 46);
			this->Move->TabIndex = 0;
			this->Move->Text = L"Move";
			this->Move->UseVisualStyleBackColor = true;
			this->Move->Click += gcnew System::EventHandler(this, &MyForm::Move_Click);
			// 
			// Turn
			// 
			this->Turn->Location = System::Drawing::Point(649, 71);
			this->Turn->Name = L"Turn";
			this->Turn->Size = System::Drawing::Size(90, 46);
			this->Turn->TabIndex = 1;
			this->Turn->Text = L"Turn";
			this->Turn->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
		    this->panel1->Location = System::Drawing::Point(35, 26);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(400, 400);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(130, 269);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(78, 63);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(374, 368);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
int numofCommands;
int lineofCommand = 0;
int worldWidth, worldHeight;
int cellWidth, cellHeight;
		

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
    {
		g = panel1->CreateGraphics();
		world = gcnew World();
        initalize();
	}
    
    
    // initalize all varibale form text file using fileParse object
    
    private: System::Void initalize()
    {
        parse = gcnew fileParse();
        
        commands = parse->parsingComs();
        numofCommands = parse->getnumberofCom();
        int args = 5;
        /*
        
       //loop to initlize wolrdWidth and wolrdHeight
        
        for (int u = 0; u < numofCommands; u++)
        {
            if (tolower(commands[u][0] == 'world'))
            {
            worldWidth = commands[u][1] - '0';
            worldHeight = commands[u][2] - '0';
            }
        } */
        world = gcnew array<Cell^, 2> (worldWidth, worldHeight);
        cellWidth = panel->Width / worldWidth;
        cellHeight = panel->Height / worldHeight;
        
        
        for (int q = 0; q < worldWidth; q++)
        {
            for(int k = 0; k < worldHeight; k++)
            {
                world[q,k] = gcnew Cell(q,w);
            }
        }
        
        
        for (int i = 0; i < numofCommands; i++)
        {
            for(int j = 0; j < args; j++;)
            {
                if (commands[i][j] == 'wall'){
                     world[commands[i][j + 1] - '0', commands[i][j+3] - '0']->setWalls(command[i][j+3] - '0');
                } else if (commands[i][j] == 'beeper'){
                     world[commands[i][j + 1] - '0', commands[i][j+2] - '0']->setBeeper(int)(command[i][j+3] - '0');
                } else  if (commands[i][j] == 'robot'){
                    robot = gcnew Robot(command[i][j+1] - '0', commands[i][j+2] - '0', commands[i][j+3] - '0', commands[i][j+4]-'0');
                }
                
            }
        }
        
    }
	private: System::Void Move_Click(System::Object^  sender, System::EventArgs^  e) 
	{
	

	}
    
    /*
	bool robotacces()
	{
		//direction comes from file
		if (direction == 'r') {
			if (world->getRobot()->getCol() < world->NUMCOLS - 1) return false;
		}
		else if (direction == 'l') {
			if (world->getRobot()->getCol() > 0) return false;
		}
		else if (direction == 'u') {
			if (world->getRobot()->getRow() > 0) return false;
		}
		
		return true;
	}
*/

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//creating robot, using cheese icon as placeholder
		int x, y;
		Drawing::Icon^ robot = gcnew System::Drawing::Icon("cheese.ico");

		int robotRow = 3;
		int robotCol = 3;

		x = robotCol * CELLSIZE;
		y = robotRow * CELLSIZE;
		Rectangle robotRect = Rectangle(x, y, CELLSIZE, CELLSIZE);
		g->DrawIcon(robot, robotRect);
	}
};
}