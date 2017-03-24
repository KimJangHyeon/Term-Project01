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
	NameListAndNumberList();
}

//namePhoneVector�� �̸��� ��ȭ��ȣ�� pair�� �̿��� nameVector�� ����
void PhoneBook::MakeIntoPair() {
	phoneVector.clear();
	nameVector.clear();
	int findIndex = 0;
	string name, phoneNumber;
	for (iter = namePhoneVector.begin(); iter != namePhoneVector.end(); ++iter) {
		findIndex = iter->find_first_of("0");
		name = iter->substr(0, findIndex - 1);
		phoneNumber	= iter->substr(findIndex, 13);
		nameVector.push_back(make_pair(name, phoneNumber));
	}
	NameNumberPair();
	sort(phoneVector.begin(), phoneVector.end());
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
			//nameVector.erase(nameVector.begin() + i);
			namePhoneVector.erase(namePhoneVector.begin() + i);
			MakeIntoPair();
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
	//nameVector.push_back(make_pair(name, phoneNumber));
	//namePhoneVector�� �߰�
	string input = name + " " + phoneNumber;
	namePhoneVector.push_back(input);
	MakeIntoPair();
}

void PhoneBook::Adjust(string reName, string rePhoneNumber, size_t index) {
	//namePhoneVector
	namePhoneVector.erase(namePhoneVector.begin() + index);
	namePhoneVector.insert(namePhoneVector.begin() + index, reName + " " + rePhoneNumber);
	//txt
	Save();
	//nameVector
	//nameVector.erase(nameVector.begin() + index);
	//nameVector.insert(nameVector.begin() + index, make_pair(reName, rePhoneNumber));
	MakeIntoPair();
}
//���� ��������...
bool PhoneBook::CompareByEachAlp(string name, string searchingName, size_t nameSize, size_t inputSize) {
	bool key = true;
	if (inputSize > nameSize) {
		key = false;
	}
	else {
		for (int i = 0; i < nameSize; i++) {
			if (name[i] != searchingName[i])
				key = false;
		}
	}
	return key;

}
//������ -1�� ��ȯ, ������ ����ġ�� ��ȯ
//�ִ� ���� �ι� �˻��� 200������ �Ѵ�.
//��Ȯ�� return, numberOfPeople
int* PhoneBook::SearchIndex(string searchingName) {
	string* stack = new string[numberOfPeople];
	int i, j;
	int nameIndex[200] = { -1 };// -1 0 0 0 0 0 0 0
								//stack ���ο� vector���� �ű�
	for (i = 0, piter = nameVector.begin(); piter != nameVector.end(); ++piter, ++i) {
		stack[i] = piter->first;
	}



	for (j = 0, i = 0; i < numberOfPeople; i++) {
		if (stack[i] == searchingName) {
			nameIndex[j++] = i;
			nameIndex[j] = -1;
		}
	}
	int count = 0;
	while (nameIndex[count] != -1) {
		count++;
	}
	if (count == 0) {
		return NULL;
	}
	else {
		int *arr = new int[count];
		for (int i = 0; i < count; i++) {
			arr[i] = nameIndex[i];
			cout << arr[i] << endl;
		}
		return arr;
	}

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

//int, name ������
void PhoneBook::NameNumberPair() {

	string frontNumber;
	string backNumber;
	string numberStr;
	char numberChar[8];

	int number;
	for (piter = nameVector.begin(); piter != nameVector.end(); piter++) {
		int findIndex = piter->second.find_first_of("-");
		frontNumber = piter->second.substr(findIndex + 1, 4);
		findIndex = piter->second.find_first_of("-", findIndex + 1);
		backNumber = piter->second.substr(findIndex + 1, 4);
		numberStr = frontNumber + backNumber;
		int count = 0;
		while (numberStr[count] != '0') {
			count++;
		}

		for (int i = 0; i < 8 - count; i++) {
			numberChar[i] = numberStr[count + i];
		}

		number = atoi(numberChar);
		phoneVector.push_back(make_pair(number, piter->first));
	}
}

bool PhoneBook::PhoneNumberFront(string phoneNumber) {
	bool key = true;
	if (phoneNumber[0] != '0') key = false;
	if (phoneNumber[1] != '1') key = false;
	if (phoneNumber[2] != '0') key = false;
	if (phoneNumber[3] != '-') key = false;
	if (phoneNumber[7] != '-') key = false;
	return key;
}

void PhoneBook::NameListAndNumberList() {
	vector<pair<size_t, string>>::iterator ppiter;
	indexOfMin = 0;
	int i;
	for (ppiter = phoneVector.begin(), i = 0; ppiter != phoneVector.end(); ++ppiter,++i) {
		phoneIntList[i] = ppiter->first;
		nameList[i] = ppiter->second;

		if (ppiter->first < 10000000) indexOfMin = i + 1;
		
	}
}

string PhoneBook::SearchByNumber(string phoneNumber) {
	char searchingNumberChar[8];
	int searchingNumber;

	//ã�� ��ȣ�� ����ȭ
	if (PhoneNumberFront(phoneNumber)) {
		int findIndex = phoneNumber.find_first_of("-");
		string frontNumber = phoneNumber.substr(findIndex + 1, 4);
		findIndex = phoneNumber.find_first_of("-", findIndex + 1);
		string backNumber = phoneNumber.substr(findIndex + 1, 4);
		string numberStr = frontNumber + backNumber;
		int count = 0;
		while (numberStr[count] == '0') {
			count++;
		}
		char compareNumberString[8];
		for (int i = 0; i < 8 - count; i++) {
			compareNumberString[i] = numberStr[count + i];
		}
		searchingNumber = atoi(compareNumberString);
	}
	//searchingNumber�� ã�� ����
	
	//int������ ���ĵ� pair 
	else {
		return "wrong~!!";
	}

	//phoneVector ���� searchingNumber�� ã��
	//int�� ������� list�� �ֱ�, �����Ǵ� name�ֱ�
	vector<pair<size_t, string>>::iterator ppiter;
	int* phoneIntList = new int[phoneVector.size()];
	string* nameList = new string[phoneVector.size()];
	int i;
	for (ppiter = phoneVector.begin(), i=0; ppiter != phoneVector.end(); ++ppiter) {
		phoneIntList[i] = ppiter->first;
		nameList[i] = ppiter->second;
	}
	int indexOfName;
	//�˰��� 
	//ù ������ '0'�� ���
	if (searchingNumber < 10000000) {
		int first = 0;
		int last = indexOfMin - 1;
		indexOfName = BinarySearching(first, last, searchingNumber);
	}
	else {
		int first = indexOfMin;
		int last = phoneVector.size() - 1;
		indexOfName = BinarySearching(first, last, searchingNumber);
	}
	if (indexOfName == -1) 
		return "There is no such a number";
	
	else 
		return nameList[indexOfName];
	
}
//phone�� ���� ����
Message::Message() {
	char numberOfPhone[MAXSIZE];
	char numberOfDate[MAXSIZE];
	char numberOfMessage[MAXSIZE];

	ifstream iPhone;
	iPhone.open("Message_phone.txt", std::ifstream::in);
	iPhone.getline(numberOfPhone, MAXSIZE);

	numberOfM = atoi(numberOfPhone);
	for (int i = 0; i < numberOfM; i++) {
		iPhone.getline(numberOfPhone, MAXSIZE);
		phoneNumberVector.push_back(numberOfPhone);
	}
	iPhone.close();

	ifstream iDate;
	iDate.open("Message_date.txt", std::ifstream::in);
	for (int i = 0; i < numberOfM; i++) {
		iDate.getline(numberOfDate, MAXSIZE);
		phoneNumberVector.push_back(numberOfDate);
	}
	iDate.close();

	ifstream iMessage;
	iMessage.open("Message_message.txt", std::ifstream::in);
	for (int i = 0; i < numberOfM; i++) {
		iPhone.getline(numberOfMessage, MAXSIZE);
		phoneNumberVector.push_back(numberOfMessage);
	}
	iMessage.close();
}

void Message::Save() {
	ofstream oPhone("Message_phone.txt");
	oPhone << numberOfM << endl;
	for (iter = phoneNumberVector.begin(); iter != phoneNumberVector.end(); ++iter) {
		oPhone << *iter << endl;
	}
	oPhone.close();
	ofstream oDate("Message_date.txt");
	for (iter = dateVector.begin(); iter != dateVector.end(); ++iter) {
		oDate << *iter << endl;
	}
	oDate.close();
	ofstream oMessage("Message_message.txt");
	for (iter = messageVector.begin(); iter != messageVector.end(); ++iter) {
		oMessage << *iter << endl;
	}
	oMessage.close();
}

string Message::ShowMessage(int index) {
	return messageVector[index];
}

string Message::ShowPhoneNumber(int index) {
	return phoneNumberVector[index];
}

string Message::ShowDate(int index) {
	return messageVector[index];
}

void Message::Add(string date, string phone, string message) {
	phoneNumberVector.push_back(phone);
	dateVector.push_back(date);
	messageVector.push_back(message);
	numberOfM++;
	Save();
}

void Message::Delete(int index) {
	numberOfM--;
	phoneNumberVector.erase(phoneNumberVector.begin() + index);
	dateVector.erase(dateVector.begin() + index);
	messageVector.erase(messageVector.begin() + index);
	Save();
}

int PhoneBook::BinarySearching(int first, int last, int searchingNumber) {
	int middle;
	
	// high�� low���� �۾����ٸ� ã������ �����Ͱ� ������ ���տ� ����.
	while (first <= last)
	{
		// �߾Ӱ��� low�� high�� ���� ���� 2�� ������ �ȴ�.
		middle = (first + last) / 2;
		// ���� ã������ ���� �߾Ӱ����� �۴ٸ� high�� mid - 1�� �д�.
		if ( phoneIntList[middle]> searchingNumber) last = middle - 1;
		// ���� ã������ ���� �߾Ӱ����� ũ�ٸ� low�� mid + 1�� �д�.
		else if (phoneIntList[middle] < searchingNumber) first = middle + 1;
		// �߾Ӱ��� ã������ ���� ��ġ�ϸ� mid�� ��ȯ�Ѵ�.
		else return middle;
	}
	// �����͸� ã�� ���ϸ� -1�� ��ȯ�Ѵ�.
		return -1;
	
}