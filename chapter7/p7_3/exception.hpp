#include <iostream>

class StackException : public std::exception
{
protected:
	const char* message_;		

public:
	StackException(const char* message)
		: message_(message)
	{ }

	const char* what() const noexcept override { return message_; }
};

class PopOnEmpty : public StackException
{
public:
	PopOnEmpty() 
		: StackException("Pop on empty stack!")
	{ }
};

class PushOnFull : public StackException
{
public:
	PushOnFull() 
		: StackException("Push on full stack!")
	{ }
};
