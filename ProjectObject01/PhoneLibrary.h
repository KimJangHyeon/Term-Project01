#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

class PhoneBook {
private:
	//ifstream pPhoneBook;
	vector<string> namePhoneVector;
	vector<pair<string, string>> nameVector;
	vector<string>::iterator iter;
	vector<pair<string, string>>::iterator piter;
	int numberOfPeople;
	int modelNumber;
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
};