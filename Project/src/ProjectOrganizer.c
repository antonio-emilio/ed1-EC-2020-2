#include "ProjectOrganizer.h"




Exception initProjectOrganizer(){
int term_y, term_x;

    getmaxyx(stdscr, term_y, term_x); 

    if(term_y < 37 || term_x  < 150)
    {
        printf("terminal size is too small\n");
        return INVALID_TERMINAL_SIZE;

    }

	printw("%d %d", term_y, term_x);

}