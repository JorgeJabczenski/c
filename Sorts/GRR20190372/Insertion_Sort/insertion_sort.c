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
    }
}

void imprimir_vetor(int v[], int t){
    for (int i = 0; i < t; i++)
        printf(" %d", v[i]);
    printf("\n");
}