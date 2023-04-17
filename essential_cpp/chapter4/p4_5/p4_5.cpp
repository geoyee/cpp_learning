#include "matrix.hpp"

int main()
{
	Matrix m;
	std::cout << m << std::endl;

	elemType arr[16] = {
		1., 2., 3., 4.,
		0., 5., 2., 0.,
		9., 7., 7., 4., 
		0., 0., 0., 1.
	};
	Matrix m2(arr);
	std::cout << m2 << std::endl;

	Matrix m3(m2);
	std::cout << m3 << std::endl;

	elemType arr2[16] = {
		1., 0., 0., 0.,
		0., 9., 0., 0.,
		0., 0., 4., 0., 
		0., 0., 0., 5.
	};
	Matrix m4(arr2);
	Matrix m5 = m2 + m4;
	std::cout << m5 << std::endl;
	Matrix m6 = m2 * m4;
	std::cout << m6 << std::endl;

	return 0;
}
