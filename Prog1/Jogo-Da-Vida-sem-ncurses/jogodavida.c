#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

#include "jdv.h"

#define SLEEP_TIME 100000 /* tempo de delay entre os 'frames' */


int main(int argc, char **argv ){

    /* Confere o número de parâmetros */
    if (argc != 3) {
        printf("Número de parametros incorreto, o programa deve possuir 2 parâmetros \n");
        return 1;
    }

    /* Declaração de Variáveis */
    geracao antiga, nova;
    int numeroDeGeracoes;
    int i;
    
    /* Define as dimensões das matrizes */
    antiga.lin  = atoi(argv[1]);
    antiga.col  = atoi(argv[2]);
    nova.lin    = atoi(argv[1]);
    nova.col    = atoi(argv[2]);


    printf("Quantas Gerações você quer imprimir?\n");
    scanf("%d", &numeroDeGeracoes);

    /* alocando as matrizes das duas gerações */
    antiga.matriz = aloca_matrizes(antiga.lin, antiga.col);
    nova.matriz   = aloca_matrizes(nova.lin  , nova.col);

    ler_geracao_inicial(&antiga); /* Le e coloca as posições da geraçao 1 */
    imprime_geracao(antiga);      /* Imprime a matriz inicial */

    for (i = 0; i < numeroDeGeracoes; i++){
        calcular_nova_geracao(&antiga, &nova); /* calcula a geração 'nova' com base na 'antiga'*/
        copia_geracao(&nova, &antiga);         /* copia a geração 'nova' calculada para a geracao 'antiga' */
        imprime_geracao(nova);                 /* imprime a matriz gerada */
        usleep(SLEEP_TIME);                    /* espera o tempo de delay em micro segundos */
    }

	return 0;
}
