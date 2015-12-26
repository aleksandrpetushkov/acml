#include "Node.h"
#include  <string>
#include <vector>
#include <set>
#include <string>

class Trie
{
	Trie()
	{

		
	}
	void Add(std::string _new)
	{
		current = &root;

		for (unsigned short int i = 0; i < _new.size();++i)
		{
			if(current->find(_new[i]))
			{
				current = current->next(_new[i]);
			}
			else
			{
				current->add(_new[i]);
				current = current->next(_new[i]);
			}
		}
		current->Set_end();
	}


	std::vector<std::string> search(const std::string& _str, const char& size_mass=5)
	{
		std::vector<std::string> result;
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
		}

		std::vector<std::string> mass_ends = current->get_exist_end();
		
		for (char i = size_mass; i > 0;--i)
		{
			std::string tmp = _str;
			n_current = current;
			for(n_current)
		}     
	}

protected:
	Node root;
	Node* current;
	
};
