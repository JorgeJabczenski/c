#include <stdio.h>
#include <stdlib.h>


struct matriz_t {
	int **mat;
	int lin;
	int col;
};

typedef struct matriz_t matriz_s;

int **alocar_matriz(int linha, int coluna){

    int **matriz;
    int i;

    matriz = (int **) malloc (linha * sizeof(int *));

    for (i = 0; i < linha; i++)
        matriz[i] = (int *) malloc (coluna * sizeof(int));

    return matriz;
}

int ler_matriz(int ** matriz, int linha, int coluna){

    int i,j;

        for (i = 0; i < linha; i++){
            for (j = 0; j < coluna; j++){
                scanf("%d", &matriz[i][j]);
            }
        }

    return 1;
}

int multiplica_matrizes(int **matriz1, int**matriz2, int linha1, int linha2, int coluna2){

    int i, j, k, soma;

        printf("\nMatriz Resultante: \n");
        for(i = 0; i < linha1; i++){
            for (j = 0; j < coluna2; j++){
                soma = 0;
                for (k = 0; k < linha2; k++){
                    soma +=  matriz1[i][k] * matriz2[k][j];
                }
                printf("%d ", soma);
            }
            printf("\n");
        }
        printf("\n");

    return 1;
}

int main(){

    int i;
    matriz_s matriz1,matriz2;

    printf("Entre com o tamanho de linha e coluna da primeira matriz:  ");
    scanf("%d %d", &matriz1.lin, &matriz1.col);
    printf("Entre com o tamanho de linha e coluna da segunda matriz:  ");
    scanf("%d %d", &matriz2.lin, &matriz2.col);

    if (matriz1.col != matriz2.lin){
        printf("NÃO É POSSÍVEL\n");
    } else {

        /* Alocar o espaço das matrizes */
        matriz1.mat = alocar_matriz(matriz1.lin, matriz1.col);
        matriz2.mat = alocar_matriz(matriz2.lin, matriz2.col);

        /* Ler o conteúdo das matrizes*/
        printf("Insira a primeira matriz\n");
        ler_matriz(matriz1.mat, matriz1.lin, matriz1.col);
        
        printf("Insira a segunda matriz\n");
        ler_matriz(matriz2.mat, matriz2.lin, matriz2.col);

        /* Realiza a multiplicação */
        multiplica_matrizes(matriz1.mat, matriz2.mat, matriz1.lin, matriz2.lin, matriz2.col);
        
        /* Libera o espaço alocado para as matrizes */
        for (i=0; i < matriz1.lin; i++){
            free (matriz1.mat[i]) ;
        }
        free (matriz1.mat) ;

        for (i=0; i < matriz2.lin; i++){
            free (matriz2.mat[i]) ;
        }
        free (matriz2.mat) ;

    }
    return 0;
}