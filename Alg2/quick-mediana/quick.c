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

    int mediana = 0;
    int meio = (ini+fim)/2;

    if ((v[ini] <= v[meio]) && (v[meio] <= v[fim]))
        mediana = meio;
    if ((v[meio] <= v[ini]) && (v[ini] <= v[fim]))
        mediana = ini;
    if ((v[ini] <= v[fim]) && (v[fim] <= v[meio]))
        mediana = fim;

        printf("A media ah %d\n",mediana);

    troca(&v[mediana], &v[fim]);

    int indice = ini-1;
    int j;
    
    for (j = ini; j < fim; j++){
           if (v[j] < v[fim]){
                troca(&v[j], &v[indice+1]);
                indice++;
           }
    }

    troca(&v[fim],&v[indice+1]);
    return (indice + 1);

}

void quicksort(int v[], int ini, int fim){

    if (ini < fim){
        int pivo = partition(v, ini, fim);
        quicksort(v, ini, pivo - 1);
        quicksort(v, pivo +1, fim);
    
    }
}

int main(){
/*
    long long int i;
    
    int vetor[MAX];
    for (i = 0; i < MAX; i++){
        vetor[i] = i;       
    }
*/
    int vetor[] = {4,3,6,23,4,6,3,56,6,4,3,5,6,4,32,1,6};
    int tam = (sizeof(vetor) / sizeof(vetor[0]));

   

    quicksort(vetor, 0, tam-1);

    printArray(vetor, tam);
    
    return 0;

}
