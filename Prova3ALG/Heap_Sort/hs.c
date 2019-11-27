#include <stdio.h>


int dir(int i){
    return 2*i+2;
}

int esq(int i){
    return 2*i+1;
}

int pai(int i){
    return i/2;
}

void swap(int *a, int *b){

    int aux = *a;
    *a = *b;
    *b = aux;
}

void max_heapify(int v[], int tam, int indice){

    int maior = indice;

    if(v[esq(indice)] > v[maior] && esq(indice) < tam)
        maior = esq(indice);
    if(v[dir(indice)] > v[maior] && dir(indice) < tam)
        maior = dir(indice);

    if (maior != indice){
        swap(&v[indice], &v[maior]);
        max_heapify(v, tam, maior);
    }
}


void build_max_heap(int v[], int tam){

    for (int i = tam/2; i >= 0; i--){
        max_heapify(v, tam, i);    
    }
}

void heap_sort(int v[], int tam){

    int i;

    build_max_heap(v,tam);
    for(i = tam-1;i >= 0; i--){
        swap(&v[0],&v[i]);
        tam--;
        max_heapify(v, i,0);
    }

}



int main(){

    int v[] = {5,1,8,5,9,4,12,6,78,13};
    int tam = sizeof(v) / sizeof(v[0]);


    for (int i = 0; i < tam; i++)
        printf("%d ", v[i]);
    printf("\n");
   
   heap_sort(v,tam);

    for (int i = 0; i < tam; i++)
        printf("%d ", v[i]);
    printf("\n");


}
