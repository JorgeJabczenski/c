#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib_ordena.h"

void copia_vetor(int voriginal[], int vcopia[], int tam){
    
    int i;

    for (i = 0; i < tam; i++)
        vcopia[i] = voriginal[i];
}

void imprime_vetor (int v[], int tam) {
    
    int i;

    for (i = 0; i < tam-1; i++)
        printf("%d ",v[i]);
    printf("%d\n",v[tam-1]);

}

void troca(int *a, int *b){

    int aux = *a;
    *a      = *b;
    *b      = aux;

}

void gera_vetor_ordenado (int v[], int tam) {
    
    int i;

    for (i = 0; i < tam; i++)
        v[i] = i;

}

void gera_vetor_aleatorio (int v[], int tam) {
  
    int i;

    srand(time(0));
    for (i = 0; i < tam; i++)
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


/* Implementação 'desotimizada' do merge */


/* Usa o primeiro elemento como pivo */

int particiona (int v[], int ini, int fim) {
    int indice = ini+1;
    int j;
    
    for (j = ini+1; j <= fim; j++){
           if (v[j] < v[ini]){
                troca(&v[j], &v[indice++]);
           }
    }

    troca(&v[ini],&v[indice-1]);
    return (indice-1);
}

/* Usa o último elemento como pivo */
/*
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
*/

void insertionsort (int v[], int ini, int fim) {
   
    int i;

    for (i = ini+1; i <= fim; i++)
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

int particiona_mediana3(int v[], int ini, int fim){

    int mediana = ini;
    int meio = (ini+fim)/2;

    if ((v[ini] < v[meio]) && (v[meio] < v[fim]))
        mediana = meio;
    if ((v[meio] < v[ini]) && (v[ini] < v[fim]))
        mediana = ini;
    if ((v[ini] < v[fim]) && (v[fim] < v[meio]))
        mediana = fim;

    troca(&v[mediana], &v[fim]);

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

void quicksort(int v[], int ini, int fim){

    if (ini < fim){
        int pivo = particiona(v, ini, fim);
        quicksort(v, ini, pivo - 1);
        quicksort(v, pivo + 1, fim);
    
    }
}

void quicksort_mediana3(int v[], int ini, int fim){

    if (ini < fim){
        int pivo = particiona_mediana3(v, ini, fim);
        quicksort_mediana3(v, ini, pivo - 1);
        quicksort_mediana3(v, pivo + 1, fim);
    
    }

}

void quicksort_mediana3_insertion(int v[], int ini, int fim){

    if (ini < fim){
        if ((fim-ini+1) <= 30){
            insertionsort(v, ini, fim);
        } else {
            int pivo = particiona_mediana3(v, ini, fim);
            quicksort_mediana3_insertion  (v, ini, pivo - 1);
            quicksort_mediana3_insertion  (v, pivo + 1, fim);
        }
    
    }       

}

void merge(int v[], int ini, int meio, int fim){

    int i = ini;       /* começo do primeiro vetor */
    int j = meio+1;    /* começo do segundo vetor  */
    int idx = 0;       /* indice do vetor auxiliar */;

    int *vetaux = malloc((fim-ini+1)*sizeof(int));

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
   
    free(vetaux);

}

void mergesort (int v[], int ini, int fim) {
    
    if(ini < fim){
        int meio = (ini+fim) / 2;
        mergesort(v, ini   , meio);
        mergesort(v, meio+1, fim );
        merge(v, ini, meio, fim);
    }
}

void merge_a(int *a, int *b, int ini, int meio, int fim){

	int i = ini;
	int j = meio + 1;
	int ind = ini;

    if (a[meio] >= a[meio+1]){

        while(i <= meio && j <= fim){
            if (a[i] < a[j])
                b[ind++] = a[i++];
            else 
                b[ind++] = a[j++];
        }

        while(i <= meio)
            b[ind++] = a[i++];

        while(j <= fim)
            b[ind++] = a[j++];

    }       
}

void mergesort_a(int *a, int *b, int ini, int fim){

	if (ini < fim){
		int meio = (ini + fim) / 2;
		mergesort_a(b, a, ini, meio);
		mergesort_a(b, a, meio+1, fim);
		merge_a(a, b, ini, meio, fim);
	}

}

void merge_b(int v[], int ini, int meio, int fim){

    int i = ini;       /* começo do primeiro vetor */
    int j = meio+1;    /* começo do segundo vetor  */
    int idx = 0;       /* indice do vetor auxiliar */
    
    int *vetaux = malloc((fim-ini+1)*sizeof(int));

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
   
    free(vetaux);

}

void mergesort_b (int v[], int ini, int fim) {
    
    if(ini < fim){
        int meio = (ini+fim) / 2;
        mergesort_b(v, ini   , meio);
        mergesort_b(v, meio+1, fim );
        merge_b(v, ini, meio, fim);
    }
}

void merge_c(int *v,int *vetaux,  int ini, int meio, int fim){

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

void mergesort_c (int v[], int va[], int ini, int fim) {
    
    if(ini < fim){
        int meio = (ini+fim) / 2;
        mergesort_c(v, va, ini   , meio);
        mergesort_c(v, va, meio+1, fim );
        merge_c(v, va, ini, meio, fim);
    }
}

