#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "lib_ordena.h"

#define MAX_IT 10 /* isto pode ser ajustado */
#define TAM_MAX_VET 100000

/* Retorna tempo em milisegundos */
double timestamp(void)
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

int main () {

    int *va, *vaux;
    va   = (int *) malloc (MAX*sizeof(int));
    vaux = (int *) malloc (MAX*sizeof(int));
    long long int i, tam;
    int k = 0;
    double tempos[9][6];
    double soma_tempos[8], ini[8], fim[8];

    /*
    insertion
    quicksort tradicional
    quicksort mediana 3
    quicksort mediana 3 + insertion
    merge
    merge alternado + vetor por referencia + checagem
    merge checagem
    merge com vetor por referencia 
  */

    for (tam = 10; tam <= TAM_MAX_VET; tam *= 10){
        /*zera os tempos*/
        for (i = 0; i < 8; i++){
            soma_tempos[i] = 0;
        }

        for (i = 0; i < MAX_IT; i++){
            
            /* Mede tempo do Insertion Sort */
            gera_vetor_aleatorio(va, tam);
            ini[0] = timestamp();
            insertionsort(va, 0, tam-1);
            fim[0] = timestamp();
            soma_tempos[0] += (fim[0] - ini[0]);

            /* Mede tempo do QuickSort Tradicional*/
            gera_vetor_aleatorio(va, tam);
            ini[1] = timestamp();
            quicksort(va, 0, tam-1);
            fim[1] = timestamp();
            soma_tempos[1] += (fim[1] - ini[1]);

            /* Mede tempo do QuickSort M3 */
            gera_vetor_aleatorio(va, tam);
            ini[2] = timestamp();
            quicksort_mediana3(va, 0, tam-1);
            fim[2] = timestamp();
            soma_tempos[2] += (fim[2] - ini[2]);

            /* Mede tempo do  QuickSort M3 + Insertion*/
            gera_vetor_aleatorio(va, tam);
            ini[3] = timestamp();
            quicksort_mediana3_insertion(va, 0, tam-1);
            fim[3] = timestamp();
            soma_tempos[3] += (fim[3] - ini[3]);

            /* Mede tempo do Merge Tradicional */
            gera_vetor_aleatorio(va, tam);
            ini[4] = timestamp();
            mergesort(va, 0, tam-1);
            fim[4] = timestamp();
            soma_tempos[4] += (fim[4] - ini[4]);

            /* Mede tempo do Merge Alternado */
            gera_vetor_aleatorio(va, tam);
            ini[5] = timestamp();
            mergesort_a(va, vaux, 0, tam-1);
            fim[5] = timestamp();
            soma_tempos[5] += (fim[5] - ini[5]);

            /* Mede tempo do Merge Chacagem */
            gera_vetor_aleatorio(va, tam);
            ini[6] = timestamp();
            mergesort_b(va, 0, tam-1);
            fim[6] = timestamp();
            soma_tempos[6] += (fim[6] - ini[6]);

            /* Mede tempo do Merge Referência */
            gera_vetor_aleatorio(va, tam);
            ini[7] = timestamp();
            mergesort_c(va, vaux, 0, tam-1);
            fim[7] = timestamp();
            soma_tempos[7] += (fim[7] - ini[7]);

        }

        tempos[0][k] = tam;

        int t;
        for (t = 0; t < 8; t++){
            tempos[t+1][k] = soma_tempos[t];
        }
        k++;
    }


    int o,p;

    for (o = 0; o < 9; o++){
        for (p = 0; p < 6; p++){
            if (o == 0)
                printf("%0.0f ",tempos[o][p]);
            else 
                printf("%f ",tempos[o][p]);
        }
        printf("\n");
    }


 return 0;
}