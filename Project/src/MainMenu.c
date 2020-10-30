#include "Display.h"
#include "Task.h"

void main_menu(){

	int max_y, max_x;

	getmaxyx(stdscr, max_y, max_x);


    // banner thread setup
    PrintBannerArgs args;
	bool stop = FALSE;

    args.stop = &stop;
    args.x = max_x/2 - 40;
    args.y = 0;

    pthread_create(&banner_th, NULL, printBanner, &args);
    usleep(3000); // there is a bug that breaks the other components if this is not called :/

     
    // creating select menu
	char* options[] = {
		"Criar Projeto",
		"Carregar Projeto",
        "something else",
        "another stuff",
        "more stuff", 
        "even more stuff",
        "a shit ton of stuff",
		"sair :c"
	};

	int num_options = sizeof(options)/sizeof(char*);
	char* question = "Bem-Vindo ao Project Organizer";

	selectWin(options, question, num_options, 25, max_x/2 - 25, 0, 0, 0);

   
	stop = TRUE;

    pthread_join(banner_th, NULL);
}