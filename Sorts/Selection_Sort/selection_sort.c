#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define  N        10
#define  MAX_RAND 50

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
    printf("Vetor ordenado:    ");
    imprimir_vetor(vetor, N);

    return 0;
}

void gerar_vetor(int v[], int t){
    for (int i = 0; i < t; i++){
        v[i] = (rand() % MAX_RAND) + 1;
    }
}

void organizar_vetor(int v[], int t){
	for (int i = 0; i < t-1; i++){
		int min = i;
		for (int j = i+1; j < t; j++){
			if (v[j] < v[min])
				min = j;
		}

		if (min != i){
			int aux = v[min];
			v[min] = v[i];
			v[i] = aux;
		}
	}

}

void imprimir_vetor(int v[], int t){
    for (int i = 0; i < t; i++)
        printf(" %d", v[i]);
    printf("\n");
}
