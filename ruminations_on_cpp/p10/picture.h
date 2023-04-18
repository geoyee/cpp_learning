#pragma once

#include <iostream>

class P_Node;

class Picture
{
private:
	friend class String_Pic;
	friend class Frame_Pic;
	friend class Hcat_Pic;
	friend class Vcat_Pic;

	friend std::ostream& operator<<(std::ostream& os, const Picture& p);
	friend Picture operator&(const Picture& p1, const Picture& p2);
	friend Picture operator|(const Picture& p1, const Picture& p2);
	friend Picture frame(const Picture& p);
	friend Picture reFrame(const Picture& p, char c, char s, char t);
	
	P_Node* pic;

	Picture(P_Node* pn);
	int height() const;
	int width() const;
	void display(std::ostream& os, int x, int y) const;

public:
	Picture(const char* const* array, int n);
	Picture(const Picture& p);
	~Picture();
	Picture& operator=(const Picture& p);
};

class P_Node
{
private:
	friend class Picture;
	friend Picture reFrame(const Picture& p, char c, char s, char t);

protected:
	int use;

	P_Node();

	static int max(int x, int y);
	static void pad(std::ostream& os, int x, int y);

	virtual ~P_Node();
	virtual int height() const = 0;  // 纯虚函数
	virtual int width() const = 0;
	virtual void display(std::ostream& os, int x, int y) const = 0;
	virtual Picture reFrame(char c, char s, char t) = 0;
};

class String_Pic : public P_Node
{
private:
	friend class Picture;

	char** data;
	int size;

	String_Pic(const char* const* array, int n);
	~String_Pic();
	int height() const;
	int width() const;
	void display(std::ostream& os, int x, int y) const;
	Picture reFrame(char c, char s, char t);
};

class Frame_Pic : public P_Node
{
private:
	friend Picture frame(const Picture& p);
	
	Picture pic;
	char corner;
	char sideborder;
	char topborder;

	Frame_Pic(const Picture& p, char c = '+', char s = '|', char t = '-');
	int height() const;
	int width() const;
	void display(std::ostream& os, int x, int y) const;
	Picture reFrame(char c, char s, char t);
};

class Vcat_Pic : public P_Node
{
private:
	friend Picture operator&(const Picture& p1, const Picture& p2);

	Picture top, bottom;

	Vcat_Pic(const Picture& t, const Picture& b);
	int height() const;
	int width() const;
	void display(std::ostream& os, int x, int y) const;
	Picture reFrame(char c, char s, char t);
};

class Hcat_Pic : public P_Node
{
private:
	friend Picture operator|(const Picture& p1, const Picture& p2);

	Picture left, right;

	Hcat_Pic(const Picture& l, const Picture& r);
	int height() const;
	int width() const;
	void display(std::ostream& os, int x, int y) const;
	Picture reFrame(char c, char s, char t);
};