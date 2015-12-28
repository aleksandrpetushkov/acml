#include "Trie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


unsigned short int main()
{
	/*
	��� �������� ������� ����� �� ������ ����������� ��� ����� (������� ��� ��� ���� ������� ��� �����������)
	��� ������ ������������� ��������� ���� ����������� ������ �������� ������ "li", (���� Node ������ 7-34).
	� ������ ������ ���� ���� ������ � ��� ������. ����� ���� ��� ������������ ������ �������� "li" �� ����������� � ��������� � �������� ������� (� ���� ��� ������ ��� � ����)

	//*/



	system("chcp 1251 >> null");
	setlocale(LC_ALL, "ru-RU");
	//cout << "Hello world\n";


	fstream in_lib("lib.txt", ios::in); //��������� ����� �� ���� ���������� ��� ��������
//	fstream in_lib1("lib.txt1", ios::out); //��������� ����� �� ���� ���������� ��� ��������

	if (!in_lib)
	{
		cerr << "Error open file\n";
		cin.get();
		return 1;
	}

	Trie tr; //�������� ���������� �������������� ������ Trie

	cout << "Load Library...\n";
	for (string st; !in_lib.eof();) //� ����� ���������� ������ �� ������ � �������� ������ � ����� add (���������� ������) � ������
	{
		getline(in_lib, st);
		if(!st.size()) // ���� ���������� ������ ����� 0 �������� - ������ ��� ����� � �� ����� ��������� � ������� ������ �������� ������
		{
			cerr << "Error load word\n";
			cin.get();
		}
		else
		{
			tr.Add(st); 
		}
	}
	in_lib.close();

	cout << "load completed\n";
	string str;
	cout << "Enter symbol for search: ";
	cin >> str;
	cin.get();
	vector<li> mass_st;
	mass_st= tr.search(str);
	cout << mass_st.size();
	sort(mass_st.begin(), mass_st.end());
	for (int i = mass_st.size() - 1; i >= 0; --i)
	{
		cout << str << mass_st[i].st << "   " << mass_st[i].weight << endl;
	}
	tr.unload_lib("lib.txt");

	//cin.get();
}