#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>


typedef struct question
{
	char prompt[300];
	char questionType[10];
	char multipleChoiceOption[200];
	char correctAnswer[50];
	int points;
}Question;

void loadQuestions(Question bank[], int* questionTotal);
void gamePlay(Question bank[], int questionTotal);
void addQuestion(Question bank[], int *questionTotal);
void deleteQuestion(Question bank[], int* questionTotal);
void shuffleQuestions(Question bank[], int questionTotal);
void printQuestions(Question bank[], int questionTotal);
void storeQuestion(Question bank[], int questionTotal);