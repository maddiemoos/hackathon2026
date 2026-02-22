#include "header.h"


void loadQuestions(Question bank[], int* questionTotal) 
{
	FILE* infile = fopen("question.txt", "r"); //open the file to read in questions
	
    if (infile == NULL) //checking if the file is working
    {
		printf("Did not open files.\n");
		return;
	}

	char line[300]; //buffer to read each line of file

    while (fgets(line, sizeof(line), infile) != NULL) //continues reading until end of line
    {
        char prompt[300] = ""; //temp values
        char questionType[50] = "";
        char questionAnswer[100] = "";
        int points = 0;

        char* token = strtok(line, ","); //parse by commas
        int column = 0; //track which column were in

        char optionsMultipleChoice[200] = ""; //stores mcq choices

        while (token != NULL) //loops through each value
        {
            if (column == 0) //question prompt
            {
                strcpy(prompt, token);
            }

            else if (column == 1) //question type
            {
                strcpy(questionType, token);
            }

            else if (column == 2) //either mcq or text question
            {
                if (strcmp(questionType, "Multiple Choice") == 0) //if it is a multiple cohice
                {
                    strcpy(optionsMultipleChoice, token); //this stores the option for mc
                }

                else //otherwise has answer
                {
                    strcpy(questionAnswer, token);
                }
            }

            else if (column == 3) //either mcq or text question
            {
                if (strcmp(questionType, "Multiple Choice") == 0) //again if it is mcq
                {
                    strcpy(questionAnswer, token); //this is the right answer
                }

                else //otherwise has answer
                {
                    points = atoi(token);
                }

            }
            
            else if (column == 4) //used for mcq
            {
                points = atoi(token); //mcq points
            }

            column++; //increments to next column
            
            token = strtok(NULL, ","); //gets next token
        }

        Question data; //question struct

        strcpy(data.prompt, prompt); //copying all parsed data into the struct
        strcpy(data.questionType, questionType);
        strcpy(data.multipleChoiceOption, optionsMultipleChoice);
        strcpy(data.correctAnswer, questionAnswer);
        data.points = points;

        bank[*questionTotal] = data; //storing struct into the array

        (*questionTotal)++; //increment the question counter
    }

	fclose(infile); //closes file
	printf("Questions were successfuly loaded!!\n");
}

void gamePlay(Question bank[], int questionTotal)
{
    int totalPoints = 0; //stores score
    int index = 0; //tracks which question we are on

    char usersAnswer[50]; //stores users input
    char correctAnswer[50]; 

    if (questionTotal == 0) //if no questions it wont work
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

    while (index < questionTotal) //loops through each question
    {
        printf("Question %d ", index + 1); //displays question number as well as the question itself
        printf("%s\n", bank[index].prompt);

        if (strcmp(bank[index].questionType, "Multiple Choice") == 0) //double check if it is a multiple choice first
        {
            printf("Options: \n");

            char copyOptions[200]; //copy since were modifying strings

            strcpy(copyOptions, bank[index].multipleChoiceOption);

            int optionIndex = 0; //tracks start of option
            char optionLetter = 'A'; //this is the first option letter

            for (int i = 0; i <= strlen(copyOptions); i++) //loop through the options string
            {
                if (copyOptions[i] == '|' || copyOptions[i] == '\0') //if we see the dividers or null terminator
                {
                    char option[50];

                    strncpy(option, &copyOptions[optionIndex], i - optionIndex); //copy the substring to option

                    option[i - optionIndex] = '\0'; //null termiate

                    printf("%c) %s\n", optionLetter, option); //print the option

                    optionLetter++; //incrememnt next letter

                    optionIndex = i + 1; //move to starting 
                }
            }

            printf("Please enter the letter that corresponds with the correct answer: (A, B, C, D): ");
            scanf(" %49s", usersAnswer);
            
            usersAnswer[strcspn(usersAnswer, "\n")] = 0; //this all just makes sure it doesnt matter with case stuff

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
                    printf("Correct!! You get +%d point(s)!!\n", bank[index].points); //correct answer
                    totalPoints += bank[index].points;
                }

                else //wrong answer
                {
                    printf("Wrong!! The correct answer should have been %s\n", bank[index].correctAnswer);
                }
            }

            else 
            {
                if (usersAnswer[0] == bank[index].correctAnswer[0]) 
                {
                    printf("Correct!! You get +%d point(s)!!\n", bank[index].points); //correct
                    totalPoints += bank[index].points;
                }

                else //wrong answer
                {
                    printf("Wrong!! The correct answer should have been %s\n", bank[index].correctAnswer);
                }
            }
            
        }
        else //checking text question answer if it is correct
        {
            printf("Please enter your answer: ");
            scanf(" %49[^\n]", usersAnswer); //read input

            if (strcmp(usersAnswer, bank[index].correctAnswer) == 0) //compare strings to see if they are the same
            {
                printf("Correct!! You get +%d point(s)!!\n", bank[index].points); //correct answer
                totalPoints += bank[index].points;
            }

            else //wrong answer
            {
                printf("Wrong!! The correct answer should have been %s\n", bank[index].correctAnswer);
            }
        }

        index++; //increment to next question

        
        

    }

    printf("\n");

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

void addQuestion(Question bank[], int* questionTotal) 
{
    printf("Enter the question prompt: "); //ask to enter prompt of question
    scanf(" %99[^\n]", bank[*questionTotal].prompt); //reads line into prompt field

    printf("Enter the question type: ");  //ask for mcq
    scanf("%s", bank[*questionTotal].questionType); //read question type

    printf("Enter the correct answer: "); //ask user for what the correct answer is
    scanf("%s", bank[*questionTotal].correctAnswer); //read correct answer

    (*questionTotal)++; //incrememnt the total number of questions that are in the bank

    printf("Question added successfully.\n");
}

void deleteQuestion(Question bank[], int* questionTotal)
{
    char target[150]; //store the question prompt they want to delete
    printf("what question do you want to delete"); 
    getchar(); //clears leftover newline

    int index = -1; //initalizes to negative one because it has not been found yet

    //find the question
    for (int i = 0; i < *questionTotal; i++) 
    { 
        if (strcmp(bank[i].prompt, target) == 0) 
        { //compares each questions prompt with what we are looking for
            index = i; //store it if found
            break; //stop
        }
    }
    if (index == -1) 
    { //if nothing changed the question wasnt found
        printf("Question not found.\n");
        return;
    }
    // Shift everything left 
    for (int i = index; i < *questionTotal - 1; i++)
    {
        bank[i] = bank[i + 1]; //overwrites the current question with the next one
    }

    (*questionTotal)--; //decreases the total question count
    printf("Question added successfully.\n");
}

void printQuestions(Question bank[], int questionTotal)
{
    for (int i = 0; i < questionTotal; i++) 
    { //loops through each question that was stored
        printf("Question %d: \n", i + 1); //print questio number
        printf("Question prompt: %s \n", bank[i].prompt); //print prompt
        printf("Types of question: %s \n", bank[i].questionType); //print type
        printf("The correct answer %s \n", bank[i].correctAnswer); //print correct answer
    }
}

void storeQuestion(Question bank[], int questionTotal)
{
    FILE* outfile = fopen("question.txt", "w"); //opens the file to write to it instead of read to it

    if (outfile == NULL)  //if the file failed to open print error message
    {
        printf("Failed to open file.\n");
    }

    for (int i = 0; i < questionTotal; i++) //loop through every question in the question bank
    {
        if (strcmp(bank[i].questionType, "Multiple Choice") == 0) //double check if it is multiple choice question
        {
            fprintf(outfile, "%s,%s,%s,%s,%d\n", bank[i].prompt, bank[i].questionType, bank[i].multipleChoiceOption, bank[i].correctAnswer, bank[i].points); //write this in the mcq formating
        }

        else
        {
            fprintf(outfile, "% s,%s,%s,%d\n", bank[i].prompt, bank[i].questionType, bank[i].correctAnswer, bank[i].points); //print the text question formatting (no 'option')
        }
    }

    fclose(outfile); //closes the file
}