#pragma once

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
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"MyForm";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
		}
#pragma endregion

		void direction(int, int);

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
			 void buttonmaker();


	};
	bool access()
	{

	}

	void position()
	{
		int col, row;



	}

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
*/
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
		}*/

	}
	void buttonmaker()
	{
		array<Button^> ^movepad = gcnew array < Button ^ >(4);											
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

	}
	System::Void Clicked(System::Object^ sender, System::EventArgs^ e) 
	{
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

		}
	}

	};
}
