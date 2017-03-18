#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<algorithm>
#include"PhoneLibrary.h"
#define MAXSIZE 1024
using namespace std;
//namePhoneVector�� txt���� �ֱ�
//numberOfPeople�� ���� �ֱ�
PhoneBook::PhoneBook() {
	//namePhoneVector���� �̸� list �ֱ�, numberOfPeople�� list�� ����� �ֱ�
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
//namePhoneVector�� ����� numberOfPeople�� txt�� ����
void PhoneBook::Save() {
	ofstream oPhoneBook("phoneBook.txt");
	oPhoneBook << numberOfPeople << endl;
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); iter++) {
		oPhoneBook << *iter << endl;
	}
	oPhoneBook.close();
}

//namePhoneVector�� �̸��� ��ȭ��ȣ�� pair�� �̿��� nameVector�� ����
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
	//namePhoneVector ����
	sort(namePhoneVector.begin(), namePhoneVector.end());

	//nameVector ����

	//sort�� ������ ���Ͽ� �Է�
	ofstream oPhoneBook("phoneBook.txt");
	oPhoneBook << numberOfPeople << endl;
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); ++iter) {
		oPhoneBook << *iter << endl;
	}
	oPhoneBook.close();

}
//namePhoneVector�� file ��ο� ����
void PhoneBook::Erase(string nameToErase, string phoneToErase) {
	int i;
	int count = 0;//��� �������� �˱� ����
	int eraseIndex[100];
	//nameVector���� ���� & namePhoneVector���� ����
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
	//numberOfPeople����
	numberOfPeople -= count;

	//txt���� ����
	Save();

	
}

//namePhoneVector�� file ��ο� �ֱ�, numberOfPeople++�ϱ�
void PhoneBook::Add(string name, string phoneNumber) {
	//txt�� �߰� 
	ofstream oPhoneBook("phoneBook.txt");
	 
	oPhoneBook << ++numberOfPeople << endl;
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); ++iter) {
		oPhoneBook << *iter << endl;
	}
	oPhoneBook << name << ' ' << phoneNumber << endl;
	oPhoneBook.close();
	//nameVector�� �߰� 
	nameVector.push_back(make_pair(name, phoneNumber));
	//namePhoneVector�� �߰�
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
//���� ��������...
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
//������ -1�� ��ȯ, ������ ����ġ�� ��ȯ
//�ִ� ���� �ι� �˻��� 200������ �Ѵ�.
//��Ȯ�� return, numberOfPeople
int* PhoneBook::SearchIndex(string searchingName) {
	string* stack = new string[numberOfPeople];
	int i;
	int nameIndex[200] = { -1 };// -1 0 0 0 0 0 0 0
	//stack ���ο� vector���� �ű�
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
//1��°�� -1�̸� �˻���� ����
//2��° �̻��� 0 �̸� break;
int* PhoneBook::SearchIndex2(string searchingName) {
	string* stack = new string[numberOfPeople];
	int i;
	int nameIndex[200] = { -1 };// -1 0 0 0 0 0 0 0
								//stack ���ο� vector���� �ű�
	for (i = 0, piter = nameVector.begin(); piter != nameVector.end(); ++piter, ++i) {
		stack[i] = piter->first;
	}


	//searching ¦
	/*for (int j = 0, i = 0; i < numberOfPeople; i++) {		
		if (CompareByEachAlp(stack[i], searchingName, stack[i].size, searchingName.size)) {
			nameIndex[j] = i;
			j++;			
		}
	}*/
	return nameIndex;
}

