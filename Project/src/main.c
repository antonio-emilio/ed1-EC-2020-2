#include <ncurses.h>

#include "ProjectOrganizer.h"
#include "Task.h"


int main(){
	// inicializa a tela
	// prepara o buffer de memoria limpa a tela
	initscr();
	cbreak();
	noecho();
	curs_set(0);

	initLabels();

	start_color();
	int y, x;
	getmaxyx(stdscr, y, x);


	Task_t* task_array[10];

	for(int i = 0; i < 10; i++)
	{
		task_array[i] = createTask("test task", "whatever");
		addLabel(task_array[i], createLabel(COLOR_CYAN, "label black"));
		addLabel(task_array[i], createLabel(COLOR_CYAN, "label cyan"));
		addLabel(task_array[i], createLabel(COLOR_GREEN, "label green"));
		addLabel(task_array[i], createLabel(COLOR_MAGENTA, "label magenta"));


	}

	printBanner(0, x/2);

	int task_y = 0;
	bool selected = False;
	bool bye = False;
	while(!bye)
	{
		char* options[] = {
			"move tasks down",
			"move tasks up",
			"show tasks",
			"hide tasks",
			"exit :c"
		};
		int options_size = sizeof(options)/sizeof(char*);

		int choice = selectWin(options, "o que quer seu merda?", options_size, y, x/2, 0, 0, choice);

		switch(choice)
		{	
			case 0:
				task_y++;
				for(int i = 0; i < 10; i++)
					moveTask(task_array[i], task_y, TASK_DISPLAY_WIDTH*i, True);
				break;

			case 1:
				task_y--;
				for(int i = 0; i < 10; i++)
					moveTask(task_array[i], task_y, TASK_DISPLAY_WIDTH*i, True);
				break;

			case 2:
				for(int i = 0; i < 10; i++)
					show(task_array[i], 0,  TASK_DISPLAY_WIDTH*i, selected);
				break;

			case 3:
				for(int i = 0; i < 10; i++)
					hide(task_array[i]);
				printBanner(0, x/2);
				break;

			case 4:
				bye = True;
				continue;
		}

		if(task_y < 0)
			task_y = 0;

		refresh();

	}

	endwin();
	return 0;
}
