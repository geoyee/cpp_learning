#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}

float max(float a, float b)
{
	return a > b ? a : b;
}

int max(vector<int> vec)
{
	return *max_element(vec.begin(), vec.end());
}

float max(vector<float> vec)
{
	return *max_element(vec.begin(), vec.end());
}

string max(vector<string> vec)
{
	return *max_element(vec.begin(), vec.end());
}

int max(int* arr, int num)
{
	return *max_element(arr, arr + num);
}

float max(float* arr, int num)
{
	return *max_element(arr, arr + num);
}

string max(string* arr, int num)
{
	return *max_element(arr, arr + num);
}

int main()
{
	int ia = 1, ib = 12;
	cout << "max(" << ia << ", " << ib << ") = " << max(ia, ib) << endl;
	float fa = 45.2, fb = 14.6;
	cout << "max(" << fa << ", " << fb << ") = " << max(fa, fb) << endl;

	int isize = 5;
	int iarr[] = {1, 2, 5, 6, 9};
	vector<int> ivec(iarr, iarr + isize);
	cout << "max(iarr) = " << max(iarr, isize) << endl;
	cout << "max(ivec) = " << max(ivec) << endl;
	
	int fsize = 7;
	float farr[] = {1.2, 2.9, 5.4 , 9.1, 6.6, 6.4, 9.0};
	vector<float> fvec(farr, farr + fsize);
	cout << "max(farr) = " << max(farr, fsize) << endl;
	cout << "max(fvec) = " << max(fvec) << endl;
	
	int ssize = 3;
	string sarr[] = {"here", "you", "are"};
	vector<string> svec(sarr, sarr + ssize);
	cout << "max(sarr) = " << max(sarr, ssize) << endl;
	cout << "max(svec) = " << max(svec) << endl;

	return 0;
}
