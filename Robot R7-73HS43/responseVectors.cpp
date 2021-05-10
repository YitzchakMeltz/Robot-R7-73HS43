#include"responseVectors.h"

vector<string> yesVector()
{
	vector<string> resVec;

	resVec.push_back("yes");
	resVec.push_back("ya");
	resVec.push_back("yeah");
	resVec.push_back("yea");
	resVec.push_back("yep");
	resVec.push_back("yup");
	resVec.push_back("ok");
	resVec.push_back("okay");
	resVec.push_back("sure");
	resVec.push_back("why not");
	resVec.push_back("fine");
	resVec.push_back("i guess");

	return resVec;
}

vector<string> noVector()
{
	vector<string> resVec;

	resVec.push_back("no");
	resVec.push_back("nope");
	resVec.push_back("na");
	resVec.push_back("naa");
	resVec.push_back("i'm good");
	resVec.push_back("not really");
	resVec.push_back("i'm ok");
	resVec.push_back("im ok");
	resVec.push_back("im okay");
	resVec.push_back("i'm okay");
	resVec.push_back("i'd rather not");
	resVec.push_back("i would rather not");

	return resVec;
}

vector<string> exceptionVector()
{
	vector<string> resVec;

	resVec.push_back("Huh? I'm not sure I understand...");
	resVec.push_back("Lol. I have no idea what you mean");
	resVec.push_back("say whaaaaa?");
	resVec.push_back("Um, I dunno what that means");
	resVec.push_back("Can you repeat that?");
	resVec.push_back("I honestly have no idea how to respond to that");
	resVec.push_back("you're cracking me up. I don't know what I'm supposed to say to that");
	resVec.push_back("come on, seriously");
	resVec.push_back("lol. not sure i understood you...");
	resVec.push_back("lol. I can also say stuff that doesn't make any sense!");
	resVec.push_back("I'm not stupid. I just have no idea what you're trying to tell me");
	resVec.push_back("come again?");
	resVec.push_back("Umm...\nthat makes just as much sense to me as biology does...");
	resVec.push_back("Is that code for something?");
	resVec.push_back("I have a feeling that you might be messing with me");
	resVec.push_back("Umm, what???");
	resVec.push_back("bahahahaha\ni don't know what that means");

	return resVec;

}

userResponse checkUserResponse(string userInput)
{
	std::transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

	userResponse checkedResult = error0;

	vector<string> splitUserInput;

	splitUserInput = splitSentence(userInput);

	vector<string> resVec;

	resVec = noVector();

	vector<string>::iterator it, jt;

	for (it = resVec.begin(); it != resVec.end(); it++)
	{
		for (size_t f = 0; (f = userInput.find(*it, f)) != std::string::npos; ++f)
		{
			//if it is a subsentence of the user input
			if ((f == 0 || std::isspace(userInput[f - 1])) && (f + (*it).size() >= userInput.size() || std::isspace(userInput[f + std::size((*it))])))
			{
				checkedResult = no;
				userInput.erase(f, (*it).size());
				f = 0;
			}
		}
	}

	resVec = yesVector();

	for (it = resVec.begin(); it != resVec.end(); it++)
	{
		for (size_t f = 0; (f = userInput.find(*it, f)) != std::string::npos; ++f)
		{
			//if it is a subsentence of the user input
			if ((f == 0 || std::isspace(userInput[f - 1])) && (f + (*it).size() >= userInput.size() || std::isspace(userInput[f + std::size((*it))])))
			{
				if (checkedResult == no)
					checkedResult = error3;
				else
					checkedResult = yes;

				userInput.erase(f, (*it).size());
				f = 0;
			}
		}
	}

	return checkedResult;
}

vector<string> splitSentence(const string& str)
{
	vector<string> rv;
	rv.reserve(20);
	size_t prev = 0, pos = 0, pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0, pos5 = 0, pos6 = 0;
	do
	{
		pos1 = str.find(' ', prev);
		pos2 = str.find(',', prev);
		pos3 = str.find('?', prev);
		pos4 = str.find('!', prev);
		pos5 = str.find('-', prev);
		pos6 = str.find('.', prev);

		pos = min(pos1, pos2);
		pos = min(pos, pos3);
		pos = min(pos, pos4);
		pos = min(pos, pos5);
		pos = min(pos, pos6);

		if (pos == string::npos)
			pos = str.length();
		const string& token = str.substr(prev, pos - prev);
		if (!token.empty())
			rv.push_back(token);
		prev = pos + 1;
	} while (pos < str.length());
	return rv;
}

int min(int x, int y)
{
	if (x <= y)
		return x;

	return y;
}