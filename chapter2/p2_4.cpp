#include <iostream>
#include <vector>

int _calcPentagonalElemByIndex(int index)
{
	return index * (3 * index - 1) / 2;
}

const std::vector<int>* pentagonal(int elemSize)
{
	static std::vector<int> pElems;
	while (pElems.size() < elemSize)
	{
		pElems.push_back(_calcPentagonalElemByIndex(pElems.size() + 1));
	}
	return &pElems;
}

int getPentagonalElemByIndex(int index)
{
	return (*pentagonal(index))[index - 1];
}

int main(int argc, char** argv)
{
	const int MAX_IND = 64;
	int ind;
	std::cout << "Please input index: ";
	std::cin >> ind;
	if (ind <= 0 || ind > MAX_IND)
	{
		std::cerr << "Invalid index." << std::endl;
		return -1;
	}
	else
	{
		std::cout << "# elem " << ind << " is " << getPentagonalElemByIndex(ind) << std::endl;
		return 0;
	}
}
