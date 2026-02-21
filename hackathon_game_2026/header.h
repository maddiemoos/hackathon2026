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

void loadQuestions(Question bank[], int* count);
void gamePlay(Question bank[], int count);
void editQuestion(Question bank[], int count);
void addQuestion(Question bank[], int *count);
void deleteQuestion(Question bank[], int* count);