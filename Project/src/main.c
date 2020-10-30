#include <ncurses.h>
#include "Display.h"

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

	main_menu();


	endwin();
	return 0;
}
