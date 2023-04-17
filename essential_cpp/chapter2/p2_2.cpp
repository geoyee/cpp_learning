#include <iostream>
#include <vector>
#include <string>

int _pentagonal(int pos)
{
	return pos * (3 * pos - 1) / 2;
}

bool save_pentagonal(std::vector<int> &vec, int number)
{
	int MAX_INDEX = 64;
	if (number <= 0 || number > MAX_INDEX)
	{
		std::cerr << "Invalid position: " << number << std::endl;
		return false;
	}
	else
	{
		for (int i = 0; i < number; i++)
			vec.push_back(_pentagonal(i));
		return true;
	}
}

void display_vector(std::vector<int> &vec, const std::string &title)
{
	std::cout << title << "\n";
	for (int n : vec)
		std::cout << n << " ";
	std::cout << std::endl;
}

int main()
{
	std::vector<int> pent;
	const std::string title("Pentagonal Numeric Series");

	if (save_pentagonal(pent, 0))
		display_vector(pent, title);
	if (save_pentagonal(pent, 12))
		display_vector(pent, title);
	if (save_pentagonal(pent, 256))
		display_vector(pent, title);

	return 0;
}
