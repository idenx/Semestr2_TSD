#pragma once

#include "DB.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string>
#include <time.h>
#include "Sort_results.h"
#include "Ошибка!.h"
#include <stdio.h>


namespace TSD2 {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	char* str2char(String^ str);
	void print_error(error_type err);
	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{

	public:

		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:

		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
		TDatabase* DB;


	private: System::Windows::Forms::TextBox^  textBox_name;
	private: System::Windows::Forms::TextBox^  textBox_surname;
	private: System::Windows::Forms::TextBox^  textBox_number;
	private: System::Windows::Forms::TextBox^  textBox_address;
	private: System::Windows::Forms::Button^  button_add;

	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  textBox_birth_year;

	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::TextBox^  textBox_birth_day;
	private: System::Windows::Forms::Label^  label_birth_year;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox_birth_month;
	private: System::Windows::Forms::Label^  label_birth_month;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label_bith_day;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;











	private: System::Windows::Forms::DataGridView^  dataGridView1;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;















	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  surname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  phone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  address;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  status;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  bith_day;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  birth_month;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  birth_year;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  post;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  company;














































	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->textBox_name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_surname = (gcnew System::Windows::Forms::TextBox());
			this->textBox_number = (gcnew System::Windows::Forms::TextBox());
			this->textBox_address = (gcnew System::Windows::Forms::TextBox());
			this->button_add = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox_birth_year = (gcnew System::Windows::Forms::TextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox_birth_day = (gcnew System::Windows::Forms::TextBox());
			this->label_birth_year = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_birth_month = (gcnew System::Windows::Forms::TextBox());
			this->label_birth_month = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label_bith_day = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->surname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->phone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->address = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->status = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bith_day = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->birth_month = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->birth_year = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->post = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->company = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox_name
			// 
			this->textBox_name->Location = System::Drawing::Point(5, 68);
			this->textBox_name->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_name->Name = L"textBox_name";
			this->textBox_name->Size = System::Drawing::Size(137, 22);
			this->textBox_name->TabIndex = 1;
			// 
			// textBox_surname
			// 
			this->textBox_surname->Location = System::Drawing::Point(5, 122);
			this->textBox_surname->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_surname->Name = L"textBox_surname";
			this->textBox_surname->Size = System::Drawing::Size(137, 22);
			this->textBox_surname->TabIndex = 2;
			// 
			// textBox_number
			// 
			this->textBox_number->Location = System::Drawing::Point(5, 183);
			this->textBox_number->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_number->Name = L"textBox_number";
			this->textBox_number->Size = System::Drawing::Size(137, 22);
			this->textBox_number->TabIndex = 3;
			// 
			// textBox_address
			// 
			this->textBox_address->Location = System::Drawing::Point(5, 239);
			this->textBox_address->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_address->Name = L"textBox_address";
			this->textBox_address->Size = System::Drawing::Size(137, 22);
			this->textBox_address->TabIndex = 4;
			// 
			// button_add
			// 
			this->button_add->Location = System::Drawing::Point(27, 513);
			this->button_add->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button_add->Name = L"button_add";
			this->button_add->Size = System::Drawing::Size(99, 44);
			this->button_add->TabIndex = 9;
			this->button_add->Text = L"Добавить!";
			this->button_add->UseVisualStyleBackColor = true;
			this->button_add->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox_birth_year);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->textBox_birth_day);
			this->groupBox1->Controls->Add(this->label_birth_year);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->button_add);
			this->groupBox1->Controls->Add(this->textBox_birth_month);
			this->groupBox1->Controls->Add(this->textBox_name);
			this->groupBox1->Controls->Add(this->textBox_surname);
			this->groupBox1->Controls->Add(this->label_birth_month);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label_bith_day);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox_address);
			this->groupBox1->Controls->Add(this->textBox_number);
			this->groupBox1->Location = System::Drawing::Point(3, 2);
			this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->groupBox1->Size = System::Drawing::Size(168, 565);
			this->groupBox1->TabIndex = 6;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Добавление нового абонента";
			// 
			// textBox_birth_year
			// 
			this->textBox_birth_year->Location = System::Drawing::Point(5, 476);
			this->textBox_birth_year->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_birth_year->Name = L"textBox_birth_year";
			this->textBox_birth_year->Size = System::Drawing::Size(137, 22);
			this->textBox_birth_year->TabIndex = 8;
			// 
			// comboBox1
			// 
			this->comboBox1->Cursor = System::Windows::Forms::Cursors::Default;
			this->comboBox1->DisplayMember = L"0";
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Личный", L"Оффициальный"});
			this->comboBox1->Location = System::Drawing::Point(5, 300);
			this->comboBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(137, 24);
			this->comboBox1->TabIndex = 5;
			this->comboBox1->ValueMember = L"0";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// textBox_birth_day
			// 
			this->textBox_birth_day->Location = System::Drawing::Point(5, 362);
			this->textBox_birth_day->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_birth_day->Name = L"textBox_birth_day";
			this->textBox_birth_day->Size = System::Drawing::Size(137, 22);
			this->textBox_birth_day->TabIndex = 6;
			// 
			// label_birth_year
			// 
			this->label_birth_year->AutoSize = true;
			this->label_birth_year->Location = System::Drawing::Point(5, 455);
			this->label_birth_year->Name = L"label_birth_year";
			this->label_birth_year->Size = System::Drawing::Size(105, 17);
			this->label_birth_year->TabIndex = 13;
			this->label_birth_year->Text = L"Год рождения:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(5, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(39, 17);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Имя:";
			// 
			// textBox_birth_month
			// 
			this->textBox_birth_month->Location = System::Drawing::Point(5, 420);
			this->textBox_birth_month->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_birth_month->Name = L"textBox_birth_month";
			this->textBox_birth_month->Size = System::Drawing::Size(137, 22);
			this->textBox_birth_month->TabIndex = 7;
			// 
			// label_birth_month
			// 
			this->label_birth_month->AutoSize = true;
			this->label_birth_month->Location = System::Drawing::Point(5, 400);
			this->label_birth_month->Name = L"label_birth_month";
			this->label_birth_month->Size = System::Drawing::Size(169, 17);
			this->label_birth_month->TabIndex = 12;
			this->label_birth_month->Text = L"Месяц рождения: (1..12)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(5, 219);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Адрес:";
			// 
			// label_bith_day
			// 
			this->label_bith_day->AutoSize = true;
			this->label_bith_day->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label_bith_day->Location = System::Drawing::Point(2, 339);
			this->label_bith_day->Name = L"label_bith_day";
			this->label_bith_day->Size = System::Drawing::Size(161, 17);
			this->label_bith_day->TabIndex = 11;
			this->label_bith_day->Text = L"День рождения: (1..31)";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(5, 102);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(74, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Фамилия:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(5, 162);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Номер телефона:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(5, 281);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(57, 17);
			this->label5->TabIndex = 10;
			this->label5->Text = L"Статус:";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(11) {this->id, this->name, 
				this->surname, this->phone, this->address, this->status, this->bith_day, this->birth_month, this->birth_year, this->post, this->company});
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::LimeGreen;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->Location = System::Drawing::Point(7, 2);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->RowTemplate->ReadOnly = true;
			this->dataGridView1->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(1098, 564);
			this->dataGridView1->TabIndex = 0;
			// 
			// id
			// 
			this->id->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->id->Frozen = true;
			this->id->HeaderText = L"№";
			this->id->Name = L"id";
			this->id->ReadOnly = true;
			this->id->Width = 35;
			// 
			// name
			// 
			this->name->FillWeight = 30;
			this->name->HeaderText = L"Имя";
			this->name->Name = L"name";
			this->name->ReadOnly = true;
			this->name->Width = 90;
			// 
			// surname
			// 
			this->surname->FillWeight = 190.6833F;
			this->surname->HeaderText = L"Фамилия";
			this->surname->Name = L"surname";
			this->surname->ReadOnly = true;
			this->surname->Width = 90;
			// 
			// phone
			// 
			this->phone->FillWeight = 651.7709F;
			this->phone->HeaderText = L"Номер телефона";
			this->phone->Name = L"phone";
			this->phone->ReadOnly = true;
			// 
			// address
			// 
			this->address->FillWeight = 18.22941F;
			this->address->HeaderText = L"Адрес";
			this->address->Name = L"address";
			this->address->ReadOnly = true;
			// 
			// status
			// 
			this->status->FillWeight = 18.22941F;
			this->status->HeaderText = L"Статус";
			this->status->Name = L"status";
			this->status->ReadOnly = true;
			this->status->Width = 120;
			// 
			// bith_day
			// 
			this->bith_day->FillWeight = 18.22941F;
			this->bith_day->HeaderText = L"День рождения";
			this->bith_day->Name = L"bith_day";
			this->bith_day->ReadOnly = true;
			this->bith_day->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->bith_day->Width = 80;
			// 
			// birth_month
			// 
			this->birth_month->FillWeight = 18.22941F;
			this->birth_month->HeaderText = L"Месяц рождения";
			this->birth_month->Name = L"birth_month";
			this->birth_month->ReadOnly = true;
			this->birth_month->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->birth_month->Width = 80;
			// 
			// birth_year
			// 
			this->birth_year->FillWeight = 18.22941F;
			this->birth_year->HeaderText = L"Год рождения";
			this->birth_year->Name = L"birth_year";
			this->birth_year->ReadOnly = true;
			this->birth_year->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->birth_year->Width = 80;
			// 
			// post
			// 
			this->post->FillWeight = 18.22941F;
			this->post->HeaderText = L"Должность";
			this->post->Name = L"post";
			this->post->ReadOnly = true;
			this->post->Width = 120;
			// 
			// company
			// 
			this->company->FillWeight = 18.22941F;
			this->company->HeaderText = L"Организация";
			this->company->Name = L"company";
			this->company->ReadOnly = true;
			this->company->Width = 130;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(21, 79);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(117, 38);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Сортировать!";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_2);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(30, 63);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 49);
			this->button2->TabIndex = 8;
			this->button2->Text = L"Удалить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(9, 112);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(154, 43);
			this->button3->TabIndex = 9;
			this->button3->Text = L"Сравнить сортировки!";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(1, 38);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(172, 17);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Количество повторений:";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->numericUpDown1->Location = System::Drawing::Point(47, 59);
			this->numericUpDown1->Margin = System::Windows::Forms::Padding(4);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {10, 0, 0, 0});
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(77, 22);
			this->numericUpDown1->TabIndex = 13;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {20, 0, 0, 0});
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(21, 124);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(117, 39);
			this->button4->TabIndex = 14;
			this->button4->Text = L"Перемешать";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->comboBox2);
			this->groupBox2->Controls->Add(this->button1);
			this->groupBox2->Controls->Add(this->button4);
			this->groupBox2->Location = System::Drawing::Point(177, 206);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(169, 180);
			this->groupBox2->TabIndex = 15;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Сортировка";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(9, 22);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(140, 17);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Способ сортировки:";
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Быстрая", L"Выбором"});
			this->comboBox2->Location = System::Drawing::Point(6, 42);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(159, 24);
			this->comboBox2->TabIndex = 15;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label6);
			this->groupBox3->Controls->Add(this->numericUpDown1);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Location = System::Drawing::Point(177, 12);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(170, 180);
			this->groupBox3->TabIndex = 16;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Сравнение сортировок";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->button2);
			this->groupBox4->Location = System::Drawing::Point(177, 408);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(169, 151);
			this->groupBox4->TabIndex = 17;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Действия с выделенными строками";
			// 
			// splitContainer1
			// 
			this->splitContainer1->Location = System::Drawing::Point(-7, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->dataGridView1);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->groupBox3);
			this->splitContainer1->Panel2->Controls->Add(this->groupBox2);
			this->splitContainer1->Panel2->Controls->Add(this->groupBox1);
			this->splitContainer1->Panel2->Controls->Add(this->groupBox4);
			this->splitContainer1->Size = System::Drawing::Size(1458, 572);
			this->splitContainer1->SplitterDistance = 1108;
			this->splitContainer1->TabIndex = 18;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1454, 566);
			this->Controls->Add(this->splitContainer1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Location = System::Drawing::Point(973, 505);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"База абонентов 0.1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				 for (int i = 0; i < dataGridView1->SelectedRows->Count; i++) {
					 DataGridViewRow ^row = dataGridView1->SelectedRows[0];
					 System::Windows::Forms::DataGridViewCell ^cell = row->Cells[0];
					 String^ val = cell->Value->ToString();
					 int id = Convert::ToInt32(val, 10);
					 DB->delete_subscriber(id);
					 print_db_to_table();
				 }
			 }
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
			 }
	private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {

				 setlocale( LC_CTYPE, "Russian_Russia.1251" );
				 char *name, *surname, *phone, *address, *birthday_post, *birthmonth_company;

				 if ((textBox_name->Text->Length == 0) || (textBox_surname->Text->Length == 0) 
					 || (textBox_number->Text->Length == 0) || (textBox_address->Text->Length == 0)) {
						 print_error(EMPTY_INPUT);
						 return;
				 }

				 name = str2char(textBox_name->Text);
				 surname = str2char(textBox_surname->Text);
				 phone = str2char(textBox_number->Text);
				 address = str2char(textBox_address->Text);

				 int day, month, year;

				 switch (comboBox1->SelectedIndex) {
				 case 0:

					 if ((textBox_birth_day->Text->Length == 0) || (textBox_birth_month->Text->Length == 0) 
						 || (textBox_birth_year->Text->Length == 0)) {
							 print_error(EMPTY_INPUT);
							 return;
					 }

					 try {
						 day = Convert::ToInt32(textBox_birth_day->Text, 10);
					 }
					 catch(...) {
						 print_error(DAY_INCORRECT_INPUT);
						 return;
					 }

					 try {
						 month = Convert::ToInt32(textBox_birth_month->Text, 10);
					 }
					 catch(...) {
						 print_error(MONTH_INCORRECT_INPUT);
						 return;
					 }

					 try {
						 year = Convert::ToInt32(textBox_birth_year->Text, 10);
					 }
					 catch(...) {
						 print_error(YEAR_INCORRECT_INPUT);
						 return;
					 }

					 if ((day > 31) || (day < 1)) {
						print_error(DAY_INCORRECT_INPUT);
						return;
					 }
					 if ((month > 12) || (month < 1)) {
						 print_error(MONTH_INCORRECT_INPUT);
						 return;
					 }
					 if ((year <= 0)) {
						 print_error(YEAR_INCORRECT_INPUT);
						 return;
					 }

					 DB->add_subscriber(name, surname, phone, address, PERSONAL, day, month, year); 

					 dataGridView1->Rows->Add(DB->db_size - 1, textBox_name->Text, textBox_surname->Text, textBox_number->Text, 
						 textBox_address->Text, "Личный", textBox_birth_day->Text, textBox_birth_month->Text, textBox_birth_year->Text);			

					 break;
				 case 1:

					 if ((textBox_birth_day->Text->Length == 0) || (textBox_birth_month->Text->Length == 0)) {
						 print_error(EMPTY_INPUT);
						 return;
					 }

						 birthday_post = str2char(textBox_birth_day->Text);
						 birthmonth_company = str2char(textBox_birth_month->Text);


					 DB->add_subscriber(name, surname, phone, address, OFFICIAL, birthday_post, birthmonth_company); 

					 dataGridView1->Rows->Add(DB->db_size - 1, textBox_name->Text, textBox_surname->Text, textBox_number->Text, 
						 textBox_address->Text, "Оффициальный", "", "", "", textBox_birth_day->Text, textBox_birth_month->Text);
					 break;

				 }

				 textBox_name->Text = "";
				 textBox_surname->Text = "";
				 textBox_number->Text = "";
				 textBox_address->Text = "";
				 textBox_birth_day->Text = "";
				 textBox_birth_month->Text = "";
				 textBox_birth_year->Text = "";



			 }
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				 switch (comboBox1->SelectedIndex) {
				 case 1:
					 textBox_birth_day->Text = "";
					 textBox_birth_month->Text = "";
					 label_bith_day->Text = "Должность:";
					 label_birth_month->Text = "Организация:";
					 label_birth_year->Visible = false;
					 textBox_birth_year->Visible = false;
					 break;
				 case 0:
					 textBox_birth_day->Text = "";
					 textBox_birth_month->Text = "";
					 label_bith_day->Text = "День рождения:";
					 label_birth_month->Text = "Месяц рождения:";
					 label_birth_year->Visible = true;
					 textBox_birth_year->Visible = true;
					 break;
				 }
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 this->textBox_birth_month->MaxLength = COMPANY_LENGTH;
				 this->textBox_birth_day->MaxLength = POST_LENGTH;
				 this->textBox_birth_year->MaxLength = 4;
				 this->textBox_address->MaxLength = ADDRESS_LENGTH;
				 this->textBox_number->MaxLength = PHONE_LENGTH;
				 this->textBox_surname->MaxLength = SURNAME_LENGTH;
				 this->textBox_name->MaxLength = NAME_LENGTH;

				 DB = new TDatabase;
				 comboBox1->Text = comboBox1->Items[0]->ToString();
				 comboBox2->Text = comboBox2->Items[0]->ToString();

				 FILE* in_file = fopen("db_gen.dat", "rb");
				 if (in_file != NULL) {
					 DB->open_from_file(in_file);
					 fclose(in_file);
				 }

				 print_db_to_table();
			 }
	private: System::Void Form1_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
				 FILE* out_file = fopen("db_gen.dat", "wb");
				 DB->save_to_file(out_file);
				 fclose(out_file);

			 }

	private: void print_db_to_table() {


				 String ^name, ^surname, ^phone, ^address, ^post, ^company;
				 char *cname, *csurname, *cphone, *caddress, *cpost, *ccompany;
				 dataGridView1->Rows->Clear();

				 int k = 0;
				 for (int i = 0; i < DB->db_size; i++) {
					 k = ((TKeyTable) (DB->key_table[i])).id;
					 cname = new char[strlen(DB->db[k].name)];
					 for (int j = 0; j < strlen(DB->db[k].name); j++) {
						 cname[j] = DB->db[k].name[j];
					 }
					 cname[strlen(DB->db[k].name)] = '\0';
					 name = gcnew String(cname);

					 csurname = new char[strlen(DB->db[k].surname)];
					 for (int j = 0; j < strlen(DB->db[k].surname); j++) {
						 csurname[j] = DB->db[k].surname[j];
					 }
					 csurname[strlen(DB->db[k].surname)] = '\0';
					 surname = gcnew String(csurname);

					 cphone = new char[strlen(DB->db[k].phone)];
					 for (int j = 0; j < strlen(DB->db[k].phone); j++) {
						 cphone[j] = DB->db[k].phone[j];
					 }
					 cphone[strlen(DB->db[k].phone)] = '\0';
					 phone = gcnew String(cphone);

					 caddress = new char[strlen(DB->db[k].address)];
					 for (int j = 0; j < strlen(DB->db[k].address); j++) {
						 caddress[j] = DB->db[k].address[j];
					 }
					 caddress[strlen(DB->db[k].address)] = '\0';
					 address = gcnew String(caddress);



					 switch (DB->db[k].status) {
					 case 0:
						 dataGridView1->Rows->Add(i, name, surname, phone, address, "Личный", DB->db[k].birth_day, DB->db[k].birth_month, DB->db[k].birth_year);		
						 break;
					 case 1:

						 cpost = new char[strlen(DB->db[k].post)];
						 for (int j = 0; j < strlen(DB->db[k].post); j++) {
							 cpost[j] = DB->db[k].post[j];
						 }
						 cpost[strlen(DB->db[k].post)] = '\0';
						 post = gcnew String(cpost);

						 ccompany = new char[strlen(DB->db[k].company)];
						 for (int j = 0; j < strlen(DB->db[k].company); j++) {
							 ccompany[j] = DB->db[k].company[j];
						 }
						 ccompany[strlen(DB->db[k].company)] = '\0';
						 company = gcnew String(ccompany);

						 dataGridView1->Rows->Add(i, name, surname, phone, address, "Оффициальный", "", "", "", post, company);		
						 break;
					 }


				 }

			 }
	private: System::Void button1_Click_2(System::Object^  sender, System::EventArgs^  e) {
				 switch (comboBox2->SelectedIndex) {
				 case 0:
					 DB->quick_sort();
					 break;
				 case 1:
					 DB->selection_sort();
					 break;
				 }
				 print_db_to_table();
			 }
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 int num_of_repeats = 0;
				 num_of_repeats = (int) numericUpDown1->Value; 

				 // Быстрая без таблицы
				 clock_t time_quick_without_table = clock();


				 for (int i = 0; i < num_of_repeats; i++) {
					 TDatabase* temp_base = DB->get_copy();
					 temp_base->test_quick_sort_without_table(temp_base->db, temp_base->db_size - 1);
					 delete temp_base;
				 }

				 time_quick_without_table = clock() - time_quick_without_table;
				 //-----------------------------


				 // Быстрая с таблицей
				 clock_t time_quick_with_table = clock();

				 for (int i = 0; i < num_of_repeats; i++) {
					 TDatabase* temp_base = DB->get_copy();
					 temp_base->test_quick_sort_with_table(temp_base->key_table, temp_base->db_size - 1);
					 delete temp_base;
				 }

				 time_quick_with_table = clock() - time_quick_with_table;
				 //----------------------------


				 // Выбором без таблицы
				 clock_t time_selection_without_table = clock();

				 for (int i = 0; i < num_of_repeats; i++) {
					 TDatabase* temp_base = DB->get_copy();
					 temp_base->test_selection_sort_without_table();
					 delete temp_base;
				 }

				 time_selection_without_table = clock() - time_selection_without_table;
				 //----------------------------------------


				 // Выбором с таблицей
				 clock_t time_selection_with_table = clock();

				 for (int i = 0; i < num_of_repeats; i++) {
					 TDatabase* temp_base = DB->get_copy();
					 temp_base->test_selection_sort_with_table();
					 delete temp_base;
				 }

				 time_selection_with_table = clock() - time_selection_with_table;
				 //------------------------------------------

				 Sort_results ^frm2 = gcnew Sort_results();

				 frm2->dataGridView2->Rows->Add("Быстрая, без таблицы", num_of_repeats, ((double) time_quick_without_table) / CLOCKS_PER_SEC);
				 frm2->dataGridView2->Rows->Add("Быстрая с таблицей", num_of_repeats, ((double) time_quick_with_table) / CLOCKS_PER_SEC);
				 frm2->dataGridView2->Rows->Add("Выбором, без таблицы", num_of_repeats, ((double) time_selection_without_table) / CLOCKS_PER_SEC);
				 frm2->dataGridView2->Rows->Add("Выбором с таблицей", num_of_repeats, ((double) time_selection_with_table) / CLOCKS_PER_SEC);

				 frm2->ShowDialog();
			 }
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 DB->shake();
				 print_db_to_table();
			 }
	private: System::Void splitContainer1_Panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }
	};

	char* str2char(String^ str) {
		size_t convertedChars = 0;
		int stlen = str->Length;
		wchar_t *w_st = new wchar_t[stlen + 1];
		for(int i = 0; i < stlen; i++) {
			w_st[i] = str[i];
		}
		w_st[stlen] = '\0';
		size_t wsize = wcslen(w_st) + 1;

		char* result = new char[stlen + 1];				
		wcstombs_s(&convertedChars, result, wsize, w_st, _TRUNCATE);
		delete [] w_st;
		return result;
	}

	void print_error(error_type err) {
		error_form_class ^err_form = gcnew error_form_class();
		String^ error_text;
		switch (err) {
		case EMPTY_INPUT:
			error_text = gcnew String("Вы не заполнили некоторые поля! Требуется заполнить ВСЕ поля.");
			break;
		case DAY_INCORRECT_INPUT:
			error_text = gcnew String("День рождения введен некорректно!");
			break;
		case MONTH_INCORRECT_INPUT:
			error_text = gcnew String("Месяц рождения введен некорректно!");
			break;
		case YEAR_INCORRECT_INPUT:
			error_text = gcnew String("Год рождения введен некорректно!");
			break;
		default:
			error_text = gcnew String("Неизвестная ошибка!");
			break;
		}


		err_form->label1->Text = error_text;
		err_form->ShowDialog();
	}

}


