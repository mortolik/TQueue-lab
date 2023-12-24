#pragma once
#include <string>
#include"../TQueue/TQueue.h"

#include<msclr\marshal_cppstd.h>
namespace CppWinForm1 {

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
		int MaxSize;
		int StartSize;
		double p;//вероятность добавления
		double d;//вероятность удаления
		int buf;
		int PushCount;
		int PopCount;
		TQueue<int> *q;
		int CenterX, CenterY, Width, Height;
		Graphics^ gr;
		Random^ rndl;
		Pen^ BlackPen;
		Pen^ ClearPen;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	//private: System::Windows::Forms::Label^ label11;
			 Pen^ ALLCLPen;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			gr = CreateGraphics();
			rndl = gcnew Random();

			BlackPen = gcnew Pen(Color::White);
			BlackPen->Width = 15.0F;
			ClearPen = gcnew Pen(Color::DarkCyan);
			ClearPen->Width = 15.0F;
			ALLCLPen = gcnew Pen(Color::DarkCyan);
			ALLCLPen->Width = 500.0F;

			CenterX = 450;
			CenterY = 150;
			Width = 300;
			Height = 300;
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
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox4;

	//private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(40, 36);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(159, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Максимальный размер";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::Label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(44, 57);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(132, 22);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox1_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(40, 148);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(214, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Вероятность записи элемента ";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::Label2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(43, 111);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(132, 22);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(40, 204);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(227, 17);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Вероятность удаления элемента";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(43, 169);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(132, 22);
			this->textBox3->TabIndex = 5;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox3_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(41, 91);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(135, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Начальный размер";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(43, 225);
			this->textBox4->Margin = System::Windows::Forms::Padding(4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(132, 22);
			this->textBox4->TabIndex = 7;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &MyForm::TextBox4_TextChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(44, 346);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(177, 17);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Количество добавленных";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::Label5_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Lime;
			this->button1->ForeColor = System::Drawing::SystemColors::Desktop;
			this->button1->Location = System::Drawing::Point(44, 255);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(72, 39);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Пуск";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::Button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Crimson;
			this->button2->Location = System::Drawing::Point(44, 302);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(72, 36);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Стоп";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::Button2_Click);
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::Timer1_Tick);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(45, 401);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 17);
			this->label6->TabIndex = 13;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(44, 384);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(161, 17);
			this->label7->TabIndex = 14;
			this->label7->Text = L"Количество удалённых";
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::Label7_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(57, 401);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 17);
			this->label8->TabIndex = 15;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(57, 363);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(0, 17);
			this->label9->TabIndex = 16;
			this->label9->Click += gcnew System::EventHandler(this, &MyForm::Label9_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(57, 401);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(0, 17);
			this->label10->TabIndex = 17;
			this->label10->Click += gcnew System::EventHandler(this, &MyForm::Label10_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1495, 773);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void DrawQueue() {
			int start = 360 * q->GetStart() / q->Size();
			int finish = 360 * q->GetCount() / q->Size();
			gr->DrawArc(BlackPen, CenterX, CenterY, Width, Height, start, finish);
		}
		void Clean()
		{
			int start = 360 * q->GetStart() / q->Size();
			int finish = 360 * (q->GetCount()) / q->Size();

			gr->DrawArc(ClearPen, CenterX, CenterY, Width, Height, start, finish);
		}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
		timer1->Enabled = buf;
		buf++;
		if (buf == 2)
		{
			buf = 0;
		}
		PushCount = 0;
		PopCount = 0;
	}
private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	gr ->DrawLine(ALLCLPen, 350, 288, 875, 288);
	MaxSize = Convert::ToInt32(textBox1->Text);
	StartSize = Convert::ToInt32(textBox2->Text);
	p = Convert::ToDouble(textBox3->Text);
	d = Convert::ToDouble(textBox4->Text);
	timer1->Interval = 100; // Convert::ToDouble(textBox5->Text);
	q = new TQueue<int> (MaxSize);
	for (int i = 0; i < StartSize; i++)
	{
		q->Push(i);
	}
	DrawQueue();
	timer1->Enabled = true;
	buf = 0;

}
private: System::Void TextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)//Maxsize
{

}
private: System::Void TextBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) //StartSize
{
}
private: System::Void TextBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) //веротность добавления
{
}
private: System::Void TextBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) //вероятность удаления
{
}

//private: System::Void TextBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {}
private: System::Void Label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Timer1_Tick(System::Object^ sender, System::EventArgs^ e) 
{
	Clean();

	if (rndl->NextDouble() < p)
	{
		if (!q->IsFull())
		{
			q->Push(1);
			PushCount++;
		}
	}
	if (rndl->NextDouble() < d)
	{
		if (!q->IsEmpty())
		{
			q->Pop();
			PopCount++;
		}
	}
	DrawQueue();
	label9->Text = Convert::ToString(PushCount);
	label10->Text = Convert::ToString(PopCount);
}
private: System::Void Label9_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Label10_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
//private: System::Void Label11_Click(System::Object^ sender, System::EventArgs^ e) {}
};
}
