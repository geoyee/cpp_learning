#include <iostream>

int fibon_elem(int pos)
{
	if (pos == 0 || pos == 1)
		return pos;
	else
		return fibon_elem(pos - 1) + fibon_elem(pos - 2);
}

int main()
{
	int pos;
	char ag;

	do
	{
		std::cout << "Please enter a position: ";
		std::cin >> pos;
		std::cout << "element # " << pos << " is " << fibon_elem(pos) << std::endl;

		std::cout << "Would you like to try again? (y/n): ";
		std::cin >> ag;
	}
	while (ag == 'y' || ag == 'Y');

	return 0;
}
