
#include "Functions.h"


/*
This function will perfom the fgets command and also remove the new line that might be at the end of the string - a known issue with the fgets
INPUT: the buffer to read into, the number of chars to read
OUTPUT: none
*/
void myFgets(char* str, int n)
{
	fgets(str, n, stdin);
	str[strcspn(str, "\n")] = 0;
}

/*
This function get frame name and return if the frame is in the gif
INPUT: the gif linked list, the frame name to search
OUTPUT: if the frame is there (int)
*/
int searchForFrame(FrameNode* head, char* frameName)
{
	FrameNode* curr = head;
	int found = 1;

	while (curr && found)
	{
		found = strcmp(curr->frame->name, frameName);
		curr = curr->next;
	}
	
	return found;
}

/*
This function add a new frame at the end of the gif
INPUT: gif's linked list, name + path + duration that is the frame info
OUTPUT: none
*/
void addNewFrame(FrameNode** head, char* name, char* path, unsigned int duration)
{
	FrameNode* tempNode = *head;
	int frameNameLen = 0;
	int pathLen = 0;

	memoryAllocate(head); // Allocate the default memory to the frame, without allocate to the name and the path
	frameNameLen = strlen(name) + 1; // +1 for the EOF
	pathLen = strlen(path) + 1; // +1 for the EOF

	if (tempNode) // if there is already a head
	{
		while (tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
		tempNode->frame->name = (char*)malloc(sizeof(char) * frameNameLen); // Allocate memory for the name
		tempNode->frame->path = (char*)malloc(sizeof(char) * pathLen); // Allocate memory for the path
		tempNode->frame->duration = duration;
		strcpy(tempNode->frame->name, name);
		strcpy(tempNode->frame->path, path);
		tempNode->next = NULL;
	}
	else
	{
		(*head)->frame->name = (char*)malloc(sizeof(char) * frameNameLen); // Allocate memory for the name
		(*head)->frame->path = (char*)malloc(sizeof(char) * pathLen); // Allocate memory for the path
		(*head)->frame->duration = duration;
		strcpy((*head)->frame->name, name);
		strcpy((*head)->frame->path, path);
		(*head)->next = NULL;
	}

}

/*
This function remove a frame from the gif
INPUT: the gif, the name of the frame to remove
OUTPUT: none
*/
void removeFrame(FrameNode** head, char* name)
{
	FrameNode* temp = *head;
	FrameNode* prev = NULL;
	int found = 1;
	if (temp && !(strcmp(temp->frame->name, name))) // If the frame is the head of the linked list
	{
		(*head) = temp->next;
		free(temp->frame->name);
		free(temp->frame->path);
		free(temp->frame);
		free(temp);
	}
	else if (temp)
	{
		while (temp && found)
		{
			found = strcmp(temp->frame->name, name);
			if (found)
			{
				prev = temp;
				temp = temp->next;
			}
		}
	}

	if (!found)
	{
		prev->next = temp->next;
		free(temp->frame->name);
		free(temp->frame->path);
		free(temp->frame);
		free(temp);
	}
	
}

/*
This function remove a frame place in the gif
INPUT: the gif, the frame's name to move, place to move
OUTPUT: none
*/
void moveFramePlace(FrameNode** head, char* frameToMove, int placeToMove)
{
	FrameNode* temp = *head;
	FrameNode* prev = *head;
	FrameNode* secondPrev = NULL;
	FrameNode* secondTemp = *head;
	int i = 0;
	int compare = 1;
	int indexesToMove = 0;
	while (temp != NULL && compare) // While it didnt reach the last node in the list and compare isnt 0
	{
		indexesToMove++; // Count the indexes to move
		compare = strcmp(temp->frame->name, frameToMove); // Compares between the current frameName and the name that is being searched
		if (compare)							   // If the strings arent equal it continues with the list
		{
			prev = temp;
			temp = temp->next;
		}
	}

	if (placeToMove != 1) // If user doesnt want to switch to the first node (1->2->3->4->5->6 - he doesnt want to switch 2 with 1)
	{
		secondPrev = secondTemp;
		for (i = 0; i < placeToMove - 1; i++)
		{
			secondPrev = secondTemp;
			secondTemp = secondTemp->next;
		}
		if (prev != temp) // If user doesnt want to switch the first node (1->2->3->4->5->6 he doesnt wanna take 1 and put it somewhere else)
		{
			if (indexesToMove > placeToMove) // If the user wants to change indexes from the right side of the linked list to the left side
			{
				// Right side to left side - 1->2->3->4->5->6, change index 5 with index 2
				prev->next = temp->next;
				secondPrev->next = temp;
				temp->next = secondTemp;
			}
			else // If the user wants to change indexes from the left side of the linked list to the right side
			{
				// Left side to right side - 1->2->3->4->5->6, change index 2 with 5
				prev->next = temp->next;
				temp->next = secondTemp->next;
				secondTemp->next = temp;
			}
		}
		else // If the user want to change the first index (1->2->3->4->5->6 - 1 change with 4)
		{
			prev = prev->next;
			temp->next = secondTemp->next;
			secondTemp->next = temp;
			(*head) = prev;
		}
	}
	else if (prev != temp) // If user want to swap with the first index (1->2->3->4->5->6 - change 4 with 1)
	{
		prev->next = temp->next;
		temp->next = (*head);
		(*head) = temp;
	}
}

/*
This function change a specific frame duration
INPUT: the gif, the frame's name, new duraiton
OUTPUT: none
*/
void changeFrameDuration(FrameNode** head, char* name, int newDuration)
{
	FrameNode* temp = *head;
	int found = 0;
	while (temp->next && !found)
	{
		if (strcmp(temp->frame->name, name) == 0)
		{
			temp->frame->duration = newDuration;
			found = TRUE;
		}
		temp = temp->next;
	}
}

/*
This function will change all the frames duration to a new one
INPUT: the gif, a new duration
OUTPUT: none
*/
void changeGifDuration(FrameNode** head, int newDuration)
{
	FrameNode* temp = *head;
	while (temp)
	{
		temp->frame->duration = newDuration;
		temp = temp->next;
	}
}


/*
This function allocate memory to the frames
INPUT: gif linked list
OUTPUT: none
*/
void memoryAllocate(FrameNode** head)
{
	FrameNode* temp = *head;
	if (*head)
	{
		while (temp->next)
		{
			temp = temp->next; // Gets to the last node in the list
		}
		temp->next = (FrameNode*)malloc(sizeof(FrameNode));
		temp->next->frame = (Frame*)malloc(sizeof(Frame));
		temp->next->next = NULL; // Allocates memory for the node and sets its next as null
	}
	else
	{
		(*head) = (FrameNode*)malloc(sizeof(FrameNode));
		(*head)->frame = (Frame*)malloc(sizeof(Frame));
		(*head)->next = NULL; // If there isnt a linked list yet it will allocate memory for the head
	}
}

/*
This function will release the dynamic memory that was allocated, recursivly
INPUT: the linked list to free
OUTPUT: none
*/
void freeTheHeap(FrameNode* head)
{
	if (head->next != NULL)
	{
		freeTheHeap(head->next); // Call the next node in the linked list
	}
	free(head->frame->name);
	free(head->frame->path);
	free(head->frame);
	free(head); // Free all the dynamic memory that was allocate to the current frame

}