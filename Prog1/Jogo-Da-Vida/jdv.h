#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>

typedef struct geracao{
    int **matriz;
    int lin;
    int col;

} geracao;

/* Operações com Matrizes */
void imprime_geracao(geracao g);
int **aloca_matrizes(int lin, int col);

/* Funções do jogo */
int conta_vizinhos();
void copia_matrizes();
void ler_geracao_inicial(geracao *g);