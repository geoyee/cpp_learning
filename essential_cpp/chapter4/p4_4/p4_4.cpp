#include "user_profile.hpp"

int main()
{
	UserProfile anon;
	std::cout << anon;

	UserProfile anon_too;
	std::cout << anon_too;

	UserProfile anna("Annal", uLevel::Guru);
	std::cout << anna;
	anna.bump_guess_count(27);
	anna.bump_guess_correct(25);
	anna.bump_login_count();
	std::cout << anna;

	std::cin >> anon;
	std::cout << anon;
}
