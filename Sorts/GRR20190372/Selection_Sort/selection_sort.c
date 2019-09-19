#include <stdio.h>

void organizar_vetor(int v[], int t);
void imprimir_vetor(int v[], int t);

int main(){

    int tam;

    scanf("%d", &tam);
    int vetor[tam];

    for (int i = 0; i < tam; i++){
        scanf("%d", &vetor[i]);
    }

    organizar_vetor(vetor, tam);

    return 0;
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