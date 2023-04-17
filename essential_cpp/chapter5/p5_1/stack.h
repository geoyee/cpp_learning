#include <iostream>
#include <string>
#include <vector>

typedef std::string elemType;

class Vstack
{
public:
	virtual ~Vstack() {}
	virtual bool pop(elemType& elem) = 0;
	virtual bool push(elemType& elem) = 0;
	virtual bool peek(int index, elemType& elem) = 0;
	virtual int top() const = 0;
	virtual int size() const = 0;
	virtual bool empty() const = 0;
	virtual bool full() const = 0;
	virtual void print(std::ostream& os=std::cout) const = 0;
};

std::ostream& operator<<(std::ostream& os, const Vstack& rhs)
{
	rhs.print(os);
	return os;
}

