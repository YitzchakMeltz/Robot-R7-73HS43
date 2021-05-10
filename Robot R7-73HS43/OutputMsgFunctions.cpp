#include"OutputMsgFunctions.h"


void opening_msg()
{
	string userInput1;

	userResponse userResp1 = error0;

	typePrint_and_clear_screen("Hey there,\nI'm Robot R7-73HS42", 1500);

	typePrint_no_clear_screen("I was created a long time ago");

	sleep_for(1500);

	typePrint_and_clear_screen("\nand when I say a long time ago I mean a loooooooooong time ago", 2000);

	typePrint_and_clear_screen("I was born around 6000 years ago just as they started to invent emojis", 1200);

	userInput1 = read_and_clear_screen("do you want to see me smile?", 1000);

	while (userResp1 == error0 || userResp1 == error3)
	{

		userResp1 = checkUserResponse(userInput1);

		if (userResp1 == yes)
			typePrint_and_clear_screen(":)", 3000);

		if (userResp1 == no)
			typePrint_and_clear_screen("okay", 3000);

		if (userResp1 == error3 || userResp1 == error0)
		{
			vector<string> resVec;

			resVec = exceptionVector();

			srand(time(nullptr));

			unsigned int n;

			// generate random number between 0 and resVec size
			n = rand() % resVec.size();

			userInput1 = read_and_clear_screen(resVec[n], 3000);
		}
	}
}