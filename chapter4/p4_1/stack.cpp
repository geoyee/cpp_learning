#include <algorithm>
#include "stack.h"

bool Stack::push(const std::string& elem)
{
	if (!full())
	{
		_stack.push_back(elem);
		return true;
	}
	return false;
}

bool Stack::pop(std::string& elem)
{
	if (!empty())
	{
		elem = _stack.back();
		_stack.pop_back();
		return true;
	}
	return false;
}

bool Stack::peek(std::string& elem)
{	
	if (!empty())
	{
		elem = _stack.back();
		return true;
	}
	return false;
}

bool Stack::find(const std::string& elem) const
{
	// 需要使用全局命名空间的find
	return std::find(_stack.begin(), _stack.end(), elem) != _stack.end(); 
}

int Stack::count(const std::string& elem) const
{
	int number = 0;
	for (std::string output : _stack)
	{
		if (output == elem)
			number++;
	}
	return number;
	// return std::count(_stack.begin(), _stack.end(), elem);
}
