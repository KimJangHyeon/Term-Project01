
#pragma once
#include <iostream>
#include "MyForm1.h"		
#include "MyForm22.h"
namespace CppWinForm1 {


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private:
		String^ foundName;
		String^ searchingPhone;
	private: System::Windows::Forms::DataGridView^  startEnd;
	private: System::Windows::Forms::DataGridView^  phoneName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  start;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  end;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  phone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;


			 bool key1 = false;

	public:

		//&* ��ȣ������� sorting�ϱ�
		//dataGridView1�� ������ dataGridView3�� ���� �Ŀ� sorting�ϱ� (0:name, 1:phone)
		void PhoneNameSet() {
			startEnd->Rows->Clear();
			for (int i = 0; i < dataGridView1->Rows->Count; i++)
				startEnd->Rows->Add(dataGridView1->Rows[i]->Cells[1]->Value, dataGridView1->Rows[i]->Cells[0]->Value);
			startEnd->Sort(startEnd->Columns[0], ListSortDirection::Ascending);
			MakeIndex();
		}
		//str1�� ũ�� 1, str2�� ũ�� -1, str1 == str2�̸� 0�� �� ���´�. 
		//int StrCmp(String^ str1, String^ str2);
		
		//String^�� int�� ��ȯ�ϴ� �Լ�
	/*	Int32 StrToInt(String^ str1) {
			int length = str1->Length;
			int decimal;
			int result = 0;
			for (int i = 0; i < length; i++) {
				decimal = 1;
				for (int j = i + 1; j < length; j++) {
					decimal *= 10;
				}
				result = toInt(str1[i])* decimal + result;
			}
			return result;
		}*/

		
		

		
		//���ڸ����� int�� char������ ��ȯ�ϴ� �Լ�
		char32_t toChar(Int32 ch) {
			switch (ch) {
			case 0:
				return '0';
				break;
			case 1:
				return '1';
				break;
			case 2:
				return '2';
				break;
			case 3:
				return '3';
				break;
			case 4:
				return '4';
				break;
			case 5:
				return '5';
				break;
			case 6:
				return '6';
				break;
			case 7:
				return '7';
				break;
			case 8:
				return '8';
				break;
			case 9:
				return '9';
				break;
			}
		}
		//���ڸ��� char�� int������ ��ȯ�ϴ� �Լ�
		/*Int32 toInt(String ^a) {
			switch (a) {
			case "0":
				return 0;
			case "1":
				return 1;
			case "2":
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
		}*/
		//dataGridView4�� index������ �ִ� �Լ�(0: start, 1: end) �� 100�� 00, 01, ..... , 99
		//binary search�� ���� ������ �ϱ� ���� ���
		void MakeIndex() {
			//start�� ���� �������� ���� �ǹ� ���� end�� ���� ���� ���� ���� ���� bool�� 
			bool afterZero = false;

			for (int i = 0; i < 100; i++) {
				phoneName->Rows->Add(-1, -1);
			}

			for (Int32 i = 0; i < 10; i++) {
				for (Int32 j = 0; j < 10; j++) {
					//
					for (Int32 k = 0; k < startEnd->Rows->Count; k++) {
						String^ firstRangePhone = "01" + i.ToString() + "-" + j.ToString() + "000-0000";
						String^ lastRangePhone = "01" + i.ToString() + "-" + j.ToString() + "999-9999";
						int index = i * 10 + j;
						//start index�� ���� �켱 ���� afterZero�� true���Ǿ� ������� �ʴ´�.
						//start index�� ���ϴ� �ڵ�

						// string^ a -> Compareto(string^ b) <0 ; a �� B���� �տ�, =0 ����, >0 a�� �� �ڿ� �ִ�.
						//strcomp�� =1�̸� �տ��� ū��, -1�̸� �ڿ��� ū��

						//.�� ���� 0���� ���� strA�� strB���� �۽��ϴ�.Zero strA�� strB�� ���� ��� 0���� ŭ strA�� strB���� ū ���
						String^ stringCheck = startEnd->Rows[k]->Cells[0]->Value->ToString()->Trim();
						if (StrCmp(stringCheck,lastRangePhone) <=0 && StrCmp(stringCheck,firstRangePhone)>=0 && (!afterZero)) {
							//int index = i * 10 + j;
							
							phoneName->Rows[index]->Cells[0]->Value = k.ToString();
							afterZero = true;
						}

						//start index�� ���� �� �Ŀ� ����ȴ�.
						//end index�� ���ϴ� �ڵ�
						if ((StrCmp(stringCheck,lastRangePhone) <=0) && (afterZero)) {
							phoneName->Rows[index]->Cells[1]->Value = k.ToString();
						}
					}
					afterZero = false;
				}
			}
		}

		//��ȭ��ȣ �� ����
		Int32 StrCmp(String^ str1, String^ str2) {
			int length = str1->Length;

			for (int i = 0; i < length; i++) {
				if (str1->Substring(i, 1) == "-");
				else if (Convert::ToInt32(str1->Substring(i,1)) > Convert::ToInt32(str2->Substring(i,1))) return 1;
				else if (Convert::ToInt32(str1->Substring(i, 1)) < Convert::ToInt32(str2->Substring(i, 1))) return -1;
				else if (i == length - 1 && Convert::ToInt32(str1->Substring(i, 1)) == Convert::ToInt32(str2->Substring(i, 1))) return 0;
				else;
			}
		}

		//binary search && ���� ������ �����ϴ� ������ ��ȭ��ȣ�� ����Ǿ� ���� ������ -1���
		Int32 BinarySearch(Int32 first, Int32 last, String ^searchingNumber) {
			int middle;
			//���� ���� ������ ��ȭ��ȣ�� ����Ǿ� ���� �ȴ� ��� 
			if (first == -1) return -1;

			//binary search
			while (first <= last)
			{
				middle = (first + last) / 2;
				if (StrCmp(startEnd->Rows[middle]->Cells[0]->Value->ToString(), searchingNumber) < 0) last = middle - 1;
				else if (StrCmp(startEnd->Rows[middle]->Cells[0]->Value->ToString(), searchingNumber) > 0) first = middle + 1;
				else return middle;
			}
			// �����͸� ã�� ���ϸ� -1�� ��ȯ�Ѵ�.
			return -1;
		}

		//foundName�̶�� ������ ã�� �̸��� �ִ´�.
		//�Էµ� ��ȭ ��ȣ�� searchingPhone�̴�.
		void IndexSearchingPhone() {
			//ã�� ������ 01������ �� ���ڸ� �޾ƿ´�.
			String ^indexSecond = searchingPhone->Substring(2, 1);
			String ^indexThird = searchingPhone->Substring(4, 1);
			MessageBox ^Error_Full_Num;
		//	if(textBox1->Text->Length!=13 || textBox1)
				Error_Full_Num->Show("input correct form");

			//�޾ƿ� �� ���ڸ� int�� ��ȯ �Ŀ� ���� ã�� start�� end�� index�� ���Ѵ�.
			int index = Convert::ToInt32(indexSecond) * 10 + Convert::ToInt32(indexThird);
			int key = BinarySearch(Convert::ToInt32(phoneName->Rows[index]->Cells[0]->Value->ToString()), Convert::ToInt32(phoneName->Rows[index]->Cells[1]->Value->ToString()), searchingPhone);
			//��ȣ�� ������ foundName���� NULL�� �����Ѵ�. 
			if (key == -1) foundName = "NULL";

			//�ƴ� ��� �� ��ȣ�� ��Ī�Ǵ� �̸��� foundName�� �����Ѵ�.
			foundName = startEnd->Rows[key]->Cells[1]->Value->ToString();

		}

		MyForm(void)
		{
			InitializeComponent();
			this->startEnd->Hide();
			this->phoneName->Hide();
			this->dataGridView2->Hide();//���͸��� ������ â�� ���ܵд�
			PhoneData_set();//�����ڸ� �̿��Ͽ� ������ ���� ��ٷ� �ҷ��´�
			PhoneNameSet();
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  �̸�;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ��ȭ��ȣ;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::CheckBox^  Filter_CheckBox;//������� �����
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
			this->phoneName = (gcnew System::Windows::Forms::DataGridView());
			this->start = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->end = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->mdf_btn = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnDel = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textPhone = (gcnew System::Windows::Forms::TextBox());
			this->textName = (gcnew System::Windows::Forms::TextBox());
			this->startEnd = (gcnew System::Windows::Forms::DataGridView());
			this->phone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->�̸� = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->��ȭ��ȣ = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->Filter_CheckBox = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->BeginInit();
			this->INFO->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->phoneName))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->startEnd))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
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
			this->dataGridView1->Location = System::Drawing::Point(19, 98);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
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
			this->btnsms->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
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
			this->textBox1->Font = (gcnew System::Drawing::Font(L"����", 15));
			this->textBox1->Location = System::Drawing::Point(54, 40);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(156, 36);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->Location = System::Drawing::Point(215, 28);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 61);
			this->button1->TabIndex = 4;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// INFO
			// 
			this->INFO->BackColor = System::Drawing::Color::YellowGreen;
			this->INFO->Controls->Add(this->mdf_btn);
			this->INFO->Controls->Add(this->btnAdd);
			this->INFO->Controls->Add(this->btnDel);
			this->INFO->Controls->Add(this->label2);
			this->INFO->Controls->Add(this->label1);
			this->INFO->Controls->Add(this->textPhone);
			this->INFO->Controls->Add(this->textName);
			this->INFO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->INFO->Location = System::Drawing::Point(301, 80);
			this->INFO->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->INFO->Name = L"INFO";
			this->INFO->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->INFO->Size = System::Drawing::Size(369, 479);
			this->INFO->TabIndex = 6;
			this->INFO->TabStop = false;
			this->INFO->Text = L"INFO";
			// 
			// phoneName
			// 
			this->phoneName->AllowUserToAddRows = false;
			this->phoneName->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->phoneName->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->start, this->end });
			this->phoneName->Location = System::Drawing::Point(301, 59);
			this->phoneName->Name = L"phoneName";
			this->phoneName->RowTemplate->Height = 27;
			this->phoneName->Size = System::Drawing::Size(240, 150);
			this->phoneName->TabIndex = 12;
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
			// mdf_btn
			// 
			this->mdf_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mdf_btn.BackgroundImage")));
			this->mdf_btn->Location = System::Drawing::Point(240, 308);
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
			this->btnAdd->Location = System::Drawing::Point(19, 308);
			this->btnAdd->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(105, 112);
			this->btnAdd->TabIndex = 2;
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &MyForm::btnAdd_Click);
			// 
			// btnDel
			// 
			this->btnDel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDel.BackgroundImage")));
			this->btnDel->Location = System::Drawing::Point(131, 308);
			this->btnDel->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnDel->Name = L"btnDel";
			this->btnDel->Size = System::Drawing::Size(103, 112);
			this->btnDel->TabIndex = 2;
			this->btnDel->UseVisualStyleBackColor = true;
			this->btnDel->Click += gcnew System::EventHandler(this, &MyForm::btnDel_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 206);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(102, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"PHONE";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click_1);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 132);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"NAME";
			// 
			// textPhone
			// 
			this->textPhone->Font = (gcnew System::Drawing::Font(L"����", 15));
			this->textPhone->Location = System::Drawing::Point(104, 200);
			this->textPhone->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textPhone->Name = L"textPhone";
			this->textPhone->Size = System::Drawing::Size(238, 36);
			this->textPhone->TabIndex = 0;
			this->textPhone->TextChanged += gcnew System::EventHandler(this, &MyForm::textPhone_TextChanged);
			// 
			// textName
			// 
			this->textName->Font = (gcnew System::Drawing::Font(L"����", 15));
			this->textName->Location = System::Drawing::Point(103, 126);
			this->textName->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textName->Name = L"textName";
			this->textName->Size = System::Drawing::Size(238, 36);
			this->textName->TabIndex = 0;
			this->textName->TextChanged += gcnew System::EventHandler(this, &MyForm::textName_TextChanged);
			// 
			// startEnd
			// 
			this->startEnd->AllowUserToAddRows = false;
			this->startEnd->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->startEnd->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->phone, this->name });
			this->startEnd->Location = System::Drawing::Point(44, 453);
			this->startEnd->Name = L"startEnd";
			this->startEnd->RowTemplate->Height = 27;
			this->startEnd->Size = System::Drawing::Size(240, 150);
			this->startEnd->TabIndex = 11;
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
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(237, 548);
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
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->�̸�, this->��ȭ��ȣ });
			this->dataGridView2->GridColor = System::Drawing::SystemColors::ControlDarkDark;
			this->dataGridView2->Location = System::Drawing::Point(19, 98);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->ReadOnly = true;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 50;
			this->dataGridView2->RowTemplate->Height = 37;
			this->dataGridView2->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView2->Size = System::Drawing::Size(274, 461);
			this->dataGridView2->TabIndex = 3;
			// 
			// �̸�
			// 
			this->�̸�->HeaderText = L"Name";
			this->�̸�->Name = L"�̸�";
			this->�̸�->ReadOnly = true;
			this->�̸�->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
			this->�̸�->Width = 80;
			// 
			// ��ȭ��ȣ
			// 
			this->��ȭ��ȣ->HeaderText = L"Phone";
			this->��ȭ��ȣ->Name = L"��ȭ��ȣ";
			this->��ȭ��ȣ->ReadOnly = true;
			this->��ȭ��ȣ->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->��ȭ��ȣ->Width = 160;
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->Location = System::Drawing::Point(496, 10);
			this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(57, 62);
			this->button2->TabIndex = 9;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// Filter_CheckBox
			// 
			this->Filter_CheckBox->AutoSize = true;
			this->Filter_CheckBox->Location = System::Drawing::Point(30, 50);
			this->Filter_CheckBox->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Filter_CheckBox->Name = L"Filter_CheckBox";
			this->Filter_CheckBox->Size = System::Drawing::Size(18, 17);
			this->Filter_CheckBox->TabIndex = 10;
			this->Filter_CheckBox->UseVisualStyleBackColor = true;
			this->Filter_CheckBox->CheckedChanged += gcnew System::EventHandler(this, &MyForm::Filter_CheckBox_CheckedChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SeaShell;
			this->ClientSize = System::Drawing::Size(690, 598);
			this->Controls->Add(this->phoneName);
			this->Controls->Add(this->startEnd);
			this->Controls->Add(this->Filter_CheckBox);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->INFO);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->btnsms);
			this->Controls->Add(this->dataGridView1);
			this->ForeColor = System::Drawing::SystemColors::MenuText;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataSet1))->EndInit();
			this->INFO->ResumeLayout(false);
			this->INFO->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->phoneName))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->startEnd))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

		textName->Text = dataGridView1->CurrentRow->Cells[0]->Value->ToString();
		textPhone->Text = dataGridView1->CurrentRow->Cells[1]->Value->ToString();


	}//��ȭ��ȣ�� â �Ʒ� �ϳ��ϳ��� ������ Ŭ�� �� �ؽ�Ʈ â�� �� ������ �ڵ����� ���̵��� �Ͽ� ������ ������ ���ߴ�.
	private: System::Void btnsms_Click(System::Object^  sender, System::EventArgs^  e) {
		MyForm1^ msg = gcnew MyForm1(this);
		msg->Show();
		this->Hide();


	}//���ڸ޽��� Ȯ�� â���� �̵�
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	}


	public: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {


	}
	private: System::Void btnAdd_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textName->Text->ToString() == "" || textPhone->Text->ToString() == "") {
			MessageBox ^a;
			a->Show("Enter Name or Numbers");
			return;
		}

		dataGridView1->Rows->Add(textName->Text, textPhone->Text);
		PhoneNameSet();
		dataGridView1->Sort(dataGridView1->Columns[0], ListSortDirection::Ascending);
		dataGridView1->ClearSelection();
		PhoneData_out();
	}//add function
	private: System::Void btnDel_Click(System::Object^  sender, System::EventArgs^  e) {
		if (dataGridView1->Rows->Count == 0) {
			MessageBox ^b;
			b->Show("List is Empty!");
		}

		for each(DataGridViewCell^ oneCell in this->dataGridView1->SelectedCells)
		{
			if (oneCell->Selected) {
				dataGridView1->Rows->RemoveAt(oneCell->RowIndex);
				PhoneNameSet();
			}
		}
		dataGridView1->Sort(dataGridView1->Columns[0], ListSortDirection::Ascending);
		PhoneData_out();
	}//delete function
	private: System::Void mdf_btn_Click(System::Object^  sender, System::EventArgs^  e) {
		if (textName->Text->ToString() == "" && textPhone->Text->ToString() == "") {
			MessageBox ^d;
			d->Show("Nothing Revised.");
			return;
		}

		for each(DataGridViewRow^ row in this->dataGridView1->Rows) {
			row->ReadOnly = false;
		}
		dataGridView1->CurrentRow->Cells[0]->Value = textName->Text;
		dataGridView1->CurrentRow->Cells[1]->Value = textPhone->Text;
		dataGridView1->Sort(dataGridView1->Columns[0], ListSortDirection::Ascending);
		PhoneData_out();
		PhoneNameSet();
	}//��������� ���� �Լ��̴�.
	private: System::Void textName_TextChanged(System::Object^  sender, System::EventArgs^  e) {


	}



			 //searching + filtering ��� ���� �Լ�, ������ �� �ؽ�Ʈâ�� �ؽ�Ʈ�� �ٲ�� �ڵ����� ���͸� ����� ���� �Ѵ�.
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		if (Filter_CheckBox->Checked == false) {
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
						if (row->Cells[i]->Value != NULL && (row->Cells[i]->Value->ToString()->ToUpper()->Contains(searchValue->ToUpper()) || row->Cells[i]->Value->ToString()->ToLower()->Contains(searchValue->ToLower()))) {
							int rowIndex = row->Index;
							dataGridView1->Rows[rowIndex]->Selected = true;
							dataGridView1->SelectedRows->Count;
							valueResult = true;
						}
					}
				}
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
		//else {
		//	dataGridView2->Show();
		//	dataGridView2->Rows->Add(key1, key1);
		//	if (key1 == true) {
		//		dataGridView2->Rows->Add("aa", "aa");
		//		searchingPhone = textBox1->Text;
		//		IndexSearchingPhone();
		//		dataGridView2->Rows->Clear();
		//		dataGridView2->Rows->Add(foundName, searchingPhone);
		//		key1 = false;
		//		dataGridView2->Rows->Add(key1, key1);
		//	}
		//}
	}
	private:System::Void PhoneData_set() {

		String^ path = Directory::GetCurrentDirectory() + "\\phoneBook.txt";;

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

		//�ؽ�Ʈ���Ϸκ��� �����͸� �о�´�.

	}
	private:System::Void PhoneData_out() {
		String ^path = Directory::GetCurrentDirectory() + "\\phoneBook.txt";;
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

	}//�ؽ�Ʈ���Ͽ� ���ĵ� �����͸� ����Ѵ�.
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		key1 = true;
		//dummy function
		if(key1 == true) {
			dataGridView2->Show();
			dataGridView2->Rows->Add(key1, key1);
			if (Filter_CheckBox->Checked == true) {
				searchingPhone = textBox1->Text;
				IndexSearchingPhone();
				dataGridView2->Rows->Clear();
				dataGridView2->Rows->Add(foundName, searchingPhone);
				key1 = false;
			}
		}

	}


	private: System::Void textPhone_TextChanged(System::Object^  sender, System::EventArgs^  e) {

		if (!(textPhone->Text->Contains("0") || textPhone->Text->Contains("1") || textPhone->Text->Contains("2") || textPhone->Text->Contains("3") ||
			textPhone->Text->Contains("4") || textPhone->Text->Contains("5") || textPhone->Text->Contains("6") || textPhone->Text->Contains("7") ||
			textPhone->Text->Contains("8") || textPhone->Text->Contains("9")) && !(textPhone->Text->Equals(""))) {
			MessageBox ^a;
			a->Show("Please Input Only Numbers.");
		}
		//��ȭ��ȣ�� �޴� �ؽ�Ʈ â ���� ���� : ���ڰ� ���� ���� ��� ���� �޼��� ���

	}
	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
		MyForm22^ frm = gcnew MyForm22(this);
		frm->Show();
	}//go to phonecall list


	//private: System::Void dataGridView4_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	//}
	//private: System::Void dataGridView4_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	//}
	//private: System::Void dataGridView4_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	//}
	//private: System::Void dataGridView3_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	//}
	private: System::Void label2_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void Filter_CheckBox_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		if (Filter_CheckBox->Checked) {
			MessageBox ^c;
			c->Show("Binary Search Engine V 1.0.0 Activated\nHow to use : Enter the fully same number to find\nIt's really prototype and Only applied 01x-xxxx-xxxx numbers.\nAlgorithm Made By Jang Hyun Kim\n Coding By GI BEOM HONG");
		}

	}
	};
}

	