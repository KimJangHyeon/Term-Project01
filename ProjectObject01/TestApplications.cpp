#include<iostream>
#include"PhoneLibrary.h"

int main() {
	PhoneBook phoneBook;
	phoneBook.MakeIntoPair();
	phoneBook.ShowTxtVector();
	phoneBook.Adjust("�ȳ�", "010-7777-5555", 3);
	phoneBook.ShowTxtVector();
}
