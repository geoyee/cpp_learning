#include <cstring>
#include "picture.h"

int Picture::height() const
{
	return pic->height();
}

int Picture::width() const
{
	return pic->width();
}

void Picture::display(std::ostream& os, int x, int y) const
{
	pic->display(os, x, y);
}

std::ostream& operator<<(std::ostream& os, const Picture& p)
{
	int ht = p.height();
	for (int i = 0; i < ht; ++i)
	{
		p.display(os, i, 0);
		os << std::endl;
	}
	return os;
}

Picture frame(const Picture& p)
{
	return new Frame_Pic(p);
}

Picture reFrame(const Picture& p, char c, char s, char t)
{
	return p.pic->reFrame(c, s, t);
}

Picture::Picture(P_Node* pn)
	: pic(pn)
{ }

Picture::Picture(const char* const* array, int n)
	: pic(new String_Pic(array, n))
{ }

Picture::Picture(const Picture& p)
	: pic(p.pic)
{
	p.pic->use++;
}

Picture::~Picture()
{
	if (--pic->use == 0)
		delete pic;
}

Picture& Picture::operator=(const Picture& p)
{
	p.pic->use++;
	if (--pic->use == 0)
		delete pic;
	pic = p.pic;
	return *this;
}

P_Node::P_Node()
	: use(1)
{ }

int P_Node::max(int x, int y)
{
	return x > y ? x : y;
}

void P_Node::pad(std::ostream& os, int x, int y)
{
	for (int i = x; i < y; ++i)
		os << ' ';
}

P_Node::~P_Node()
{ }

String_Pic::String_Pic(const char* const* array, int n)
	: data(new char*[n]), size(n)
{
	for (int i = 0; i < n; ++i)
	{
		data[i] = new char[strlen(array[i]) + 1];
		strcpy(data[i], array[i]);
	}
}

String_Pic::~String_Pic()
{
	for (int i = 0; i < size; ++i)
		delete[] data[i];
	delete[] data;
}

int String_Pic::height() const
{
	return size;
}

int String_Pic::width() const
{
	int n = 0;
	for (int i = 0; i < size; ++i)
		n = P_Node::max(n, strlen(data[i]));
	return n;
}

void String_Pic::display(std::ostream& os, int x, int y) const
{
	int start = 0;
	if (x >= 0 && x < height())
	{
		os << data[x];
		start = strlen(data[x]);
	}
	P_Node::pad(os, start, y);
}

Picture String_Pic::reFrame(char c, char s, char t)
{
	use++;
	return this;
}

Frame_Pic::Frame_Pic(const Picture& p, char c, char s, char t)
	: pic(p), corner(c), sideborder(s), topborder(t)
{ }

int Frame_Pic::height() const
{
	return pic.height() + 2;
}

int Frame_Pic::width() const
{
	return pic.width() + 2;
}

void Frame_Pic::display(std::ostream& os, int x, int y) const
{
	if (x < 0 || x >= height())
		P_Node::pad(os, 0, y);
	else
	{
		if (x == 0 || x == height() - 1)
		{
			os << corner;
			int i = pic.width();
			while (--i >= 0)
				os << topborder;
			os << corner;
		}
		else 
		{
			os << sideborder;
			pic.display(os, x - 1, pic.width());
			os << sideborder;
		}
		P_Node::pad(os, width(), y);
	}
}

Picture Frame_Pic::reFrame(char c, char s, char t)
{
	return new Frame_Pic(::reFrame(pic, c, s, t), c, s, t);
}

Vcat_Pic::Vcat_Pic(const Picture& t, const Picture& b)
	: top(t), bottom(b)
{ }

Picture operator&(const Picture& p1, const Picture& p2)
{
	return new Vcat_Pic(p1, p2);
}

int Vcat_Pic::height() const
{
	return top.height() + bottom.height();
}

int Vcat_Pic::width() const
{
	return P_Node::max(top.width(), bottom.width());
}

void Vcat_Pic::display(std::ostream& os, int x, int y) const
{
	if (x >= 0 && x < top.height())
		top.display(os, x, y);
	else if (x < (top.height() + bottom.height()))
		bottom.display(os, x - top.height(), y);
	else
		P_Node::pad(os, 0, y);
}

Picture Vcat_Pic::reFrame(char c, char s, char t)
{
	return new Vcat_Pic(::reFrame(top, c, s, t), ::reFrame(bottom, c, s, t));
}

Hcat_Pic::Hcat_Pic(const Picture& l, const Picture& r)
	: left(l), right(r)
{ }

Picture operator|(const Picture& p1, const Picture& p2)
{
	return new Hcat_Pic(p1, p2);
}

int Hcat_Pic::height() const
{
	return P_Node::max(left.height(), right.height());
}

int Hcat_Pic::width() const
{
	return left.width() + right.width();
}

void Hcat_Pic::display(std::ostream& os, int x, int y) const
{
	left.display(os, x, left.width());
	right.display(os, x, right.width());
	P_Node::pad(os, width(), y);
}

Picture Hcat_Pic::reFrame(char c, char s, char t)
{	
	return new Hcat_Pic(::reFrame(left, c, s, t), ::reFrame(right, c, s, t));
}