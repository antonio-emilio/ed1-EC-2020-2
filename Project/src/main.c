#include <ncurses.h>


int main(){
	// inicializa a tela
	// prepara o buffer de memoria limpa a tela
	initscr();
	start_color();

  	getch();

	/*
		program must run here
	*/

	// desaloca a memoria e termina ncurses
	endwin();
	return 0;
}
