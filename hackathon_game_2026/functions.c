#include "header.h"


void loadQuestions(Question bank[], int* count) {
	FILE* infile = fopen("question.txt", "r");
	if (infile == NULL) {
		printf("did not open files.");
		return;
	}

	while (fscanf(infile, " %[^/n]", bank[*count].prompt) == 1) {

		//type of questions 
		fscanf(infile, " %s", bank[*count].questionType);

		//correct Answer
		fscanf(infile, " %s", bank[*count].correctAnswer);
		(*count)++;
	}

	fclose(infile);
	printf("Question were successfuly loaded.");
}

void gamePlay(Question bank[], int count) {



}
void editQuestion(Question bank[], int count) {



}
void addQuestion(Question bank[], int* count) {



}
void deleteQuestion(Question bank[], int* count) {



}