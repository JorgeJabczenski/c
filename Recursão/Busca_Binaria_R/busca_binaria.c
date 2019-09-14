#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 10

void gerar_vetor(int v[], int t){
    for (int i = 0; i < t; i++)
        v[i] = rand() % 200;
}

void selection_sort(int v[], int t){

    

}

int busca_binaria_R(int v[], int x, int ini, int fim){

    if (ini > fim)
        return -1;

    if (x == v[(ini+fim)/2])
        return (ini+fim)/2;

    if (x < v[(ini+fim)/2]){
       return busca_binaria_R(v,x,ini,((ini+fim)/2)-1);
    } else {
       return busca_binaria_R(v,x,((ini+fim)/2)+1,fim);
    }
}

int main(){
    srand(time(NULL));
    int tam = MAX,x;
    int vetor[MAX]; 
    
   gerar_vetor(vetor, tam);
    
    printf("O vetor gerado foi : ");
    for (int i = 0; i < tam; i++) printf("%d ", vetor[i]);
    printf("\n");
    
    scanf("%d", &x);
    int achou = busca_binaria_R(vetor,x,0,MAX-1); 
    if (achou == -1){
        printf("Número não encontrado\n");
    } else {
        printf("O número está na posição %d\n", achou);
    }
return 0;
}
