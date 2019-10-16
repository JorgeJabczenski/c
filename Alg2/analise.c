#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "lib_ordena.h"

#define MAX_IT 10 /* isto pode ser ajustado */
#define TAM_MAX_VET 1000000

/* Retorna tempo em milisegundos */
double timestamp(void)
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

int main () {

  /*int va[MAX], vb[MAX]; */
  int *va, *vb, *vaux;
  va   = (int *) malloc (MAX*sizeof(int));
  vb   = (int *) malloc (MAX*sizeof(int));
  vaux = (int *) malloc (MAX*sizeof(int));
  long long int i, tam;
  double iniA, iniB, fimA, fimB, soma_tempo_a, soma_tempo_b;

/*****************************************************************************************/
/*                          QuickSortM3 x MergeSort A                                    */
/*****************************************************************************************/
printf("Comparando MergeSort e MergeSort_A (alternado)");
  
  for (tam = 10; tam < TAM_MAX_VET; tam *= 10){

    soma_tempo_a = 0;
    soma_tempo_b = 0; 

    for (i = 0; i < MAX_IT; i++){

      /* Gera duas copias do mesmo vetor */
      gera_vetor_aleatorio (va,tam);
      copia_vetor(va,vb,tam);

      /* Mede o tempo do MergeSort */
      iniA = timestamp();
      mergesort(va,0,tam-1);
      fimA = timestamp();
      soma_tempo_a += (fimA - iniA);

      /* Mede o tempo do MergeSort_B */
      iniB = timestamp();
      quicksort_mediana3(vb,0,tam-1);
      fimB = timestamp();
      soma_tempo_b += (fimB - iniB);

    }

    printf("\ntamanho : %lld\n", tam);
    printf("vetor: aleatório\n");
    printf("tempo medio do mergesort alternado:   %f\n", soma_tempo_b/MAX_IT);
    printf("tempo medio do quicksort m3 ins:      %f\n", soma_tempo_a/MAX_IT);

    soma_tempo_a = 0;
    soma_tempo_b = 0;
    
    for (i = 0; i < MAX_IT; i++){

      /* Gera duas copias do mesmo vetor */
      gera_vetor_ordenado (va,tam);
      copia_vetor(va,vb,tam);

      /* Mede o tempo do MergeSort */
      iniA = timestamp();
      mergesort(va,0,tam-1);
      fimA = timestamp();
      soma_tempo_a += (fimA - iniA);

      /* Mede o tempo do MergeSort_B */
      iniB = timestamp();
      quicksort_mediana3(vb,0,tam-1);
      fimB = timestamp();
      soma_tempo_b += (fimB - iniB);

    }

    printf("\ntamanho : %lld\n", tam);
    printf("vetor: ordenado\n");
    printf("tempo medio do mergesort alternado:   %f\n", soma_tempo_b/MAX_IT);
    printf("tempo medio do quicksort m3 ins:      %f\n", soma_tempo_a/MAX_IT);

    printf("---------------------------\n");


}

/*****************************************************************************************/
/*                          MergeSort Normal x MergeSort A                               */
/*****************************************************************************************/
printf("Comparando MergeSort e MergeSort_A (alternado)");
  
  for (tam = 10; tam < TAM_MAX_VET; tam *= 10){

    soma_tempo_a = 0;
    soma_tempo_b = 0; 

    for (i = 0; i < MAX_IT; i++){

      /* Gera duas copias do mesmo vetor */
      gera_vetor_aleatorio (va,tam);
      copia_vetor(va,vb,tam);

      /* Mede o tempo do MergeSort */
      iniA = timestamp();
      mergesort(va,0,tam-1);
      fimA = timestamp();
      soma_tempo_a += (fimA - iniA);

      /* Mede o tempo do MergeSort_B */
      iniB = timestamp();
      mergesort_a(vaux,vb,0,tam-1);
      fimB = timestamp();
      soma_tempo_b += (fimB - iniB);

    }

    printf("\ntamanho : %lld\n", tam);
    printf("vetor: aleatório\n");
    printf("tempo medio do mergesort normal:      %f\n", soma_tempo_a/MAX_IT);
    printf("tempo medio do mergesort alternado:   %f\n", soma_tempo_b/MAX_IT);

    soma_tempo_a = 0;
    soma_tempo_b = 0;
    
    for (i = 0; i < MAX_IT; i++){

      /* Gera duas copias do mesmo vetor */
      gera_vetor_ordenado (va,tam);
      copia_vetor(va,vb,tam);

      /* Mede o tempo do MergeSort */
      iniA = timestamp();
      mergesort(va,0,tam-1);
      fimA = timestamp();
      soma_tempo_a += (fimA - iniA);

      /* Mede o tempo do MergeSort_B */
      iniB = timestamp();
      mergesort_a(vaux,vb,0,tam-1);
      fimB = timestamp();
      soma_tempo_b += (fimB - iniB);

    }

    printf("\ntamanho : %lld\n", tam);
    printf("vetor: ordenado\n");
    printf("tempo medio do mergesort normal:      %f\n", soma_tempo_a/MAX_IT);
    printf("tempo medio do mergesort alternado:   %f\n", soma_tempo_b/MAX_IT);

    printf("---------------------------\n");


}
/*****************************************************************************************/
/*                          MergeSort Normal x MergeSort C                               */
/*****************************************************************************************/

printf("Comparando MergeSort e MergeSort_C (passagem por parametro)");
  
  for (tam = 10; tam < TAM_MAX_VET; tam *= 10){

    soma_tempo_a = 0;
    soma_tempo_b = 0; 

    for (i = 0; i < MAX_IT; i++){

      /* Gera duas copias do mesmo vetor */
      gera_vetor_aleatorio (va,tam);
      copia_vetor(va,vb,tam);

      /* Mede o tempo do MergeSort */
      iniA = timestamp();
      mergesort(va,0,tam-1);
      fimA = timestamp();
      soma_tempo_a += (fimA - iniA);

      /* Mede o tempo do MergeSort_c */
      iniB = timestamp();
      mergesort_c(vb, vaux, 0, tam-1);
      fimB = timestamp();
      soma_tempo_b += (fimB - iniB);

    }

    printf("\ntamanho : %lld\n", tam);
    printf("vetor: aleatório\n");
    printf("tempo medio do mergesort normal:   %f\n", soma_tempo_a/MAX_IT);
    printf("tempo medio do mergesort com va:   %f\n", soma_tempo_b/MAX_IT);

    soma_tempo_a = 0;
    soma_tempo_b = 0;
    
    for (i = 0; i < MAX_IT; i++){

      /* Gera duas copias do mesmo vetor */
      gera_vetor_ordenado (va,tam);
      copia_vetor(va,vb,tam);

      /* Mede o tempo do MergeSort */
      iniA = timestamp();
      mergesort(va,0,tam-1);
      fimA = timestamp();
      soma_tempo_a += (fimA - iniA);

      /* Mede o tempo do MergeSort_B */
      iniB = timestamp();
      mergesort_c(vb, vaux, 0, tam-1);
      fimB = timestamp();
      soma_tempo_b += (fimB - iniB);

    }

    printf("\ntamanho : %lld\n", tam);
    printf("vetor: ordenado\n");
    printf("tempo medio do mergesort normal:   %f\n", soma_tempo_a/MAX_IT);
    printf("tempo medio do mergesort com va:   %f\n", soma_tempo_b/MAX_IT);

    printf("---------------------------\n");


}

/*****************************************************************************************/
/*                          MergeSort Normal x MergeSort B                               */
/*****************************************************************************************/

printf("Comparando MergeSort e MergeSort_B");
  
  for (tam = 10; tam < TAM_MAX_VET; tam *= 10){

    soma_tempo_a = 0;
    soma_tempo_b = 0; 

    for (i = 0; i < MAX_IT; i++){

      /* Gera duas copias do mesmo vetor */
      gera_vetor_aleatorio (va,tam);
      copia_vetor(va,vb,tam);

      /* Mede o tempo do MergeSort */
      iniA = timestamp();
      mergesort(va,0,tam-1);
      fimA = timestamp();
      soma_tempo_a += (fimA - iniA);

      /* Mede o tempo do MergeSort_B */
      iniB = timestamp();
      mergesort_b(vb,0,tam-1);
      fimB = timestamp();
      soma_tempo_b += (fimB - iniB);

    }

    printf("\ntamanho : %lld\n", tam);
    printf("vetor: aleatório\n");
    printf("tempo medio do mergesort normal:   %f\n", soma_tempo_a/MAX_IT);
    printf("tempo medio do mergesort com if:   %f\n", soma_tempo_b/MAX_IT);

    soma_tempo_a = 0;
    soma_tempo_b = 0;
    
    for (i = 0; i < MAX_IT; i++){

      /* Gera duas copias do mesmo vetor */
      gera_vetor_ordenado (va,tam);
      copia_vetor(va,vb,tam);

      /* Mede o tempo do MergeSort */
      iniA = timestamp();
      mergesort(va,0,tam-1);
      fimA = timestamp();
      soma_tempo_a += (fimA - iniA);

      /* Mede o tempo do MergeSort_B */
      iniB = timestamp();
      mergesort_b(vb,0,tam-1);
      fimB = timestamp();
      soma_tempo_b += (fimB - iniB);

    }

    printf("\ntamanho : %lld\n", tam);
    printf("vetor: ordenado\n");
    printf("tempo medio do mergesort normal:   %f\n", soma_tempo_a/MAX_IT);
    printf("tempo medio do mergesort com if:   %f\n", soma_tempo_b/MAX_IT);

    printf("---------------------------\n");


}

/*****************************************************************************************/
/*                          QuickSortM3 x QuickSort+Insertion                              */
/*****************************************************************************************/
  
  printf("Comparando QuickSortM3 e QuickSortM3+Insertion");
  
  for (tam = 10; tam < TAM_MAX_VET; tam *= 10){

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
      quicksort_mediana3(vb,0,tam-1);
      fimB = timestamp();
      soma_tempo_b += (fimB - iniB);

    }

    printf("\ntamanho : %lld\n", tam);
    printf("vetor: aleatório\n");
    printf("tempo medio do quicksort normal:       %f\n", soma_tempo_a/MAX_IT);
    printf("tempo medio do quicksort mediana de 3: %f\n", soma_tempo_b/MAX_IT);

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
      quicksort_mediana3(vb,0,tam-1);
      fimB = timestamp();
      soma_tempo_b += (fimB - iniB);

    }

    printf("\ntamanho : %lld\n", tam);
    printf("vetor: ordenado\n");
    printf("tempo medio do quicksort normal:       %f\n", soma_tempo_a/MAX_IT);
    printf("tempo medio do quicksort mediana de 3: %f\n", soma_tempo_b/MAX_IT);

    printf("---------------------------\n");


}



/*****************************************************************************************/
/*                          QuickSort x QuickSort Mediana de 3                           */
/*****************************************************************************************/

  printf("Comparando o QuickSort Normal e o QuickSort Mediana de 3\n"); 

  for (tam = 10; tam < TAM_MAX_VET; tam *= 10){

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
        quicksort_mediana3(vb,0,tam-1);
        fimB = timestamp();
        soma_tempo_b += (fimB - iniB);

      }

      printf("\ntamanho : %lld\n", tam);
      printf("vetor: aleatório\n");
      printf("tempo medio do quicksort normal:       %f\n", soma_tempo_a/MAX_IT);
      printf("tempo medio do quicksort mediana de 3: %f\n", soma_tempo_b/MAX_IT);

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
        quicksort_mediana3(vb,0,tam-1);
        fimB = timestamp();
        soma_tempo_b += (fimB - iniB);

      }

      printf("\ntamanho : %lld\n", tam);
      printf("vetor: ordenado\n");
      printf("tempo medio do quicksort normal:       %f\n", soma_tempo_a/MAX_IT);
      printf("tempo medio do quicksort mediana de 3: %f\n", soma_tempo_b/MAX_IT);

      printf("---------------------------\n");


}
/*****************************************************************************************/
/*                                QuickSort x MergeSort                                  */
/*****************************************************************************************/

      printf("Comparando o QuickSort e o MergeSort\n");

      /* Comparando o QuickSort e o MergeSort com Entradas Aleatórias */
      
      for (tam = 10; tam < TAM_MAX_VET; tam *= 10){

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
/*****************************************************************************************/
/*                                QuickSort x InsertionSort                              */
/*****************************************************************************************/

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
      printf("tempo medio do quicksort: %f\n", soma_tempo_a/MAX_IT);
      printf("tempo medio do insertion: %f\n", soma_tempo_b/MAX_IT);

      printf("---------------------------\n");

    }
/*****************************************************************************************/
/*                              MergeSort x InsertionSort                                */
/*****************************************************************************************/

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

  free(va);
  free(vb);
  free(vaux);

  return 0;
}
