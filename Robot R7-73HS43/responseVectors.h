#include<vector>
#include <iostream>
#include <cstdlib>
#include <string>
#include<algorithm>
#include<cctype>

#pragma once

using namespace std;

enum userResponse { error0, yes, no, error3 };

vector<string> yesVector();

vector<string> noVector();

vector<string> exceptionVector();

userResponse checkUserResponse(string userInput);

vector<string> splitSentence(const string& str);

int min(int x, int y);