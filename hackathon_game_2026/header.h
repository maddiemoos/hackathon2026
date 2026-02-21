#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>


typedef struct question
{
	char prompt[300];
	char questionType[10];
	char correctAnswer[50];
	int points;
}Question;

//Description:
//Precondition:
//Postcondition:
void gamePlay(Question bank[], int questionTotal);

//Description:
//Precondition:
//Postcondition:
void addQuestion(Question bank[], int *questionTotal);

//Description:
//Precondition:
//Postcondition:
void deleteQuestion(Question bank[], int* questionTotal);

//Description:
//Precondition:
//Postcondition:
void shuffleQuestions(Question bank[], int questionTotal);

//Description:
//Precondition:
//Postcondition:
void printQuestions(Question bank[], int questionTotal);