#include <iostream>

template <typename elemType>
class Matrix
{
	template <typename T>
	friend Matrix<elemType> operator+(const Matrix<elemType>& m1, const Matrix<elemType>& m2);
	template <typename T>
	friend Matrix<elemType> operator*(const Matrix<elemType>& m1, const Matrix<elemType>& m2);

protected:
	int _rows;
	int _cols;
	elemType* _matrix;

public:
	Matrix(int rows, int columns);
	Matrix(const Matrix& m);
	~Matrix() { delete[] _matrix; }
	int rows() const { return _rows; }
	int cols() const { return _cols; }
	std::ostream& print(std::ostream& os) const;
	Matrix& operator=(const Matrix& m);
	void operator+=(const Matrix& m);
	elemType& operator()(int row, int column)
		{ return _matrix[row * cols() + column]; }
	const elemType& operator()(int row, int column) const
		{ return _matrix[row * cols() + column]; }
	bool sameSize(const Matrix& m) const
		{ return (rows() == m.rows() && cols() == m.cols()); }
	bool comfortable(const Matrix& m) const
		{ return (cols() == m.rows()); }
};

template <typename elemType>
inline std::ostream& operator<<(std::ostream& os, const Matrix<elemType>& m)
{ 
	return m.print(os); 
}

template <typename elemType>
Matrix<elemType> operator+(const Matrix<elemType>& m1, const Matrix<elemType>& m2)
{
	Matrix<elemType> result(m1);
	result += m2;
	return result;
}

template <typename elemType>
Matrix<elemType> operator*(const Matrix<elemType>& m1, const Matrix<elemType>& m2)
{
	Matrix<elemType> result(m1.rows(), m2.cols());
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

template <typename elemType>
void Matrix<elemType>::operator+=(const Matrix<elemType>& m)
{
	int matrix_size = cols() * rows();
	for (int ix = 0; ix < matrix_size; ++ix)
		(*(_matrix + ix)) += (*(m._matrix + ix));
}

template <typename elemType>
std::ostream& Matrix<elemType>::print(std::ostream& os) const
{
	int col = cols();
	int matrix_size = cols() * rows();
	for (int ix = 0; ix < matrix_size; ix++)
	{
		if (ix % col == 0)
			os << std::endl;
		os << (*(_matrix + ix)) << " ";
	}
	os << std::endl;
	return os;
}

template <typename elemType>
Matrix<elemType>::Matrix(int rows, int columns)
	: _rows(rows), _cols(columns)
{
	int size = _rows * _cols;
	_matrix = new elemType[size];
	for (int ix = 0; ix < size; ++ix)
		_matrix[ix] = elemType();
}

template <typename elemType>
Matrix<elemType>::Matrix(const Matrix& m)
{
	_rows = m._rows;
	_cols = m._cols;
	int matrix_size = _rows * _cols;
	_matrix = new elemType[matrix_size];
	for (int ix = 0; ix < matrix_size; ++ix)
		_matrix[ix] = m._matrix[ix];
}

template <typename elemType>
Matrix<elemType>& Matrix<elemType>::operator=(const Matrix<elemType>& m)
{
	if (this != &m)
	{
		_rows = m._rows;
        	_cols = m._cols;
        	int matrix_size = _rows * _cols;
        	_matrix = new elemType[matrix_size];
        	for (int ix = 0; ix < matrix_size; ++ix)
                	_matrix[ix] = m._matrix[ix];
	}
	return *this;
}
