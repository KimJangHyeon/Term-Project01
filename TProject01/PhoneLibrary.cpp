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
	NameListAndNumberList();
}

//namePhoneVector의 이름과 전화번호를 pair를 이용해 nameVector에 저장
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
	//nameVector.push_back(make_pair(name, phoneNumber));
	//namePhoneVector에 추가
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
//오류 있을지도...
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
//없으면 -1을 반환, 있으면 그위치를 반환
//최대 동일 인물 검색을 200까지로 한다.
//불확실 return, numberOfPeople
int* PhoneBook::SearchIndex(string searchingName) {
	string* stack = new string[numberOfPeople];
	int i, j;
	int nameIndex[200] = { -1 };// -1 0 0 0 0 0 0 0
								//stack 내부에 vector들을 옮김
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

//int, name 형으로
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

	//찾은 번호를 정수화
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
	//searchingNumber은 찾을 숫자
	
	//int형으로 정렬된 pair 
	else {
		return "wrong~!!";
	}

	//phoneVector 에서 searchingNumber을 찾기
	//int를 순서대로 list에 넣기, 대응되는 name넣기
	vector<pair<size_t, string>>::iterator ppiter;
	int* phoneIntList = new int[phoneVector.size()];
	string* nameList = new string[phoneVector.size()];
	int i;
	for (ppiter = phoneVector.begin(), i=0; ppiter != phoneVector.end(); ++ppiter) {
		phoneIntList[i] = ppiter->first;
		nameList[i] = ppiter->second;
	}
	int indexOfName;
	//알고리즘 
	//첫 시작이 '0'인 경우
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
//phone에 갯수 저장
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
	
	// high가 low보다 작아진다면 찾으려는 데이터가 데이터 집합에 없다.
	while (first <= last)
	{
		// 중앙값은 low와 high를 더한 값을 2로 나누면 된다.
		middle = (first + last) / 2;
		// 만약 찾으려는 값이 중앙값보다 작다면 high를 mid - 1로 둔다.
		if ( phoneIntList[middle]> searchingNumber) last = middle - 1;
		// 만약 찾으려는 값이 중앙값보다 크다면 low를 mid + 1로 둔다.
		else if (phoneIntList[middle] < searchingNumber) first = middle + 1;
		// 중앙값과 찾으려는 값이 일치하면 mid를 반환한다.
		else return middle;
	}
	// 데이터를 찾지 못하면 -1를 반환한다.
		return -1;
	
}