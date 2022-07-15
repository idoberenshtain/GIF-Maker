/*********************************
 * Class: MAGSHIMIM C2			 *
 * Week:                			 *
 * Name:    Ido Berenshtain       *
 * Credits:                       *
 **********************************/

#include <stdio.h>
#include "LinkedList.h"
#include "view.h"
#include "LinkedList.h"
#include "Management.h"
#include "PrintFunctions.h"
#include "Functions.h"
#include "SaveOrLoad.h"

#define NEW_GIF 0
#define EXIST_GIF 1
#define EXIT 0

/*
This function control the whole program
INPUT: none
OUTPUT: 1 - on fail, 0 - on success
*/
int main(void)
{
	FrameNode *gif = NULL;
	int userChoice = 0;
	userChoice = startMenu();
	char path[MAX_STR] = {0};
	FILE *gifFile = NULL;

	if (userChoice == NEW_GIF) // Create new gif
	{
		printf("Working on a new project..");
		do
		{
			userChoice = optionsMenu();
			makeAnAction(&gif, userChoice);
		} while (userChoice != EXIT); // User choice isn't 0 exit
	}
	else if (userChoice == EXIST_GIF) // Open an exist gif
	{
		printf("Instructions: full project path - the last path the project was saved\n");
		printf("Example: C:\\ExampleFile\\TheProject.txt\n");
		printf("Enter full project path to load\n");
		myFgets(path, MAX_STR);
		gifFile = fopen(path, "r");
		while (!gifFile)
		{
			printf("Invalid file path! Please enter a valid file path\n");
			myFgets(path, MAX_STR);
			gifFile = fopen(path, "r");
		}
		fclose(gifFile);		  // Close the file after
		loadExistGif(path, &gif); // Call the function to load the exist gif
		do
		{
			userChoice = optionsMenu();
			makeAnAction(&gif, userChoice);
		} while (userChoice != EXIT); // User choice isn't exit
	}

	if (gif) // Only if the gif not NULL , means exist
	{
		freeTheHeap(gif);
	}

	getchar();
	return 0;
}
