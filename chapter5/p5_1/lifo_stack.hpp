#ifndef _STACK_H_
#define _STACK_H_
#include "stack.h"
#endif

class LIFO_Stack : public Vstack
{
private:
	std::vector<elemType> _stack;
	int _top;

public:
	LIFO_Stack(int capacity = 0);
        bool pop(elemType& elem);
        bool push(elemType& elem);
        bool peek(int index, elemType& elem);
        int top() const { return _top; }
        int size() const { return _stack.size(); }
        bool empty() const { return !_top; }
	bool full() const { return size() >= _stack.max_size(); }
        void print(std::ostream& os=std::cout) const;
};

LIFO_Stack::LIFO_Stack(int capacity)
	: _top(0)
{
	if (capacity)
		_stack.reserve(capacity);
}

bool LIFO_Stack::pop(elemType& elem)
{
	if (empty())
		return false;
	elem = _stack[--_top];
	_stack.pop_back();
	return true;
}

bool LIFO_Stack::push(elemType& elem)
{
	if (full())
		return false;
	_stack.push_back(elem);
	++_top;
	return true;
}

bool LIFO_Stack::peek(int index, elemType& elem)
{
	return false;
}

void LIFO_Stack::print(std::ostream& os) const
{
	std::vector<elemType>::const_reverse_iterator 
		rit = _stack.rbegin(), 
		rend = _stack.rend();
	os << "\n\t";
	while (rit != rend)
		os << *rit++ << "\n\t";
	os << std::endl;
}
