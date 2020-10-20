#include "ProjectOrganizer.h"




void init_project_organizer(){

    /* default ncurses configurations */
    initscr();
	cbreak();
	noecho();
    curs_set(0);

    /* init functions are called here */
	initLabels();
	start_color();
}
