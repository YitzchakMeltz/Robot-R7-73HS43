#include "DelayedPrintAndClearFunctions.h"

std::ostream& clear_screen()
{
	// generally works on both cmd.exe (windows) and bash (linux etc.)
	// this may also work on tcash and zsh (needs testing)
	std::system("@cls || clear");
	return std::cout;
}

void sleep_for(unsigned int millisecs)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(millisecs));
}

std::ostream& print_and_clear_screen(const std::string& txt, unsigned int millisecs_delay)
{
	std::cout << txt << std::flush;
	sleep_for(millisecs_delay);
	return clear_screen();
}

std::string read_and_clear_screen(const std::string& prompt, unsigned int millisecs_delay)
{
	typePrint_no_clear_screen(prompt);
	sleep_for(500);
	std::cout << "\n";
	std::string str;
	std::getline(std::cin, str);
	sleep_for(millisecs_delay);
	clear_screen();
	return str;
}

std::ostream& typePrint_and_clear_screen(const std::string& txt, unsigned int millisecs_delay)
{
	// initialize random seed
	srand(time(nullptr));

	unsigned int n;

	// generate random number between 1 and 10
	for (unsigned int i = 0; i < txt.length(); i++)
	{
		n = rand() % 10 + 1;
		std::cout << txt[i] << std::flush;
		sleep_for(n * 30);
	}

	//leave message on screen for given time
	sleep_for(millisecs_delay);
	return clear_screen();
}

std::ostream& typePrint_no_clear_screen(const std::string& txt)
{
	// initialize random seed
	srand(time(nullptr));

	unsigned int n;

	// generate random number between 1 and 10
	for (unsigned int i = 0; i < txt.length(); i++)
	{
		n = rand() % 10 + 1;
		std::cout << txt[i] << std::flush;
		sleep_for(n * 30);
	}

	return std::cout;
}