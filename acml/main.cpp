#include "Trie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "gtest/gtest.h"

using namespace std;

TEST(tri�, add, search)  //���� ���������� �����
{
	Trie tr;
	tr.Add("����������\t10");
	ostringstream test_str;
	for(const auto& elem:tr.search("����"))
	{
		test_str <<"����" << elem.st << elem.weight;
	}
	EXPECT_EQ("����������10", string(test_str.str()));
}

TEST(trie, up) //����������� ����� �������� ���� � ��������
{
	Trie tr;
	tr.Add("����������\t10");
	tr.up("����������");
	ostringstream test_str;
	for (const auto& elem : tr.search("����"))
	{
		test_str << "����" << elem.st << elem.weight;
	}
	EXPECT_EQ("����������11", string(test_str.str()));
}


TEST(trie, common) //����� ���� ������. ����������� ����� � ������ �����, ����������� ��������� � ������������ � ���������
{
	Trie tr;
	tr.Add("����������\t10");
	tr.Add("�����");
	tr.Add("����\t5");
	ostringstream test_str;
	vector<li> v = tr.search("�");
	sort(v.begin(), v.end());
	for (const auto& elem : v)
	{
		test_str << "�" << elem.st << elem.weight;
	}
	EXPECT_EQ("�����0����5����������10", string(test_str.str()));

}




unsigned short int main(int argc, char* argv[])
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
			/*
			cerr << "Error load word\n";
			cin.get();
			//*/
		}
		else
		{
			tr.Add(st); 
		}
	}
	in_lib.close();

	cout << "load completed\n";
	
	//cin.get();
	vector<li> mass_st;
	//cout << mass_st.size();
	for (bool b = true;b;)
	{
		string str;
		int num(0);
		cout << "Menu:\n" << "1. Work programs.\n" << "5. exit.\n";
		int zz;
		cin >> zz;
		switch (zz)
		{
		case 1:
			cout << "Enter symbol for search: ";
			cin >> str;
			mass_st = tr.search(str);
			sort(mass_st.begin(), mass_st.end());
			if(mass_st.size()==0)
			{
				cout << "Enter word not exist. add?(y/n); ";
				char ch;
				cin >> ch;
				if(ch=='y')
				{
					tr.Add(str);
				}
			}
			else
			{
				unsigned int i(0);
				for (unsigned int k = mass_st.size() ; k > 0; --k)
				{
					cout << "[" << mass_st.size() - k+1 << "] - " << str << mass_st[k-1].st << "  " << mass_st[k-1].weight << endl;
					if (i == 7)
					{
						break;
					}
					++i;
				}
				cin >> num;
				tr.up(str + mass_st[mass_st.size() - num].st);
			}
			
			break;
		case 5:
			b = false;
			break;
		}
	}
	tr.unload_lib("lib.txt");// �������� ����������
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	cin.get();
	cin.get();

}