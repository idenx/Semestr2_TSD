#pragma once

namespace TSD2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Sort_results
	/// </summary>
	public ref class Sort_results : public System::Windows::Forms::Form
	{
	public:
		Sort_results(void)
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
		~Sort_results()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  sort_name;
	public: 
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  sorts_num;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  time;

	private: 

	protected: 

	protected: 





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
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->sort_name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->sorts_num = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToResizeColumns = false;
			this->dataGridView2->AllowUserToResizeRows = false;
			this->dataGridView2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->sort_name, 
				this->sorts_num, this->time});
			this->dataGridView2->Location = System::Drawing::Point(-2, 0);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->RowTemplate->ReadOnly = true;
			this->dataGridView2->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView2->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView2->Size = System::Drawing::Size(724, 129);
			this->dataGridView2->TabIndex = 15;
			// 
			// sort_name
			// 
			this->sort_name->HeaderText = L"Способ сортировки";
			this->sort_name->Name = L"sort_name";
			this->sort_name->ReadOnly = true;
			// 
			// sorts_num
			// 
			this->sorts_num->HeaderText = L"Количество сортировок";
			this->sorts_num->Name = L"sorts_num";
			this->sorts_num->ReadOnly = true;
			// 
			// time
			// 
			this->time->HeaderText = L"Время сортировки, c";
			this->time->Name = L"time";
			this->time->ReadOnly = true;
			// 
			// Sort_results
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(721, 129);
			this->Controls->Add(this->dataGridView2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"Sort_results";
			this->ShowInTaskbar = false;
			this->Text = L"Результаты сортировки";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
