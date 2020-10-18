#include <ncurses.h>

#include "Task.h"
#include "ProjectOrganizer.h"


int main(){
	// inicializa a tela
	// prepara o buffer de memoria limpa a tela
	initscr();
	cbreak();
	noecho();

	// project organizer init funcs
	if(initProjectOrganizer() == INVALID_TERMINAL_SIZE)
		return -1;


	initLabels();


	start_color();


	Task_t* test = createTask("title teste", "this is a test task from the project organizer :)");
	Label_t* label_test = createLabel(COLOR_BLUE, "feature");

	addLabel(test,label_test);

	show(test, 1, 1);


	refresh();

	getch();

	endwin();
	return 0;
}
