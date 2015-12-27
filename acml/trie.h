#include "Node.h"
#include  <string>
#include <vector>
#include <set>
#include <string>

class Trie
{
public:
	Trie()
	{

		
	}
	void Add(std::string _new) //Добавление строки
	{
		current = &root; // current - будет использоваться для передвижения по дереву, изначально приравнивается к указателю на корневой узел

		for (unsigned short int i = 0; i < _new.size();++i) // Цикл в котором будет перебираться строка по символам и заноситься в дерево
		{
			std::cout << _new[i];
			
			if(current->find(_new[i])) // Если указанные символ имеется в списке узла - то передвигаем cuurrnt на данный узел
			{
				current = current->next(_new[i]);
			}
			else // если узла в списке нет - создаем его и передвигаем current на него;
			{
				current->add(_new[i]);
				current = current->next(_new[i]);
			}
		}
		std::cout << std::endl;
		current->Set_end();// После того как прошлись по всем символам строки последний символ помечаем как конец слова
	}


	std::vector<std::string> search(const std::string& _str)
	{
		std::vector<std::string> result;
		
		current = &root;
		for (unsigned short int i = 0; i < _str.size(); ++i)
		{
			if (current->find(_str[i]))
			{
				current = current->next(_str[i]);
			}
			else
			{
				return result;
			}
			std::cout << _str[i];
		}
		std::cout << std::endl << std::endl;
	
		result = current->get_exist_end();
		
		return result;
	}

protected:
	Node root;
	Node* current;
	
};
