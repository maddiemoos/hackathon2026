#include "header.h"

int main(void)
{
	Question bank[300]; //array that stores 300 question structs if we want
	int questionTotal = 0; //tracks how many are stored currently
	int choice = 0; //user choice for menu
	
	do //menu loop
	{
		printf("                                 _____   _____ _   _  _____   _____ ___________ _____ \n");
		printf("                                /  __ \\ |_   _| | | ||  ___| /  __ \\  _  |  _  \\  ___|\n");
		printf("                                | /  \\/   | | | |_| || |__   | /  \\/ | | | | | | |__  \n");
		printf("                          ***** | |       | | |  _  ||  __|  | |   | | | | | | |  __| *****\n");
		printf("                                | \\__/\\   | | | | | || |___  | \\__/\\ \\_/ / |/ /| |___ \n");
		printf("                                 \\____/   \\_/ \\_| |_\\/\\____/  \\____/\\___/|___/ \\____/ \n");
		printf("                                                      \n");
		printf("                =====================================================================================\n");

		printf("1) Play Game\n"); //menu options
		printf("2) Display Questions and Answers\n");
		printf("3) Add Question\n");
		printf("4) Delete Question\n");
		printf("5) Store Questions\n");
		printf("6) Load Questions\n");
		printf("7) Exit\n");
		 
		printf("Please enter your option: "); //ask for what option they want
		scanf("%d", &choice); //scan in what the choice is
		getchar(); //clear newline
		system("cls"); //clear screen

		switch (choice)
		{
		case 1:
			gamePlay(bank, questionTotal); //call the gameplay function
			break;

		case 2:
			printQuestions(bank, questionTotal); //call display function
			break;

		case 3:
			addQuestion(bank, &questionTotal); //call function to add a question
			break;

		case 4:
			deleteQuestion(bank, &questionTotal); //call function to delete a question
			break;

		case 5:
			storeQuestion(bank, questionTotal); //call function to store the questions
			break;

		case 6:
			loadQuestions(bank, &questionTotal); //call function to load all of the questions from file
			break;

		case 8:
			printf("Thanks! Goodbye.\n"); //exit case
			break;

		default:
			printf("Invalid input. Please try again!\n"); //invalid choice try again
		}
	}while (choice != 7); //loop until user enters exit case
	
	return 0; //end
}