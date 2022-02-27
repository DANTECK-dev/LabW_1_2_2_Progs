#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <algorithm>
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

struct myList {
	myList* next = NULL;
	string field;
};

void firstGeneralTask() {
	std::cout<<"\n\n\tC������ ����� ��������� ������\n\n\t";
	int structSize;
	cin >> structSize;
	std::system("cls");
	if (structSize == 0){ std::cout << "0 ��������� � ������, ������� ����� ������� ��� ������... "; char p = _getch(); std::system("cls"); return; }
	
	string str;
	std::cout << "\n\n\t������� ������ 1 ��������: ";
	cin >> str;

	myList* head = NULL;
	head = new myList;
	head->field = str;
	myList* pointer = head;

	for (int i = 1; i < structSize; i++) {
		std::cout << "\n\t������� ������ " << i + 1 << " ��������: ";
		cin >> str;
		pointer->next = new myList; // ������� ����� �������
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

struct myList {
	myList* next = NULL;
	myList* prev = NULL;
	string field;
};

void secondGeneralTask() {
	string str;
	std::cout << "\n\n\t������� ������ 1 ��������: ";
	cin >> str;

	myList* head = NULL;
	head = new myList;
	head->field = str;
	myList* pointer = head;
}


#pragma endregion


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#pragma region individualTask


struct person {
	string	Surname = { "None" };
	string	Name = { "None" };
	string	Patronymic = { "None" };
	string	Address = { "None" };
	string	PhoneNum = { "None" };
	string	PayDay = { "None" };
	int 	Summ = 0;
};

void fillClients(person* clients, int* counter);

void addClients(person* clients, int* counter);
void sortClients(person* clients, int* counter);
void transformClients(person* clients, int* counter);
void delClients(person* clients, int* counter);
void showClients(person* clients, int* counter);
void searchClients(person* clients, int* counter);
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

	int maxSize;
	std::system("cls");
	std::cout << "\n\t������� ������������ ���������� ��������: ";
	cin >> maxSize;
	int* counter = new int;
	*counter = 0;
	person* clients = new person[maxSize];
	std::system("cls");

	fillClients(clients, counter);


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
		//std::cout << "\n\t   ----== 7. ������� �������� �� ����� ==----   ";
		std::cout << "\n\t              ----== 0.  ����� ==----           \n\t";
		int inputNum;
		std::cin >> inputNum;
		std::system("cls");
		switch (inputNum) {
		case(0): {std::cout << "\n\t�����\n"; return; }
		case(1): {addClients(clients, counter); break; }
		case(2): {sortClients(clients, counter); break; }
		case(3): {transformClients(clients, counter); break; }
		case(4): {delClients(clients, counter); break; }
		case(5): {showClients(clients, counter); break; }
		case(6): {searchClients(clients, counter); break; }
			   //case(7): {selectionClients	(clients, counter); break; }
		default: {std::cout << "\n\t������� �������� ��������, ������� ����� ������� ��� �����������... "; char p = _getch(); std::system("cls"); break; }
		}
	}
}

void fillClients(person* clients, int* counter) {
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

	for (int i = 0; i < 10; i++) {
		clients[*counter].Surname = surnames[i];
		clients[*counter].Name = names[i];
		clients[*counter].Patronymic = Patronymics[i];
		clients[*counter].Address = Address[i];
		clients[*counter].PhoneNum = PhoneNums[i];
		clients[*counter].PayDay = PayDays[i];
		clients[*counter].Summ = Summs[i];
		(*counter)++;
	}
}
//finished

void addClients(person* clients, int* counter) {
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

	clients[*counter].Surname = newSurname;
	clients[*counter].Name = newName;
	clients[*counter].Patronymic = newPatronymic;
	clients[*counter].Address = newAddress;
	clients[*counter].PhoneNum = "+7" + newPhoneNum;
	clients[*counter].PayDay = newPayDay;
	clients[*counter].Summ = newSumm;

	(*counter)++;

	std::cout << "\n\t�������� \n" << "\n\t�������: " << newSurname
		<< "\n\t���: " << newName << "\n\t��������: " << newPatronymic
		<< "\n\t������: " << newAddress << "\n\t����� ��������: +7" << newPhoneNum
		<< "\n\t���� ������: " << newPayDay << "\n\t����� �������: " << newSumm;

	std::cout << "\n\n\t������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls");
	std::system("cls");
};
//finished

void swapClients(person* clients, int* counter, int j) {
	string temp = clients[j].Patronymic;
	clients[j].Patronymic = clients[j + 1].Patronymic;
	clients[j + 1].Patronymic = temp;
	temp = clients[j].Name;
	clients[j].Name = clients[j + 1].Name;
	clients[j + 1].Name = temp;
	temp = clients[j].Surname;
	clients[j].Surname = clients[j + 1].Surname;
	clients[j + 1].Surname = temp;
	temp = clients[j].Address;
	clients[j].Address = clients[j + 1].Address;
	clients[j + 1].Address = temp;
	temp = clients[j].PhoneNum;
	clients[j].PhoneNum = clients[j + 1].PhoneNum;
	clients[j + 1].PhoneNum = temp;
	temp = clients[j].PayDay;
	clients[j].PayDay = clients[j + 1].PayDay;
	clients[j + 1].PayDay = temp;
	int tempInt = clients[j].Summ;
	clients[j].Summ = clients[j + 1].Summ;
	clients[j + 1].Summ = tempInt;
}
void sortClients(person* clients, int* counter) {



	if (*counter == 1) {
		std::cout << "\n\n\t� ���� ����� ���� ���� ������, ����������� ������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return;
	}
	std::cout << "\n\t����������� ���� �������� ��\n";
	std::cout << "\n\t1. �������\t2. ���\t0.�����\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
	switch (inputNum) {
	case(0): {std::cout << "\n\n\t�����"; std::system("cls"); return; }
	case(1): {
		for (int i = 1; i < *counter; i++) {
			for (int j = 0; j < (*counter) - i; j++) {
				if (clients[j].Surname > clients[j + 1].Surname) {
					swapClients(clients, counter, j);
				}
			}
		}
		std::cout << "\n\n\t���������� �� ������� ���������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return;
	}
	case(2): {
		for (int i = 1; i < *counter; i++) {
			for (int j = 0; j < (*counter) - i; j++) {
				if (clients[j].Name > clients[j + 1].Name) {
					swapClients(clients, counter, j);
				}
			}
		}
		std::cout << "\n\n\t���������� �� ����� ���������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return;
	}
	default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); break; }
	}

	std::system("cls");
}
//finished

void transform(person* clients, int* counter, int searchID) {
	std::cout << "\n\n\t����� ������ ��������\n"
		<< "\n\t1. ������� - " << clients[searchID].Surname
		<< "\n\t2. ��� - " << clients[searchID].Name
		<< "\n\t3. �������� - " << clients[searchID].Patronymic
		<< "\n\t4. ������ - " << clients[searchID].Address
		<< "\n\t5. ���������� ����� - " << clients[searchID].PhoneNum
		<< "\n\t6. ���� ������ - " << clients[searchID].PayDay
		<< "\n\t7. ����� - " << clients[searchID].Summ
		<< "\n\t0. �����\n\n\t";
	int InInt;
	cin >> InInt;
	switch (InInt) {
	case(0): {break; }
	case(1): {std::cout << "\n\n\t������� �������: ";	string temp; cin.get(); getline(cin, temp); clients[searchID].Surname = temp; break; }
	case(2): {std::cout << "\n\n\t������� ���: ";		string temp; cin.get(); getline(cin, temp); clients[searchID].Name = temp; break; }
	case(3): {std::cout << "\n\n\t������� ��������: ";	string temp; cin.get(); getline(cin, temp); clients[searchID].Patronymic = temp; break; }
	case(4): {std::cout << "\n\n\t������� ������: ";		string temp; cin.get(); getline(cin, temp); clients[searchID].Address = temp; break; }
	case(5): {std::cout << "\n\n\t������� ����������: ";	string temp; cin.get(); getline(cin, temp); clients[searchID].PhoneNum = temp; break; }
	case(6): {std::cout << "\n\n\t������� ����: ";		string temp; cin.get(); getline(cin, temp); clients[searchID].PayDay = temp; break; }
	case(7): {std::cout << "\n\n\t������� �����: ";		int	   temp; cin.get();			cin >> temp; clients[searchID].Summ = temp; break; }
	default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls");	  break; }
	}
	std::system("cls");
}
void transformClients(person* clients, int* counter) {
	std::cout << "\n\n\t�������� ������ �������\n\n\t\t����� �� \n\n\t1. ���\t2. ����� � ����\t0. �����\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
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
		for (int i = 0; i < *counter; i++) {
			if (inputStr == clients[i].Surname) { searchID = i; couErr++; }
			if (inputStr == clients[i].Name) { searchID = i; couErr++; }
			if (inputStr == clients[i].Patronymic) { searchID = i; couErr++; }
		}

		if (couErr > 1) { std::cout << "\n\n\t������� ����� ������ �������, ������� ������ ������� �������. ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return; }
		if (searchID == -1) { std::cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); std::system("cls"); return; }
		if (searchID >= 0) {
			std::cout << "\n\n\t�������� ������ ������� " << clients[searchID].Surname << " " << clients[searchID].Name
				<< " " << clients[searchID].Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
			int inputH;
			cin >> inputH;
			std::system("cls");
			switch (inputH) {
			case(1): {transform(clients, counter, searchID); return; }
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
		inputInt--;
		std::system("cls");
		std::cout << "\n\n\t�������� ������ ������� " << clients[inputInt].Surname << " " << clients[inputInt].Name
			<< " " << clients[inputInt].Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
		int inP;
		cin >> inP;
		std::system("cls");
		switch (inP) {
		case(1): {transform(clients, counter, inputInt); return; }
		case(2): { return; }
		default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return; }
		}
	}
	default: {std::cout << "\n\n\t������� �������� ��������, ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return; }
	}

	std::system("cls");



	std::system("cls");
}
//finished

void swapAndDelClients(person* clients, int* counter, int searchID) {
	for (int i = searchID; i < *counter; i++) {
		clients[i].Surname = clients[i + 1].Surname;
		clients[i].Name = clients[i + 1].Name;
		clients[i].Patronymic = clients[i + 1].Patronymic;
		clients[i].Address = clients[i + 1].Address;
		clients[i].PhoneNum = clients[i + 1].PhoneNum;
		clients[i].PayDay = clients[i + 1].PayDay;
		clients[i].Summ = clients[i + 1].Summ;
	}
	(*counter)--;
}
void delClients(person* clients, int* counter) {
	std::cout << "\n\t������� ������ �������\n\n\t\t����� �� \n\n\t1. ���\t2. ����� � ����\t0. �����\n\n\t";
	int inputNum;
	cin >> inputNum;
	std::system("cls");
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
		for (int i = 0; i < *counter; i++) {
			if (inputStr == clients[i].Surname) { searchID = i; couErr++; }
			if (inputStr == clients[i].Name) { searchID = i; couErr++; }
			if (inputStr == clients[i].Patronymic) { searchID = i; couErr++; }
		}

		if (couErr > 1) { std::cout << "\n\n\t������� ����� ������ �������, ������� ������ ������� �������. ������� ����� ������� ��� �������� � ����... "; char p = _getch(); std::system("cls"); return; }
		if (searchID == -1) { std::cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); std::system("cls"); return; }
		if (searchID >= 0) {
			std::cout << "\n\n\t������� ������ ������� " << clients[searchID].Surname << " " << clients[searchID].Name
				<< " " << clients[searchID].Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
			int inputH;
			cin >> inputH;
			std::system("cls");
			switch (inputH) {
			case(1): {swapAndDelClients(clients, counter, searchID);
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
		inputInt--;
		std::system("cls");
		std::cout << "\n\n\t������� ������ ������� " << clients[inputInt].Surname << " " << clients[inputInt].Name
			<< " " << clients[inputInt].Patronymic << "\n\n\t1. ��\t2. ���\n\n\t";
		int inP;
		cin >> inP;
		std::system("cls");
		switch (inP) {
		case(1): {swapAndDelClients(clients, counter, inputInt);
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
//finished


void showClients(person* clients, int* counter) {
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
		int LenSurname = clients[i].Surname.length();
		int LenName = clients[i].Name.length();
		int LenPatronymic = clients[i].Patronymic.length();
		int LenAddress = clients[i].Address.length();
		int LenPhoneNum = clients[i].PhoneNum.length();
		int LenPayDay = clients[i].PayDay.length();
		int LenSumm = 0;
		int Summ = clients[i].Summ;
		int g = 0;
		while (Summ > 0) { Summ /= 10; LenSumm++; }
		maxSumm += clients[i].Summ;

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
			maxLenSurname, clients[i].Surname.c_str(),
			maxLenName, clients[i].Name.c_str(),
			maxLenPatronymic, clients[i].Patronymic.c_str(),
			maxLenAddress, clients[i].Address.c_str(),
			maxLenPhoneNum, clients[i].PhoneNum.c_str(),
			maxLenPayDay, clients[i].PayDay.c_str(),
			maxLenSumm, clients[i].Summ
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
//finished 

void show(person* clients, int* counter, int searchID) {
	std::cout << "\n\n\t���: " << clients[searchID].Surname << " " << clients[searchID].Name << " " << clients[searchID].Patronymic << " ������: "
		<< clients[searchID].Address << "\n\t��������� �����: " << clients[searchID].PhoneNum << " ���� ������: " << clients[searchID].PayDay << " �����: " << clients[searchID].Summ;
}
void searchClients(person* clients, int* counter) {
	std::cout << "\n\t����� ������� �� ����";
	std::cout << "\n\n\t������� ������� ��� ��� ��� ��������\t0. �����\n\n\t";
	string inputStr;
	cin >> inputStr;
	std::system("cls");
	if (inputStr == "0") { return; }

	int searchID = -1;
	for (int i = 0; i < *counter; i++) {
		if (inputStr == clients[i].Surname) { searchID = i; show(clients, counter, searchID); }
		if (inputStr == clients[i].Name) { searchID = i; show(clients, counter, searchID); }
		if (inputStr == clients[i].Patronymic) { searchID = i; show(clients, counter, searchID); }
	}
	if (searchID >= 0) { std::cout << "\n\n\t������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); std::system("cls");  return; }
	if (searchID == -1) { std::cout << "\n\n\t������ �� ������, ������� ����� ������� ���-�� ��������� � ����... "; char p = _getch(); std::system("cls"); return; }
	std::system("cls");
}
//finish

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