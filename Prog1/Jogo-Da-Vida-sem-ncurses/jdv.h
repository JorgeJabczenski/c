#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define clear() printf("\033[H\033[J")

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
void ler_geracao_inicial(geracao *g);
void copia_geracao(geracao *g1, geracao *g2);
void calcular_nova_geracao(geracao *g1, geracao *g2);