#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "lib_ordena.h"

#define MAX_IT 1000 /* isto pode ser ajustado */

/* Retorna tempo em milisegundos */
double timestamp(void)
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

int main () {
    int va[MAX], vb[MAX]; 
    int i, tam;
    double iniA, iniB, fimA, fimB, soma_tempo_a, soma_tempo_b;

    /* testes com vetores gerados randomicamente */

    /* defina tam como voce achar melhor */

    for (tam = 10; tam < 10000000; tam *= 10){


      /* Comparando o QuickSort e o MergeSort com Entradas Aleatórias */

      soma_tempo_a = 0;
      soma_tempo_b = 0;
      for (i = 0; i < MAX_IT; i++){

        /* Gera duas copias do mesmo vetor */
        gera_vetor_aleatorio (va,tam);
        copia_vetor(va,vb,tam);

        /* Mede o tempo do QuickSort */
        iniA = timestamp();
        quicksort(va,0,tam-1);
        fimA = timestamp();
        soma_tempo_a += (fimA - iniA);

        /* Mede o tempo do MergeSort */
        iniB = timestamp();
        mergesort(vb,0,tam-1);
        fimB = timestamp();
        soma_tempo_b += (fimB - iniB);

      }

      printf("\ntamanho : %d\n", tam);
      printf("vetor: aleatório\n");
      printf("tempo medio do quicksort: %f\n", soma_tempo_a/MAX_IT);
      printf("tempo medio do mergesort: %f\n", soma_tempo_b/MAX_IT);
  /*-----------------------------------------------------------------------------------------*/
      /* Comparando o QuickSort e o MergeSort com Entradas Ordenadas */

      soma_tempo_a = 0;
      soma_tempo_b = 0;
      for (i = 0; i < MAX_IT; i++){

        /* Gera duas copias do mesmo vetor */
        gera_vetor_ordenado (va,tam);
        copia_vetor(va,vb,tam);

        /* Mede o tempo do QuickSort */
        iniA = timestamp();
        quicksort(va,0,tam-1);
        fimA = timestamp();
        soma_tempo_a += (fimA - iniA);

        /* Mede o tempo do MergeSort */
        iniB = timestamp();
        mergesort(vb,0,tam-1);
        fimB = timestamp();
        soma_tempo_b += (fimB - iniB);

      }

      printf("\ntamanho : %d\n", tam);
      printf("vetor: ordenado\n");
      printf("tempo medio do quicksort: %f\n", soma_tempo_a/MAX_IT);
      printf("tempo medio do mergesort: %f\n", soma_tempo_b/MAX_IT);

      printf("---------------------------\n");

    }


  return 0;
}
