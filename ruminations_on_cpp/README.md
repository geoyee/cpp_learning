# Ruminations on C++ 课后练习

PDF链接：[百度网盘](https://pan.baidu.com/share/link?uk=1614005835&shareid=344393322})

*来源：[http://www.yunpz.net/document/f-3812dd0e2f9e4459b973ccc58bf61179.html](http://www.yunpz.net/document/f-3812dd0e2f9e4459b973ccc58bf61179.html)*

## 部分代码勘误

- `P83`中，`Picture::Picture(const char* const* array, int n)`函数的`while`循环的缩进有问题。
- `P97`中，`ostream& operator<<(ostream& os, const Picture& picture)`函数中的`picture.display(os, i, o)`中的字母`o`改为数字`0`。
- `P101`中，第二行代码`os << "-"`缩进错误，需要增加一个缩进。
- `P103`中，在`P_Node`中需要把全局函数`reframe`设置为友元函数，因此`friend Picture reframe(char, char, char)`应改为`friend Picture reframe(const Picture&, char, char, char)`。
