#ifndef FUNCTIONSH
#define FUNCTIONSH

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "view.h"
#include "linkedList.h"
#include "Management.h"

void myFgets(char* str, int n);
int searchForFrame(FrameNode* head, char* frameName);
void addNewFrame(FrameNode** head, char* name, char* path, unsigned int duration);
void removeFrame(FrameNode**, char* name);
void moveFramePlace(FrameNode** head, char* frameToMove, int placeToMove);
void changeFrameDuration(FrameNode** head, char* name, int newDuration);
void changeGifDuration(FrameNode** head, int newDuration);
void memoryAllocate(FrameNode** head);
void freeTheHeap(FrameNode* head);

#endif
