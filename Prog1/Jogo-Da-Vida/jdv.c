#include "jdv.h"

/**********************************************/
/*          Operações com Matrizes            */
/**********************************************/
void imprime_geracao(geracao g){
    
    int i,j;

    for (i = 0; i < g.lin; i++)
        for (j = 0; j < g.col; j++)
			mvprintw(j,i,"%d", g.matriz[i][j]);

}

int **aloca_matrizes(int lin, int col){
   
    int **m;
    int i;
    
    m = (int **) malloc (lin * sizeof(int*));

    for (i = 0; i < lin; i++)
        m[i] = (int *) malloc (col * sizeof(int));

    return m;
}


/**********************************************/
/*              Funções do Jogo               */
/**********************************************/

/* Tentar implementar com loop around | (x + i + linhas) % linhas | (y + j + colunas) % colunas */
int conta_vizinhos(){

    int soma = 0;

    return soma;
}

void copia_matrizes(){

}

void ler_geracao_inicial(geracao *g){

     
}
