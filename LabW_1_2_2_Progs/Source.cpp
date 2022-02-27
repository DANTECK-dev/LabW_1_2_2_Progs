#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <time.h>
#include <random>

using namespace std;




void firstGeneralTask();
void secondGeneralTask();
void individualTask();
void additionalTask();




int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));

	while (true) {
		std::cout << "\n\t\t����� �������\n\t1. ������� 1\t2. ������� 2\n\n\t3. �������������� ������� 7 �������\n\n\t4. �������������� �������\n\n\t0. �����\n\n\t";
		int inputNum;
		cin >> inputNum;
		std::system("cls");
		switch (inputNum) {
		case(0): {return 0; }
		case(1): {firstGeneralTask();	break; }
		case(2): {secondGeneralTask();	break; }
		case(3): {individualTask();		break; }
		case(4): {additionalTask();		break; }
		default: {std::cout << "\n\t������� �������� ��������, ������� ����� ������� ��� �����������... "; char p = _getch(); std::system("cls"); break; }
		}
		std::system("cls");
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region firstGeneralTask

	/*� ������� ���������� ������ � ������� �������� � ����������� ������ � ������� ��
	������ ���������� ������� ��������� � �����.*/



void firstGeneralTask() {

	struct FIFO_LIFO {
		FIFO_LIFO* next = NULL;
		string field;
	};

	std::cout<<"\n\n\tC������ ����� ��������� ������\n\n\t";
	int structSize;
	cin >> structSize;
	std::system("cls");
	if (structSize == 0){ std::cout << "0 ��������� � ������, ������� ����� ������� ��� ������... "; char p = _getch(); std::system("cls"); return; }
	
	string str;
	std::cout << "\n\n\t������� ������ 1 ��������: ";
	cin >> str;

	FIFO_LIFO* head = NULL;
	head = new FIFO_LIFO;
	head->field = str;
	FIFO_LIFO* pointer = head;

	for (int i = 1; i < structSize; i++) {
		std::cout << "\n\t������� ������ " << i + 1 << " ��������: ";
		cin >> str;
		pointer->next = new FIFO_LIFO; // ������� ����� �������
		pointer = pointer->next;
		pointer->field = str;
	}
	std::system("cls");
	
	
	std::cout << "\n\n\t1.FIFO or 2.LIFO   0.�����\n\n\t";
	int inputNum;
	cin >> inputNum;
	switch (inputNum) {
		case(0):{std::cout << "\n\n\t������� ����� ������� ��� ������... "; char p = _getch(); std::system("cls"); return; }
		case(1):{
			int i = 1;
			pointer = head;
			int Size = 0;
			std::cout << endl;
			while (true) {
				if (pointer->next->next == NULL) {
					std::cout << "\n\t������ " << i+1 << " �������� �� ������: ";
					std::cout << pointer->next->field;
					delete pointer->next;
					pointer->next = NULL;
					pointer = head;
					Size++;
					i = 1;
				}
				else {
					pointer = pointer->next;
					i++;
				}
				if (Size == (structSize-1))break;
			}
			std::cout << "\n\t������ " << i << " �������� �� ������: ";
			std::cout << pointer->field;
			delete pointer;
			break;
		}
		case(2):{
			int i = 1;
			pointer = head;
			std::cout << endl;
			while (pointer != NULL) {
				std::cout << "\n\t������ " << i << " �������� �� ������: ";
				std::cout << pointer->field;
				pointer = pointer->next;
				i++;
			}
			break;
		}
		default: {std::cout << "\n\n\t�������� �������� ��������, ������� ����� ������� ��� ������... "; char p = _getch(); std::system("cls"); return; }
	}

	std::cout << "\n\n\t������� ����� ������� ��� ������... "; char p = _getch(); std::system("cls"); return;
}


#pragma endregion


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region secondGeneralTask

	/*����������� ������ � ���������� �������. ������ ����������� ������� � ������
	���������� ��������. ����� �������� ����������� � ����� ������. ������������ �����
	�������� �������� �� ��������� ��� ���������� ������� ������ (�������� ��������
	������������). ��� ����� �������� ������� �������. ������� �� ��������� ������, ����� ���
	����� �������� �� ����� �� ��� �������.*/

void secondGeneralTask() {

	struct myList {
		myList* next = NULL;
		myList* prev = NULL;
		string field;
	};

	string str;
	std::cout << "\n\n\t������� ������ 1 ��������: ";
	cin >> str;

	myList* head = NULL;
	head = new myList;
	head->field = str;
	myList* pointer = head;
	std::system("cls");
	int counter = 1;

	while (true) {
		cout << "\n\n\t������ ������ "<< counter <<" ������� ������ : " << pointer->field;
		if (pointer->next == NULL)cout << "\n\n\t���������� �������� ���";
		if (pointer->prev == NULL)cout << "\n\n\t����������� �������� ���";
		cout << "\n\n\t1.�������� � ������� � ����� ������.\n\t2.������� ��������� ������� ������\n\t3.������� ���������� ������� ������\n\t0.�����\n\n\t";
		int inputNum;
		cin >> inputNum;
		std::system("cls");
		switch (inputNum) {
			case(0): {std::cout << "\n\n\t������� ����� ������� ��� ������... "; char p = _getch(); std::system("cls"); return; }
			case(1): {
				string str;
				cout << "\n\n\t������� ������ ���������� �������� ������: ";
				cin >> str;
				while (true) {
					if (pointer->next == NULL)break;
					pointer = pointer->next;
					counter++;
				}
				pointer->next = new myList;
				pointer->next->prev = pointer;
				pointer = pointer->next;
				pointer->field = str;
				counter++;
				std::system("cls");
				break;
			}
			case(2): {
				if (pointer->next == NULL) {
					cout << "\n\n\t���������� �������� ���, ������� ����� ������� ��� ������... ";
					char p = _getch();
					std::system("cls");
					continue;
				}
				pointer = pointer->next;
				counter++;
				break;
			}
			case(3): {
				if (pointer->prev == NULL) {
					cout << "\n\n\t������������ �������� ���, ������� ����� ������� ��� ������... ";
					char p = _getch();
					std::system("cls");
					continue;
				}
				pointer = pointer->prev;
				counter--;
				break;
			}
			default:{std::cout << "\n\n\t�������� �������� ��������, ������� ����� ������� ��� ������... "; char p = _getch(); std::system("cls"); continue;}
		}
		std::system("cls");
	}
	std::cout << "\n\n\t������� ����� ������� ��� ������... "; char p = _getch(); std::system("cls"); return;
}


#pragma endregion


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region individualTask


struct person {
	person* next = NULL;
	person* prev = NULL;
	struct {
		string	Surname = { "None" };
		string	Name = { "None" };
		string	Patronymic = { "None" };
		string	Address = { "None" };
		string	PhoneNum = { "None" };
		string	PayDay = { "None" };
		int 	Summ = 0;
	}Data;
};

void fillClients(person* head, person* clients, int* counter);

void addClients(person* head, person* clients, int* counter);
void sortClients(person* head, person* clients, int* counter);
void transformClients(person* head, person* clients, int* counter);
void delClients(person* head, person* clients, int* counter);
void showClients(person* head, person* clients, int* counter);
void searchClients(person* head, person* clients, int* counter);
//void selectionClients	(person* clients, int* counter);


void individualTask() {										//<<<<--------main ��������������� �������

	/*��������� ������������: ���� �������; ���; �������� �����; ����� ��������; �����
	�������. ����������� �������� � ����� ����� �������.
	*/

	/*1) �������� ������ �������� ������� �������� (���� ��� ������);
	2) ���������� ������� ��������;
	3) ��������� �������� ��������� (�������� ����� �������� � ������� ��������, � ���
	������ ���������� �� ����� ��������� ������������� ������);
	4) �������� ��������� �� ������� (����� ���������� �������� ������� ���������
	�������� ���������� �������� � ��������� ���������� ��������� � ������� ��������);
	5) ����� �� ����� ������� �������� � ���� �������. ����� �������� �����������
	�������� �� ����� �������, ��������� � ����� ��������.
	6) ����� � ������� �������� �� ��������� ��������� (�������������� �������� ����
	��������� � ���������� ����� �� ����). �� ���� ��� �����, �� ������ ������������ ������.*/


	person* head = NULL;
	head = new person;
	person* clients = head;
	int* counter = new int;
	*counter = 0;

	std::system("cls");

	fillClients(head, clients, counter);

	///////	   ����    /////////

	while (true) {
		std::cout << "\n\t   ___ ___     ______    __  ___     __    __";
		std::cout << "\n\t /' __` __`\\  /\\  ___\\  /\\ \\/ __`\\  /\\ \\  /  \\";
		std::cout << "\n\t /\\ \\/\\ \\/\\ \\ \\ \\  ___\\ \\ \\  /_ \\ \\ \\ \\ \\/ /\\ \\";
		std::cout << "\n\t \\ \\_\\ \\_\\ \\ \\ \\ \\_____\\ \\ \\_\\ \\ \\_\\ \\ \\__/\\ \\_\\";
		std::cout << "\n\t  \\/_/\\/_/\\/_/  \\/_____/  \\/_/  \\/_/  \\/__/ \\/_/\n";
		std::cout << "\n\t  ----== ������� ����� ������� �������� ==----  ";
		std::cout << "\n\t       ----== 1. ��������  ������� ==----       ";
		std::cout << "\n\t   ----== 2. ����������� ���� �������� ==----   ";
		std::cout << "\n\t    ----== 3. �������� ������ ������� ==----    ";
		std::cout << "\n\t    ----== 4. �������  ������ ������� ==----    ";
		std::cout << "\n\t    ----== 5. ������� ������ �������� ==----    ";
		std::cout << "\n\t     ----== 6. ����� ������� �� ���� ==----     ";
		std::cout << "\n\t              ----== 0.  ����� ==----           \n\t";
		int inputNum;
		std::cin >> inputNum;
		std::system("cls");
		switch (inputNum) {
			case(0): {std::cout << "\n\thead, �����\n"; return; }
			case(1): {addClients		(head, clients, counter); break; }
			case(2): {sortClients		(head, clients, counter); break; }
			case(3): {transformClients	(head, clients, counter); break; }
			case(4): {delClients		(head, clients, counter); break; }
			case(5): {showClients		(head, clients, counter); break; }
			case(6): {searchClients		(head, clients, counter); break; }
			default: {std::cout << "\n\t������� �������� ��������, ������� ����� ������� ��� �����������... "; char p = _getch(); std::system("cls"); break; }
		}
	}
}
//finished

void fillClients(person* head, person* clients, int* counter) {
	string surnames[10] = { "Wallace",	"��������", "����������",	"������",		"����������",	"Brandon",	"���������",	"������",		"���������",		"��������" };
	string names[10] = { "Carter",		"�����",	"����",			"���������",	"�����",		"Rose",		"�����",		"����",			"������",			"����" };
	string Patronymics[10] = { "None",		"��������",	"���������",	"����������",	"����������",	"None",		"���������",	"���������",	"��������������",	"����������", };
	string Address[10] = {
		"3959 Wyatt Street, West Palm Beach, Florida",
		"447191, ����������� �������, ����� ���������� �����, ����� ������, 92",
		"737989, �������� �������, ����� ���������, ������� 1905 ����, 22",
		"434586, ����������� �������, ����� �������, ������ ��������, 59",
		"337525, ��������� �������, ����� �����, ���. �������������, 97",
		"3850 Cedarstone Drive, Toledo, Ohio",
		"107943, �������� �������, ����� �������, ������� �����, 64",
		"314032, ��������������� �������, ����� �������, ����� �����������, 85",
		"038819, ������� �������, ����� ����, ������� �������, 27",
		"139377, ��������� �������, ����� ����-�������, ����� �����, 43", };
	string PhoneNums[10] = { "+18005553535",	"+78652158365",	"+78664788078",	"+78027969659",	"+78895542709",	"+18655790207",	"+78032538250",	"+78253336952",	"+78412045196",	"+78003477306" };
	string PayDays[10] = { "29.03.2021",		"27.02.2021",	"03.04.2021",	"01.02.2022",	"14.12.2021",	"23.11.2021",	"09.06.2021",	"22.05.2021",	"01.02.2021",	"05.12.2021", };
	int Summs[10] = { 10333,			20419,			9103,			23374,			1826,			2873,			7059,			5318,			20832,			7256, };

	clients->Data.Surname = surnames[0];
	clients->Data.Name = names[0];
	clients->Data.Patronymic = Patronymics[0];
	clients->Data.Address = Address[0];
	clients->Data.PhoneNum = PhoneNums[0];
	clients->Data.PayDay = PayDays[0];
	clients->Data.Summ = Summs[0];
	(*counter)++;

	for (int i = 1; i < 10; i++) {
		clients->next = new person;
		clients->next->prev = clients;
		clients = clients->next;
		clients->Data.Surname = surnames[i];
		clients->Data.Name = names[i];
		clients->Data.Patronymic = Patronymics[i];
		clients->Data.Address = Address[i];
		clients->Data.PhoneNum = PhoneNums[i];
		clients->Data.PayDay = PayDays[i];
		clients->Data.Summ = Summs[i];
		(*counter)++;
	}
}
//finished

void addClients(person* head, person* clients, int* counter) {
	std::cout << "\n\n\t���������� �������\n";
	string	newSurname = { "None" };
	string	newName = { "None" };
	string	newPatronymic = { "None" };
	string	newAddress = { "None" };
	string	newPhoneNum = { "None" };
	string	newPayDay = { "None" };
	int		newSumm = 0;

	std::cout << "\n\t������� ������ �������\n";
	std::cout << "\n\t�������: "; 	cin.get();		std::getline(cin, newSurname);
	std::cout << "\n\t���: ";						std::getline(cin, newName);
	std::cout << "\n\t��������: ";					std::getline(cin, newPatronymic);
	std::cout << "\n\t������: ";					std::getline(cin, newAddress);
	std::cout << "\n\t����� �������� (��� +7): ";	std::getline(cin, newPhoneNum);
	std::cout << "\n\t���� ������ (��.��.����): ";	std::getline(cin, newPayDay);
	std::cout << "\n\t����� �������: ";				cin >> newSumm;
	std::system("cls");

	while (true) {
		if (clients->next == NULL) break;
		clients = clients->next;
	}
	clients->next				= new person;
	clients->next->prev			= clients;
	clients						= clients->next;
	clients->Data.Surname		= newSurname;
	clients->Data.Name			= newName;
	clients->Data.Patronymic	= newPatronymic;
	clients->Data.Address		= newAddress;
	clients->Data.PhoneNum		= "+7" + newPhoneNum;
	clients->Data.PayDay		= newPayDay;
	clients->Data.Summ			= newSumm;

	(*counter)++;

	std::cout	<< "\n\t�������� \n"		<< "\n\t�������: "	<< newSurname
				<< "\n\t���: "				<< newName			<< "\n\t��������: "			<< newPatronymic
				<< "\n\t������: "			<< newAddress		<< "\n\t����� ��������: +7" << newPhoneNum
				<< "\n\t���� ������: "		<< newPayDay		<< "\n\t����� �������: "	<< newSumm;

	std::cout << "\n\n\t������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls");
	std::system("cls");
};
//finished

void sortClients(person* head, person* clients, int* counter) {

	std::cout << "\n\t����������� ���� �������� ��\n";
	std::cout << "\n\t1. �������\t2. ���\t0.�����\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
	switch (inputNum) {
		case(0): {std::cout << "\n\n\t�����"; std::system("cls"); return; }
		case(1): {
			for (int i = 1; i < *counter; i++) {
				clients = head;
				for (int j = 0; j < (*counter) - i; j++) {
					if (clients->Data.Surname > clients->next->Data.Surname) {
						clients->Data = clients->next->Data;
					}
					clients = clients->next;
				}
			}
			std::cout << "\n\n\t���������� �� ������� ���������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return;
		}
		case(2): {
			for (int i = 1; i < *counter; i++) {
				clients = head;
				for (int j = 0; j < (*counter) - i; j++) {
					if (clients->Data.Name > clients->next->Data.Name) {
						clients->Data = clients->next->Data;
					}
					clients = clients->next;
				}
			}
			std::cout << "\n\n\t���������� �� ����� ���������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return;
		}
		default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); break; }
	}
	std::system("cls");
}
//finished

void transform(person* head, person* clients, int* counter) {
	std::cout << "\n\n\t����� ������ ��������\n"
		<< "\n\t1. ������� - "				<< clients->Data.Surname
		<< "\n\t2. ��� - "					<< clients->Data.Name
		<< "\n\t3. �������� - "				<< clients->Data.Patronymic
		<< "\n\t4. ������ - "				<< clients->Data.Address
		<< "\n\t5. ���������� ����� - "		<< clients->Data.PhoneNum
		<< "\n\t6. ���� ������ - "			<< clients->Data.PayDay
		<< "\n\t7. ����� - "				<< clients->Data.Summ
		<< "\n\t0. �����\n\n\t";
	int InInt;
	cin >> InInt;
	switch (InInt) {
	case(0): {break; }
	case(1): {std::cout << "\n\n\t������� �������: ";		cin.get(); getline(cin, clients->Data.Surname); 	break; }
	case(2): {std::cout << "\n\n\t������� ���: ";			cin.get(); getline(cin, clients->Data.Name); 		break; }
	case(3): {std::cout << "\n\n\t������� ��������: ";		cin.get(); getline(cin, clients->Data.Patronymic);	break; }
	case(4): {std::cout << "\n\n\t������� ������: ";		cin.get(); getline(cin, clients->Data.Address); 	break; }
	case(5): {std::cout << "\n\n\t������� ����������: ";	cin.get(); getline(cin, clients->Data.PhoneNum); 	break; }
	case(6): {std::cout << "\n\n\t������� ����: ";			cin.get(); getline(cin, clients->Data.PayDay);		break; }
	case(7): {std::cout << "\n\n\t������� �����: ";			cin.get();		   cin >> clients->Data.Summ;		break; }
	default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls");	  break; }
	}
	std::system("cls");
}
void transformClients(person* head, person* clients, int* counter) {
	std::cout << "\n\n\t�������� ������ �������\n\n\t\t����� �� \n\n\t1. ���\t2. ����� � ����\t0. �����\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
	clients = head;
	switch (inputNum) {
	case(0): {std::cout << "\n\n\t�����"; std::system("cls"); return; }
	case(1): {
		std::cout << "\n\n\t������� ������� ��� ��� ��� ��������. 0. �����\n\n\t";
		string inputStr;
		cin >> inputStr;
		std::system("cls");
		if (inputStr == "0") { return; }
		int searchID = -1;
		int couErr = 0;
		int id = 1;
		while(true){
			if (clients->next == NULL)break;
			if (inputStr == clients->Data.Surname)		{ searchID = id; couErr++; }
			if (inputStr == clients->Data.Name)			{ searchID = id; couErr++; }
			if (inputStr == clients->Data.Patronymic)	{ searchID = id; couErr++; }
			clients = clients->next;
			id++;
		}
		if (couErr > 1) { std::cout << "\n\n\t������� ����� ������ �������, ������� ������ ������� �������. ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return; }
		if (searchID == -1) { std::cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); std::system("cls"); return; }
		if (searchID >= 0) {
			clients = head;
			for (int i = 0; i < searchID-1; i++) {
				clients = clients->next;
			}
			std::cout << "\n\n\t�������� ������ ������� " << clients->Data.Surname << " " << clients->Data.Name
				<< " " << clients->Data.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
			int inputH;
			cin >> inputH;
			std::system("cls");
			switch (inputH) {
			case(1): {transform(head, clients, counter); return; }
			case(2): { return; }
			default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return; }
			}
		}
	}
	case(2): {
		std::cout << "\n\n\t������� ����� � ����. 0. �����\n\n\t";
		int inputInt;
		cin >> inputInt;
		if (inputInt == 0) { std::system("cls"); return; }
		for (int i = 0; i < inputInt-1; i++) {
			clients = clients->next;
		}
		std::system("cls");
		std::cout << "\n\n\t�������� ������ ������� " << clients->Data.Surname << " " << clients->Data.Name
			<< " " << clients->Data.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
		int inP;
		cin >> inP;
		std::system("cls");
		switch (inP) {
		case(1): {transform(head, clients, counter); return; }
		case(2): { return; }
		default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return; }
		}
	}
	default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return; }
	}

	std::system("cls");
}
//finished

void swapAndDelClients(person* head, person* clients, int* counter) {
	if (clients->prev != nullptr && clients->next != nullptr) {
		person* del = clients;
		clients = clients->prev;
		clients->next = clients->next->next;
		clients->next->prev = clients;
		delete *&del;
	}
	if (clients == head) {
		clients = clients->next;
		delete *&clients->prev;
		clients->prev = NULL;
		head = clients->next;
	}
	if (clients->prev != nullptr && clients->next == nullptr) {
		clients = clients->prev;
		delete *&clients->next;
		clients->next = nullptr;
	}
	if (clients->prev == nullptr && clients->next == nullptr) delete *&clients;
	(*counter)--;
}
void delClients(person* head, person* clients, int* counter) {
	std::cout << "\n\t������� ������ �������\n\n\t\t����� �� \n\n\t1. ���\t2. ����� � ����\t0. �����\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
	clients = head;
	switch (inputNum) {
	case(0): {std::cout << "\n\n\t�����"; std::system("cls"); return; }
	case(1): {
		std::cout << "\n\n\t������� ������� ��� ��� ��� ��������. 0. �����\n\n\t";
		string inputStr;
		cin >> inputStr;
		std::system("cls");
		if (inputStr == "0") { return; }
		int id = 1;
		int searchID = -1;
		int couErr = 0;
		while (true){
			if (clients->next == NULL)break;
			if (inputStr == clients->Data.Surname)		{ searchID = id; couErr++; }
			if (inputStr == clients->Data.Name)			{ searchID = id; couErr++; }
			if (inputStr == clients->Data.Patronymic)	{ searchID = id; couErr++; }
			clients = clients->next;
			id++;
		}
		if (couErr > 1) { std::cout << "\n\n\t������� ����� ������ �������, ������� ������ ������� �������. ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return; }
		if (searchID == -1) { std::cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); std::system("cls"); return; }
		if (searchID >= 0) {
			clients = head;
			for (int i = 0; i < searchID-1; i++) {
				clients = clients->next;
			}
			std::cout << "\n\n\t������� ������ ������� " << clients->Data.Surname << " " << clients->Data.Name
				<< " " << clients->Data.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
			int inputH;
			cin >> inputH;
			std::system("cls");
			switch (inputH) {
			case(1): {swapAndDelClients(head, clients, counter);
				std::cout << "\n\n\t������� �������, ������� ����� ������� ��� ������ � ����... "; char p = _getch(); std::system("cls"); return;
			}
			case(2): { return; }
			default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return; }
			}
		}
	}
	case(2): {
		std::cout << "\n\n\t������� ����� � ����. 0. �����\n\n\t";
		int inputInt;
		cin >> inputInt;
		if (inputInt == 0)return;
		for (int i = 0; i < inputInt - 1; i++) {
			clients = clients->next;
		}
		std::system("cls");
		std::cout << "\n\n\t������� ������ ������� " << clients->Data.Surname << " " << clients->Data.Name
			<< " " << clients->Data.Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
		int inP;
		cin >> inP;
		std::system("cls");
		switch (inP) {
		case(1): {swapAndDelClients(head, clients, counter);
			std::cout << "\n\n\t������� �������, ������� ����� ������� ��� ������ � ����... "; char p = _getch(); std::system("cls"); return;
		}
		case(2): { return; }
		default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return; }
		}
	}
	default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return; }
	}

	std::system("cls");
}


void showClients(person* head, person* clients, int* counter) {
	std::cout << "\n\n\t������� ������ ��������\n\n";

	int maxLenSurname = 7;
	int maxLenName = 3;
	int maxLenPatronymic = 8;
	int maxLenAddress = 15;
	int maxLenPhoneNum = 16;
	int maxLenPayDay = 11;
	int maxLenSumm = 13;

	//int LenSurname;
	//int LenName;
	//int LenPatronymic;
	//int LenAddress;
	//int LenPhoneNum;
	//int LenPayDay;
	//int LenSumm;

	int maxSumm = 0;

	for (int i = 0; i < *counter; i++) {
		int LenSurname		= clients->Data.Surname.length();
		int LenName			= clients->Data.Name.length();
		int LenPatronymic	= clients->Data.Patronymic.length();
		int LenAddress		= clients->Data.Address.length();
		int LenPhoneNum		= clients->Data.PhoneNum.length();
		int LenPayDay		= clients->Data.PayDay.length();
		int LenSumm			= 0;
		int Summ			= clients->Data.Summ;
		int g				= 0;
		while (Summ > 0) { Summ /= 10; LenSumm++; }
		maxSumm += clients->Data.Summ;

		if (LenSurname > maxLenSurname) { maxLenSurname = LenSurname; }
		if (LenName > maxLenName) { maxLenName = LenName; }
		if (LenPatronymic > maxLenPatronymic) { maxLenPatronymic = LenPatronymic; }
		if (LenAddress > maxLenAddress) { maxLenAddress = LenAddress; }
		if (LenPhoneNum > maxLenPhoneNum) { maxLenPhoneNum = LenPhoneNum; }
		if (LenPayDay > maxLenPayDay) { maxLenPayDay = LenPayDay; }
		if (LenSumm > maxLenSumm) { maxLenSumm = LenSumm; }
	}

	int maxLength = maxLenSurname + maxLenName + maxLenPatronymic + maxLenAddress + maxLenPhoneNum + maxLenPayDay + maxLenSumm + 22;



	std::cout << "\t";
	for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
	std::cout << endl;

	printf_s("\t| %*s | %*s | %*s | %*s | %*s | %*s | %*s |",
		maxLenSurname, "�������",
		maxLenName, "���",
		maxLenPatronymic, "��������",
		maxLenAddress, "�������� ������",
		maxLenPhoneNum, "���������� �����",
		maxLenPayDay, "���� ������",
		maxLenSumm, "����� �������");
	std::cout << "\n\t";

	for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
	std::cout << "\n";

	for (int i = 0; i < *counter; i++) {
		printf_s(
			"\t| %*s | %*s | %*s | %*s | %*s | %*s | %*d |",
			maxLenSurname, clients->Data.Surname.c_str(),
			maxLenName, clients->Data.Name.c_str(),
			maxLenPatronymic, clients->Data.Patronymic.c_str(),
			maxLenAddress, clients->Data.Address.c_str(),
			maxLenPhoneNum, clients->Data.PhoneNum.c_str(),
			maxLenPayDay, clients->Data.PayDay.c_str(),
			maxLenSumm, clients->Data.Summ
		);

		std::cout << "\n\t";

		for (int i = 0; i < maxLength; i++) { std::cout << "-"; }
		std::cout << endl;

	}
	std::cout << "\t";
	for (int i = 0; i < maxLength - (maxLenPayDay + 6); i++) { std::cout << " "; }
	printf_s("| %*d |", maxLenSumm, maxSumm); std::cout << "\n\t";
	for (int i = 0; i < maxLength - (maxLenPayDay + 6); i++) { std::cout << " "; }
	for (int i = 0; i < maxLenPayDay + 6; i++) { std::cout << "-"; }


	std::cout << "\n\t������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls");
	std::system("cls");
}
 

void show(person* head, person* clients, int* counter, int searchID) {
	std::cout << "\n\n\t���: " << clients->Data.Surname << " " << clients->Data.Name << " " << clients->Data.Patronymic << " ������: "
		<< clients->Data.Address << "\n\t��������� �����: " << clients->Data.PhoneNum << " ���� ������: " << clients->Data.PayDay << " �����: " << clients->Data.Summ;
}
void searchClients(person* head, person* clients, int* counter) {
	std::cout << "\n\t����� ������� �� ����";
	std::cout << "\n\n\t������� ������� ��� ��� ��� ��������\t0. �����\n\n\t";
	string inputStr;
	cin >> inputStr;
	std::system("cls");
	if (inputStr == "0") { return; }

	int searchID = -1;
	for (int i = 0; i < *counter; i++) {
		if (inputStr == clients->Data.Surname)		{ searchID = i; show(head, clients, counter, searchID); }
		if (inputStr == clients->Data.Name)			{ searchID = i; show(head, clients, counter, searchID); }
		if (inputStr == clients->Data.Patronymic)	{ searchID = i; show(head, clients, counter, searchID); }
	}
	if (searchID >= 0) { std::cout << "\n\n\t������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); std::system("cls");  return; }
	if (searchID == -1) { std::cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); std::system("cls"); return; }
	std::system("cls");
}


/*void swapSelectionClients(person* clients, int* counter, int couA, int i) {
	//for (int i = searchID; i < *counter; i++) {
		clients[i].Surname		= clients[i++].Surname;
		clients[i].Name			= clients[i++].Name;
		clients[i].Patronymic	= clients[i++].Patronymic;
		clients[i].Address		= clients[i++].Address;
		clients[i].PhoneNum		= clients[i++].PhoneNum;
		clients[i].PayDay		= clients[i++].PayDay;
		clients[i].Summ			= clients[i++].Summ;
	//}
		couA++;
}
void selectionClients(person* clients, int* counter) {
	std::cout << "\n\n\t������� �����: ";
	int summ;
	cin >> summ;
	std::system("cls");
	std::cout << "\n\n\t����� �������� � ������� ����� \n\n\t1. ������  ���  2. ������ ��������\n\n\t0. �����\n\n\t";
	int inputInt;
	cin >> inputInt;
	int couA = 0;
	std::system("cls");
	switch (inputInt) {
	case(0): {return; }
	case(1): {
		for (int i = 1; i < *counter; i++) {
			for (int j = 0; j < (*counter) - i; j++) {
				if (inputInt > clients[i].Summ) {
					swapSelectionClients(clients, counter, couA, i);
				}
			}
		}
		*counter = (*counter) - couA;
		std::cout << "\n\n\t������, ������� ����� ������� ��� ������ � ����... "; char p =_getch(); std::system("cls");
		return; }
	case(2): {
		for (int i = 1; i < *counter; i++) {
			for (int j = 0; j < (*counter) - i; j++) {
				if (inputInt < clients[i].Summ) {
					swapSelectionClients(clients, counter, couA, i);
				}
			}
		}
		*counter = (*counter) - couA;
		std::cout << "\n\n\t������, ������� ����� ������� ��� ������ � ����... "; char p =_getch(); std::system("cls");
		return; }
	default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p =_getch(); std::system("cls"); return; }
	}
}*/


#pragma endregion


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region additionalTask


#define SIZE 10
struct MyStruct {
	int Type;
	union {
		int	x[SIZE];
		char c[SIZE];
	}TypeUnion;
}TypeStruct;

void additionalTask() {
	/*�������� ���������� ��������� (��������� � ������������ � �������� ��������),
	�������������� ����� ������������� ������, ������� ����� ���� ����������� ��� ������
	����� ����� ��� ������. ������ ��������� �������� ����������-����� (����), �������
	������� � ���, ������ ���� ������ ������ � ���������� ���������.
	����������������� ������ ������ ������ ���������. ������������ ������ ��� �������,
	��� �������� � ��������� ������ ���������. ����� ������ �������� ������ ������� �� �����.*/
	std::cout << "\n\n\t������� ���, ������� ����� ������� � ������, � ���� \n\n\t1. �����     2. ����     0. �����\n\n\t";
	cin >> TypeStruct.Type;
	std::system("cls");
	switch (TypeStruct.Type) {
	case(0):return;
	case(1): {
		std::cout << "\n\n\t���� �����\n\n";
		for (int i = 0; i < SIZE; i++) {
			std::cout << "\t������� " << i + 1 << " �����: ";
			cin >> TypeStruct.TypeUnion.x[i];
		}
		std::system("cls");
		std::cout << "\n\n\t�� �����: ";
		for (int i = 0; i < SIZE; i++) {
			std::cout << TypeStruct.TypeUnion.x[i] << " ";
		}
		std::cout << "\n\n\t��� ������, ������� ����� �������... "; char p = _getch(); std::system("cls");
		return;
	}
	case(2): {
		std::cout << "\n\n\t���� ����\n\n";
		for (int i = 0; i < SIZE; i++) {
			std::cout << "\t������� " << i + 1 << " �����: ";
			cin >> TypeStruct.TypeUnion.c[i];
		}
		std::system("cls");
		std::cout << "\n\n\t�� �����: ";
		for (int i = 0; i < SIZE; i++) {
			std::cout << TypeStruct.TypeUnion.c[i];
		}
		std::cout << "\n\n\t��� ������, ������� ����� �������... "; char p = _getch(); std::system("cls");
		return;
	}
	default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� �������, ����� �������� ������ ���... "; char p = _getch(); std::system("cls"); break; }
	}
	if (TypeStruct.Type > 2 || TypeStruct.Type < 0) { std::cout << "\n\n\t������� �������� ��������, ������� ����� �������, ����� �������� ������ ���... "; char p = _getch(); std::system("cls"); return; }
	if (TypeStruct.Type == 0) { return; }

}



#pragma endregion


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////