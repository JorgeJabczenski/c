#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  N        10
#define  MAX_RAND 50

void gerar_vetor(int v[], int t);
void organizar_vetor(int v[], int t);
void imprimir_vetor(int v[], int t);


int main(){

    int tam;

    scanf("%d", &tam);
    int vetor[tam];

    // Gera uma semente aleatória
    srand(time(NULL));

    // Gerar vetor de aleatórios
//    gerar_vetor(vetor, N);


    for (int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }

    //printf("Vetor desordenado: ");
    //imprimir_vetor(vetor, tam);

    // Organizar com Bubble Sort
    organizar_vetor(vetor, tam);
    //printf("Vetor ordenado: ");
    //imprimir_vetor(vetor, tam);

    return 0;
}

void gerar_vetor(int v[], int t){
    for (int i = 0; i < t; i++){
        v[i] = (rand() % MAX_RAND) + 1;
    }
}

void organizar_vetor(int v[], int t){
    for (int i = 1; i < t; i++)
    {
        int key = v[i];
        int j = i-1;
        while(key < v[j] && j >= 0)
        {
            v[j+1] = v[j];
            j--;
            
        }
        v[j+1] = key;
        //imprimir_vetor(v,t);
    }
}

void imprimir_vetor(int v[], int t){
    for (int i = 0; i < t; i++)
        printf(" %d", v[i]);
    printf("\n");
}
