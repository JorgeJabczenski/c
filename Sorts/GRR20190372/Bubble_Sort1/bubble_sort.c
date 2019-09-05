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
        for (int j = 0; j < (t-i) - 1; j++){
            if (v[j] > v[j+1]){
                int aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
}

void imprimir_vetor(int v[], int t){
    for (int i = 0; i < t; i++)
        printf(" %d", v[i]);
    printf("\n");
}
