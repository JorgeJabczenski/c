#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void troca(int *a, int *b){

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

    int indice = ini+1;
    int j;
    
    for (j = ini+1; j <= fim; j++){
           if (v[j] < v[ini]){
                troca(&v[j], &v[indice++]);
           }
    }

    troca(&v[ini],&v[indice-1]);
    return (indice-1);
}

void quicksort(int v[], int ini, int fim){

    if (ini < fim){
        int pivo = partition(v, ini, fim);
        quicksort(v, ini, pivo - 1);
        quicksort(v, pivo +1, fim);
    
    }
}

int main(){

    long long int i;
    
    int vetor[MAX];
    for (i = 0; i < MAX; i++){
        vetor[i] = i;       
    }
    int tam = (sizeof(vetor) / sizeof(vetor[0]));

   

    quicksort(vetor, 0, tam-1);

    printArray(vetor, tam);
    
    return 0;

}
