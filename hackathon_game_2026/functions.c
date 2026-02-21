#include "header.h"


//void loadQuestions(Question bank[], int* count) {
//	FILE* infile = fopen("question.txt", "r");
//	if (infile == NULL) {
//		printf("did not open files.");
//		return;
//	}
//
//	while (fscanf(infile, " %[^/n]", bank[*count].prompt) == 1) {
//
//		//type of questions 
//		fscanf(infile, " %s", bank[*count].questionType);
//
//		//correct Answer
//		fscanf(infile, " %s", bank[*count].correctAnswer);
//		(*count)++;
//	}
//
//	fclose(infile);
//	printf("Question were successfuly loaded.");
//}

void gamePlay(Question bank[], int questionTotal) 
{
	if (questionTotal == 0)
	{
		printf("There are no questions available. Please add questions before continuing!!\n");
		return;
	}




}
void editQuestion(Question bank[], int questionTotal) 
{



}
void addQuestion(Question bank[], int* questionTotal) 
{



}
void deleteQuestion(Question bank[], int* questionTotal) 
{



}
void shuffleQuestions(Question bank[], int questionTotal)
{

}
void printQuestions(Question bank[], int questionTotal)
{

}