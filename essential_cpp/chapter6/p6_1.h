// 原类
class example
{
public:
	example(double min, double max);
	example(const double* array, int size);
	double& operator[](int index);
	bool operator==(const example& ex) const;
	bool insert(const double* value, int index);
	bool insert(const double value);
	double min() const { return _min; }
	double max() const { return _max; }
	void min(double value);
	void max(double value);
	int count(double value) const;

private:
	int size;
	double* parray;
	double _min;
	double _max;
}

// 模板类
template <typename elemType>
class example
{
public:
        example(elemType& min, elemType& max);
        example(const elemType* array, int size);
        double& operator[](int index);
        bool operator==(const example& ex) const;
        bool insert(const elemType* value, int index);
        bool insert(const elemType& value);
        elemType min() const { return _min; }
        elemType max() const { return _max; }
        void min(elemType& value);
        void max(elemType& value);
        int count(elemType& value) const;

private:
        int size;
        elemType* parray;
        elemType _min;
        elemType _max;
}
