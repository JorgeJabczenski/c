#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b){

    printf("Trocando %d com %d \n", *a, *b);
    int aux = *a;
    *a      = *b;
    *b      = aux;

}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 


int partition(int v[], int ini, int fim){

    int indice = ini-1;
    int j;
    
    for (j = ini; j < fim; j++){
           if (v[j] < v[fim]){
                printf("%d é menor que %d\n indice : %d  \n", v[j], v[fim], indice+1);
                troca(&v[j], &v[indice+1]);
                printArray(v, fim-ini+1);
                indice++;
           }
    }

    troca(&v[fim],&v[indice+1]);
    printArray(v, fim-ini+1);
    printf("Retornando %d \n", indice+1);
    return (indice + 1);
}

void quicksort(int v[], int ini, int fim){

    printf("\n chamando novo quicksort para %d %d\n\n", ini, fim);
    if (ini < fim){
        int pivo = partition(v, ini, fim);
        quicksort(v, ini, pivo - 1);
        quicksort(v, pivo +1, fim);
    
    }
}

int main(){

    int vetor[] = {4,3,6,1,2,8,7,5};
    int tam = (sizeof(vetor) / sizeof(vetor[0]));

    printArray(vetor, tam);

    quicksort(vetor, 0, tam-1);

    printArray(vetor, tam);
    
    return 0;

}
