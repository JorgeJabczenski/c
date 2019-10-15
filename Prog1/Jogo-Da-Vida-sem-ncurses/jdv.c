#include "jdv.h"

/**********************************************/
/*          Operações com Matrizes            */
/**********************************************/
void imprime_geracao(geracao g){
    
    int i,j;

    for (i = 0; i < g.lin; i++){     
        for (j = 0; j < g.col; j++){
            if (g.matriz[i][j] == 0)
			    printf("-");
            else 
                printf("o");
        }
        printf("\n");
    }
    clear();
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

void ler_geracao_inicial(geracao *g){
    int linha, coluna;

    printf("Para encerrar a entrada, digite -1 em qualquer uma das posições\n");
    scanf("%d %d", &linha, &coluna);

    while((linha >=0) && (coluna >= 0)){
        if ((linha >= g->lin) || (coluna >= g->col) ){
            printf("Coordenadas Inválidas\n");
        } else {
            g->matriz[linha][coluna] = 1;
        }

        scanf("%d %d", &linha, &coluna);

    }
     
}


int conta_vizinhos(geracao *g, int x, int y){

    /* Implementa a função vizinhos como uma esfera, dando a volta no tabuleiro     */
    /* Eu achei mais prático fazer assim do que ter que me preocupar com as bordas, */
    /* mesmo que a matemática seja meio chata no inicio, logo ela se torna clara    */

    int soma = 0, i, j;

    for (i = -1; i < 2; i++){
        for (j = -1; j < 2; j++){
            soma += g->matriz[(i + x + g->lin) % g->lin][(j + y + g->col) % g->col];
        }
    }

    soma -= g->matriz[x][y]; /* retira o valor da posição enviada*/
    return soma;
}

void copia_geracao(geracao *g1, geracao *g2){

    int i,j;

    for (i = 0; i < g1->lin; i++){
        for (j = 0; j < g1->col; j++){
            if (g1->matriz[i][j] != g2->matriz[i][j])
                g2->matriz[i][j] = g1->matriz[i][j];
        }
    }

}


void calcular_nova_geracao(geracao *g1, geracao *g2){

    int vizinhos;
    int i, j;

    for (i = 0; i < g1->lin; i++){
        for (j = 0; j < g1->col; j++){
            vizinhos = conta_vizinhos(g1, i, j);
            if ((vizinhos < 2 )|| (vizinhos > 3)){
                g2->matriz[i][j] = 0;
            } else if (vizinhos == 3){
                g2->matriz[i][j] = 1;
            } else {
                g2->matriz[i][j] = g1->matriz[i][j];
            }
        }
    }

}
