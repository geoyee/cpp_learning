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
