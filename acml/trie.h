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
	void Add(std::string _new) //���������� ������
	{
		current = &root; // current - ����� �������������� ��� ������������ �� ������, ���������� �������������� � ��������� �� �������� ����

		for (unsigned short int i = 0; i < _new.size();++i) // ���� � ������� ����� ������������ ������ �� �������� � ���������� � ������
		{
			std::cout << _new[i];
			
			if(current->find(_new[i])) // ���� ��������� ������ ������� � ������ ���� - �� ����������� cuurrnt �� ������ ����
			{
				current = current->next(_new[i]);
			}
			else // ���� ���� � ������ ��� - ������� ��� � ����������� current �� ����;
			{
				current->add(_new[i]);
				current = current->next(_new[i]);
			}
		}
		std::cout << std::endl;
		current->Set_end();// ����� ���� ��� �������� �� ���� �������� ������ ��������� ������ �������� ��� ����� �����
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
