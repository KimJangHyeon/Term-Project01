
#pragma once
#include <iostream>
#include "MyForm1.h"
namespace CppWinForm1 {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	//dataGridView4==>start end
	//dataGridView3==>phone name
	using namespace std;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: 
		String^ foundName;
		String^ searchingPhone;
	private: System::Windows::Forms::DataGridView^  dataGridView3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  phone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  start;
	private: System::Windows::Forms::DataGridView^  dataGridView4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  end;
	public:
		//&* 번호순서대로 sorting하기
		//dataGridView1의 내용을 dataGridView3에 넣은 후에 sorting하기 (0:name, 1:phone)
		void PhoneNameSet() {
			dataGridView3->Rows->Clear();
			for (int i = 0; i < dataGridView1->SelectedRows->Count; i++)
				dataGridView3->Rows->Add(dataGridView1->SelectedRows[i]->Cells[1]->Value, dataGridView1->SelectedRows[i]->Cells[0]->Value);
			dataGridView3->Sort(dataGridView3->Columns[0], ListSortDirection::Ascending);
		}
		//str1이 크면 1, str2가 크면 -1, str1 == str2이면 0을 내 놓는다. 
		int StrCmp(String^ str1, String^ str2);
		//String^을 int로 변환하는 함수
		int StrToInt(String^ str1) {
			int length = str1->Length;
			int decimal;
			int result=0;
			for (int i = 0; i < length; i++) {
				decimal = 1;
				for (decimal = i + 1; decimal < length; i++) {
					decimal *= 10;
				}
				result = toInt(str1[i])* decimal + result;
			}
			return result;
		}
		//한자리수의 int를 char형으로 변환하는 함수
		char toChar(int ch) {
			switch (ch) {
			case '0':
				return 0;
				break;
			case '1':
				return 0;
				break;
			case '2':
				return 0;
				break;
			case '3':
				return 0;
				break;
			case '4':
				return 0;
				break;
			case '5':
				return 0;
				break;
			case '6':
				return 0;
				break;
			case '7':
				return 0;
				break;
			case '8':
				return 0;
				break;
			case '9':
				return 0;
				break;
			}
		}
		//한자리의 char를 int형으로 변환하는 함수
		int toInt(char a) {
			switch (a) {
			case '0':
				return 0;
			case '1':
				return 1;
			case '2':
				return 2;
			case '3':
				return 3;

			case '4':
				return 4;

			case '5':
				return 5;

			case '6':
				return 6;

			case '7':
				return 7;

			case '8':
				return 8;

			case '9':
				return 9;
			}
		}
		//dataGridView4에 index값들을 넣는 함수(0: start, 1: end) 총 100개 00, 01, ..... , 99
		//binary search를 보다 빠르게 하기 위한 방법
		void MakeIndex() {
			//start의 값이 정해지기 전에 의미 없이 end에 값이 들어가는 것을 막기 위한 bool값 
			bool afterZero = false;

			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					//
					for (int k = 0; k<dataGridView3->SelectedRows->Count; k++) {
						String^ firstRangePhone = "01" + toChar(i) + toChar(j)+"0000000";
						String^ lastRangePhone = "01" + toChar(i) + toChar(j) + "9999999";
						
						//start index에 값이 우선 들어가면 afterZero가 true가되어 실행되지 않는다.
						//start index를 구하는 코드
						if (StrCmp(dataGridView3->SelectedRows[i]->Cells[0]->Value->ToString, lastRangePhone)!= 1 && StrCmp(dataGridView4->SelectedRows[i]->Cells[0]->Value->ToString, firstRangePhone) == 1 && !afterZero) {
							int index = i * 10 + j;
							dataGridView4->SelectedRows[index]->Cells[0]->Value = k;
							afterZero = true;
						}

						//start index의 값이 들어간 후에 실행된다.
						//end index를 구하는 코드
						if (StrCmp(dataGridView3->SelectedRows[i]->Cells[0]->Value->ToString , lastRangePhone) != 1 && afterZero) {
							int index = i * 10 + j;
							dataGridView4->SelectedRows[index]->Cells[1]->Value = k;
						}
					}
					afterZero = false;
				}
			}
		}

		//전화번호 비교 전용
		int StrCmp(String^ str1, String^ str2) {
			int length = str1->Length;
			
			for (int i = 0; i < length; i++) {
				if (str1[i] > str2[i]) return 1;
				else if (str1[i] < str2[i]) return -1;
				else return 0;
			}	
		}
		
		//binary search && 만약 조건을 만족하는 범위에 전화번호가 저장되어 있지 않으면 -1출력
		int BinarySearch(int first, int last, String ^searchingNumber) {
			int middle;
			//조건 만족 범위에 전화번호가 저장되어 있지 안는 경우 
			if (first == -1) return -1;

			//binary search
			while (first <= last)
				{
				middle = (first + last) / 2;
				if (StrCmp(dataGridView3->SelectedRows[middle]->Cells[0]->ToString , searchingNumber) == 1) last = middle - 1;
				else if (StrCmp(dataGridView3->SelectedRows[middle]->Cells[0]->ToString, searchingNumber) == -1) first = middle + 1;
				else return middle;
			}
			// 데이터를 찾지 못하면 -1를 반환한다.
			return -1;
		}
		
		//foundName이라는 변수에 찾은 이름을 넣는다.
		//입력된 전화 번호는 searchingPhone이다.
		void IndexSearchingPhone() {
			//찾는 숫자의 01이후의 두 숫자를 받아온다.
			char indexSecond = searchingPhone[2];
			char indexThird = searchingPhone[3];

			//받아온 두 숫자를 int로 변환 후에 내가 찾는 start와 end의 index를 구한다.
			int index = toInt(indexSecond) * 10 + toInt(indexThird);
			int key = BinarySearch(StrToInt(dataGridView3->SelectedRows[index]->Cells[0]->Value->ToString), StrToInt(dataGridView3->SelectedRows[index]->Cells[1]->Value->ToString), searchingPhone);
			
			//번호가 없으면 foundName값에 NULL을 저장한다. 
			if (key == -1) foundName = "NULL";

			//아닌 경우 그 번호와 매칭되는 이름을 foundName에 저장한다.
			foundName = dataGridView3->SelectedRows[key]->Cells[1]->Value->ToString;

		}
	public:
		MyForm(void)
		{	
			//00부터 99까지 start와 end에 -1을 넣는다.
			for (int i = 0; i < 100;i++)
				dataGridView4->Rows->Add(-1, -1);
			for (int i = 0; i < dataGridView1->SelectedRows->Count; i++) 
				dataGridView3->Rows->Add(dataGridView1->SelectedRows[i]->Cells[1]->Value, dataGridView1->SelectedRows[i]->Cells[0]->Value);

			InitializeComponent();
			this->dataGridView3->Hide();
			this->dataGridView4->Hide();
			this->dataGridView2->Hide();
			PhoneData_set();

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
	private: System::Windows::Forms::Button^  btnsms;



	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn4;



	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::GroupBox^  INFO;







	private: System::Windows::Forms::Button^  btnAdd;
	private: System::Windows::Forms::Button^  btnDel;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::TextBox^  textPhone;
	public: System::Windows::Forms::TextBox^  textName;
	private:

	private: System::Windows::Forms::Button^  mdf_btn;


	private: System::Windows::Forms::Label^  label3;


	private: System::Data::DataSet^  dataSet1;
	public: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  이름;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  전화번호;
	private: System::Windows::Forms::Button^  button2;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataSet1 = (gcnew System::Data::DataSet());
			this->btnsms = (gcnew System::Windows::Forms::Button());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->INFO = (gcnew System::Windows::Forms::GroupBox());
			this->mdf_btn = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnDel = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textPhone = (gcnew System::Windows::Forms::TextBox());
			this->textName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->이름 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->전화번호 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->phone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->start = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->end = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
			this->INFO->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::MintCream;
			this->dataGridView1->ColumnHeadersHeight = 50;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2
			});
			this->dataGridView1->Location = System::Drawing::Point(20, 98);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 4;
			this->dataGridView1->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::DisableResizing;
			this->dataGridView1->RowTemplate->Height = 50;
			this->dataGridView1->RowTemplate->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(274, 438);
			this->dataGridView1->TabIndex = 1;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->FillWeight = 80;
			this->dataGridViewTextBoxColumn1->HeaderText = L"Name";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			this->dataGridViewTextBoxColumn1->Width = 80;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Phones";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->ReadOnly = true;
			this->dataGridViewTextBoxColumn2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
			this->dataGridViewTextBoxColumn2->Width = 160;
			// 
			// dataSet1
			// 
			this->dataSet1->DataSetName = L"NewDataSet";
			// 
			// btnsms
			// 
			this->btnsms->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnsms.BackgroundImage")));
			this->btnsms->Location = System::Drawing::Point(574, 10);
			this->btnsms->Margin = System::Windows::Forms::Padding(4);
			this->btnsms->Name = L"btnsms";
			this->btnsms->Size = System::Drawing::Size(57, 62);
			this->btnsms->TabIndex = 2;
			this->btnsms->UseVisualStyleBackColor = true;
			this->btnsms->Click += gcnew System::EventHandler(this, &MyForm::btnsms_Click);
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"굴림", 15));
			this->textBox1->Location = System::Drawing::Point(54, 40);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(156, 36);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Location = System::Drawing::Point(217, 30);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 61);
			this->button1->TabIndex = 4;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// INFO
			// 
			this->INFO->Controls->Add(this->mdf_btn);
			this->INFO->Controls->Add(this->btnAdd);
			this->INFO->Controls->Add(this->btnDel);
			this->INFO->Controls->Add(this->label2);
			this->INFO->Controls->Add(this->label1);
			this->INFO->Controls->Add(this->textPhone);
			this->INFO->Controls->Add(this->textName);
			this->INFO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->INFO->Location = System::Drawing::Point(300, 80);
			this->INFO->Margin = System::Windows::Forms::Padding(4);
			this->INFO->Name = L"INFO";
			this->INFO->Padding = System::Windows::Forms::Padding(4);
			this->INFO->Size = System::Drawing::Size(335, 479);
			this->INFO->TabIndex = 6;
			this->INFO->TabStop = false;
			this->INFO->Text = L"INFO";
			// 
			// mdf_btn
			// 
			this->mdf_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mdf_btn.BackgroundImage")));
			this->mdf_btn->Location = System::Drawing::Point(226, 308);
			this->mdf_btn->Margin = System::Windows::Forms::Padding(2);
			this->mdf_btn->Name = L"mdf_btn";
			this->mdf_btn->Size = System::Drawing::Size(103, 112);
			this->mdf_btn->TabIndex = 3;
			this->mdf_btn->UseVisualStyleBackColor = true;
			this->mdf_btn->Click += gcnew System::EventHandler(this, &MyForm::mdf_btn_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAdd.BackgroundImage")));
			this->btnAdd->Location = System::Drawing::Point(6, 308);
			this->btnAdd->Margin = System::Windows::Forms::Padding(4);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(105, 112);
			this->btnAdd->TabIndex = 2;
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
			// 
			// btnDel
			// 
			this->btnDel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDel.BackgroundImage")));
			this->btnDel->Location = System::Drawing::Point(118, 308);
			this->btnDel->Margin = System::Windows::Forms::Padding(4);
			this->btnDel->Name = L"btnDel";
			this->btnDel->Size = System::Drawing::Size(103, 112);
			this->btnDel->TabIndex = 2;
			this->btnDel->UseVisualStyleBackColor = true;
			this->btnDel->Click += gcnew System::EventHandler(this, &MyForm::btnDel_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(-5, 200);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"PHONE";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 132);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"NAME";
			// 
			// textPhone
			// 
			this->textPhone->Font = (gcnew System::Drawing::Font(L"굴림", 15));
			this->textPhone->Location = System::Drawing::Point(98, 200);
			this->textPhone->Margin = System::Windows::Forms::Padding(4);
			this->textPhone->Name = L"textPhone";
			this->textPhone->Size = System::Drawing::Size(238, 36);
			this->textPhone->TabIndex = 0;
			this->textPhone->TextChanged += gcnew System::EventHandler(this, &MyForm::textPhone_TextChanged);
			// 
			// textName
			// 
			this->textName->Font = (gcnew System::Drawing::Font(L"굴림", 15));
			this->textName->Location = System::Drawing::Point(94, 128);
			this->textName->Margin = System::Windows::Forms::Padding(4);
			this->textName->Name = L"textName";
			this->textName->Size = System::Drawing::Size(238, 36);
			this->textName->TabIndex = 0;
			this->textName->TextChanged += gcnew System::EventHandler(this, &MyForm::textName_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(236, 548);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 15);
			this->label3->TabIndex = 8;
			// 
			// dataGridView2
			// 
			this->dataGridView2->AllowUserToAddRows = false;
			this->dataGridView2->AllowUserToDeleteRows = false;
			this->dataGridView2->AllowUserToOrderColumns = true;
			this->dataGridView2->AllowUserToResizeColumns = false;
			this->dataGridView2->AllowUserToResizeRows = false;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::MintCream;
			this->dataGridView2->ColumnHeadersHeight = 50;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->이름, this->전화번호 });
			this->dataGridView2->GridColor = System::Drawing::SystemColors::ControlDarkDark;
			this->dataGridView2->Location = System::Drawing::Point(20, 98);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 50;
			this->dataGridView2->RowTemplate->Height = 37;
			this->dataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView2->Size = System::Drawing::Size(274, 438);
			this->dataGridView2->TabIndex = 3;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView2_CellContentClick);
			// 
			// 이름
			// 
			this->이름->HeaderText = L"Name";
			this->이름->Name = L"이름";
			this->이름->ReadOnly = true;
			this->이름->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
			this->이름->Width = 80;
			// 
			// 전화번호
			// 
			this->전화번호->HeaderText = L"Phone";
			this->전화번호->Name = L"전화번호";
			this->전화번호->ReadOnly = true;
			this->전화번호->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->전화번호->Width = 160;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->Location = System::Drawing::Point(496, 10);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(57, 62);
			this->button2->TabIndex = 9;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->phone,
					this->name
			});
			this->dataGridView3->Location = System::Drawing::Point(34, 350);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowTemplate->Height = 27;
			this->dataGridView3->Size = System::Drawing::Size(240, 150);
			this->dataGridView3->TabIndex = 10;
			this->dataGridView3->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView3_CellContentClick);
			// 
			// phone
			// 
			this->phone->HeaderText = L"phone";
			this->phone->Name = L"phone";
			// 
			// name
			// 
			this->name->HeaderText = L"name";
			this->name->Name = L"name";
			// 
			// dataGridView4
			// 
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->start,
					this->end
			});
			this->dataGridView4->Location = System::Drawing::Point(27, 159);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->RowTemplate->Height = 27;
			this->dataGridView4->Size = System::Drawing::Size(247, 150);
			this->dataGridView4->TabIndex = 4;
			this->dataGridView4->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyForm::dataGridView4_CellContentClick);
			// 
			// start
			// 
			this->start->HeaderText = L"start";
			this->start->Name = L"start";
			// 
			// end
			// 
			this->end->HeaderText = L"end";
			this->end->Name = L"end";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 598);
			this->Controls->Add(this->dataGridView4);
			this->Controls->Add(this->dataGridView3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->INFO);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btnsms);
			this->Controls->Add(this->dataGridView1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
			this->INFO->ResumeLayout(false);
			this->INFO->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

		textName->Text = dataGridView1->CurrentRow->Cells[0]->Value->ToString();
		textPhone->Text = dataGridView1->CurrentRow->Cells[1]->Value->ToString();


	}
	private: System::Void btnsms_Click(System::Object^  sender, System::EventArgs^  e) {
		MyForm1^ msg = gcnew MyForm1();
		msg->Show();
		this->Hide();


	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	}


	public: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {


	}
	private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {

		dataGridView1->Rows->Add(textName->Text, textPhone->Text);
		dataGridView1->Sort(dataGridView1->Columns[0], ListSortDirection::Ascending);
		dataGridView1->ClearSelection();
		PhoneData_out();
	}//add function
	private: System::Void btnDel_Click(System::Object^  sender, System::EventArgs^  e) {
		for each(DataGridViewCell^ oneCell in this->dataGridView1->SelectedCells)
		{
			if (oneCell->Selected)
				dataGridView1->Rows->RemoveAt(oneCell->RowIndex);
		}//delete function
		dataGridView1->Sort(dataGridView1->Columns[0], ListSortDirection::Ascending);
		PhoneData_out();
	}
	private: System::Void mdf_btn_Click(System::Object^  sender, System::EventArgs^  e) {


		for each(DataGridViewRow^ row in this->dataGridView1->Rows) {
			row->ReadOnly = false;
		}
		dataGridView1->CurrentRow->Cells[0]->Value = textName->Text;
		dataGridView1->CurrentRow->Cells[1]->Value = textPhone->Text;
		dataGridView1->Sort(dataGridView1->Columns[0], ListSortDirection::Ascending);
		PhoneData_out();
	}
	private: System::Void textName_TextChanged(System::Object^  sender, System::EventArgs^  e) {


	}

	


	private:

	

			 //searching + filtering 
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		String ^searchValue = textBox1->Text;
		
		bool onswitch = true;
		dataGridView1->ClearSelection();
		if (textBox1->Text->ToString() != "" && onswitch == true) {
			dataGridView1->Hide();
			dataGridView2->Show();
			btnAdd->Hide();
			btnDel->Hide();
			mdf_btn->Hide();
			onswitch = false;
		}


		try {
			bool valueResult = false;
			dataGridView2->Rows->Clear();
			for each(DataGridViewRow ^row in dataGridView1->Rows) {
				
				for (int i = 0; i < row->Cells->Count; i++) {
					if (row->Cells[i]->Value != NULL && row->Cells[i]->Value->ToString()->Contains(searchValue)) {
						int rowIndex = row->Index;
						dataGridView1->Rows[rowIndex]->Selected = true;
						dataGridView1->SelectedRows->Count;
						valueResult = true;
						}
					
						//dataGridView2->Rows->Add(dataGridView1->Rows[rowIndex]->Cells[0]->Value, dataGridView1->Rows[rowIndex]->Cells[1]->Value);
						
						
						//break;
					}
				}//for out	

			

			if (!valueResult) {
				MessageBox ^a;
				a->Show("Unable to find" + textBox1->Text, "Not Found");
			}
			for (int i = 0; i < dataGridView1->SelectedRows->Count; i++) {
				dataGridView2->Rows->Add(dataGridView1->SelectedRows[i]->Cells[0]->Value, dataGridView1->SelectedRows[i]->Cells[1]->Value);
				dataGridView2->Sort(dataGridView2->Columns[0], ListSortDirection::Ascending);
				
			}

			if (dataGridView2->RowCount >= 2) {
				for (int i = 0; i < dataGridView2->RowCount - 1; i++) {
					for (int j = i + 1; j < dataGridView2->RowCount; j++) {
						if (dataGridView2->Rows[i]->Cells[0]->Value == dataGridView2->Rows[j]->Cells[0]->Value)
							dataGridView2->Rows->RemoveAt(j);
					}
				
				}
			}

		}

		
		catch (Exception ^exc) {
			MessageBox ^b;
			b->Show(exc->Message);
		}

		if (textBox1->Text->ToString() == "") {
			dataGridView2->Rows->Clear();
			dataGridView2->Hide();
			dataGridView1->Show();
			dataGridView1->ClearSelection();
			btnAdd->Show();
			btnDel->Show();
			mdf_btn->Show();
		}




	}
			 private:System::Void PhoneData_set() {

				 String^ path = "D:\\a\\CppWinForm1\\phoneBook.txt";

				 StreamReader^ sr = File::OpenText(path);
				 try {
					 String^ s = "";
					 String^ q = "";

					 while (sr->EndOfStream == false) {
						 s = sr->ReadLine();
						 q = sr->ReadLine();
						 dataGridView1->Rows->Add(s, q);
					 }

				 }
				 finally{
					 if (sr)
						 delete(IDisposable^)(sr);
				 }



			 }
					 private:System::Void PhoneData_out() {
						 String ^path = "D:\\a\\CppWinForm1\\phoneBook.txt";
						 StreamWriter^ wr = File::CreateText(path);
						 try
						 {
							 for (int i = 0; i < dataGridView1->Rows->Count; i++) {
								 wr->WriteLine(dataGridView1->Rows[i]->Cells[0]->Value);
								 wr->WriteLine(dataGridView1->Rows[i]->Cells[1]->Value);
							 }
						 }
						 finally
						 {
							 if (wr)
								 delete (IDisposable^)(wr);
						 }

					 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {


			
	}


	private: System::Void textPhone_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (!(textPhone->Text->StartsWith("0") || textPhone->Text->StartsWith("1") || textPhone->Text->StartsWith("2") || textPhone->Text->StartsWith("3") ||
			textPhone->Text->StartsWith("4") || textPhone->Text->StartsWith("5") || textPhone->Text->StartsWith("6") || textPhone->Text->StartsWith("7") ||
			textPhone->Text->StartsWith("8") || textPhone->Text->StartsWith("9"))&&!(textPhone->Text->Equals(""))) {
			MessageBox ^a;
			a->Show("Please Input Only Numbers.");
		}

	}
private: System::Void dataGridView2_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void dataGridView4_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void dataGridView4_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void dataGridView4_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void dataGridView3_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
}
	; }
	