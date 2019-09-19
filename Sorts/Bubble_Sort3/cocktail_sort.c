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
    int top = t-1;
    int bot = 0;
    while (top >= bot){
        int ntrocou = 1;

        for (int j = bot; j < top; j ++){
            if (v[j] > v[j+1]) {
                int aux = v[j];
                v[j]    = v[j+1];
                v[j+1]  = aux;
                ntrocou = 0;
            }    
        }
        
        top--;

        for (int j = top; j > bot; j--){
            if (v[j] < v[j-1]){
                int aux = v[j];
                v[j]    = v[j-1];
                v[j-1]  = aux;
                ntrocou = 0;
            }
        }
        bot++;
    
        if (ntrocou) break;
    }
}

void imprimir_vetor(int v[], int t){
    for (int i = 0; i < t; i++)
        printf(" %d", v[i]);
    printf("\n");
}
