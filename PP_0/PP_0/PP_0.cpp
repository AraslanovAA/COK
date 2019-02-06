// PP_0.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include <locale>//setlocale
#include "stdafx.h"
#include <Windows.h>//setconsoleCP
#include<iostream> //cout
#include <string>
#include <malloc.h>
#include <math.h> 



using namespace std;

int IInsert(int MaxNum = INT_MAX, string input = "") {//���� ����� ���� int �� 1 �� MaxNum
	string s;
	bool key = false;
	int res;

	if (input != "") {
		size_t check;
		try {
			res = stoi(input, &check);
			if (check == input.size()) {
				if ((res >= 1) && (res <= MaxNum))
				{
					return res;
				}
				else
				{
					cout << "������!����� ��� ���������" << endl;
					return  -1;
				}
			}
			else {
				cout << "������ �����" << endl;
				return -1;
			}
		}
		catch (const invalid_argument&) { cout << "������!������� �� �����" << endl; 
		return -1;
		}
		catch (const out_of_range&) {
			cout << "����� ��� ��������� integer" << endl;
			return -1;
		}
		
	}

	do {

		getline(cin, s);
		
		int i;
		if (int i = s.find(' ') != std::string::npos) {
			s.resize(i + 1);
		}
		while ((i = s.find(' ')) != std::string::npos)
			s.erase(i, 1);

		size_t check;
		try {
			res = stoi(s, &check);
			if (check == s.size()) {
				if ((res >= 1) && (res <= MaxNum))
				{
					key = true;
				}
				else
				{
					cout << "��� ��������� ���������� ���������" << endl;
				}
			}
			else {
				cout << "������ �����" << endl;
			}
		}
		catch (const invalid_argument&) { cout << "������� �� �����" << endl; cout << "���������� �����" << endl; }
		catch (const out_of_range&) {
			cout << "����� ��� ��������� integer" << endl; cout << "���������� �����" << endl;
		}
	} while (key == false);
	return res;
}


double DInsert() {
	string s;
	bool key = false;
	double res;
	system("cls");
	cout << "������� �����: ";
	/*getline(cin, s);*/
	do {

		getline(cin, s);
		int i;
		if (int i = s.find(' ') != std::string::npos) {
			s.resize(i + 1);
		}
		while ((i = s.find(' ')) != std::string::npos)
			s.erase(i, 1);

		size_t check;
		try {
			res = stod(s, &check);
			if (check == s.size()) {
				if (res >= 0) {
					double a;
					if (modf(res, &a) == 0) {
						key = true;
					}
					else
					{
						cout << "����� ������ ���� �����" << endl;
					}
				}
				else {
					cout << "������������ ������ ��������������� �����" << endl;
				}
			}
			else {
				cout << "������ �����" << endl;
			}
		}
		catch (const invalid_argument&) { cout << "������� �� �����" << endl; cout << "���������� �����" << endl; }
		catch (const out_of_range&) {
			cout << "����� ��� ��������� double" << endl; cout << "���������� �����" << endl;
		}
	} while (key != true);
	return res;
}


int gcd(int x, int y)//������� ���������� 2 �����, ���������� 1 ���� ����� �������������.
{
	return y ? gcd(y, x%y) : x;
}
int* ReadBas() {//������� �������� ����� ������, ������ ������ ��������� ��� NULL
	cout << "������� ����� �����, �������� ����� ��������" << endl;
	string SBasNums = "";
	getline(cin, SBasNums);
	int z;
	while ((z = SBasNums.find("  ")) != std::string::npos)//������� ������ �����������
		SBasNums.erase(z, 1);
	if (SBasNums[0] == ' ')//������� ������� � 1 � ��������� ������� ������ ���� ����
		SBasNums.erase(0, 1);
	if (SBasNums[SBasNums.length() - 1] == ' ')
		SBasNums.erase(SBasNums.length() - 1, 1);//������ ��� ��������� �������������� ��������� 1 ��������
	short SpaceCount = 0;
	for (int i = 0;i < SBasNums.length() - 1;i++) {
		if (SBasNums[i] == ' ')
			SpaceCount++;
	}
	string *SArr1Basis;//������ � ���������� ���� string, ���������� �������� ������
	SArr1Basis = new string[SpaceCount + 1];
	for (int i = 0;i < SpaceCount+1;i++) {
		if (i != SpaceCount) {
			int k = SBasNums.find(' ');
			SArr1Basis[i] = SBasNums.substr(0, k);
			SBasNums.erase(0, k + 1);
		}
		else {
			SArr1Basis[SpaceCount] = SBasNums;//��� ��� ���������. ��� ���������?
		}
	}//     1    2 3456 7 8 910    ��c�
	int NumElements = SpaceCount + 1;
	int *IArr1Basis;//������ ��� ��������� ������
	IArr1Basis = new int[NumElements];
	for (int i = 0; i < NumElements;i++) {
		IArr1Basis[i] = IInsert(INT_MAX, SArr1Basis[i]);//������
	}
	bool BasisCreated = true;

	for (int i = 0; i < NumElements;i++)
	{
		if (IArr1Basis[i] == -1) {//��������� ��� �� �������� ���� ���������
			cout << "������ � ������: " << SArr1Basis[i] << endl;
			BasisCreated = false;
		}
	}
		if (BasisCreated == true) {//����� ������ ���������
			for (int i = 0; i < NumElements;i++) {//��� �������� ������ ����� ������ ���� ������� ������� ������.
				for (int j = i; j < NumElements;j++) {
					if (i == j) {
						//���������� � ����� �� �����, �� ���� �������� � ����� +1 �� ����� � �� ������� ������� ����
					}
					else {
						if (gcd(IArr1Basis[i], IArr1Basis[j]) != 1) {
							BasisCreated = false;
							cout << "����� " << IArr1Basis[i] << " � " << IArr1Basis[j] << " �� �������� ���������������" << endl;
						}
					}
				}
			}
			if (BasisCreated) {//��� ����� ��������� ������� ��������
				return IArr1Basis;
			}
			else {//������� �� ������� ������� �����
				return NULL;
			}
		}
		else {//����������� ������ �����
			return NULL;
		}
	}

bool CmpParamsBasis(int *Basis, double Num1, double Num2) {
	double MaxNums;
	int n = _msize(Basis) / sizeof(int);//���������� ��������� �������
	MaxNums = 1;
	for (int i = 0; i < n;i++) {
		MaxNums *= Basis[i];
	}
	MaxNums--;
	cout << "�������� �������� ������: [0; " << MaxNums << "]" << endl;
	if ((Num1 != NULL) && (Num2 != NULL)) {
		if ((Num1 <= MaxNums) && (Num2 <= MaxNums)) {
			cout << "��������� \n" << Num1 << "\n" << Num2 << "\n ������������� ��������� ������" << endl;
			return true;
		}
		else
		{
			cout << "�� ��� ������� ���������\n" << Num1 << "\n" << Num2 << "������������� ��������� ������" << endl;
			return false;
		}
	}
	else {
		cout << "���������� ������ ���������" << endl;
	}
}
void ShowBasis(int *Basis) {
	if (Basis == NULL) {
		cout << "����� �� �����" << endl;
	}
	else {
		cout << "������� �����:" << endl;
		int n = _msize(Basis) / sizeof(int);//���������� ��������� �������
		cout << "(";
		for (int i = 0; i < n;i++) {
			cout << Basis[i] << "; ";
		}
		cout << ")" << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	bool EndApp = false;
	double MaxNums = 0;
	int *Basis = NULL, *testBas;
	double Num1 = NULL, Num2 = NULL;
	int choise;
	std::cout << "�������� ��������" << endl;

	while (EndApp == false)
	{
		cout << "1 - ������ �����" << endl;
		cout << "2 - ������ ���������" << endl;
		cout << "3 - ���������" << endl;
		cout << "4 - �����" << endl;
		//cout << "5 - ������������ ������" << endl; todo
		choise = IInsert(4);
		cout << choise << endl;
		switch (choise)
		{
		case 1: 

			testBas = ReadBas();
			if (testBas != NULL) {
				Basis = testBas;//��������� ��� �������� ���������� �� ��������
				cout << "����� ������� �����" << endl;
				ShowBasis(Basis);
				CmpParamsBasis(Basis, Num1, Num2);
			}
			else {
				cout << "����� �� ������"<<endl;
				ShowBasis(Basis);
			}
			break;
		case 2: 
			Num1 = DInsert();
			Num2 = DInsert();
			ShowBasis(Basis);
			CmpParamsBasis(Basis, Num1, Num2);
			break;
		case 3: break;
		case 4: 
			EndApp = true; 
			break;
		default:
			cout << "���������� �����" << endl;
			break;
		}
	}
    return 0;
}

