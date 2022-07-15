#ifndef MANAGEMENTH
#define MANAGEMENTH

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "view.h"
#include "linkedList.h"
#include "Functions.h"
#include "PrintFunctions.h"

#define MAX_STR 200
#define EXIT 0
#define ADD_NEW_FRAME 1
#define REMOVE_FRAME 2
#define CHANGE_FRAME_INDEX 3
#define CHANGE_FRAME_DUR 4
#define CHANGE_ALL_FRAME_DUR 5
#define LIST_FRAMES 6
#define PLAY 7
#define SAVE 8

void makeAnAction(FrameNode** head, int userOption);

#endif