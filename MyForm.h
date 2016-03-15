#pragma once
#include "World.h"
#include "Robot.h"
#include "Cell.h"
#include "RobotLocation.h"

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
		RobotLocation^ robotLoc();

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
			this->panel1->Location = System::Drawing::Point(20, 19);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(246, 224);
			this->panel1->TabIndex = 0;
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
		/*
		void direction(int, int);*/

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

		void buttonmaker();
		g = panel1->CreateGraphics();
		world = gcnew World();
		


	}
	private: System::Void Move_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//test if open or a beaper in it
		//move 

		if (beaperaccess() == true && robotacces() == true) {
			move();

		}



	}
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

	void move()
	{
		world->getWorld()[r, c];

		int x = robotLoc.getcol();
		int y = robotLoc.getrow();


		//testing next cell to get acess before moving 
		if (x++)
	}

	
	}

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
