#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include"DelayedPrintAndClearFunctions.h"
#include"OutputMsgFunctions.h"

int main()
{
	sleep_for(2000);
	opening_msg();

	// clear the screen after a second after input
	const std::string name = read_and_clear_screen("what is your name?", 1000);

	if (!name.empty())
	{
		sleep_for(3000); // wait for three seconds

		// print the greeting and clear the screen after five seconds
		print_and_clear_screen("hello " + name + "!\n", 5000);
	}
}
