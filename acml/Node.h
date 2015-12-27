#include <map>
#include <vector>
#include <iostream>
#include <string>


class Node
{
public:
	Node(){}
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
	std::vector<std::string> get_exist_end()const
	{

		std::vector<std::string> result;
		std::string tmp;
		for (const auto& elem : list)
		{
			if (elem.second.End())
			{
				tmp = elem.first;
				result.push_back(tmp);
				for (const auto& elem1 : elem.second.get_exist_end())
				{
					tmp = elem.first + elem1;
					result.push_back(tmp);
				}
			}
			else
			{
				for (const auto& elem1 : elem.second.get_exist_end())
				{
					tmp =elem.first+ elem1;
					result.push_back(tmp);
				}
			}
		}
		return result;
	}

	char size_nodes()const
	{
		return list.size();
	}

protected:
	char _val;
	bool _end;
	std::map<char, Node> list;
};

