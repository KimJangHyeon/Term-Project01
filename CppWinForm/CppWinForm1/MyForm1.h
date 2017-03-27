#pragma once

#include "MyForm.h"


namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// MyForm1에 대한 요약입니다.
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			Message_Set();
			Matching();

			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridViewMessage;
	private: System::Windows::Forms::Button^  msgDel_btn;
	protected:

	protected:

	protected:





	private: System::Windows::Forms::Button^  button1;



	private: System::Windows::Forms::RichTextBox^  MessageTextBox;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  날짜;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  발신자;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  내용;
































	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->dataGridViewMessage = (gcnew System::Windows::Forms::DataGridView());
			this->날짜 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->발신자 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->내용 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->msgDel_btn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->MessageTextBox = (gcnew System::Windows::Forms::RichTextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMessage))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridViewMessage
			// 
			this->dataGridViewMessage->AllowUserToAddRows = false;
			this->dataGridViewMessage->AllowUserToDeleteRows = false;
			this->dataGridViewMessage->AllowUserToResizeColumns = false;
			this->dataGridViewMessage->AllowUserToResizeRows = false;
			this->dataGridViewMessage->ColumnHeadersHeight = 70;
			this->dataGridViewMessage->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridViewMessage->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->날짜,
					this->발신자, this->내용
			});
			this->dataGridViewMessage->Location = System::Drawing::Point(43, 70);
			this->dataGridViewMessage->Margin = System::Windows::Forms::Padding(2);
			this->dataGridViewMessage->Name = L"dataGridViewMessage";
			this->dataGridViewMessage->RowHeadersVisible = false;
			this->dataGridViewMessage->RowTemplate->Height = 37;
			this->dataGridViewMessage->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewMessage->Size = System::Drawing::Size(450, 470);
			this->dataGridViewMessage->TabIndex = 0;
			this->dataGridViewMessage->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm1::dataGridViewMessage_CellContentClick);
			// 
			// 날짜
			// 
			this->날짜->FillWeight = 4.973593F;
			this->날짜->HeaderText = L"날짜";
			this->날짜->Name = L"날짜";
			this->날짜->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// 발신자
			// 
			this->발신자->FillWeight = 10.25483F;
			this->발신자->HeaderText = L"발신자";
			this->발신자->Name = L"발신자";
			// 
			// 내용
			// 
			this->내용->FillWeight = 284.7716F;
			this->내용->HeaderText = L"내용";
			this->내용->Name = L"내용";
			this->내용->Width = 250;
			// 
			// msgDel_btn
			// 
			this->msgDel_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"msgDel_btn.BackgroundImage")));
			this->msgDel_btn->Location = System::Drawing::Point(463, 21);
			this->msgDel_btn->Margin = System::Windows::Forms::Padding(2);
			this->msgDel_btn->Name = L"msgDel_btn";
			this->msgDel_btn->Size = System::Drawing::Size(30, 30);
			this->msgDel_btn->TabIndex = 1;
			this->msgDel_btn->UseVisualStyleBackColor = true;
			this->msgDel_btn->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Location = System::Drawing::Point(43, 11);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 50);
			this->button1->TabIndex = 2;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// MessageTextBox
			// 
			this->MessageTextBox->Location = System::Drawing::Point(524, 42);
			this->MessageTextBox->Margin = System::Windows::Forms::Padding(2);
			this->MessageTextBox->Name = L"MessageTextBox";
			this->MessageTextBox->Size = System::Drawing::Size(238, 290);
			this->MessageTextBox->TabIndex = 3;
			this->MessageTextBox->Text = L"";
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(780, 609);
			this->Controls->Add(this->MessageTextBox);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->msgDel_btn);
			this->Controls->Add(this->dataGridViewMessage);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm1";
			this->Text = L"MyForm1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewMessage))->EndInit();
			this->ResumeLayout(false);

		}
	private: void message_manager() {
	/*	dataGridViewMessage->Rows->Add("2017-01-01", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-01-03", "010-3224-2122", "안녕하세요. 김미영팀장입니다.");
		dataGridViewMessage->Rows->Add("2017-01-07", "010-3376-4850", "장현오빠~~~~~~");
		dataGridViewMessage->Rows->Add("2017-01-10", "010-3324-2122", "날씨가 참 좋네요~ 오늘 하루도 힘내세요! - 삼호저축은행 유미영팀장");
		dataGridViewMessage->Rows->Add("2017-01-31", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-02-01", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-02-01", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-02-01", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-02-08", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-02-11", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-02-13", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-02-15", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-02-17", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-02-19", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-02-20", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-02-21", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-02-23", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-03-01", "010-3324-2122", "행복한 주택 담보대출");
		dataGridViewMessage->Rows->Add("2017-03-02", "010-3324-2122", "행복한 주택 담보대출");*/
		
	}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		for each(DataGridViewCell^ oneCell in this->dataGridViewMessage->SelectedCells)
		{
			if (oneCell->Selected)
				dataGridViewMessage->Rows->RemoveAt(oneCell->RowIndex);
		}//delete function
		dataGridViewMessage->Sort(dataGridViewMessage->Columns[0], ListSortDirection::Descending);
		Message_Out();

	}

	private: System::Void Message_Set() {
		
		String^ path = "D:\\a\\CppWinForm1\\Message.txt";

		StreamReader^ mr = File::OpenText(path);
		try {
			String^ i = "";
			String^ j = "";
			String^ k = "";

			while (mr->EndOfStream == false) {
				i = mr->ReadLine();
				j = mr->ReadLine();
				k = mr->ReadLine();

				dataGridViewMessage->Rows->Add(i, j, k);
			}
			dataGridViewMessage->Sort(dataGridViewMessage->Columns[0], ListSortDirection::Descending);
		}
		finally{
			if (mr)
				delete(IDisposable^)(mr);
		}
		Message_Out();

	}
			 private: System::Void Message_Out() {
				 String^ path = "D:\\a\\CppWinForm1\\Message.txt";

				 StreamWriter^ wr = File::CreateText(path);
				 try
				 {
					 for (int i = 0; i < dataGridViewMessage->Rows->Count; i++) {
						 wr->WriteLine(dataGridViewMessage->Rows[i]->Cells[0]->Value);
						 wr->WriteLine(dataGridViewMessage->Rows[i]->Cells[1]->Value);
						 wr->WriteLine(dataGridViewMessage->Rows[i]->Cells[2]->Value);
					 }
				 }
				 finally
				 {
					 if (wr)
						 delete (IDisposable^)(wr);
				 }
			 }

	private: System::Void Matching() {
		dataGridViewMessage->ReadOnly = false;
		String ^path = "D:\\a\\CppWinForm1\\phoneBook.txt";

		StreamReader ^sr = File::OpenText(path);
		try {
		

			while(sr->EndOfStream == false){
				String ^i = "";
				String ^j = "";
				i = sr->ReadLine();
				j = sr->ReadLine();
				for (int c = 0; c < dataGridViewMessage->Rows->Count; c++) {
					if (j->ToString() == dataGridViewMessage->Rows[c]->Cells[1]->Value->ToString())
						dataGridViewMessage->Rows[c]->Cells[1]->Value = i;

				}
			}
		
		
		}
		finally{
			if (sr)
			delete(IDisposable^)(sr);
		
		}
	

	
	}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	//MyForm ^frm=gcnew MyForm();
	//frm->Show();
}
private: System::Void dataGridViewMessage_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

	MessageTextBox->Text = dataGridViewMessage->CurrentRow->Cells[2]->Value->ToString();

	}


};
}

