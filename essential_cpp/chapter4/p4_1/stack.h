#include <iostream>
#include <string>
#include <vector>

class Stack
{
private:
	std::vector<std::string> _stack;

public:
	bool push(const std::string& elem);
	bool pop(std::string& elem);
	bool peek(std::string& elem);
	bool find(const std::string& elem) const;
	int count(const std::string& elem) const;
	bool empty() const { return _stack.empty(); }
	bool full() const { return _stack.size() == _stack.max_size(); }
	int size() const { return _stack.size(); }
};
