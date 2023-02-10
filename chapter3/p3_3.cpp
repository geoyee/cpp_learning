#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <fstream>

typedef std::string str;
typedef std::vector<std::string> strvec;
typedef std::map<std::string, std::vector<std::string>> ssmap;

strvec strSplit(const str sentence, const str division)
{
	strvec words;
	int start_pos = 0;
	int end_pos = sentence.size();
	int pos = start_pos;
	while (start_pos < end_pos)
	{
		str word;
		pos = sentence.find(division, start_pos);
		if (pos == std::string::npos)
		{
			word = sentence.substr(start_pos, end_pos - start_pos);
			words.push_back(word);
			break;
		}
		word = sentence.substr(start_pos, pos - start_pos);
		words.push_back(word);
		start_pos = pos + 1;
	}
	return words;
}

void printStrVec(const str& s, const strvec& vec)
{
	std::cout << s << " >> ";
	for (str ss : vec)
		std::cout << ss << " ";
	std::cout << std::endl;
}

void printMap(const ssmap map)
{
	for (auto it = map.begin(); it != map.end(); it++)
		printStrVec(it->first, it->second);
}

int main()
{
	ssmap families;
	std::ifstream reader("families_list.txt");
	if (!reader)
	{
		std::cerr << "Can not open file." << std::endl;
		return -1;
	}

	str all_name;
	while (std::getline(reader, all_name))
	{
		strvec names = strSplit(all_name, " ");
		str f_name = names[0];
		names.erase(names.begin());
		families[f_name] = names;
	}

	std::cout << "Please enter a family name: ";
	str input;
	std::cin >> input;
	ssmap::const_iterator it;
	it = families.find(input);
	if (it != families.end())
		printStrVec(it->first, it->second);
	else
		std::cout << "Not find." << std::endl;

	std::cout << "== All families ==" << std::endl;
	printMap(families);

	return 0;
}
