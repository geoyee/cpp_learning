#include <iostream>
#include <string>
#include <vector>

typedef std::string elemType;

class Stack
{
protected:
	std::vector<elemType> _stack;
	int _top;

public:
	Stack(int capacity = 0);
	virtual ~Stack() {}
        bool pop(elemType& elem);
        bool push(elemType& elem);
        virtual bool peek(int index, elemType& elem) { return false; }
        int top() const { return _top; }
        int size() const { return _stack.size(); }
        bool empty() const { return !_top; }
	bool full() const { return size() >= _stack.max_size(); }
        void print(std::ostream& os=std::cout) const;
};

Stack::Stack(int capacity)
	: _top(0)
{
	if (capacity)
		_stack.reserve(capacity);
}

bool Stack::pop(elemType& elem)
{
	if (empty())
		return false;
	elem = _stack[--_top];
	_stack.pop_back();
	return true;
}

bool Stack::push(elemType& elem)
{
	if (full())
		return false;
	_stack.push_back(elem);
	++_top;
	return true;
}

void Stack::print(std::ostream& os) const
{
	std::vector<elemType>::const_reverse_iterator 
		rit = _stack.rbegin(), 
		rend = _stack.rend();
	os << "\n\t";
	while (rit != rend)
		os << *rit++ << "\n\t";
	os << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Stack& rhs)
{
        rhs.print(os);
        return os;
}
