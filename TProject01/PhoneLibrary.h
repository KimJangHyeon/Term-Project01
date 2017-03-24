#pragma once
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class PhoneBook {
private:
	//ifstream pPhoneBook;
	vector<pair<size_t, string>> phoneVector;
	vector<string> namePhoneVector;
	vector<pair<string, string>> nameVector;
	vector<string>::iterator iter;
	vector<pair<string, string>>::iterator piter;
	int numberOfPeople;
	int phoneIntList[1000];
	string nameList[1000];
	int indexOfMin;//���� ��� 10000000���� ������ ���� ���� ����Ű�� ����
	string modelNumber = "010***####";
public:
	PhoneBook();
	~PhoneBook();
	void Save();
	void MakeIntoPair();
	void ShowList();
	void Sorting();
	void Erase(string nameToErase, string phoneToErase);
	void Add(string name, string phoneNumber);
	void Adjust(string reName, string rePhoneNumber, size_t index);
	int* SearchIndex(string searchingName);
	int* SearchIndex2(string searchingName);
	bool CompareByEachAlp(string name, string searchingName, size_t nameSize, size_t inputSize);
	void ShowTxtVector();
	void NameNumberPair();
	bool PhoneNumberFront(string phoneNumber);
	string SearchByNumber(string phoneNumber);
	void NameListAndNumberList();
	int BinarySearching(int first, int last, int searchingNumber);//������ -1�� ����
};

class Message {
private:
	//string parsing = "@#!$%7*&";
	int numberOfM;
	vector<string>::iterator iter;
	vector<string> phoneNumberVector;
	vector<string> dateVector;
	vector<string> messageVector;
public:
	void Save();
	Message();
	string ShowMessage(int index);
	string ShowPhoneNumber(int index);
	string ShowDate(int index);

	void Add(string date, string phone, string message);
	void Delete(int index);
};