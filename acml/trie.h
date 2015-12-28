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
	void Add(std::string _new) //���������� ������
	{
		unsigned int weight(0);
		current = &root; // current - ����� �������������� ��� ������������ �� ������, ���������� �������������� � ��������� �� �������� ����
		size_t pos1(0), pos(0), pos2(0), pos3(0);
		pos = _new.find_first_not_of(" \t", 0);
		pos1 = _new.find_first_of(" \t", pos);

		pos2 = _new.find_first_not_of(" \t", pos1);
		pos3 = _new.find_first_of(" \t", pos2);

		if(pos2!=pos3)
		{
			weight = stoi(_new.substr(pos2, pos3 - pos2));
		}
		//std::cout << _new;
	
		_new = _new.substr(pos, pos1 - pos); // ���������� �� ������ ������ ������ ����� ��� ������� �������

		//std::cout << "         " << _new;

		for (unsigned short int i = 0; i < _new.size();++i) // ���� � ������� ����� ������������ ������ �� �������� � ���������� � ������
		{

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

		//std::cout << "     " << weight << std::endl;;
		current->set_weigth(weight);
		current->Set_end();// ����� ���� ��� �������� �� ���� �������� ������ ��������� ������ �������� ��� ����� �����
	}


	std::vector<li> search(const std::string& _str) // ����� ������ ��������� �����
	{
		std::vector<li> result;
		
		current = &root;
		for (unsigned short int i = 0; i < _str.size(); ++i) // � ����� ��������� � ���������� ����
		{
			if (current->find(_str[i]))// ���� ���� � ��������� ������� ���������� - ��������� � ����
			{
				current = current->next(_str[i]);
			}
			else //���� ���� �� ���������� - �������� ������ ������ - ����������� ������
			{
				return result;
			}
		}

		result = current->get_exist_end(); // ����� ���� ��� ������� � ���������� ���� �������� ����� - �� ������� ���� ����������� ������������ ���������.
		
		
		return result;
	}
	void unload_lib(std::string file_name)
	{
		std::fstream fs(file_name, std::ios::out);
		fs.clear();
		//std::cin.get();
		if (!fs) {}
		else
		{
			std::vector<li> out;
			for (unsigned int i(0); i < root.size(); ++i)
			{
				int zzz = root.size();
				current = root.next(i);
				
				
				out = current->get_exist_end();
				if (current->End())
				{
					fs << current->get_val() << "\t" << current->get_weight()<< std::endl;
				}
				for(const li o:out)
				{
					fs << current->get_val() << o.st << "\t" << o.weight << std::endl;
				}
			}
			fs.close();
		}
	}

protected:
	Node root;
	Node* current;
	
};
