#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib_ordena.h"

void imprime_vetor (int v[], int tam) {
    int i;

    for (i=0; i<tam-1; i++)
        printf("%d ",v[i]);
    printf("%d\n",v[tam-1]);
}

void troca(int *a, int *b){

    int aux = *a;
    *a      = *b;
    *b      = aux;

}

void gera_vetor_em_ordem (int v[], int tam) {
    int i;

    for (i=0; i<tam; i++)
        v[i] = i;
}

void gera_vetor_randomico (int v[], int tam) {
    int i;

    srand(time(0));
    for (i=0; i<tam; i++)
        v[i] = (unsigned int) (rand() % (tam*3)); /* pode modificar se quiser */
}

void embaralha_vetor (int v[], int tam) {
    int k, i, j, max_trocas;

    max_trocas = (unsigned int) (rand() % tam) + tam; /* pode modificar */
    for (k=0; k<max_trocas; k++) {
        i = (unsigned int) (rand() % tam);
        j = (unsigned int) (rand() % tam);
        troca (&v[i],&v[j]);
    }
}

void merge(int v[], int ini, int meio, int fim){

    int vtemp[MAX];
    int p1 = ini, p2 = meio+1, f1 = 1, f2 = 1, tam = fim-ini+1;
    int i, j;
    for(i = 0; i < tam; i++){
        if (f1 && f2){
            if (v[p1] < v[p2])
                vtemp[i] = v[p1++];
            else
                vtemp[i] = v[p2++];

            if (p1 > meio) f1 = 0;
            if (p2 >  fim) f2 = 0; 
        } else {
            if (f1)
                vtemp[i] = v[p1++];
             else
                vtemp[i] = v[p2++];
        }
    }

    for (i = 0, j = ini; i < tam; i++,j++){
        v[j] = vtemp[i];
    }


}

int particiona (int v[], int ini, int fim) {

    int indice = ini-1;
    int j;
    
    for (j = ini; j < fim; j++){
           if (v[j] < v[fim]){
                troca(&v[j], &v[indice+1]);
                indice++;
           }
    }

    troca(&v[fim],&v[indice+1]);
    return (indice + 1);

}

void inserctionsort (int v[], int ini, int fim) {
    
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

void quicksort(int v[], int ini, int fim){

    if (ini < fim){
        int pivo = particiona(v, ini, fim);
        quicksort(v, ini, pivo - 1);
        quicksort(v, pivo +1, fim);
    
    }
}


void mergesort (int v[], int ini, int fim) {
    
    if(ini < fim){
        int meio = (ini+fim) / 2;
        mergesort(v, ini   , meio);
        mergesort(v, meio+1, fim );
        merge(v, ini, meio, fim);
    }
}

