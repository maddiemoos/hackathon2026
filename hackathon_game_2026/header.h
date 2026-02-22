#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>


typedef struct question //stores all data related to a question within the quiz/game
{
	char prompt[300]; //stores question prompt
	char questionType[10]; //stores what type of question i.e. text, multiple choice, etc.
	char multipleChoiceOption[200]; //stores options related to onlly multiple choice questions
	char correctAnswer[50]; //this stores the correct answer for a question
	int points; //stores how many points the user has
}Question;

//Description: loads the questions from the file into the array
//Precondition: bank must be a valid array, the file must be validly formatted and opened, and questiontotal has to be initialized
//Postcondition: bank gets the questions from the file, and question total is given a number
void loadQuestions(Question bank[], int* questionTotal);


//Description: runs the actual quiz, displays questions answers gets inputs etc.
//Precondition: bank has to actually have questions in it and questiontotal must have a number as well
//Postcondition: the user completes the quiz and the total score is displayed
void gamePlay(Question bank[], int questionTotal);


//Description: allows the user to insert whatever questions they want
//Precondition: questiontotal must be less than array total
//Postcondition: a new question is added and questiontotal also goes up by how ever many questions are added
void addQuestion(Question bank[], int *questionTotal);


//Description: removes a question from the question bank
//Precondition: there has to be questions in the bank
//Postcondition: a question is removed and questiontotal has one taken away from it
void deleteQuestion(Question bank[], int* questionTotal);


//Description: displays all question data upon request
//Precondition: bank has to have valid questions with valid data
//Postcondition: all questions are shown on the screen
void printQuestions(Question bank[], int questionTotal);


//Description: saves all of the questions and modifications made to the text file
//Precondition: bank has to have valid questions
//Postcondition: file is updated
void storeQuestion(Question bank[], int questionTotal);