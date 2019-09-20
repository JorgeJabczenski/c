#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 10

int swap(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;

    return 0;
}

void gera_vetor(int v[], int t)
{
    int i;
    for (i = 0; i < t; i++)
       v[i] = rand() % 100;
}

void imprime_vetor(int v[], int t)
{
    int i;
    for (i = 0; i < t;i++)
        printf("%d ",v[i]);
    printf("\n");
}

int idx_menor_numero(int v[], int t)
{
    if (t == 1)
        return 0;
   
    int m = idx_menor_numero(v, t-1);

    return (v[m] < v[t-1]) ? m : t-1;
}

int selection_sort(int v[], int t)
{
   if (t == 1)
        return 0;
      
   int m = idx_menor_numero(v,t);
   swap(&v[m], &v[0]);
   return selection_sort(v+1, t-1);
}

int main(){

    srand(time(NULL));
    int vetor[MAX];
    
    gera_vetor(vetor, MAX);
    imprime_vetor(vetor, MAX);
    selection_sort(vetor, MAX);
    imprime_vetor(vetor, MAX);
    return 0;
}
