#include "SaveOrLoad.h"

/*
This function will save the gif that was created to a provided path
The file format is:
- num_of_frames
- frame1_duration
- frame1_name
- frame1_path
and all the frames after it...
INPUT: gif's linked list and a path
OUTPUT: none
*/
void saveGif(FrameNode** head, char* path)
{
	FILE* fileToSave = NULL;
	FrameNode* tempNode = *head;
	int numOfFrames = 0;

	if (*head)
	{
		fileToSave = fopen(path, "w");

		while (tempNode) // Count the num of frames in the gif
		{
			numOfFrames++;
			tempNode = tempNode->next;
		}

		tempNode = *head;
		fprintf(fileToSave, "%d\n", numOfFrames); // Write the frames amount in the head of the file
		while (tempNode) // Save every frame to the file
		{
			fprintf(fileToSave, "%d\n", tempNode->frame->duration);
			fprintf(fileToSave, "%s\n", tempNode->frame->name);
			fprintf(fileToSave, "%s\n", tempNode->frame->path);
			tempNode = tempNode->next;
		}

		fclose(fileToSave); // Closing the file after finishing save the gif
	}
}

/*
This function will load an exist gif to the program
The file saved as:
- num_of_frames
- frame1_duration
- frame1_name
- frame1_path
and all the frames after it...
INPUT: the path of the gif, the linked list to put the gif in it
OUTPUT: none
*/
void loadExistGif(char* path, FrameNode** head)
{
	FILE* gifFile = NULL;
	FrameNode* tempNode = NULL;
	int numOfNodes = 0;
	int i = 0;
	char framePath[MAX_STR] = { 0 };
	char name[MAX_STR] = { 0 };
	int duration = 0;

	gifFile = fopen(path, "r");
	fscanf(gifFile, "%d", &numOfNodes); // Get the number of nodes

	for (i = 0; i < numOfNodes; i++)
	{
		memoryAllocate(head);
		tempNode = *head;
		while (tempNode->next)
		{
			tempNode = tempNode->next;
		}
		fscanf(gifFile, "%d", &duration); // Get the duration from the file
		fscanf(gifFile, "%s", &name); // Get the name from the file
		fscanf(gifFile, "%s", &framePath); // Get the path from the file
		tempNode->frame->duration = duration;
		tempNode->frame->name = (char*)malloc(sizeof(char) * strlen(name) + 1); // +1 for the EOF
		tempNode->frame->path = (char*)malloc(sizeof(char) * strlen(framePath) + 1); // +1 for the EOF

		strcpy(tempNode->frame->name, name); // Put the name in the node
		strcpy(tempNode->frame->path, framePath); // Put the path in the node
	}
	fclose(gifFile);
}