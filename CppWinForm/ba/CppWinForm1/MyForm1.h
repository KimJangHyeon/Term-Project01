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
		MyForm1(CppWinForm1::Windows::Forms::Form ^frm)
		{
			otherform = frm;
			InitializeComponent();
			Message_Set();
			Matching();
			//생성자를 통해 메세지를 텍스트파일에서 바로 불러온다. 매칭도 곧바로 실행한다.
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
	public: System::Windows::Forms::Form ^otherform;
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
			this->날짜->HeaderText = L"Date";
			this->날짜->Name = L"날짜";
			this->날짜->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// 발신자
			// 
			this->발신자->FillWeight = 10.25483F;
			this->발신자->HeaderText = L"Sender";
			this->발신자->Name = L"발신자";
			// 
			// 내용
			// 
			this->내용->FillWeight = 284.7716F;
			this->내용->HeaderText = L"Contents";
			this->내용->Name = L"내용";
			this->내용->Width = 250;
			// 
			// msgDel_btn
			// 
			this->msgDel_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"msgDel_btn.BackgroundImage")));
			this->msgDel_btn->Location = System::Drawing::Point(453, 31);
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
			this->button1->Location = System::Drawing::Point(43, 16);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 50);
			this->button1->TabIndex = 2;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// MessageTextBox
			// 
			this->MessageTextBox->Location = System::Drawing::Point(521, 70);
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
			this->BackColor = System::Drawing::Color::SeaShell;
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

#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

		for each(DataGridViewCell^ oneCell in this->dataGridViewMessage->SelectedCells)
		{
			if (oneCell->Selected)
				dataGridViewMessage->Rows->RemoveAt(oneCell->RowIndex);
		}//delete function
		dataGridViewMessage->Sort(dataGridViewMessage->Columns[0], ListSortDirection::Descending); //일자 기준 내림차순 정렬
		Message_Out();

	} //메세지를 삭제 후 자동 정렬한다. 수정된 목록은 텍스트파일에 Message_Out()함수를 통해 출력된다.

	private: System::Void Message_Set() {
		
		String^ path = Directory::GetCurrentDirectory() + "\\Message.txt";

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
			dataGridViewMessage->Sort(dataGridViewMessage->Columns[0], ListSortDirection::Descending); //추가 후 자동정렬이 되도록 한다, 일자 기준 내림차순이다.
		}
		finally{
			if (mr)
				delete(IDisposable^)(mr);
		}
		Message_Out();

	}//메세지를 텍스트파일에서 불러온다.
			 private: System::Void Message_Out() {
				 String^ path = Directory::GetCurrentDirectory() + "\\Message.txt";

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
			 }//메세지를 텍스트파일에 출력한다

	private: System::Void Matching() {
		dataGridViewMessage->ReadOnly = false;
		String ^path = Directory::GetCurrentDirectory() + "\\phoneBook.txt";

		StreamReader ^sr = File::OpenText(path);
		try {
		

			while(sr->EndOfStream == false){
				String ^i = "";
				String ^j = "";
				i = sr->ReadLine();
				j = sr->ReadLine();
				for (int c = 0; c < dataGridViewMessage->Rows->Count; c++) {
					if (j->ToString() == dataGridViewMessage->Rows[c]->Cells[1]->Value->ToString()) {
						
						dataGridViewMessage->Rows[c]->Cells[1]->Value = i;
					}
				}
			}
		
		
		}
		finally{
			if (sr)
			delete(IDisposable^)(sr);
		
		}
	

	
	}// 전화번호부의 전화와 메세지 발신자의 전화번호가 일치하면 전화번호가 아니라 이름이 보이도록 한다.
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Hide();
	otherform->Show();

}//go to previous
private: System::Void dataGridViewMessage_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

	MessageTextBox->Text = dataGridViewMessage->CurrentRow->Cells[2]->Value->ToString();

	}
		 //show full message

};
}

