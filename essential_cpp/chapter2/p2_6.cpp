#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

template <typename Type>
Type mmax(Type a, Type b)
{
	return a > b ? a : b;
}

template <typename ArrType>
ArrType mmax(const ArrType* arr, int num)
{
	return *max_element(arr, arr + num);
}

template <typename VecType>
VecType mmax(const vector<VecType> vec)
{
	return *max_element(vec.begin(), vec.end());
}

int main()
{
	int ia = 1, ib = 12;
	cout << "max(" << ia << ", " << ib << ") = " << mmax<int>(ia, ib) << endl;
	float fa = 45.2, fb = 14.6;
	cout << "max(" << fa << ", " << fb << ") = " << mmax<float>(fa, fb) << endl;

	int isize = 5;
	int iarr[] = {1, 2, 5, 6, 9};
	vector<int> ivec(iarr, iarr + isize);
	cout << "max(iarr) = " << mmax<int>(iarr, isize) << endl;
	cout << "max(ivec) = " << mmax<int>(ivec) << endl;
	
	int fsize = 7;
	float farr[] = {1.2, 2.9, 5.4 , 9.1, 6.6, 6.4, 9.0};
	vector<float> fvec(farr, farr + fsize);
	cout << "max(farr) = " << mmax<float>(farr, fsize) << endl;
	cout << "max(fvec) = " << mmax<float>(fvec) << endl;
	
	int ssize = 3;
	string sarr[] = {"here", "you", "are"};
	vector<string> svec(sarr, sarr + ssize);
	cout << "max(sarr) = " << mmax<string>(sarr, ssize) << endl;
	cout << "max(svec) = " << mmax<string>(svec) << endl;

	return 0;
}
