#pragma once

#include <iostream>

class Picture
{	
private:
	int height, width;
	char* data;

	char& position(int row, int col);  // 允许直接读写
	char position(int row, int col) const;  // 返回所需的副本
	void init(int h, int w);
	void copyBlock(int r, int c, const Picture& p);
	void clear(int r1, int c1, int r2, int c2);
	static int max(int m, int n);

	friend std::ostream& operator<<(std::ostream& os, const Picture& p);
	friend Picture operator&(const Picture& p1, const Picture& p2);  // 纵向连接
	friend Picture operator|(const Picture& p1, const Picture& p2);  // 横向连接
	friend Picture frame(const Picture& p);  // 加框

public:
	Picture();
	Picture(const char* const* array, int n);
	Picture(const Picture& p);
	~Picture();
	Picture operator=(const Picture& p);
};
