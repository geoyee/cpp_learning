#include <iostream>
#include "picture.h"

int main()
{
	char const* init[] = {"Paris", "in the", "Spring"};
	Picture p(init, 3);
	Picture q = frame(p);
	std::cout << frame(q & (p | q)) << std::endl;

	return 0;
}
