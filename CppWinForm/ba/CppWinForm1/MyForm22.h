#pragma once

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm21
	/// </summary>
	public ref class MyForm22 : public System::Windows::Forms::Form
	{
	public:
		MyForm22(System::Windows::Forms::Form ^frm1)
		{
			otherform = frm1;
			InitializeComponent();
			InOut_Set();
			Matching();
			//메세지와 마찬가지로 데이터파일을 바로 불러오고, 매칭을 진행한다.

			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm22()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridViewCall;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	public: System::Windows::Forms::Form ^otherform;
	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm22::typeid));
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridViewCall = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCall))->BeginInit();
			this->SuspendLayout();
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->Location = System::Drawing::Point(282, 53);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(30, 30);
			this->button2->TabIndex = 5;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm22::button2_Click);
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Location = System::Drawing::Point(12, 33);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 50);
			this->button1->TabIndex = 6;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm22::button1_Click);
			// 
			// dataGridViewCall
			// 
			this->dataGridViewCall->AccessibleRole = System::Windows::Forms::AccessibleRole::MenuBar;
			this->dataGridViewCall->AllowUserToAddRows = false;
			this->dataGridViewCall->AllowUserToDeleteRows = false;
			this->dataGridViewCall->AllowUserToResizeColumns = false;
			this->dataGridViewCall->AllowUserToResizeRows = false;
			this->dataGridViewCall->ColumnHeadersHeight = 50;
			this->dataGridViewCall->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridViewCall->Location = System::Drawing::Point(12, 88);
			this->dataGridViewCall->Margin = System::Windows::Forms::Padding(2);
			this->dataGridViewCall->Name = L"dataGridViewCall";
			this->dataGridViewCall->RowHeadersVisible = false;
			this->dataGridViewCall->RowHeadersWidth = 50;
			this->dataGridViewCall->RowTemplate->Height = 37;
			this->dataGridViewCall->Size = System::Drawing::Size(300, 400);
			this->dataGridViewCall->TabIndex = 7;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"In/Out";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Width = 50;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Phone";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Time";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Width = 125;
			// 
			// MyForm21
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(326, 539);
			this->Controls->Add(this->dataGridViewCall);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Name = L"MyForm22";
			this->Text = L"MyForm22";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewCall))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion
		private: System::Void InOut_Set() {
			String ^path = Directory::GetCurrentDirectory() + "\\inout.txt";

			StreamReader ^sr = File::OpenText(path);
			try {
				while (sr->EndOfStream == false) {

					String ^i = "";
					String ^j = "";
					String ^k = "";

					i = sr->ReadLine();
					j = sr->ReadLine();
					k = sr->ReadLine();
					dataGridViewCall->Rows->Add(i, j, k);
				}
			}
			finally{
				if (sr)
					delete(IDisposable^)(sr);
			}
			dataGridViewCall->Sort(dataGridViewCall->Columns[2], ListSortDirection::Descending);
		}//수발신기록 텍스트파일을 불러온다



		private: System::Void Matching() {
			dataGridViewCall->ReadOnly = false;
			String ^path = Directory::GetCurrentDirectory() + "\\phoneBook.txt";

			StreamReader ^sr = File::OpenText(path);
			try {
				while (sr->EndOfStream == false) {
					String ^i = "";
					String ^j = "";
					i = sr->ReadLine();
					j = sr->ReadLine();
					for (int c = 0; c < dataGridViewCall->Rows->Count; c++) {
						if (j->ToString() == dataGridViewCall->Rows[c]->Cells[1]->Value->ToString()) {
							dataGridViewCall->Rows[c]->Cells[1]->Value = i;
							break;
						}
					}
				}
			}
			finally{
				if (sr)
					delete(IDisposable^)(sr);
			}

		} //전화번호부의 번호와 수발신자의 번호가 일치하면 번호가 아니라 해당자의 이름이 출력되도록 만든다.
	private: System::Void InOut_out() {
		String ^path = Directory::GetCurrentDirectory() + "\\inout.txt";

		StreamWriter ^sw = File::CreateText(path);

		try {
			for (int i = 0; i < dataGridViewCall->Rows->Count; i++) {
				sw->WriteLine(dataGridViewCall->Rows[i]->Cells[0]->Value);
				sw->WriteLine(dataGridViewCall->Rows[i]->Cells[1]->Value);
				sw->WriteLine(dataGridViewCall->Rows[i]->Cells[2]->Value);

			}
		}

		finally {
			if (sw)
				delete(IDisposable^)(sw);

		}

	} //변경된 수발신목록을 텍스트파일에 출력한다.




	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		this->Hide();
		otherform->Show();
	}//go to previous
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	for each(DataGridViewCell^ oneCell in this->dataGridViewCall->SelectedCells)
	{
		if (oneCell->Selected)
			dataGridViewCall->Rows->RemoveAt(oneCell->RowIndex);
	}//delete function
	dataGridViewCall->Sort(dataGridViewCall->Columns[2], ListSortDirection::Ascending);
	InOut_out();
}
};
}
