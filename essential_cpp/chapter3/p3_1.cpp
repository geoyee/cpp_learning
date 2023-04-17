#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

void initExcSet(set<string>& eset)
{
	const string exc_str_arr[25] = {
		"the", "and", "but", "that", "then", "are", "been",
		"can", "a", "could", "did", "for", "of",
		"had", "have", "him", "his", "her", "its", "is",
		"were", "which", "when", "with", "would"
	};
	eset.insert(exc_str_arr, exc_str_arr+25);
}

int main()
{
	// 文件初始化
	ifstream reader("column.txt");
	ofstream writer("column_map.txt");
	if (!reader || !writer)
	{
		cerr << "Can not open or create file." << endl;
		return -1;
	}
	// 定义set和map
	set<string> exc_set;
	initExcSet(exc_set);
	map<string, int> word_map;
	// 循环读取判断添加
	string word;
	while (reader >> word)
	{
		// 擦除标点
		auto p = remove_if(word.begin(), word.end(), [](char const &c) {
        		return std::ispunct(c);
    		});
    		word.erase(p, word.end());
		// 转为小写
		transform(word.begin(), word.end(), word.begin(), ::tolower);  // 全局命名空间的tolower
		// 判断添加
		if (exc_set.count(word) != 0)
			continue;
		word_map[word]++;
	}
	// 判断用户输入是否存在
	string user_str;
	string again;
	map<string, int>::const_iterator it;
	do
	{
		cout << "Please enter a word: ";
		cin >> user_str;
		it = word_map.find(user_str);
		if (it != word_map.end())
			cout << "Find word `" << user_str << "` and count is " << word_map[user_str] << endl;
		else
			cout << "Can not find word `" << user_str << "`" << endl;
		cout << "Try again? (y/n): ";
		cin >> again;
	}
	while (again == "y");
	// 打印结果
	cout << "== Word Map ==";
	for (it = word_map.begin(); it != word_map.end(); it++)
	{
		cout << it->first << ": " << it->second << "\n";
	}
	cout << endl;

	return 0;
}
