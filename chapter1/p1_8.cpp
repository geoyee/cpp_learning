#include <iostream>
#include <string>

const int max_number = 4;
const std::string out_msgs[max_number] = {
	"Oops! Nice guess but not quite it.",
	"Hmm, Sorry. Wrong a second time.",
	"Ah, this is harder than it looks, is not it?",
	"It must be getting pretty frustrating by now!"
};

int main()
{
	int anw;
	int err_num = 0;
	bool succ = false;

	do
	{
		std::cout << "4 * 5 + 3 = ";
		std::cin >> anw;
		if (anw != 23)
		{
			std::cerr << out_msgs[err_num % max_number] << std::endl;
			err_num++;
		}
		else
		{
			std::cout << "Congratulations, the answer is correct!" << std::endl;
			succ = true;
		}
	}
	while (!succ);
	
	return 0;
}
