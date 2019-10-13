#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "lib_ordena.h"

#define MAX_IT 10000 /* isto pode ser ajustado */

/* Retorna tempo em milisegundos */
double timestamp(void)
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

int main () {
    /*int va[MAX], vb[MAX]; */
    int *va, *vb;
    va = (int*) malloc (MAX*sizeof(int));
    vb = (int*) malloc (MAX*sizeof(int));
    long long int i, tam;
    double iniA, iniB, fimA, fimB, soma_tempo_a, soma_tempo_b;

    /* testes com vetores gerados randomicamente */

    /* defina tam como voce achar melhor */
/*****************************************************************************************/
      printf("Comparando o QuickSort e o MergeSort\n");

      /* Comparando o QuickSort e o MergeSort com Entradas Aleatórias */
      
      for (tam = 10; tam < 1000000; tam *= 10){

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

      printf("\ntamanho : %lld\n", tam);
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

      printf("\ntamanho : %lld\n", tam);
      printf("vetor: ordenado\n");
      printf("tempo medio do quicksort: %f\n", soma_tempo_a/MAX_IT);
      printf("tempo medio do mergesort: %f\n", soma_tempo_b/MAX_IT);

      printf("---------------------------\n");

    }
/*------------------------------------------------------------------------------*/
      printf("Comparando o Quick e o Insertion \n");

      /* Comparando o QuickSort e o Insertion com Entradas Aleatórias */

    for (tam = 10; tam <= 100; tam += 10){


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
        insertionsort(vb,0,tam-1);
        fimB = timestamp();
        soma_tempo_b += (fimB - iniB);

      }

      printf("\ntamanho : %lld\n", tam);
      printf("vetor: aleatório\n");
      printf("tempo medio do quicksort: %f\n", soma_tempo_a/MAX_IT);
      printf("tempo medio do insertion: %f\n", soma_tempo_b/MAX_IT);
  /*-----------------------------------------------------------------------------------------*/
      /* Comparando o QuickSort e o Insertion com Entradas Ordenadas */

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
        insertionsort(vb,0,tam-1);
        fimB = timestamp();
        soma_tempo_b += (fimB - iniB);

      }

      printf("\ntamanho : %lld\n", tam);
      printf("vetor: ordenado\n");
      printf("tempo medio do quick: %f\n", soma_tempo_a/MAX_IT);
      printf("tempo medio do insertion: %f\n", soma_tempo_b/MAX_IT);

      printf("---------------------------\n");

    }
/*-----------------------------------------------------------------------------------------*/
      printf("Comparando o Merge e o Insertion\n");
      /* Comparando o Merge e o Insertion com Entradas Aleatórias */

    for (tam = 10; tam <= 100; tam += 10){

      soma_tempo_a = 0;
      soma_tempo_b = 0;
      for (i = 0; i < MAX_IT; i++){

        /* Gera duas copias do mesmo vetor */
        gera_vetor_aleatorio (va,tam);
        copia_vetor(va,vb,tam);

        /* Mede o tempo do QuickSort */
        iniA = timestamp();
        mergesort(va,0,tam-1);
        fimA = timestamp();
        soma_tempo_a += (fimA - iniA);

        /* Mede o tempo do MergeSort */
        iniB = timestamp();
        insertionsort(vb,0,tam-1);
        fimB = timestamp();
        soma_tempo_b += (fimB - iniB);

      }

      printf("\ntamanho : %lld\n", tam);
      printf("vetor: aleatório\n");
      printf("tempo medio do mergesort: %f\n", soma_tempo_a/MAX_IT);
      printf("tempo medio do insertion: %f\n", soma_tempo_b/MAX_IT);
  /*-----------------------------------------------------------------------------------------*/
      /* Comparando o Merge e o Insertion com Entradas Ordenadas */

      soma_tempo_a = 0;
      soma_tempo_b = 0;
      for (i = 0; i < MAX_IT; i++){

        /* Gera duas copias do mesmo vetor */
        gera_vetor_ordenado (va,tam);
        copia_vetor(va,vb,tam);

        /* Mede o tempo do QuickSort */
        iniA = timestamp();
        mergesort(va,0,tam-1);
        fimA = timestamp();
        soma_tempo_a += (fimA - iniA);

        /* Mede o tempo do MergeSort */
        iniB = timestamp();
        insertionsort(vb,0,tam-1);
        fimB = timestamp();
        soma_tempo_b += (fimB - iniB);

      }

      printf("\ntamanho : %lld\n", tam);
      printf("vetor: ordenado\n");
      printf("tempo medio do mergesort: %f\n", soma_tempo_a/MAX_IT);
      printf("tempo medio do insertion: %f\n", soma_tempo_b/MAX_IT);

      printf("---------------------------\n");

    }
/**************************************************************************************/

  return 0;
}
