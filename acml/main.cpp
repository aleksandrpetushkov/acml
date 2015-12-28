#include "Trie.h"
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


unsigned short int main()
{
	/*
	При загрузка словаря рядом со словом указывается вес слова (сколько раз оно было выбрано для подстановки)
	При поиске постановочных вариантов слов формируется вектор объектов класса "li", (файл Node строки 7-34).
	В данном классе есть поля строка и вес строки. После того как сформируется вектор объектов "li" он сортируется и выводится в обратном порядке (у кого вес больше тот и выше)

	//*/



	system("chcp 1251 >> null");
	setlocale(LC_ALL, "ru-RU");
	//cout << "Hello world\n";


	fstream in_lib("lib.txt", ios::in); //Открываем поток на файл библиотеке для загрузки
//	fstream in_lib1("lib.txt1", ios::out); //Открываем поток на файл библиотеке для загрузки

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