#include "stack.h"

int main()
{
	Stack st;
	std::string strs;
	
	std::cout << st.empty() << std::endl;
	st.push("one");
	st.push("day");
	st.push("is");
	st.push("a");
	st.push("good");
	st.push("day");
	st.push("!");
	std::cout << st.size() << std::endl;
	st.peek(strs);
	std::cout << strs << " " << st.size() << std::endl;
	st.pop(strs);
	std::cout << strs << " " << st.size() << std::endl;
	std::cout << st.find("one") << " " << st.find("two") << std::endl;
	std::cout << st.count("day") << " " << st.count("year") << std::endl;	

	return 0;
}
