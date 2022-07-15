#include "printFunctions.h"

/*
This function print the start menu and get the user choice if to load a gif or create a new one
INPUT: none
OUTPUT: 1 / 0, for the option
*/
int startMenu()
{
	int userChoice = 0;
	printf("***** VIDEOINPUT LIBRARY - 0.1995 - TFW07 *****\n\n");
	printf("Welcome to Magshimim Movie Maker! what would you like to do?\n");
	printf(" [0] Create a new project\n");
	printf(" [1] Load existing project\n");
	scanf("%d", &userChoice); // Gets user's choice
	getchar();  // Clean the buffer

	return userChoice;
}

/*
This function print the options menu, and get the option from the user
INPUT: none
OUTPUT: user choice
*/
int optionsMenu()
{
	int userChoice = 0;
	printf("\n\n");
	printf("What would you like to do?\n");
	printf(" [0] Exit\n");
	printf(" [1] Add new frame\n");
	printf(" [2] Remove a frame\n");
	printf(" [3] Change frame index\n");
	printf(" [4] Change frame duration\n");
	printf(" [5] Change duration of all frames\n");
	printf(" [6] List frames\n");
	printf(" [7] Play movie!\n");
	printf(" [8] Save Project\n");
	scanf("%d", &userChoice); // Get user's choice
	getchar(); // Clean the buffer

	return userChoice;
}


/*
This function will print the frame's name, duration and path
INPUT: the head of the frames
OUTPUT: none
*/
void printFrames(FrameNode* head)
{
	FrameNode* tempFrame = head;
	while (tempFrame != NULL)
	{
		printf("Name: % s, Duration : % d ms, Path : % s\n", tempFrame->frame->name, tempFrame->frame->duration, tempFrame->frame->path);
		tempFrame = tempFrame->next;
	}
}

/*
This function print the taken names in the frames
INPUT: the head of the frames
OUTPUT: none
*/
void printTakenNames(FrameNode* head)
{
	FrameNode* curr = head;
	printf("Taken names: ");
	while (curr)
	{
		printf("%s, ", curr->frame->name);
		curr = curr->next;
	}
	printf("\n");
}

/*
This function print the filters option that avaliable and get the option from the user
INPUT: none
OUTPUT: the user choice
*/
int filtersAvailable()
{
	int userChoice = 0;
	printf("Please choose one of the options below:\n");
	printf(" [0] Normal\n");
	printf(" [1] Black & White\n");
	scanf("%d", &userChoice); // Get user's choice
	getchar(); // Clean the buffer
}