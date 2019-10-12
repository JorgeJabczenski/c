#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include "lib_ordena.h"

#define MAX_IT 1000 /* isto pode ser ajustado */

/* Retorna tempo em milisegundos */
double timestamp(void)
{
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return((double)(tp.tv_sec*1000.0 + tp.tv_usec/1000.0));
}

int main () {
    int v[MAX]; 
    int i, tam;
    double ini, fim, soma_tempo;

    /* testes com vetores gerados randomicamente */

    /* defina tam como voce achar melhor */
    tam = 1000;
    gera_vetor_aleatorio (v,tam);

    soma_tempo = 0;
    for (i=0; i<MAX_IT; i++) {
        ini = timestamp();
        quicksort (v,0,tam-1);  /* mede tempo so do quicksort */
        fim = timestamp();
        soma_tempo += (fim-ini);
        embaralha_vetor (v,tam);    /* nao conta o tempo de embaralhar */
    }
    printf("tamanho : %d\n", tam);
    printf("tempo medio do quicksort: %f\n", soma_tempo/MAX_IT);

    return 0;
}
