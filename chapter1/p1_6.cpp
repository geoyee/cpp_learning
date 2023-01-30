#include <iostream>
#include <vector>

int main()
{
	std::vector<int> ivec;
	const int max_number = 128;
	int iarr[max_number];

	int ival;
	int arr_size = 0;
	std::cout << "Please enter some integer: ";
	while (std::cin >> ival)
	{
		ivec.push_back(ival);
		iarr[arr_size++] = ival;
	}

	int vec_sum = 0;
	double vec_avg = 0.f;
	for (int val : ivec)
		vec_sum += val;
	vec_avg = vec_sum / ivec.size();
	std::cout << "[vector]\nsum: " << vec_sum << ", avg: " << vec_avg << std::endl;

	int arr_sum = 0;
	double arr_avg = 0.f;
	for (int i = 0; i < arr_size; i++)
		arr_sum += iarr[i];
	arr_avg = arr_sum / arr_size;
	std::cout << "[array]\nsum: " << arr_sum << ", avg: " << arr_avg << std::endl;

	return 0;
}
