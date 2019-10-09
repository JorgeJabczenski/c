#include <stdio.h>
#include <stdlib.h>

int alocar_matriz(){


    return 1;
}

int ler_matriz(){


    return 1;
}

int multiplica_matrizes(){



    return 1;
}

int main(){

    int i,j,k; /* Indices */
    int linha1, coluna1,linha2, coluna2, soma;
    int **matriz1,**matriz2;

    printf("Entre com o tamanho de linha e coluna da primeira matriz:  ");
    scanf("%d %d", &linha1, &coluna1);
    printf("Entre com o tamanho de linha e coluna da segunda matriz:  ");
    scanf("%d %d", &linha2, &coluna2);

    if (coluna1 != linha2){
        printf("NÃO É POSSÍVEL\n");
    } else {

        matriz1 = (int**) malloc (linha1 * sizeof(int *));

        for (j = 0; j < coluna1; j++){
            matriz1[j] = (int *) malloc (coluna1 * sizeof(int));
        }

        matriz2 = (int **) malloc (linha2 * sizeof(int *));

        for (j = 0; j < coluna2; j++){
            matriz2[j] = (int *) malloc (coluna2 * sizeof(int));
        }

/*
        matrizResultante = (int **) malloc (linha1 * sizeof(int *));

        for (j = 0; j < coluna2; j++){
            matrizResultante[j] = (int *) malloc (coluna2 * sizeof(int));
        }
*/
        printf("Insira a primeira matriz\n");

        for (i = 0; i < linha1; i++){
            for (j = 0; j < coluna1; j++){
                scanf("%d", &matriz1[i][j]);
            }
        }

        printf("Insira a segunda matriz\n");

        for (i = 0; i < linha2; i++){
            for (j = 0; j < coluna2; j++){
                scanf("%d", &matriz2[i][j]);
            }
        }

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


    }

    for (i=0; i < linha 1; i++){
        free (matriz1[i]) ;
    }
    for (i=0; i < linha2; i++){
        free (matriz2[i]) ;
    }
    free (matriz1) ;
    free (matriz2) ;

    return 0;
}