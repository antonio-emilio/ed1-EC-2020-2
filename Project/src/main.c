#include <ncurses.h>


int main(){
	// inicializa a tela
	// prepara o buffer de memoria limpa a tela
	initscr();
	
	// recarrega a tela para dar load no que esta
	// na memoria
	refresh();

	getch();
	

	// desaloca a memoria e termina ncurses
	endwin();
	return 0;
}
