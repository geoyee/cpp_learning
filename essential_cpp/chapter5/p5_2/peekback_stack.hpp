#include "stack.hpp"

class Peekback_Stack : public Stack
{
public:
	Peekback_Stack(int capacity = 0);
        virtual bool peek(int index, elemType& elem);
};

Peekback_Stack::Peekback_Stack(int capacity)
	: Stack(0)
{

}

bool Peekback_Stack::peek(int index, elemType& elem)
{
	if (empty())
		return false;
	if (index < 0 || index >= size())
		return false;
	elem = _stack[index];
	return true;
}
