#include "header.h"

int main(void)
{
	Question bank[300];
	int questionTotal = 0;
	int choice = 0; //user choice for menu
	
	do
	{
		printf("                                 _____   _____ _   _  _____   _____ ___________ _____ \n");
		printf("                                /  __ \\ |_   _| | | ||  ___| /  __ \\  _  |  _  \\  ___|\n");
		printf("                                | /  \\/   | | | |_| || |__   | /  \\/ | | | | | | |__  \n");
		printf("                          ***** | |       | | |  _  ||  __|  | |   | | | | | | |  __| *****\n");
		printf("                                | \\__/\\   | | | | | || |___  | \\__/\\ \\_/ / |/ /| |___ \n");
		printf("                                 \\____/   \\_/ \\_| |_\\/\\____/  \\____/\\___/|___/ \\____/ \n");
		printf("                                                      \n");
		printf("                =====================================================================================\n");

		printf("1) Play Game\n");
		printf("2) Display Questions and Answers\n");
		printf("3) Add Question\n");
		printf("4) Delete Question\n");
		printf("5) Shuffle Questions\n");
		printf("6) Load Questions\n");
		printf("7) Exit\n");

		printf("Please enter your option: ");
		scanf("%d", &choice);
		getchar();
		//system("cls");

		switch (choice)
		{
		case 1:
			gamePlay(bank, questionTotal);
			break;

		case 2:
			printQuestions(bank, questionTotal);
			break;

		case 3:
			addQuestion(bank, &questionTotal);
			break;

		case 4:
			deleteQuestion(bank, &questionTotal);
			break;

		case 5:
			shuffleQuestions(bank, questionTotal);
			break;

		case 6:
			loadQuestions(bank, questionTotal);
			break;

		case 7:
			printf("Thanks! Goodbye.\n");
			break;

		default:
			printf("Invalid input. Please try again!\n");
		}
	}while (choice != 7);
	
	return 0;
}