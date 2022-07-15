#ifndef SAVEORLOADH
#define SAVEORLOADH

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "view.h"
#include "linkedList.h"
#include "Management.h"

void saveGif(FrameNode** head, char* path);
void loadExistGif(char* path, FrameNode** head);

#endif