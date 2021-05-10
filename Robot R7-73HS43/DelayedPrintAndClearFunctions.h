#include <iostream>
#include <cstdlib>
#include <string>
#include <thread>
#include <chrono>
#include <ctime>
#include<algorithm>

#pragma once

std::ostream& clear_screen();
void sleep_for(unsigned int millisecs);
std::ostream& print_and_clear_screen(const std::string& txt, unsigned int millisecs_delay);
std::ostream& typePrint_and_clear_screen(const std::string& txt, unsigned int millisecs_delay);
std::ostream& typePrint_no_clear_screen(const std::string& txt);
std::string read_and_clear_screen(const std::string& prompt, unsigned int millisecs_delay);