#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

void displayVector(const std::vector<std::string>& vec)
{
	for (std::string word : vec)
		std::cout << word << " ";
	std::cout << std::endl;
}

bool wordSort(const std::string& w1, const std::string& w2)
{
	return w1.size() < w2.size();
}

int main()
{
	std::ifstream reader("column.txt");
	if (!reader)
	{
		std::cerr << "Can not open file." << std::endl;
		return -1;
	}

	std::vector<std::string> word_list;
	std::string word;
	while (reader >> word)
	{
		auto p = remove_if(word.begin(), word.end(), [](char const &c) {
        		return std::ispunct(c);
    		});  // 查找标点
    		word.erase(p, word.end());  // 擦除标点
		word_list.push_back(word);  // 添加到vector
	}

	std::cout << "before sort: " << std::endl;
	displayVector(word_list);

	std::sort(word_list.begin(), word_list.end(), wordSort);

	std::cout << "after sort: " << std::endl;
	displayVector(word_list);

	return 0;
}
