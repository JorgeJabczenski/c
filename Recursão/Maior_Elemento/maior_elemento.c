#include <stdio.h>
#include <time.h>
#define MAX 10

void gerar_vetor(int v[], int t){
    for (int i = 0; i < t; i++)
        v[i] = rand() % 200;
}

int acha_maior(int v[], int t){

    if (t == 1)
        return v[0];

    if (v[t-1] > v[t-2]){
        int aux = v[t-1];
        v[t-1]  = v[t-2];
        v[t-2]  = aux;
    }

    return acha_maior(v,t-1);
}

int main(){
    srand(time(NULL));
    int tam = MAX;
    int vetor[MAX];
    
    gerar_vetor(vetor, tam);
    
    printf("O vetor gerado foi : ");
    for (int i = 0; i < tam; i++) printf("%d ", vetor[i]);
    printf("\n");

    int maior = acha_maior(vetor,tam);

    printf("o maior numero do vetor é %d\n", maior);

}
