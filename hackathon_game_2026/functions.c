#include "header.h"


void loadQuestions(Question bank[], int* questionTotal) 
{
	FILE* infile = fopen("question.txt", "r");
	
    if (infile == NULL) 
    {
		printf("Did not open files.");
		return;
	}

	char line[300];

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
            if (column == 0)
            {
                strcpy(prompt, token);
            }

            else if (column == 1)
            {
                strcpy(questionType, token);
            }

            else if (column == 2)
            {
                strcpy(questionAnswer, token);
            }

            else if (column == 3)
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
    int totalPoints = 0;
    int index = 0;

    char usersAnswer[50];
    char correctAnswer[50];

    if (questionTotal == 0)
    {
        printf("No questions available. Please add questions before continuing!!\n");
        return;
    }

    printf("                _____ _______       _____ _______ _____ _   _  _____    _____          __  __ ______ \n");
    printf("               / ____|__   __|/\\   |  __ \\__   __|_   _| \\ | |/ ____|  / ____|   /\\   |  \\/  |  ____|\n");
    printf("              | (___    | |  /  \\  | |__) | | |    | | |  \\| | |  __  | |  __   /  \\  | \\  / | |__   \n");
    printf("               \\___ \\   | | / /\\ \\ |  _  /  | |    | | | . ` | | |_ | | | |_ | / /\\ \\ | |\\/| |  __|  \n");
    printf("               ____) |  | |/ ____ \\| | \\ \\  | |   _| |_| |\\  | |__| | | |__| |/ ____ \\| |  | | |____ \n");
    printf("              |_____/   |_/_/    \\_\\_|  \\_\\ |_|  |_____|_| \\_|\\_____|  \\_____/_/    \\_\\_|  |_|______|\n");
    printf("\n");

    while (index < questionTotal)
    {
        printf("Question %d", index + 1);
        printf("%s\n", bank[index].prompt);

        if (strcmp(bank[index].questionType, "Multiple Choice") == 0)
        {
            printf("Options: \n");

            char copyOptions[200];

            strcpy(copyOptions, bank[index].multipleChoiceOption);

            int optionIndex = 0;
            char optionLetter = 'A';

            for (int i = 0; i <= strlen(copyOptions); i++)
            {
                if (copyOptions[i] == '|' || copyOptions[i] == '\0')
                {
                    char option[50];

                    strncpy(option, &copyOptions[optionIndex], i - optionIndex);

                    option[i - optionIndex] = '\0';

                    printf("%c) %s\n", optionLetter, option);

                    optionLetter++;

                    optionIndex = i + 1;
                }
            }

            printf("Please enter the letter that corresponds with the correct answer: (A, B, C, D): ");
            scanf(" %49s", usersAnswer);

            if (usersAnswer[0] >= 'a' && usersAnswer[0] <= 'z')
            {
                if (usersAnswer[0] == 'a')
                {
                    usersAnswer[0] = 'A';
                }

                else if (usersAnswer[0] == 'b')
                {
                    usersAnswer[0] = 'B';
                }

                else if (usersAnswer[0] == 'c')
                {
                    usersAnswer[0] = 'C';
                }

                else if (usersAnswer[0] == 'd')
                {
                    usersAnswer[0] = 'D';
                }


                if (usersAnswer[0] == bank[index].correctAnswer[0]) //checking multiple choice answer if it is correct
                {
                    printf("Correct!! You get +%d point(s)!!\n", bank[index].points);
                    totalPoints += bank[index].points;
                }

                else
                {
                    printf("Wrong!! The correct answer should have been %s\n", bank[index].correctAnswer);
                }
            }

            else //checking text question answer if it is correct
            {
                printf("Please enter your answer: ");
                scanf(" %49[^\n]", usersAnswer);

                if (strcmp(usersAnswer, bank[index].correctAnswer) == 0)
                {
                    printf("Correct!! You get +%d point(s)!!\n", bank[index].points);
                    totalPoints += bank[index].points;
                }

                else
                {
                    printf("Wrong!! The correct answer should have been %s\n", bank[index].correctAnswer);
                }
            }

            index++;

            printf("\n");
        }

        printf("   _____                                            \n");
        printf("  / ____|                                           \n");
        printf(" | |  __  __ _ _ __ ___   ___    _____   _____ _ __ \n");
        printf(" | | |_ |/ _` | '_ ` _ \\ / _ \\  / _ \\ \\ / / _ \\ '__|\n");
        printf(" | |__| | (_| | | | | | |  __/ | (_) \\ V /  __/ |   \n");
        printf("  \\_____|\\__,_|_| |_| |_|\\___|  \\___/ \\_/ \\___|_|   \n");
        printf("                                                    \n");
        printf("                                                    \n");
    
        printf("You scored %d points total!! Good job!\n", totalPoints);

    }


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

void deleteQuestion(Question bank[], int* questionTotal) {
    char target[150];
    printf("what question do you want to delete");
    getchar();

    int index = -1;

    //find the question
    for (int i = 0; i < *questionTotal; i++) {
        if (strcmp(bank[i].prompt, target) == 0) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        printf("Question not found.\n");
        return;
    }
    // Shift everything left 
    for (int i = index; i < *questionTotal - 1; i++) {
        bank[i] = bank[i + 1];
    }

    (*questionTotal)--;
    printf("Question added successfully.\n");
}
void shuffleQuestions(Question bank[], int questionTotal)
{

}
void printQuestions(Question bank[], int questionTotal)
{
    for (int i = 0; i < questionTotal; i++) {
        printf("Questions %d:\n", i + 1);
        printf("Questions prompt: %s\n", bank[i].prompt);
        printf("Types of questions: %s\n", bank[i].questionType);
        printf("The correct answers %s\n", bank[i].correctAnswer);
    }
}