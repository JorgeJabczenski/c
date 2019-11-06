#include <stdio.h>

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int esquerda(int n){
    return 2*n+1;
}

int direita(int n){
    return 2*n+2;
}

void max_heapify(int v[], int indice, int t){
    int maior = indice;
    int esq = esquerda(indice);
    int dir = direita (indice);


    if (esq < t && v[esq] > v[maior])
        maior = esq;

    if (dir < t && v[dir] > v[maior])
        maior = dir;

    if (maior != indice){
        troca(&v[indice], &v[maior]);
        max_heapify(v,maior, t);
    }
}

void heapsort(int v[], int tam){
    int i;

    for (i = tam/2; i >= 0; i--)
        max_heapify(v, i, tam);
    
    for (i = tam-1; i >= 0; i--){
        troca(&v[0], &v[i]);
        max_heapify(v, 0, i);
    }

}

int main(){
    int heap[] = {5,3,8,6,4,8,9,6};
    int tam = 8;
    int i;

    for(i = 0; i < tam-1; i++){
        printf("%d ", heap[i]);
    }
    printf("%d\n", heap[tam-1]);
    
    heapsort(heap, tam);
    for(i = 0; i < tam-1; i++){
        printf("%d ", heap[i]);
    }
    printf("%d\n", heap[tam-1]);


    return 0;
}
