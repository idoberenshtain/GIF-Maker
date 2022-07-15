#include "Management.h"

/*
This function get user option and a gif's linked list and call the function by the option and got the params if there are, basicly the Function.c's main
INPUT: gif's linked list, user option
OUTPUT: none
*/
void makeAnAction(FrameNode** head, int userOption)
{
	char name[MAX_STR] = { 0 };
	unsigned int duration = 0;
	char path[MAX_STR] = { 0 };
	int found = 0;
	int index = 0;
	int numOfNodes = 0;
	int imageMode = 0;
	FILE* tempFile = NULL;
	FrameNode* tempNode = NULL;

	switch (userOption)
	{
	case EXIT: // userOption: 0
		printf("Bye!\n");
		break;
	case ADD_NEW_FRAME: // userOption: 1
		printf("*** Creating new frame ***\n");
		printf("Please insert frame path:\n");
		myFgets(path, MAX_STR);

		printf("Please insert frame duration(in miliseconds):\n");
		scanf("%d", &duration);
		getchar(); // Clean the buffer

		printf("Please choose a name for that frame:\n");
		myFgets(name, MAX_STR);

		found = searchForFrame(*head, name);
		while (!found)
		{
			printTakenNames(*head); // Print the used names so the user will know what NOT to choose
			printf("The name is already taken, please enter another name\n");
			printf("Please insert frame name:\n");
			myFgets(name, MAX_STR);
		}

		tempFile = fopen(path, "r");
		if (tempFile)
		{
			fclose(tempFile); // Close the file we just wanted to check if he there
			addNewFrame(head, name, path, duration);
		}
		else
		{
			printf("Can't find file! Frame will not be added!");
		}

		break;
	case REMOVE_FRAME: // userOption: 2
		printf("Enter the name of the frame you wish to erase\n");
		myFgets(name, MAX_STR);
		if (!searchForFrame(*head, name))
		{
			removeFrame(head, name);
		}
		else
		{
			printf("The frame was not found\n");
		}

		break;
	case CHANGE_FRAME_INDEX: // userOption: 3
		printf("Enter the name of the frame\n");
		myFgets(name, MAX_STR);

		if (*head) // Check if the head is exist what means that there is at least one frame in the linked list
		{
			found = searchForFrame(*head, name);
			if (!found)
			{
				printf("Enter the new index in the movie you wish to place the frame\n");
				scanf("%d", &index);
				getchar();
				tempNode = *head;
				while (tempNode) // Count the num of nodes in the linked list
				{
					numOfNodes++;
					tempNode = tempNode->next;
				}

				if (index != numOfNodes && !(index > numOfNodes) && index != 0)
				{
					moveFramePlace(head, name, index);
				}
				else
				{
					printf("Please enter a valid amount of indexes, or not the same index to swap next time! Current indexes: 1 - %d\n", numOfNodes);
					printf("You attempted: %d\n", index);
				}

			}
			else
			{
				printf("The frame does not exist\n");
			}
		}
		break;
	case CHANGE_FRAME_DUR: // userOption: 4
		printf("Enter the name of the frame\n");
		myFgets(name, MAX_STR);

		found = searchForFrame(*head, name); // Check if there a frame with that name
		if (!found)
		{
			printf("Enter the new duartion\n");
			scanf("%d", &duration);
			changeFrameDuration(head, name, duration);
		}
		else
		{
			printf("The frame does not exist\n");
		}

		break;
	case CHANGE_ALL_FRAME_DUR: // userOption: 5
		printf("Enter the duration for all frames\n");
		scanf("%d", &duration);
		getchar(); // Clean the buffer
		changeGifDuration(head, duration);
		break;
	case LIST_FRAMES: // userOption: 6
		printFrames(*head);
		break;
	case PLAY: // userOption: 7
		if (*head)
		{
			play(*head);
		}
		else 
		{
			printf("There is nothing to play:(\n");
		}
		break;
	case SAVE: // userOption: 8
		if (*head) // Only if there any frame to save
		{
			printf("Where do you want to save project? enter a full path and file name\n");
			printf("How to save project? - C:\\ExamplePath\\filename.txt - .txt is always required or save wont work!\n");
			printf("WARNING: The save option WILL Overwrite a file, do not enter an existing file name!\n");
			myFgets(path, MAX_STR);
			tempFile = fopen(path, "w"); // Open the file to check if it not NULL (may cause it in Administrator area)
			if (tempFile)
			{
				fclose(tempFile); // Close the file, we just wanted to check if we can access this loaction
				saveGif(head, path); // Call the function to sve the gif
			}
			else // Means we cant reach this location
			{
				printf("ERROR: Couldn't open file, make sure you follow the instructions!\n");
			}
		}
		else // Means the gif is empty (no frames)
		{
			printf("Cant save a project without adding any frames to it!\n");
		}
		break;
	default:
		printf("You can only enter number between 0-8!\n");
	}
}