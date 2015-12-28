#include <map>
#include <vector>
#include <iostream>
#include <string>


class li
{
public:
	li(unsigned int i, std::string _st)
	{
		weight = i;
		st = _st;
	}
	bool operator==(const li& _in)const // перегрузка оператора для сортировки.
	{
		if(weight==_in.weight)
		{
			return true;
		}
		return false;
	}

	bool operator <(const li& right)const // перегрузка оператора для сортировки 
	{
		if(weight<right.weight)
		{
			return true;
		}
		return false;
	}
	unsigned int weight;
	std::string st;
};

class Node
{
public:
	Node() {}
	Node(char _elem)
	{
		_val = _elem;
	}

	bool find(const char& in)
	{
	
		if(list.find(in)!=list.end()) // Если данный символ является концом - значит это последний симвл слова
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void set_weigth_up() 
	{
		++weight;
	}
	Node* next(unsigned int i)
	{
		std::map<char, Node>::iterator iter = list.begin();
		for (; i > 0; --i, ++iter)
		{
			std::cout << "i" << std::endl;
		}
		return	&(iter->second);;
	}
	Node* next(char _val)
	{
		return	&list[_val];
	}
	void add(char _elem)
	{
		Node nNode(_elem);
		list[_elem] = nNode;
	}
	bool End()const
	{
		return _end;
	}
	void Set_end()
	{
		_end = true;
	}
	char get_val()
	{
		return _val;
	}
	std::vector<li> get_exist_end()const // В рекурсии перебираются нижние узлы и формируется список существующих окончаний от запрошенного узла
	{

		std::vector<li> result;
		std::string tmp;
		for (const auto& elem : list)
		{
			if (elem.second.End())
			{
				
				tmp = elem.first;
				li l(elem.second.get_weight(), tmp);
				result.push_back(l);
				for (const auto& elem1 : elem.second.get_exist_end())
				{
					tmp = elem.first + elem1.st;
					li l(elem1.weight, tmp);
					result.push_back(l);
				}
			}
			else
			{
				for (const auto& elem1 : elem.second.get_exist_end())
				{
					tmp = elem.first + elem1.st;
					li l(elem1.weight, tmp);
					result.push_back(l);
				}
			}
		}
		return result;
	}
	std::vector<li> get_lib()const
	{

		std::vector<li> result;
		std::string tmp;
		for (const auto& elem : list)
		{
			if (_end)
			{

				tmp = _val;
				li l(weight, tmp);
				result.push_back(l);
				for (const auto& elem1 : elem.second.get_lib())
				{
					tmp = _val + elem1.st;
					li l(elem1.weight, tmp);
					result.push_back(l);
				}
			}
			else
			{
				for (const auto& elem1 :elem.second.get_lib())
				{
					tmp = _val + elem1.st;
					li l(elem1.weight, tmp);
					result.push_back(l);
				}
			}
		}
		return result;
	}

	char size_nodes()const
	{
		return list.size();
	}
	void set_weigth(unsigned int _weight)
	{
		weight = _weight;
	}

	unsigned int get_weight()const
	{
		return weight;
	}
	unsigned int size()
	{
		return list.size();
	}
protected:
	unsigned int weight=0;
	char _val;
	bool _end;
	std::map<char, Node> list;
};

