#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <ncurses.h>
#include <string.h>

#define BANNER_COLOR 100 

bool IS_RESIZED;

int selectWin(char** options, char* question, int num_options, int y, int x, unsigned int width,unsigned int height, int default_choice);

void printBanner(int y, int x);

#endif 