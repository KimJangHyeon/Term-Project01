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
	int numberOfPeople;
public:
	PhoneBook();
	~PhoneBook();
	void MakeIntoPair();
	void ShowList();
	void Sorting();
	void Erase(string nameToErase);
	void Add(string name, string phoneNumber);
	void Adjust();

};