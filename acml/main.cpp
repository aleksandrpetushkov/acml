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


	fstream in_lib("lib.txt", ios::in); //Открываем поток на файл библиотеке для загрузки
	fstream in_lib1("lib.txt1", ios::out); //Открываем поток на файл библиотеке для загрузки

	if (!in_lib)
	{
		cerr << "Error open file\n";
		cin.get();
		return 1;
	}

	Trie tr; //Создание экземпляра разработанного класса Trie

	cout << "Load Library...\n";
	for (string st; !in_lib.eof();) //В цикле построчное чтение из потока и отправка строки в метод add (добавление строки) в дерево
	{
		getline(in_lib, st);
		if(!st.size()) // Если прочтенная строка имеет 0 символов - значит она пуста и ее нужно отбросить и вывести ошибку загрузки строки
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
			st = st.substr(pos, pos1 - pos); // Вырезается из строки только первое слово для отброса лишнего
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