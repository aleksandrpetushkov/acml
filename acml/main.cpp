#include "Trie.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


unsigned short int main()
{
	system("chcp 1251 >> null");
	
	setlocale(LC_ALL, "ru-RU");
	cout << "Hello world\n";


	fstream in_lib("lib.txt", ios::in); //��������� ����� �� ���� ���������� ��� ��������
	fstream in_lib1("lib.txt1", ios::out); //��������� ����� �� ���� ���������� ��� ��������

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
			/*
			size_t pos1(0), pos(0);
			pos = st.find_first_not_of(" \t", 0);
			pos1 = st.find_first_of(" \t", pos);
			st = st.substr(pos, pos1 - pos); // ���������� �� ������ ������ ������ ����� ��� ������� �������
			//*/

			tr.Add(st); 
		}
	}
	cout << "load completed\n";
	string str;
	cout << "Enter symbol for search: ";
	cin >> str;
	map<unsigned int, string>mass_st;
	cin.get();
	mass_st= tr.search(str);
	//cout << mass_st.size();
	cin.get();
	for (int i = mass_st.size() - 1; i >= 0; --i)
	{
		cout << str << mass_st[i] << "   " << i << endl;
	}


	cin.get();
}