/*********************************
* Class: MAGSHIMIM Final Project *
* Play function declaration	 	 *
**********************************/

#ifndef VIEWH
#define VIEWH

#define CV_IGNORE_DEBUG_BUILD_GUARD
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <stdio.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>
#include "LinkedList.h"

#define GIF_REPEAT 5


void play(FrameNode* list);

#endif