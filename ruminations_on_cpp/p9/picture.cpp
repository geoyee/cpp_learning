#include <cstring>
#include "picture.h"

inline char& Picture::position(int row, int col)
{
	return data[row * width + col];
}

inline char Picture::position(int row, int col) const
{
	return data[row * width + col];
}

inline int Picture::max(int m, int n)
{
	return m > n ? m : n;
}

inline void Picture::init(int h, int w)
{
	height = h;
	width = w;
	data = new char[height * width];
}

inline void Picture::copyBlock(int r, int c, const Picture& p)
{
	for (int i = 0; i < p.height; ++i)
		for (int j = 0; j < p.width; ++j)
			Picture::position(i + r, j + c) = p.position(i, j);
}

inline void Picture::clear(int r1, int c1, int r2, int c2)
{
	for (int r = r1; r < r2; ++r)
		for (int c = c1; c < c2; ++c)
			Picture::position(r, c) = ' ';
}

std::ostream& operator<<(std::ostream& os, const Picture& p)
{
	for (int i = 0; i < p.height; ++i)
	{
		for (int j = 0; j < p.width; ++j)
			os << p.position(i, j);
		os << std::endl;
	}
	return os;
}

Picture::Picture()
	: height(0), width(0), data(nullptr)
{ }

Picture::Picture(const char* const* array, int n)
{
	int w = 0;
	for (int i = 0; i < n; ++i)
		w = Picture::max(w, strlen(array[i]));
	Picture::init(n, w);
	for (int i = 0; i < n; ++i)
	{
		const char* src = array[i];
		int len = strlen(src);
		int j = 0;
		while (j < len)
		{
			Picture::position(i, j) = src[j];
			++j;
		}
		while (j < width)
		{
			Picture::position(i, j) = ' ';
			++j;
		}
	}
}

Picture::Picture(const Picture& p)
	: height(p.height), width(p.width), data(new char[p.height * p.width])
{
	Picture::copyBlock(0, 0, p);
}

Picture::~Picture()
{
	delete[] data;
}

Picture Picture::operator=(const Picture& p)
{
	if (this != &p)
	{
		delete[] data;
		Picture::init(p.height, p.width);
		Picture::copyBlock(0, 0, p);
	}
	return *this;
}

Picture operator&(const Picture& p1, const Picture& p2)
{
	Picture r;
	r.init(p1.height + p2.height, Picture::max(p1.width, p2.width));
	r.clear(0, p1.width, p1.height, r.width);
	r.clear(p1.height, p2.width, r.height, r.width);
	r.copyBlock(0, 0, p1);
	r.copyBlock(p1.height, 0, p2);
	return r;
}

Picture operator|(const Picture& p1, const Picture& p2)
{
	Picture r;
	r.init(Picture::max(p1.height, p2.height), p1.width + p2.width);
	r.clear(p1.height, 0, r.height, p1.width);
	r.clear(p2.height, p1.width, r.height, r.width);
	r.copyBlock(0, 0, p1);
	r.copyBlock(0, p1.width, p2);
	return r;
}

Picture frame(const Picture& p)
{
	Picture r;
	r.init(p.height + 2, p.width + 2);
	// 画左右框
	for (int i = 1; i < r.height - 1; ++i)
	{
		r.position(i, 0) = '|';
		r.position(i, r.width - 1) = '|';
	}
	// 画上下框
	for (int j = 1; j < r.width - 1; ++j)
	{
		r.position(0, j) = '-';
		r.position(r.height - 1, j) = '-';
	}
	// 画四个角点
	r.position(0, 0) = '+';
	r.position(0, r.width - 1) = '+';
	r.position(r.height - 1, 0) = '+';
	r.position(r.height - 1, r.width - 1) = '+';
	// 填充数据
	r.copyBlock(1, 1, p);
	return r;
}
