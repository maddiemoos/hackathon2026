#include "header.h"

int main(void)
{
	Question bank[50]; //question bank
	int questionTotal = 0; //total amount of questions counter basically
	int choice = 0; //user choice for menu
	
	do //menu
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
		printf("6) Exit\n");

		printf("Please enter your option: ");
		scanf("%d", &choice);
		getchar();
		system("cls");

		switch (choice)
		{
		case 1:
			gamePlay(bank, &questionTotal);
			break;

		case 2:
			printQuestions(bank, &questionTotal);
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
			printf("Thanks! Goodbye.\n");
			break;

		default:
			printf("Invalid input. Please try again!\n");
		}
	}while (choice != 6); //make sure there is a valid input
	
	return 0;
}