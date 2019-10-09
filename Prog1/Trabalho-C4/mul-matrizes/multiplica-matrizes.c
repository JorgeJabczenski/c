#include <stdio.h>
#include <stdlib.h>

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

    int i,linha1, coluna1,linha2, coluna2;
    int **matriz1,**matriz2;

    printf("Entre com o tamanho de linha e coluna da primeira matriz:  ");
    scanf("%d %d", &linha1, &coluna1);
    printf("Entre com o tamanho de linha e coluna da segunda matriz:  ");
    scanf("%d %d", &linha2, &coluna2);

    if (coluna1 != linha2){
        printf("NÃO É POSSÍVEL\n");
    } else {

        /* Alocar o espaço das matrizes */
        matriz1 = alocar_matriz(linha1, coluna1);
        matriz2 = alocar_matriz(linha2, coluna2);

        /* Ler o conteúdo das matrizes*/
        printf("Insira a primeira matriz\n");
        ler_matriz(matriz1, linha1, coluna1);
        
        printf("Insira a segunda matriz\n");
        ler_matriz(matriz2, linha2, coluna2);

        /* Realiza a multiplicação */
        multiplica_matrizes(matriz1, matriz2, linha1, linha2, coluna2);
        
        /* Libera o espaço alocado para as matrizes */
        for (i=0; i < linha1; i++){
            free (matriz1[i]) ;
        }
        free (matriz1) ;

        for (i=0; i < linha2; i++){
            free (matriz2[i]) ;
        }
        free (matriz2) ;

    }
    return 0;
}