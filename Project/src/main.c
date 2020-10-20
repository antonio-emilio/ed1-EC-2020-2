#include <ncurses.h>

#include "Task.h"
#include "ProjectOrganizer.h"


int main(){
	init_project_organizer();	


	Task_t* test = createTask("title teste", "this is a test task from the project organizer :)");
	Task_t* test2 = createTask("algum teste qualquer", "this is a test task from the project organizer :)");

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
