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
