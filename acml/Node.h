#include <map>
#include <vector>
#include <iostream>
#include <string>


class li;

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
	
		if(list.find(in)!=list.end())
		{
			return true;
		}
		else
		{
			return false;
		}
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
	std::map<unsigned int, std::string> get_exist_end()const
	{

		std::map<unsigned int, std::string> result;
		std::string tmp;
		for (const auto& elem : list)
		{
			if (elem.second.End())
			{

				tmp = elem.first;

				result[elem.second.get_weight()] = tmp;
				for (const auto& elem1 : elem.second.get_exist_end())
				{
					tmp = elem.first + elem1.second;
					result[elem1.first]=tmp;
				}
			}
			else
			{
				for (const auto& elem1 : elem.second.get_exist_end())
				{
					tmp = elem.first + elem1.second;
					result[elem1.first] = tmp;
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
	
protected:
	unsigned int weight=0;
	char _val;
	bool _end;
	std::map<char, Node> list;
};

class li
{
public:

	li(){}
	li(unsigned int _i, std::string s)
	{
		w = _i;
		str = s;
	}
	unsigned int w=0;
	std::string str;

};

