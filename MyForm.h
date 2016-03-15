#pragma once
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
			this->SuspendLayout();
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
	/*
	bool access()
	{
		
	}

	void position()
	{
		int col, row;



	}*/

	/*void direction(int, int) {
		char north = '8', south = '2', east = '6', west = '4';
		char startdirection;

		std::cin >> startdirection;

		if (startdirection == north && access() == true)
		{
			gonorth();

		}
		else if (startdirection == west && access() == true) {
			gowest();
		}
		else if (startdirection == south && access() == true)
		{
			gosouth();

		}
		else if (startdirection == east && access() == true)
		{
			goeast();

		}
		else
		{
			MessageBox::Show("New direction");

		}

		/*switch (startdirection)
		{
		case '8':
		world->getrobot()->access()->north();
		break;
		case '6':
		world->getrobot()->access()->east();
		break;
		case '2':
		world->getrobot()->access()->south();
		break;
		case '4':
		world->getrobot()->access()->west();
		break;


		default:
		break;
		}

	}*/
	void buttonmaker()
	{
		/*array<Button^> ^movepad = gcnew array < Button ^ >(4);											
		int x = 50;
		int y = 50;

		for (int i = 0; i < 4; i++)
		{
			movepad[i] = gcnew Button;
			movepad[i]->Location = Point(x, y);
			movepad[i]->Parent = this;
			movepad[i]->Size = (Drawing::Size(50, 50));
			movepad[i]->Click += gcnew System::EventHandler(this, &MyForm::Clicked);
			movepad[i]->Font = (gcnew System::Drawing::Font(L"Microsoft Bell MT", 40, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));

			x += 100;

		}
		x = 50;
		y += 100;
		*/
	}
	System::Void Clicked(System::Object^ sender, System::EventArgs^ e) 
	{/*
		Button^ button = dynamic_cast<Button^>(sender);

		char direction;

		if (direction == north && access() == true)
		{
			gonorth();

		}
		else if (direction == west && access() == true) {
			gowest();
		}
		else if (direction == south && access() == true)
		{
			gosouth();

		}
		else if (direction == east && access() == true)
		{
			goeast();

		}
		else
		{
			MessageBox::Show("New direction");

		}*/
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
