// Программа для умножения длинных чисел, 8 Вариант
// ИУ7-32, Исаев Денис

#pragma once
#include "LongNums.h"
#include "String.h"



namespace LongNums2005 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(17, 284);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(169, 38);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Умножить!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(9, 110);
			this->textBox1->MaxLength = 30;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(270, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(9, 184);
			this->textBox2->MaxLength = 30;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(270, 20);
			this->textBox2->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(14, 91);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(144, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Введите первое число:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 157);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(143, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Введите второе число:";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(9, 246);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(270, 20);
			this->textBox3->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(9, 221);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Ответ:";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(204, 292);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Очистить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->groupBox2->Location = System::Drawing::Point(9, 4);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(270, 84);
			this->groupBox2->TabIndex = 9;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Формат ввода чисел в программе:";
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(3, 49);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(262, 32);
			this->label7->TabIndex = 1;
			this->label7->Text = L"длина A + длина B <= 30; длина C <= 5";
			this->label7->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(8, 20);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(256, 61);
			this->label6->TabIndex = 0;
			this->label6->Text = L"[+/-]A.B e[+/-]C";
			this->label6->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(292, 331);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->Location = System::Drawing::Point(8, 11);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Умножатель!";
			this->groupBox2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 textBox3->Text = "";
				 String^ txt1 = textBox1->Text;
				 String^ txt2 = textBox2->Text;

				 if ((txt1->Length == 0) || (txt2->Length == 0)) {
					 textBox3->Text = "Пустой ввод!";
					 return;
				 }



				 String^ str = textBox1->Text;
				 int len = str->Length;
				 char *sNum = new char[len];
				 for(int i = 0; i < len; i++) {
					 sNum[i] = str[i];
				 }			
				 sNum[len] = '\0';
				 LongNums A(sNum);	
				 if (!strcmp(A.error, "input error")) {
					 textBox3->Text = "Первое число введено неверно!";
					 return;
				 }
				 str = textBox2->Text;
				 len = str->Length;
				 for(int i = 0; i < len; i++) {
					 sNum[i] = str[i];
				 }
				 sNum[len] = '\0';
				 LongNums B(sNum);
				 if (!strcmp(B.error, "input error")) {
					 textBox3->Text = "Второе число введено неверно!";
					 return;
				 }


				 LongNums mul_result;

				 mul_result = LongNums::multiply(A, B);
				 if (!strcmp(mul_result
					 .error, "exp_of")) {
						 textBox3->Text = "Переполнение экспоненты!";
						 return;
				 }				

				 sNum = mul_result.toString();
				 str = "";
				 for(int i = 0; i < strlen(sNum); i++) {
					 String^ x = gcnew  String(&(sNum[i]),0,1);
					 str += x;
				 }
				 textBox3->Text = str;



			 }

			 private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
						  textBox1->Text = "";
						  textBox2->Text = "";
						  textBox3->Text = "";					 
					  }
};
	}

