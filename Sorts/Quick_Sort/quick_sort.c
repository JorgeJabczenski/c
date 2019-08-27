#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  N        10
#define  MAX_RAND 50

void quick_sort(int v[], int inicio, int fim);
void gerar_vetor(int v[], int t);
void organizar_vetor(int v[], int t);
void imprimir_vetor(int v[], int t);


int main(){

    int vetor[N];

    // Gera uma semente aleatória
    srand(time(NULL));

    // Gerar vetor de aleatórios
    gerar_vetor(vetor, N);
    printf("Vetor desordenado: ");
    imprimir_vetor(vetor, N);

    // Organizar com Bubble Sort
    organizar_vetor(vetor, N);
    printf("Vetor ordenado: ");
    imprimir_vetor(vetor, N);

    return 0;
}

void gerar_vetor(int v[], int t){
    for (int i = 0; i < t; i++){
        v[i] = (rand() % MAX_RAND) + 1;
    }
}

void organizar_vetor(int v[], int t){
    quick_sort(v,0,t);
}

void imprimir_vetor(int v[], int t){
    for (int i = 0; i < t; i++)
        printf(" %d", v[i]);
    printf("\n");
}

void quick_sort(int v[], int inicio, int fim){
  
    int pivo = v[(inicio+fim) / 2];
    int i = inicio;
    int j = fim;

  do{
        while(v[i] < pivo) i++;
        while(v[j] > pivo) j--;

        if (i <= j){
            int aux = v[i];
            v[i] = v[j];
            v[j] = aux;

            i++;
            j--;
        }
    } while(j > i);

    if (inicio < j) quick_sort(v,inicio,j);
    if (i < fim)    quick_sort(v,i,fim);

}