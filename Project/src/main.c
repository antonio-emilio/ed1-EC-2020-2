#include <ncurses.h>

#include "Task.h"


int main(){
	// inicializa a tela
	// prepara o buffer de memoria limpa a tela
	initscr();
	cbreak();
	noecho();


	start_color();


	// desaloca a memoria e termina ncurses
	endwin();
	return 0;
}
