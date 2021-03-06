#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>
#include "jdv.h"


int main(int argc, char **argv ){

	initscr();
    clear();
    
    /* Confere o número de parâmetros */
    if (argc != 3) {
        printf("Número de parametros incorreto, o programa deve possuir 2 parâmetros \n");
        endwin();
        return 1;
    }

    geracao antiga, nova;
    antiga.lin  = atoi(argv[1]);
    antiga.col  = atoi(argv[2]);
    nova.lin    = atoi(argv[1]);
    nova.col    = atoi(argv[2]);

    /* alocando as matrizes das duas gerações */
    antiga.matriz = aloca_matrizes(antiga.lin, antiga.col);
    nova.matriz   = aloca_matrizes(nova.lin  , nova.col);

    getch();

    ler_geracao_inicial(&antiga); /* Le e coloca as jogadas da geraçao 1 */

    imprime_geracao(antiga);

    getch();

    int i,j;

	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
			mvprintw(j,i,"~");

	refresh();
	getch();

	endwin();

	return 0;
}
