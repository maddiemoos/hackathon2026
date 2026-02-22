#include "header.h"


void loadQuestions(Question bank[], int* questionTotal) 
{
	FILE* infile = fopen("question.txt", "r");
	
    if (infile == NULL) 
    {
		printf("Did not open files.");
		return;
	}

	char line[250];

    while (fgets(line, sizeof(line), infile) != NULL)
    {
        char prompt[300] = "";
        char questionType[50] = "";
        char questionAnswer[100] = "";
        int points = 0;

        char* token = strtok(line, ",");
        int column = 0;

        while (token != NULL)
        {
            if (column = 0)
            {
                strcpy(prompt, token);
            }

            else if (column = 1)
            {
                strcpy(questionType, token);
            }

            else if (column = 2)
            {
                strcpy(questionAnswer, token);
            }

            else if (column = 3)
            {
                points = atoi(token);
            }

            column++;
            
            token = strtok(NULL, ",");
        }

        Question data;

        strcpy(data.prompt, prompt);
        strcpy(data.questionType, questionType);
        strcpy(data.correctAnswer, questionAnswer);
        data.points = points;

        bank[*questionTotal] = data;

        (*questionTotal)++;
    }

	fclose(infile);
	printf("Questions were successfuly loaded!!");
}

void gamePlay(Question bank[], int questionTotal) 
{



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