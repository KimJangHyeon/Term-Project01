#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include"PhoneLibrary.h"
#define MAXSIZE 1024
using namespace std;
//namePhoneVector에 txt내용 넣기
//numberOfPeople에 숫자 넣기
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


void PhoneBook::ShowTxtVector() {
	cout << "txt" << endl;
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
	cout << "\n\n\n" << endl;
	cout << "namePhoneVector" << endl;
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); iter++) {
		cout << *iter << endl;
	}
	cout << "\n\n\n" << endl;
	cout << "nameVector" << endl;
	
	for (piter = nameVector.begin(); piter != nameVector.end(); piter++) {
		cout << piter->first << ' ' << piter->second << endl;
	}
}
//namePhoneVector의 내용과 numberOfPeople을 txt에 저장
void PhoneBook::Save() {
	ofstream oPhoneBook("phoneBook.txt");
	oPhoneBook << numberOfPeople << endl;
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); iter++) {
		oPhoneBook << *iter << endl;
	}
	oPhoneBook.close();
}

//namePhoneVector의 이름과 전화번호를 pair를 이용해 nameVector에 저장
void PhoneBook::MakeIntoPair() {
	int findIndex = 0;
	string name, phoneNumber;
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); ++iter) {
		findIndex = iter->find_first_of("0");
		name = iter->substr(0, findIndex - 1);
		phoneNumber = iter->substr(findIndex, 13);
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
	//namePhoneVector 정렬
	sort(namePhoneVector.begin(), namePhoneVector.end());

	//nameVector 정렬

	//sort한 내용을 파일에 입력
	ofstream oPhoneBook("phoneBook.txt");
	oPhoneBook << numberOfPeople << endl;
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); ++iter) {
		oPhoneBook << *iter << endl;
	}
	oPhoneBook.close();

}
//namePhoneVector와 file 모두에 제거
void PhoneBook::Erase(string nameToErase, string phoneToErase) {
	int i;
	int count = 0;//몇개를 지웠는지 알기 위함
	int eraseIndex[100];
	//nameVector에서 제거 & namePhoneVector에서 제거
	for (i = 0, piter = nameVector.begin(); piter != nameVector.end();) {
		if (piter->first == nameToErase && piter->second == phoneToErase) {
			nameVector.erase(nameVector.begin() + i);
			namePhoneVector.erase(namePhoneVector.begin() + i);
			ShowTxtVector();
			eraseIndex[count] = i;
			count++;
		}
		else {
			i++;
			piter++;
		}
	}
	//numberOfPeople감소
	numberOfPeople -= count;

	//txt에서 제거
	Save();

	
}

//namePhoneVector와 file 모두에 넣기, numberOfPeople++하기
void PhoneBook::Add(string name, string phoneNumber) {
	//txt에 추가 
	ofstream oPhoneBook("phoneBook.txt");
	 
	oPhoneBook << ++numberOfPeople << endl;
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); ++iter) {
		oPhoneBook << *iter << endl;
	}
	oPhoneBook << name << ' ' << phoneNumber << endl;
	oPhoneBook.close();
	//nameVector에 추가 
	nameVector.push_back(make_pair(name, phoneNumber));
	//namePhoneVector에 추가
	string input = name + " " + phoneNumber;
	namePhoneVector.push_back(input);
}

void PhoneBook::Adjust(string reName, string rePhoneNumber,size_t index) {
	//namePhoneVector
	namePhoneVector.erase(namePhoneVector.begin() + index);
	namePhoneVector.insert(namePhoneVector.begin() + index, reName + " " + rePhoneNumber);
	//txt
	Save();
	//nameVector
	nameVector.erase(nameVector.begin() + index);
	nameVector.insert(nameVector.begin() + index, make_pair(reName, rePhoneNumber));
}
//오류 있을지도...
bool PhoneBook::CompareByEachAlp(string name, string searchingName, size_t nameSize, size_t inputSize) {
	int key = 1;
	if (inputSize > nameSize) {
		return -1;
	}
	else {
		for (int i = 0; i < nameSize; i++) {
			if (name[i] != searchingName[i])
				key = 0;
		}
		return key;
	}
}
//없으면 -1을 반환, 있으면 그위치를 반환
//최대 동일 인물 검색을 200까지로 한다.
//불확실 return, numberOfPeople
int* PhoneBook::SearchIndex(string searchingName) {
	string* stack = new string[numberOfPeople];
	int i;
	int nameIndex[200] = { -1 };// -1 0 0 0 0 0 0 0
	//stack 내부에 vector들을 옮김
	for (i = 0, piter = nameVector.begin(); piter != nameVector.end(); ++piter, ++i) {
		stack[i] = piter->first;
	}


	
	for (int j = 0, i = 0; i < numberOfPeople; i++) {
		if (stack[i] == searchingName) {
			nameIndex[j] = i;
			j++;
		}
	}
	return nameIndex;
}
//1번째가 -1이면 검색결과 없음
//2번째 이상이 0 이면 break;
int* PhoneBook::SearchIndex2(string searchingName) {
	string* stack = new string[numberOfPeople];
	int i;
	int nameIndex[200] = { -1 };// -1 0 0 0 0 0 0 0
								//stack 내부에 vector들을 옮김
	for (i = 0, piter = nameVector.begin(); piter != nameVector.end(); ++piter, ++i) {
		stack[i] = piter->first;
	}


	//searching 짝
	/*for (int j = 0, i = 0; i < numberOfPeople; i++) {		
		if (CompareByEachAlp(stack[i], searchingName, stack[i].size, searchingName.size)) {
			nameIndex[j] = i;
			j++;			
		}
	}*/
	return nameIndex;
}

