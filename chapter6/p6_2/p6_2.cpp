#include "matrix.hpp"

int main()
{
	Matrix<float> identity(4, 4);
	std::cout << identity << std::endl;

	float arr[16] = {
		1., 0., 0., 0.,
		0., 1., 0., 0.,
		0., 0., 1., 0., 
		0., 0., 0., 1.
	};
	for (int i = 0, k = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			identity(i, j) = arr[k++];
	std::cout << identity << std::endl;

	Matrix<float> m(identity);
	std::cout << m << std::endl;

	Matrix<float> m2(8, 12);
	std::cout << m2 << std::endl;

	m2 = m;
	std::cout << m2 << std::endl;

	Matrix<float> m3(4, 4);
	float arr2[16] = {
		1., 0., 6.3, 7.5,
		2.2, 9., 4.5, 0.,
		0., 0., 4., 0., 
		0.9, 0., 4.5, 5.
	};
	for (int i = 0, k = 0; i < 4; ++i)
                for (int j = 0; j < 4; ++j)
                        m3(i, j) = arr2[k++];
        std::cout << m3 << std::endl;

	Matrix<float> m4 = m3 * identity;
	std::cout << m4 << std::endl;
	Matrix<float> m5 = m3 + m4;
	std::cout << m5 << std::endl;

	return 0;
}
