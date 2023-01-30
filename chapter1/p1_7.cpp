#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	std::ifstream reader("./p1_7_text.txt");
	if (!reader)
		std::cerr << "Can not open this file." << std::endl;
	std::ofstream writer("./p1_7_text_sort.txt");
	if (!writer)
		std::cerr << "Can not open output file." << std::endl;
	std::vector<std::string> word_list;

	// 读取信息并显示
	std::string word;
	while (reader >> word)
		word_list.push_back(word);
	std::cout << "Raw text: \n";
	for (std::string word : word_list)
		std::cout << word << " ";
	std::cout << std::endl;

	// 排序并显示/保存
	sort(word_list.begin(), word_list.end());
	std::cout << "Sorted text: \n";
	for (std::string word : word_list)
	{
		std::cout << word << " ";
		writer << word << " ";
	}
	std::cout << std::endl;
	writer << std::endl;

	return 0;
}
