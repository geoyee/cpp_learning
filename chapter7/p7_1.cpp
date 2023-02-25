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


// 修改后
int* alloc_and_init(std::string file_name)
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
