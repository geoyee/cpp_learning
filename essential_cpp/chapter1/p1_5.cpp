#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>  // setw需要

int main()
{
	// 1. 使用string
	std::cout << "1. string: \n" << std::endl;

	std::string user_name;

	std::cout << "Please enter your name: ";
	std::cin >> user_name;

	int name_len = user_name.length();
	if (name_len < 2)
		std::cout << "\nPlease make sure the length of your name is greater than or equal 2, not "
			  << name_len << "." << std::endl;
	else
		std::cout << "\nHello, " << user_name << "." << std::endl;

	// 2. c-style
	std::cout << "\n2. c-style: \n" << std::endl;

	int nm_size = 128;
	char* user_name_2 = new char[128];

	std::cout << "Please enter your name: ";
	std::cin >> std::setw(nm_size) >> user_name_2;  // 避免超过127个字符
	
	int name_len_2 = strlen(user_name_2);

	if (name_len_2 < 2)
		std::cout << "\nPlease make sure the length of your name is greater than or equal 2, not "
			  << name_len_2 << "." << std::endl;
	else
	{
		if (name_len == 127)
			std::cout << "\nSo big name, it has been cut off.";
		std::cout << "\nHello, " << user_name_2 << "." << std::endl;
	}

	return 0;
}
