#include <iostream>

typedef float elemType;

class Matrix
{
	friend Matrix operator+(const Matrix& m1, const Matrix& m2);
	friend Matrix operator*(const Matrix& m1, const Matrix& m2);

private:
	elemType _matrix[4][4];

public:
	Matrix(const elemType* array);
	Matrix(elemType a11 = 0., elemType a12 = 0., elemType a13 = 0., elemType a14 = 0.,
	       elemType a21 = 0., elemType a22 = 0., elemType a23 = 0., elemType a24 = 0.,
	       elemType a31 = 0., elemType a32 = 0., elemType a33 = 0., elemType a34 = 0.,
	       elemType a41 = 0., elemType a42 = 0., elemType a43 = 0., elemType a44 = 0.);
	int rows() const { return 4; }
	int cols() const { return 4; }
	std::ostream& print(std::ostream& os) const;
	void operator+=(const Matrix& m);
	elemType operator()(int row, int column) const
		{ return _matrix[row][column]; }
	elemType& operator()(int row, int column)
		{ return _matrix[row][column]; }
};

inline std::ostream& operator<<(std::ostream& os, const Matrix& m)
{ 
	return m.print(os); 
}

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	Matrix result(m1);
	result += m2;
	return result;
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{
	Matrix result;
	for (int ix = 0; ix < m1.rows(); ix++)
	{
		for (int jx = 0; jx < m1.cols(); jx++)
		{
			result(ix, jx) = 0;
			for (int kx = 0; kx < m1.cols(); kx++)
				result(ix, jx) += m1(ix, kx) * m2(kx, jx);
		}
	}
	return result;
}

void Matrix::operator+=(const Matrix& m)
{
	for (int ix = 0; ix < 4; ++ix)
		for (int jx = 0; jx < 4; ++jx)
			_matrix[ix][jx] += m._matrix[ix][jx];
}

std::ostream& Matrix::print(std::ostream& os) const
{
	int cnt = 0;
	for (int ix = 0; ix < 4; ix++)
	{
		for (int jx = 0; jx < 4; ++jx, ++cnt)
		{
			if (cnt && !(cnt % 8))
				os << std::endl;
			os << _matrix[ix][jx] << " ";
		}
	}
	os << std::endl;
	return os;
}

Matrix::Matrix(const elemType* array)
{
	int array_index = 0;
	for (int ix = 0; ix < 4; ++ix)
		for (int jx = 0; jx < 4; ++jx)
			_matrix[ix][jx] = array[array_index++];
}

Matrix::Matrix(elemType a11, elemType a12, elemType a13, elemType a14,
	       elemType a21, elemType a22, elemType a23, elemType a24,
	       elemType a31, elemType a32, elemType a33, elemType a34,
	       elemType a41, elemType a42, elemType a43, elemType a44)
{
	_matrix[0][0] = a11;
	_matrix[0][1] = a12;
	_matrix[0][2] = a13;
	_matrix[0][3] = a14;
	_matrix[1][0] = a21;
	_matrix[1][1] = a22;
	_matrix[1][2] = a23;
	_matrix[1][3] = a24;
	_matrix[2][0] = a31;
	_matrix[2][1] = a32;
	_matrix[2][2] = a33;
	_matrix[2][3] = a34;
	_matrix[3][0] = a41;
	_matrix[3][1] = a42;
	_matrix[3][2] = a43;
	_matrix[3][3] = a44;
}

