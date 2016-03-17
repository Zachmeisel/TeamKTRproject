#pragma once
#include "Item.h"
#include "World.h"
#include "Robot.h"
#include "Cell.h"


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(116, 344);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(311, 63);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button2";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(28, 32);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(583, 288);
			this->panel1->TabIndex = 0;
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(637, 436);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
		

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) 
    {
		g = panel1->CreateGraphics();
		world = gcnew World();
		


	}
	private: System::Void Move_Click(System::Object^  sender, System::EventArgs^  e) 
	{
	

	}
	/*bool robotacces()
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
	}*/

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
		for (int row = 0; row < world->NUMROWS; row++)
		{
			for (int col = 0; col < world->NUMCOLS; col++)
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