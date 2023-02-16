#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

enum uLevel { Beginner, Intermediate, Advanced, Guru };

void _mitoa(int id, char* buffer)
{
	sprintf(buffer, "%d", id);
}

class UserProfile
{
private:
	std::string _login;
	std::string _user_name;
	int _times_logged;
	int _guesses;
	int _correct_guesses;
	uLevel _user_level;

	static std::map<std::string, uLevel> _level_map;
	static void init_level_map();
	static std::string guest_login();

public:
	UserProfile(std::string login, uLevel = Beginner);
	UserProfile();

	bool operator==(const UserProfile& rhs);
	bool operator!=(const UserProfile& rhs);

	std::string login() const { return _login; }
	std::string user_name() const { return _user_name; }
	int login_count() const { return _times_logged; }
	int guess_count() const { return _guesses; }
	int guess_correct() const { return _correct_guesses; }
	double guess_average() const;
	std::string level() const;

	void reset_login(const std::string& val) { _login = val; }
	void user_name(const std::string& val) { _user_name = val; }
	void reset_level(const std::string& val);
	void reset_level(uLevel newLevel) { _user_level = newLevel; }
	void reset_login_count(int val) { _times_logged = val; }
	void reset_guess_count(int val) { _guesses = val; }
	void reset_guess_correct(int val) { _correct_guesses = val; }
	void bump_login_count(int cnt = 1) { _times_logged += cnt; }
	void bump_guess_count(int cnt = 1) { _guesses += cnt; }
	void bump_guess_correct(int cnt = 1) { _correct_guesses += cnt; }
};

inline double UserProfile::guess_average() const
{
	return _guesses ? double(_correct_guesses) / double(_guesses) * 100 : 0.0;
}

inline UserProfile::UserProfile(std::string login, uLevel level)
	: _login(login), _user_level(level), _times_logged(1), _guesses(0), _correct_guesses(0)
{

}

inline UserProfile::UserProfile()
	: _login("guest"), _user_level(Beginner), _times_logged(1), _guesses(0), _correct_guesses(0)
{
	static int id = 0;
	char buffer[16];
	_mitoa(id++, buffer);
	_login += buffer;
}

inline bool UserProfile::operator==(const UserProfile& rhs)
{
	if (_login == rhs._login && _user_name == rhs._user_name)
		return true;
	return false;
}

inline bool UserProfile::operator!=(const UserProfile& rhs)
{
	return !(*this == rhs);
}

inline std::string UserProfile::level() const
{
	static std::string _level_table[] = { "Beginner", "Intermediate", "Advanced", "Guru" };
	return _level_table[_user_level];
}

std::ostream& operator<<(std::ostream &os, const UserProfile &rhs)
{
	os << rhs.login() << ' '
	   << rhs.level() << ' '
	   << rhs.login_count() << ' '
	   << rhs.guess_count() << ' '
	   << rhs.guess_correct() << ' '
	   << rhs.guess_average() << std::endl;
	return os;
}

std::map<std::string, uLevel> UserProfile::_level_map;

void UserProfile::init_level_map()
{
	_level_map["Beginner"] = Beginner;
	_level_map["Intermediate"] = Intermediate;
	_level_map["Advanced"] = Advanced;
	_level_map["Guru"] = Guru;
}

inline void UserProfile::reset_level(const std::string& level)
{
	std::map<std::string, uLevel>::iterator it;
	if (_level_map.empty())
		init_level_map();
	_user_level = ((it = _level_map.find(level)) != _level_map.end()) ? it->second : Beginner;
}

std::istream& operator>>(std::istream& is, UserProfile& rhs)
{
	std::string login, level;
	is >> login >> level;
	int lcount, gcount, gcorrect;
	rhs.reset_login(login);
	rhs.reset_level(level);
	rhs.reset_login_count(lcount);
	rhs.reset_guess_count(gcount);
	rhs.reset_guess_correct(gcorrect);
	return is;
}
