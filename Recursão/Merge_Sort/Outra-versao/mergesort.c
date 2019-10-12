#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int ini, int meio, int fim){

    int i = ini;       /* começo do primeiro vetor */
    int j = meio+1;    /* começo do segundo vetor  */
    int idx = 0;       /* indice do vetor auxiliar */

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


void merge_sort(int *v, int ini, int fim){
    
    if (ini < fim){
        int meio = (ini + fim) / 2;
        merge_sort(v, ini, meio);
        merge_sort(v, meio+1, fim);
        merge(v, ini, meio, fim);
    }
}

int main(){

    int v[]={9,8,7,6,5,4,3};
    int t = sizeof(v)/sizeof(v[0]);

    merge_sort(v, 0, t-1);

    int i;
    for (i = 0; i < t; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}
