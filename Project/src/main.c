#include <ncurses.h>

#include "Task.h"
#include "ProjectOrganizer.h"


int main(){
	// inicializa a tela
	// prepara o buffer de memoria limpa a tela
	initscr();
	cbreak();
	noecho();

	initLabels();

	start_color();


	Task_t* test = createTask("title teste", "this is a test task from the project organizer :)");
	Task_t* test2 = createTask("title2 teste", "this is a test task from the project organizer :)");


	addLabel(test2, createLabel(COLOR_CYAN, "label black"));
	addLabel(test, createLabel(COLOR_BLUE, "feature"));
	addLabel(test, createLabel(COLOR_WHITE, "label white"));
	addLabel(test, createLabel(COLOR_CYAN, "label cyan"));
	addLabel(test, createLabel(COLOR_GREEN, "label green"));
	addLabel(test, createLabel(COLOR_MAGENTA, "label magenta"));

	boolean selected = False;
	char c; 

	while(c != '0')
	{
		c = getch();

		if(c == 's')	
			selected = !selected;

		show(test, 1, 1, selected);
		show(test2, TASK_DISPLAY_HEIGHT + 4, 1, selected);

	}
	refresh();
	hide(test);
	hide(test2);

	getch();


	endwin();
	return 0;
}
