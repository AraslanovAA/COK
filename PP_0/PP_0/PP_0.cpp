// PP_0.cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include <locale>//setlocale
#include "stdafx.h"
#include<vector>
#include <Windows.h>//setconsoleCP
#include<iostream> //cout
#include <string>
#include <malloc.h>
#include <math.h> 
#include <ctime>
#include <algorithm>
#include <thread>
#include <fstream>
long long *xaF, *xbF;
long long *MPAR1;
long long *MPAR2;
long long *Bas, *Adr;
using namespace std;

long long IInsert(long long MaxNum = INT_MAX, string input = "") {//���� ����� ���� long long �� 1 �� MaxNum
	string s;
	bool key = false;
	long long res;

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
		catch (const invalid_argument&) {
			cout << "������!������� �� �����" << endl;
			return -1;
		}
		catch (const out_of_range&) {
			cout << "����� ��� ��������� integer" << endl;
			return -1;
		}

	}

	do {

		getline(cin, s);

		long long i;
		if ((i = s.find(' ')) != std::string::npos) {
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
		long long i;
		if ((i = s.find(' ')) != std::string::npos) {
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


long long gcd(long long x, long long y)//������� ���������� 2 �����, ���������� 1 ���� ����� �������������.
{
	return y ? gcd(y, x%y) : x;
}
long long* ReadBas() {//������� �������� ����� ������, ������ ������ ��������� ��� NULL
	cout << "������� ����� �����, �������� ����� ��������" << endl;
	string SBasNums = "";
	getline(cin, SBasNums);
	long long z;
	while ((z = SBasNums.find("  ")) != std::string::npos)//������� ������ �����������
		SBasNums.erase(z, 1);
	if (SBasNums != "") {
		if (SBasNums[0] == ' ')//������� ������� � 1 � ��������� ������� ������ ���� ����
			SBasNums.erase(0, 1);
		if (SBasNums[SBasNums.length() - 1] == ' ')
			SBasNums.erase(SBasNums.length() - 1, 1);//������ ��� ��������� �������������� ��������� 1 ��������

		short SpaceCount = 0;
		long long wtf = SBasNums.length() - 1;
		for (long long i = 0; i < wtf; i++) {
			if (SBasNums[i] == ' ')
				SpaceCount++;
		}
		string *SArr1Basis;//������ � ���������� ���� string, ���������� �������� ������
		SArr1Basis = new string[SpaceCount + 1];
		for (long long i = 0; i < SpaceCount + 1; i++) {
			if (i != SpaceCount) {
				long long k = SBasNums.find(' ');
				SArr1Basis[i] = SBasNums.substr(0, k);
				SBasNums.erase(0, k + 1);
			}
			else {
				SArr1Basis[SpaceCount] = SBasNums;//��� ��� ���������. ��� ���������?
			}
		}//     1    2 3456 7 8 910    ��c�
		long long NumElements = SpaceCount + 1;
		long long *IArr1Basis;//������ ��� ��������� ������
		IArr1Basis = new long long[NumElements];
		for (long long i = 0; i < NumElements; i++) {
			IArr1Basis[i] = IInsert(INT_MAX, SArr1Basis[i]);//������
		}
		bool BasisCreated = true;

		for (long long i = 0; i < NumElements; i++)
		{
			if (IArr1Basis[i] == -1) {//��������� ��� �� �������� ���� ���������
				cout << "������ � ������: " << SArr1Basis[i] << endl;
				BasisCreated = false;
			}
		}
		if (BasisCreated == true) {//����� ������ ���������
			for (long long i = 0; i < NumElements; i++) {//��� �������� ������ ����� ������ ���� ������� ������� ������.
				for (long long j = i; j < NumElements; j++) {
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
	else {//���� ������� ������ ������ SBasNums ==""
		cout << "������� ������ ������" << endl;
		return NULL;
	}
}

bool CmpParamsBasis(long long *Basis, long long Num1, long long Num2) {
	double MaxNums;
	long long n = _msize(Basis) / sizeof(long long);//���������� ��������� �������
	MaxNums = 1;
	for (long long i = 0; i < n; i++) {
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
void ShowBasis(long long *Basis) {
	if (Basis == NULL) {
		cout << "����� �� �����" << endl;
	}
	else {
		cout << "������� �����:" << endl;
		long long n = _msize(Basis) / sizeof(long long);//���������� ��������� �������
		cout << "(";
		for (long long i = 0; i < n; i++) {
			cout << Basis[i] << "; ";
		}
		cout << ")" << endl;
	}
}


long long* CreateModParams(long long *Basis, long long Num) {
	//������� ���� ��������� �� ������� ������������ ����� � �������� � ��������� ������ � ������� ����� ����������� ������
	// ��� �������� �� �������� �������� �������� �� NULL � ������������ ������
	long long n = _msize(Basis) / sizeof(long long);//���������� ��������� �������
	long long *ModParam = new long long[n];
	for (long long i = 0; i < n; i++) {
		ModParam[i] = Num % Basis[i];
	}
	return ModParam;
}

void Add2(long long nstart,long long nend) {
	for (long long i = nstart; i <= nend; i++) {
		Adr[i] = (MPAR1[i] + MPAR2[i]) % Bas[i];
	}
}
void Add1(long long *ModParam1, long long *ModParam2, long long *Basis, long long *B) {
	MPAR1 = ModParam1;
	MPAR2 = ModParam2;
	Bas = Basis;
	Adr = B;
	long long n = _msize(Basis) / sizeof(long long);
	thread s1(Add2, 0, ((n / 4) - 1));
	thread s2(Add2, (n / 4), ((2*n / 4) - 1));
	thread s3(Add2, (2*n / 4), (3*n/4)-1);
	Add2((3*n / 4), n - 1);
	s1.join();
	s2.join();
	s3.join();
	B = Adr;
}
void Add(long long *ModParam1, long long *ModParam2, long long *Basis, long long *B) {
	long long n = _msize(Basis) / sizeof(long long);
	for (long long i = 0; i < n; i++) {
		B[i] = (ModParam1[i] + ModParam2[i]) % Basis[i];
	}
}

long long* CreateModParams1(long long *Basis, INT64 Num) {
	//������� ���� ��������� �� ������� ������������ ����� � �������� � ��������� ������ � ������� ����� ����������� ������
	// ��� �������� �� �������� �������� �������� �� NULL � ������������ ������
	long long n = _msize(Basis) / sizeof(long long);//���������� ��������� �������

	long long *ModParam = new long long[n];
	for (INT64 i = 0; i < n; i++) {
		ModParam[i] = Num % Basis[i];
	}
	return ModParam;
}



//----------------------------------------------------------------------------------------------------------------------------------
bool MoreOrNot(string num1, string num2) {
	//num1 num2 > 0
	long long n1 = num1.length();
	long long n2 = num2.length();
	if (n1 > n2) {
		return true;
	}
	if (n1 < n2) {
		return false;
	}
	for (long long i = 0;i < n1;i++) {
		if ((num1[i] - '0') >(num2[i] - '0')) {
			return true;
		}
		if ((num1[i] - '0') <(num2[i] - '0')) {
			return false;
		}
	}
	return true;
}
string AMinB(string num1, string num2) {
	//����� ��������� � ������� ������ ����� ����� ��������, ��� num1 > num2
	long long n1 = num1.length();
	long long n2 = num2.length();
	string s3;//result
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	long long ostatok = 0;
	for (long long i = 0;i < n2;i++) {
		long long sum = ((num1[i] - '0') - (num2[i] - '0') - ostatok);
		if (sum < 0) {
			sum += 10;
			ostatok = 1;
		}
		else {
			ostatok = 0;
		}
		s3.push_back(sum % 10 + '0');
	}
	for (long long i = n2;i < n1;i++) {
		long long sum = ((num1[i] - '0') - ostatok);
		if (sum < 0) {
			sum += 10;
			ostatok = 1;
		}
		else {
			ostatok = 0;
		}
		s3.push_back(sum % 10 + '0');
	}
	reverse(s3.begin(), s3.end());
	while (s3[0] == '0')
	{
		s3.erase(0, 1);
		if (s3 == "") {
			return "0";
		}
	}
	return s3;
}
string SumBF(string num1, string num2) {
	long long n1 = num1.length();
	long long n2 = num2.length();
	if (n1 > n2) {
		swap(num1, num2);//����� ������� ������ ������
		swap(n1, n2);
	}
	string s3;//result
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	long long ostatok = 0;
	for (long long i = 0;i < n1;i++) {
		long long sum = ((num1[i] - '0') + (num2[i] - '0') + ostatok);
		s3.push_back(sum % 10 + '0');
		ostatok = sum / 10;
	}
	for (long long i = n1;i < n2;i++) {
		long long sum = ((num2[i] - '0') + ostatok);
		s3.push_back(sum % 10 + '0');
		ostatok = sum / 10;
	}
	if (ostatok) s3.push_back(ostatok + '0');
	reverse(s3.begin(), s3.end());
	return s3;
}
string MultBF(string num1, string num2) {
	long long n1 = num1.length();
	long long n2 = num2.length();
	if (n1 > n2) {
		swap(num1, num2);//����� ������� ������ ������
		swap(n1, n2);
	}
	string s3 = "0";//result
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	long long ostatok = 0;
	//��������� ����� n1 ��� n1[0]
	//������ n[i-uyu] ����������� � ������ n2[k-��]
	string promezhut = "";
	for (long long i = 0;i < n1;i++) {
		promezhut = "";
		for (long long j = 0;j < n2;j++) {
			long long sum = ((num1[i] - '0')*(num2[j] - '0') + ostatok);
			promezhut.push_back(sum % 10 + '0');
			ostatok = sum / 10;
		}
		if (ostatok != 0) {
			promezhut.push_back(ostatok + '0');
		}
		ostatok = 0;
		reverse(promezhut.begin(), promezhut.end());
		for (long long l = 0;l < i;l++) {
			promezhut.push_back('0');
		}
		s3 = SumBF(s3, promezhut);
	}

	return s3;
}
string* MultNASum(string num1, string num2, string *resultarea) {
	string i = "1";
	string *res = new string(num1);
	//cout << "WTF" << *res;
	while (i != num2) {
		*res = SumBF(*res, num1);
		i = SumBF(i, "1");
	}
	//cout << "WTF" << *res << endl;
	*resultarea = *res;
	delete res;
	//cout << *resultarea << "DFFGRLUKHFJE:FBR" << endl;
	return resultarea;
}
//----------------------------------------------------------------------------------------------------------------------------------
string FactLongLong(long long Num) {
	string aF = "1";
	for (long long i = 1;i <= Num;i++) {
		string *whereret = new string();
		aF = MultBF(aF, to_string(i));
		//aF = MultBF(aF, to_string(i));
	}
	return aF;
}
string RepeatFormulaLongLong(long long Num1, long long Num2) {
	clock_t startT = clock();

	//MultNASum("2", "4",whereret);
	string N1 = to_string(Num1);
	string N2 = to_string(Num2);
	string aF = "1";
	aF = FactLongLong(Num1);
	string bF = "1";
	bF = FactLongLong(Num2);
	string i = "1";
	string etoresult = SumBF(aF, bF);//a!=b!

	string res1;

	res1 = MultBF(aF, bF);//a!*b!
	res1 = SumBF(etoresult, res1);//a!*b! + a! + b!
	string resumn;
	resumn = MultBF(aF, aF);
	res1 = SumBF(res1, resumn);//a!*b! + a! + b! + a!*a!
	resumn = MultBF(bF, bF);
	res1 = SumBF(res1, resumn);//a!*b! + a! + b! + a!*a! + b!*b!
	clock_t endT = clock();
	cout << "����� ������ � ������� ����������: " << (double)(endT - startT) / CLOCKS_PER_SEC << endl;
	cout << res1 << "  : ���� ��� ��� res" << endl;
	return res1;
}

long long Retranslate(long long *Basis, long long *Result, long long Num1, long long Num2) {//����� ��������� ������ � 10-�� ����

	long long n = _msize(Basis) / sizeof(long long);//���������� ��������� �������
	string result = RepeatFormulaLongLong(Num1, Num2);

	const long long base = 1000 * 1000 * 1000;
	bool flagCorrect = true;

	for (long long everyPinBas = 0;everyPinBas < n;everyPinBas++) {
		vector<long long> a;
		for (long long i = (long long)result.length(); i > 0; i -= 9)//��������� ������
			if (i < 9)
				a.push_back(atoi(result.substr(0, i).c_str()));
			else
				a.push_back(atoi(result.substr(i - 9, 9).c_str()));//��������� ���������

		long long carry = 0;
		long long b = Basis[everyPinBas];
		for (long long i = (long long)a.size() - 1; i >= 0; --i) {
			long long cur = a[i] + carry * 1ll * base;
			a[i] = long long(cur / b);
			carry = long long(cur % b);
		}
		while (a.size() > 1 && a.back() == 0)
			a.pop_back();


		if (carry != Result[everyPinBas]) {
			flagCorrect = false;
		}
	}
	if (flagCorrect == true) {
		cout << "" << endl;
		cout << "Answer:  " << result << endl;
	}
	cout << "GG" << endl;
	return 0;
}


long long* Multy(long long *ModParam1, long long *ModParam2, long long *Basis, bool flagdelete, long long num) {
	long long n = _msize(Basis) / sizeof(long long);
	long long *B;
	long long *A = new long long[n];
	for (long long i = 0; i < n; i++) {
		A[i] = ModParam1[i];
	}
	long long i = 1;
	long long *currentparam;
	bool flag = false;
	currentparam = CreateModParams(Basis, i);
	for (long long j = 0; j < n; j++) {
		if (currentparam[j] != ModParam2[j]) {
			flag = true;
		}
	}
	delete[] currentparam;
	if (flag) {
		flag = false;
		while (!flag)
		{
			flag = true;
			i++;
			B = new long long[n];
			Add(A, ModParam1, Basis, B);
			delete[] A;
			A = B;
			currentparam = CreateModParams(Basis, i);
			for (long long j = 0; j < n; j++) {
				if (currentparam[j] != ModParam2[j]) {
					flag = false;
				}
			}
			delete[] currentparam;
		}
	}
	if (flagdelete == true) {
		delete[] ModParam1;
		delete[] ModParam2;
	}
	if (num == 1) {
		xaF = A;
	}
	if (num == 2) {
		xbF = A;
	}
	return A;
}

long long* Multy1(long long *ModParam1, long long *ModParam2, long long *Basis, bool flagdelete, long long num) {
	long long n = _msize(Basis) / sizeof(long long);
	long long *B;
	long long *A = new long long[n];
	for (long long i = 0; i < n; i++) {
		A[i] = ModParam1[i];
	}
	long long i = 1;
	long long *currentparam;
	bool flag = false;
	currentparam = CreateModParams(Basis, i);
	for (long long j = 0; j < n; j++) {
		if (currentparam[j] != ModParam2[j]) {
			flag = true;
		}
	}
	delete[] currentparam;
	if (flag) {
		flag = false;
		while (!flag)
		{
			flag = true;
			i++;
			B = new long long[n];
			Add1(A, ModParam1, Basis, B);
			delete[] A;
			A = B;
			currentparam = CreateModParams(Basis, i);
			for (long long j = 0; j < n; j++) {
				if (currentparam[j] != ModParam2[j]) {
					flag = false;
				}
			}
			delete[] currentparam;
		}
	}
	if (flagdelete == true) {
		delete[] ModParam1;
		delete[] ModParam2;
	}
	if (num == 1) {
		xaF = A;
	}
	if (num == 2) {
		xbF = A;
	}
	return A;
}
long long* Fact(long long *ModParam1, long long *Basis, long long num) {
	long long n = _msize(Basis) / sizeof(long long);
	long long *A = new long long[n];//��������� ���������

	for (long long i = 0; i < n; i++) {
		A[i] = 1;
	}
	long long i = 1;
	long long *currentparam = NULL;
	bool flag = false;
	while (!flag)
	{
		flag = true;
		currentparam = CreateModParams(Basis, i);
		for (long long j = 0; j < n; j++) {
			if (currentparam[j] != ModParam1[j]) {
				flag = false;
			}
		}

		A = Multy(A, currentparam, Basis, true, 0);
		i++;
		//delete[] A;
		//A = B;
	}
	if (num == 1) {
		xaF = A;
	}
	if (num == 2) {
		xbF = A;
	}

	return A;
}

long long* Fact1(long long *ModParam1, long long *Basis, long long num) {
	long long n = _msize(Basis) / sizeof(long long);
	long long *A = new long long[n];//��������� ���������

	for (long long i = 0; i < n; i++) {
		A[i] = 1;
	}
	long long i = 1;
	long long *currentparam = NULL;
	bool flag = false;
	while (!flag)
	{
		flag = true;
		currentparam = CreateModParams(Basis, i);
		for (long long j = 0; j < n; j++) {
			if (currentparam[j] != ModParam1[j]) {
				flag = false;
			}
		}

		A = Multy1(A, currentparam, Basis, true, 0);
		i++;
		//delete[] A;
		//A = B;
	}
	if (num == 1) {
		xaF = A;
	}
	if (num == 2) {
		xbF = A;
	}

	return A;
}


//long long* F(long long *ModParam1, long long *ModParam2, long long *Basis) {//��������� �������
//	clock_t startT = clock();
//	long long n = _msize(Basis) / sizeof(long long);
//	
//	double start_time = clock();
//	//long long *aF = Fact(ModParam1, Basis);
//	long long *aF = new long long[n];
//	//Fact(ModParam1, Basis, std::cref(aF));
//	thread fact0(Fact, ModParam1, Basis, 1);
//	
//	long long *bF = new long long[n];
//	Fact(ModParam2, Basis, 2);
//	for (long long i = 0;i < n;i++) {
//		bF[i] = xbF[i];
//	}
//	fact0.join();
//	for (long long i = 0;i < n;i++) {
//		aF[i] = xaF[i];
//	}
//	long long *Result = new long long[n];//result = a!
//	for (long long i = 0;i < n;i++) {
//		Result[i] = aF[i];
//	}
//	long long *B = new long long[n];
//
//	
//	Add(Result, bF, Basis,B);//a!+b!
//	delete[] Result;
//	Result = B;
//
//	long long *Umnozh = Multy(aF, bF, Basis, false, 0);//a!*b!
//
//	B = new long long[n];
//	Add(Result, Umnozh, Basis, B);//a! + b! + a!*b!
//	delete[] Result;
//	Result = B;
//	delete[] Umnozh;
//	thread multaa(Multy, aF, aF, Basis, false, 1);
//	//Umnozh = Multy(aF, aF, Basis, false,true);//a!*a!
//	Umnozh = Multy( bF, bF, Basis, false,0);
//	B = new long long[n];
//	Add(Result, Umnozh, Basis, B);//a! + b! + a!*b! + b!*b!
//	delete[] Result;
//	Result = B;
//	delete[] Umnozh;
//
//	B = new long long[n];
//	multaa.join();
//	Add(Result, xaF, Basis, B);//a! + b! + a!*b! + a!*a! + b!*b!
//	delete[] Result;
//	Result = B;	
//	delete[] aF;
//	delete[] bF;
//	clock_t endT = clock();
//	cout <<"����� ������ � ���: "<< (double)(endT - startT) / CLOCKS_PER_SEC << endl;
//	return Result;
//}
long long* F(long long *ModParam1, long long *ModParam2, long long *Basis) {//��������� �������
	clock_t startT = clock();
	long long n = _msize(Basis) / sizeof(long long);

	double start_time = clock();
	long long *aF = Fact(ModParam1, Basis, 0);
	long long *bF = Fact(ModParam2, Basis, 0);
	long long *Result = new long long[n];//result = a!
	for (long long i = 0;i < n;i++) {
		Result[i] = aF[i];
	}
	long long *B = new long long[n];
	Add(Result, bF, Basis, B);//a!+b!
	delete[] Result;
	Result = B;

	long long *Umnozh = Multy(aF, bF, Basis, false, 0);//a!*b!

	B = new long long[n];
	Add(Result, Umnozh, Basis, B);//a! + b! + a!*b!
	delete[] Result;
	Result = B;
	delete[] Umnozh;

	Umnozh = Multy(aF, aF, Basis, false, 0);//a!*a!

	B = new long long[n];
	Add(Result, Umnozh, Basis, B);//a! + b! + a!*b! + a!*a!
	delete[] Result;
	Result = B;
	delete[] Umnozh;

	Umnozh = Multy(bF, bF, Basis, false, 0);//b!*b!

	B = new long long[n];
	Add(Result, Umnozh, Basis, B);//a! + b! + a!*b! + a!*a! + b!*b!
	delete[] Result;
	Result = B;
	delete[] Umnozh;

	delete[] aF;
	delete[] bF;
	clock_t endT = clock();
	cout << "����� ������ � ���: " << (double)(endT - startT) / CLOCKS_PER_SEC << endl;
	return Result;
}

long long* F1(long long *ModParam1, long long *ModParam2, long long *Basis) {//��������� �������
	clock_t startT = clock();
	long long n = _msize(Basis) / sizeof(long long);

	double start_time = clock();
	long long *aF = Fact1(ModParam1, Basis, 0);
	long long *bF = Fact1(ModParam2, Basis, 0);
	long long *Result = new long long[n];//result = a!
	for (long long i = 0;i < n;i++) {
		Result[i] = aF[i];
	}
	long long *B = new long long[n];
	Add1(Result, bF, Basis, B);//a!+b!
	delete[] Result;
	Result = B;

	long long *Umnozh = Multy1(aF, bF, Basis, false, 0);//a!*b!

	B = new long long[n];
	Add1(Result, Umnozh, Basis, B);//a! + b! + a!*b!
	delete[] Result;
	Result = B;
	delete[] Umnozh;

	Umnozh = Multy1(aF, aF, Basis, false, 0);//a!*a!

	B = new long long[n];
	Add1(Result, Umnozh, Basis, B);//a! + b! + a!*b! + a!*a!
	delete[] Result;
	Result = B;
	delete[] Umnozh;

	Umnozh = Multy1(bF, bF, Basis, false, 0);//b!*b!

	B = new long long[n];
	Add1(Result, Umnozh, Basis, B);//a! + b! + a!*b! + a!*a! + b!*b!
	delete[] Result;
	Result = B;
	delete[] Umnozh;

	delete[] aF;
	delete[] bF;
	clock_t endT = clock();
	cout << "����� ������ � ��� �����������: " << (double)(endT - startT) / CLOCKS_PER_SEC << endl;
	return Result;
}


bool CheckCommon(long long num) {
	for (long long i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			// �������, ��� n  �� �������, ��� ��� ������� �� i
			return false;
		}
	}
	// ������� ��� n �������.
	return true;
}
int main()
{	//�������� ��������� ��� � double,�� ����� ��� ��������� ������� �����������
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251); SetConsoleOutputCP(1251);
	bool EndApp = false;
	long long choise;

	double MaxNums = 0;
	long long *Basis = NULL, *testBas;
	long long *Res;
	long long Num1 = NULL, Num2 = NULL;//���� ������� double,�� ������� �� ������� �������� ������ ������
									   //�������� DInsert � ��������� � CMp � Create
									   //long long **TableAllowNums = NULL;
	long long *ModParam1 = NULL;
	long long *ModParam2 = NULL;
	string str0;
	long long j;
	ifstream fin("cppstudio.txt"); // ������� ���� ��� ������
	string a = "kek";
	std::cout << "�������� ��������" << endl;

	while (EndApp == false)
	{
		cout << "1 - ������ �����" << endl;
		cout << "2 - ������ ���������" << endl;
		cout << "3 - ���������" << endl;
		cout << "4 - �����" << endl;
		//cout << "5 - ������������ ������" << endl; todo
		choise = IInsert(6);
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
				cout << "����� �� ������" << endl;
				ShowBasis(Basis);
			}
			break;
		case 2:
			cout << "������� ������ ��������: ";
			Num1 = IInsert();
			cout << "������� ������ ��������: ";
			Num2 = IInsert();
			if (Basis != NULL) {
				//ShowBasis(Basis);
				if (CmpParamsBasis(Basis, Num1, Num2)) {
					ModParam1 = CreateModParams(Basis, Num1);//���������� �������
					ModParam2 = CreateModParams(Basis, Num2);
				}
			}
			break;
		case 3:
			if (Basis != NULL) {
				if (Num1 != NULL) {
					if (CmpParamsBasis(Basis, Num1, Num2)) {
						//F(ModParam1, ModParam2, Basis);
						//Retranslate(Basis, F(ModParam1, ModParam2, Basis), Num1, Num2);
						F(ModParam1, ModParam2, Basis);
						F1(ModParam1, ModParam2, Basis);
					}
				}
				else {
					cout << "�� ������� ���������" << endl;
				}
			}
			else {
				cout << "����� �� �����" << endl;
			}
			break;
		case 4:
			EndApp = true;
			break;
		case 5:
			Basis = new long long[1000000];
			for (int i = 0;i < 1000000;i++) {
				fin >> a;
				Basis[i] = stoi(a);
			}
			fin.close(); // ��������� ����
			break;
		case 6:

			RepeatFormulaLongLong(4, 3);

			break;



		default:
			cout << "���������� �����" << endl;
			break;
		}
	}
	return 0;
}

