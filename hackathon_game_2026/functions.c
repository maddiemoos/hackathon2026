#include "header.h"


void loadQuestions(Question bank[], int* count) {
	FILE* infile = fopen("question.txt", "r");
	if (infile == NULL) {
		printf("did not open files.");
		return 1;
	}

	if(infile != NULL) {
		printf("open");





		return 0;
	}

}
void gamePlay(Question bank[], int count) {



}
void editQuestion(Question bank[], int count) {



}
void addQuestion(Question bank[], int* count) {



}
void deleteQuestion(Question bank[], int* count) {



}