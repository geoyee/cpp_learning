#include "stack.h"

int main()
{
	Stack st;
	std::string strs;
	
	std::cout << st.empty() << std::endl;
	st.push("one");
	st.push("day");
	std::cout << st.size() << std::endl;
	st.peek(strs);
	std::cout << strs << " " << st.size() << std::endl;
	st.pop(strs);
	std::cout << strs << " " << st.size() << std::endl;

	return 0;
}
