#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int **geracaoAntiga, **geracaoNova;

/* Tentar implementar com loop around | (x + i + linhas) % linhas | (y + j + colunas) % colunas */
int conta_vizinhos(){

}

void copia_matrizes(){

}

void aloca_matrizes(){

}


int main(){

	initscr();
    clear();

	printw("hello");
	refresh();

	getch();
	int i,j;

	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
			mvprintw(j,i,"~");

	getch();

	endwin();

	return 0;
}
