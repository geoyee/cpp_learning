#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <fstream>

bool evenElem(int elem)
{
	return elem % 2 ? false : true;
}

int main()
{
	std::vector<int> input;
	std::istream_iterator<int> in(std::cin), eos;

	std::copy(in, eos, back_inserter(input));
	std::vector<int>::iterator div = std::stable_partition(input.begin(), input.end(), evenElem);

	std::ofstream even_file("even_file.txt"),
		      odd_file("odd_file.txt");
	if (!even_file || !odd_file)
	{
		std::cerr << "Can not create file." << std::endl;
		return -1;
	}

	std::ostream_iterator<int> even_iter(even_file, "\n");
	std::ostream_iterator<int> odd_iter(odd_file, " ");
	std::copy(input.begin(), div, even_iter);
	std::copy(div, input.end(), odd_iter);

	return 0;
}
