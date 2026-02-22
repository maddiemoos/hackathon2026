#include "header.h"


void loadQuestions(Question bank[], int* questionTotal) {
	FILE* infile = fopen("question.txt", "r");
	if (infile == NULL) {
		printf("Did not open files.");
		return;
	}

	while (fscanf(infile, " %[^/n]", bank[*questionTotal].prompt) == 1) 
	{

		//type of questions 
		fscanf(infile, " %s", bank[*questionTotal].questionType);

		//correct Answer
		fscanf(infile, " %s", bank[*questionTotal].correctAnswer);
		(*questionTotal)++;

	}

	fclose(infile);
	printf("Question were successfuly loaded.");
}

void gamePlay(Question bank[], int questionTotal) 
{



}
void addQuestion(Question bank[], int* questionTotal) {
    printf("Enter the question prompt: ");
    scanf(" %99[^\n]", bank[*questionTotal].prompt);

    // remove newline from fgets
    bank[*questionTotal].prompt[strcspn(bank[*questionTotal].prompt, "\n")] = '\0';

    printf("Enter the question type: ");
    scanf("%s", bank[*questionTotal].questionType);

    printf("Enter the correct answer: ");
    scanf("%s", bank[*questionTotal].correctAnswer);

    (*questionTotal)++;

    printf("Question added successfully.\n");
}

void deleteQuestion(Question bank[], int* count) {



}
void shuffleQuestions(Question bank[], int questionTotal)
{

}
void printQuestions(Question bank[], int questionTotal)
{

}