#include "lifo_stack.hpp"
#include "peekback_stack.hpp"

void peek(Vstack& st, int index)
{
	std::cout << std::endl;
	std::string t;
	if (st.peek(index, t))
		std::cout << "Peek: " << t;
	else
		std::cout << "Peek failed";
	std::cout << std::endl;
}

int main()
{
	LIFO_Stack st;
	std::string str;
	while (std::cin >> str && !st.full())
		st.push(str);
	std::cout << "\n" << "About to call peek() with LIFO_Stack:" << std::endl;
	peek(st, st.top() - 1);
	std::cout << st;

	Peekback_Stack pst;
	while (!st.empty())
	{
		std::string t;
		if (st.pop(t))
			pst.push(t);
	}
	std::cout << "About to call peek() with Peekback_Stack:" << std::endl;
	peek(pst, pst.top() - 1);
	std::cout << pst << std::endl;

	return 0;
}
