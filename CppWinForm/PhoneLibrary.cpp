#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include"PhoneLibrary.h"
#define MAXSIZE 1024
using namespace std;

PhoneBook::PhoneBook() {
	//namePhoneVector내에 이름 list 넣기, numberOfPeople에 list의 사람수 넣기
	char nameAndPhoneNumber[MAXSIZE];
	ifstream pPhoneBook;
	pPhoneBook.open("phoneBook.txt", std::ifstream::in);
	pPhoneBook.getline(nameAndPhoneNumber, MAXSIZE);
	numberOfPeople = atoi(nameAndPhoneNumber);
	for (int i = 0; i < numberOfPeople; i++) {
		pPhoneBook.getline(nameAndPhoneNumber, MAXSIZE);
		namePhoneVector.push_back(nameAndPhoneNumber);
	}
	pPhoneBook.close();
}
PhoneBook::~PhoneBook() {
	
}

void PhoneBook::MakeIntoPair() {
	int findIndex = 0;
	string name, phoneNumber;
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); ++iter) {
		findIndex = iter->find_first_of("0");
		name = iter->substr(0, findIndex - 1);
		cout << name << endl;
		phoneNumber = iter->substr(findIndex, 13);
		cout << phoneNumber << endl;
		nameVector.push_back(make_pair(name, phoneNumber));
	}
}

void PhoneBook::ShowList() {
	char nameAndPhoneNumber[MAXSIZE];
	ifstream pPhoneBook;
	pPhoneBook.open("phoneBook.txt", std::ifstream::in);
	pPhoneBook.getline(nameAndPhoneNumber, MAXSIZE);
	numberOfPeople = atoi(nameAndPhoneNumber);
	for (int i = 0; i < numberOfPeople; i++) {
		pPhoneBook.getline(nameAndPhoneNumber, MAXSIZE);
		cout << nameAndPhoneNumber << endl;
	}
	pPhoneBook.close();
}

void PhoneBook::Sorting() {
	sort(namePhoneVector.begin(), namePhoneVector.end());

	//sort한 내용을 파일에 입력
	ofstream oPhoneBook("phoneBook.txt");
	oPhoneBook << numberOfPeople << endl;
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); ++iter) {
		oPhoneBook << *iter << endl;
	}
	
	oPhoneBook.close();

}
//namePhoneVector와 file 모두에 제거
void PhoneBook::Erase(string nameToErase) {
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); ++iter) {
		
	}
}

//namePhoneVector와 file 모두에 넣기 
void PhoneBook::Add(string name, string phoneNumber) {
	ofstream oPhoneBook("phoneBook.txt");
	oPhoneBook << numberOfPeople << endl;
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); ++iter) {
		oPhoneBook << *iter << endl;
	}
	oPhoneBook << name << ' ' << phoneNumber << endl;
	oPhoneBook.close();
}