#include <ncurses.h>
#include "Display.h"

#define DEBUG TRUE

// n curses config and project init functions
void init(){

	initscr();
	cbreak();
	noecho();
	curs_set(0);

	start_color();
	init_colors();
}


int main(){

	init();

	int status, location = loop(&status);	

	endwin();
	if(status != OK)
	{
		printf("an statusor has occured.\n");
		printf("status code: %d\n", status);
		printf("location: %d\n", location);
		printf(":/\n");
		return -1;
	}
	else if(DEBUG)
	{

	}

	printf("bye :)\n");


	return 0;
}
