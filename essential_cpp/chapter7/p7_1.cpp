#include <iostream>
#include <string>

// 原始代码
int* alloc_and_init(std::string file_name)
{
	std::ifstream infile(file_name);
	int elem_cnt;
	infile >> elem_cnt;
	int* pi = allocate_array(elem_cnt);

	int elem;
	int index = 0;
	while (infile >> elem)
		pi[index++] = elem;

	sort_array(pi, elem_cnt);
	register_data(pi);

	return pi;
}


// 7.1修改后
int* alloc_and_init_1(std::string file_name)
{
	std::ifstream infile(file_name.c_str());
	if (!infile)  // 判断文件是否正常打开
		return -1;
	int elem_cnt;
	infile >> elem_cnt;
	if (!infile)  // 判断读取的东西的是否正常
		return -1;
	int* pi = allocate_array(elem_cnt);
	if (!pi)  // 判断空间分配有没有问题
		return -1;

	int elem;
	int index = 0;
	while (infile >> elem)
		pi[index++] = elem;

	sort_array(pi, elem_cnt);
	register_data(pi);

	return pi;
}

// 7.2修改后
int* alloc_and_init_2(std::string file_name)
{	
	try
		alloc_and_init_1(file_name);
	catch (const noMem& allocate_array_err)
	{
		std::cerr << allocate_array_err << std::endl;
		return -1;
	}
	catch (int& sort_array_err)
	{
		std::cerr << sort_array_err << std::endl;
		return -1;
	}
	catch (std::string& register_data_err)
	{
		std::cerr << register_data_err << std::endl;
		return -1;
	}	
}
