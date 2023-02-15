#include <iostream>
#include <string>

class globalWrapper
{
private:
	static std::string _program_name;
	static std::string _version_stamp;
	static int _version_number;
	static int _tests_run;
	static int _tests_passed;

public:
	static std::string program_name() { return _program_name; }
	static std::string version_stamp() { return _version_stamp; }
	static int version_number() { return _version_number; }
	static int tests_run() { return _tests_run; }
	static int tests_passed() { return _tests_passed; }

	static void program_name(const std::string& pn) { _program_name = pn; }
	static void version_stamp(const std::string& vs) { _version_stamp = vs; }
	static void version_number(int vn) { _version_number = vn; }
	static void tests_run(int tr) { _tests_run = tr; }
	static void tests_passed(int tp) { _tests_passed = tp; }
};

// 全局变量
std::string globalWrapper::_program_name;
std::string globalWrapper::_version_stamp;
int globalWrapper::_version_number;
int globalWrapper::_tests_run;
int globalWrapper::_tests_passed;
