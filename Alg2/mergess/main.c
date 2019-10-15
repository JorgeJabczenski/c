#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "lib_ordena.h"

void merg(int *v,int *vetaux,  int ini, int meio, int fim){

    int i = ini;       /* começo do primeiro vetor */
    int j = meio+1;    /* começo do segundo vetor  */
    int idx = 0;       /* indice do vetor auxiliar */

    if (v[meio] > v[meio+1]){

        while((i <= meio) && (j <= fim)){
        
            if (v[i] < v[j]){
                vetaux[idx++] = v[i++];
            } else {
                vetaux[idx++] = v[j++];
            }
        }

        while(i <= meio){
            vetaux[idx++] = v[i++];
        }

        while(j <= fim){
            vetaux[idx++] = v[j++];
        }

        for (i = 0; i < (fim-ini)+1; i++)
            v[ini+i] = vetaux[i];
    }
}

void mergesor (int v[], int va[], int ini, int fim) {
    
    if(ini < fim){
        int meio = (ini+fim) / 2;
        mergesor(v, va, ini   , meio);
        mergesor(v, va, meio+1, fim );
        merg(v, va, ini, meio, fim);
    }
}


int main(){
    
    int *va, *vb, *vaux;
    va   = (int *) malloc (MAX*sizeof(int));
    vaux = (int *) malloc (MAX*sizeof(int));
    
    int tam = 10;
    gera_vetor_aleatorio (va,tam);
    imprime_vetor(va, tam);
    mergesor(va, vaux, 0, tam-1);
    imprime_vetor(va,tam);


    return 0;
}