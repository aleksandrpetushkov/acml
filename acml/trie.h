#include "Node.h"
#include  <string>
#include <vector>
#include <set>
#include <string>
#include <fstream>

class Trie
{
public:
	Trie()
	{

		
	}
	void Add(std::string _new) //ƒобавление строки
	{
		unsigned int weight(0);
		current = &root; // current - будет использоватьс€ дл€ передвижени€ по дереву, изначально приравниваетс€ к указателю на корневой узел
		size_t pos1(0), pos(0), pos2(0), pos3(0);
		pos = _new.find_first_not_of(" \t", 0);
		pos1 = _new.find_first_of(" \t", pos);

		pos2 = _new.find_first_not_of(" \t", pos1);
		pos3 = _new.find_first_of(" \t", pos2);

		if(pos2!=pos3)
		{
			weight = stoi(_new.substr(pos2, pos3 - pos2));
		}
	
		_new = _new.substr(pos, pos1 - pos); // ¬ырезаетс€ из строки только первое слово дл€ отброса лишнего


		for (unsigned short int i = 0; i < _new.size();++i) // ÷икл в котором будет перебиратьс€ строка по символам и заноситьс€ в дерево
		{

			if(current->find(_new[i])) // ≈сли указанные символ имеетс€ в списке узла - то передвигаем cuurrnt на данный узел
			{
				current = current->next(_new[i]);
			}
			else // если узла в списке нет - создаем его и передвигаем current на него;
			{
				current->add(_new[i]);
				current = current->next(_new[i]);
			}
		}

		//std::cout << "     " << weight << std::endl;;
		current->set_weigth(weight);
		current->Set_end();// ѕосле того как прошлись по всем символам строки последний символ помечаем как конец слова
	}


	std::vector<li> search(const std::string& _str) // ћетод поиска окончаний слова
	{
		std::vector<li> result;
		
		current = &root;
		for (unsigned short int i = 0; i < _str.size(); ++i) // ¬ цикле переходим к последнему узлу
		{
			if (current->find(_str[i]))// ≈сли узел с указанным списком существует - переходим в него
			{
				current = current->next(_str[i]);
			}
			else //≈сли узла не существует - возвраем пустой список - подставл€ть нечего
			{
				return result;
			}
		}

		result = current->get_exist_end(); // ѕосле того как перешли к последнему узлу элемента слова - от данного узла запрашиваем существующие окончани€.
		
		
		return result;
	}


	/*
	ѕринимаетс€ им€ файла и на него открываетс€ поток. ‘айл очищаетс€ и выгружаетс€ обновленна€ библиотека слов с весами

	*/
	void unload_lib(std::string file_name) 
	{
		std::vector<li> out; //¬ектор дл€ слов с весами
		std::fstream fl(file_name, std::ios::out);

		if (!fl)
		{
			std::cerr << "Error open file\n";
		}
		else
		{
			/*
			÷икл перебирающей все узлы в корневом узле
			*/
			for (unsigned int i(0); i < root.size(); ++i) 
			{
				current = root.next(i);
				out = current->get_lib();
				for (const li o : out)
				{
					fl << o.st << "\t" << o.weight << std::endl;
				}
			}
			fl.close();
		}
	}
	void up(std::string _new)
	{
		current = &root;
		for (unsigned short int i = 0; i < _new.size(); ++i) // ÷икл в котором будет перебиратьс€ строка по символам и заноситьс€ в дерево
		{

			if (current->find(_new[i])) // ≈сли указанные символ имеетс€ в списке узла - то передвигаем cuurrnt на данный узел
			{
				current = current->next(_new[i]);
			}
		}
		current->set_weigth_up();
	}

protected:
	Node root;
	Node* current;
	
};
