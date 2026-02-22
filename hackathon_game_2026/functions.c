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

void gamePlay(Question bank[], int count) {



}

void addQuestion(Question bank[], int* questionTotal) {
    printf("Enter the question prompt: ");
    scanf(" %99[^\n]", bank[*questionTotal].prompt);

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
    for (int i = 0; i < questionTotal; i++) {
        printf("Questions %d:\n", i + 1);
        printf("Questions prompt: %s\n", bank[questionTotal].prompt);
        printf("Types of questions: %s\n", bank[questionTotal].questionType);
        printf("The correct answers %s\n", bank[questionTotal].correctAnswer);
    }
}