#include <stdio.h>
#include "lib_fila.h"

int main(){

    t_item a,b,c,d, tirado;
    t_fila jorge;

    a.chave = 20;
    a.prioridade = 2;

    b.chave = 40;
    b.prioridade = 4;

    c.chave = 30;
    c.prioridade = 3;

    d.chave = 10;
    d.prioridade = 1;

    inicializa_fila(&jorge);


    insere_prioridade_fila(d, &jorge);
    imprime_fila(&jorge);
    insere_prioridade_fila(c, &jorge);
    imprime_fila(&jorge);
    insere_prioridade_fila(a, &jorge);
    imprime_fila(&jorge);
    insere_prioridade_fila(b, &jorge);
    imprime_fila(&jorge);

    remove_fila(&tirado, &jorge);
    printf("item retirado = %d \n", tirado.chave);
    remove_fila(&tirado, &jorge);
    printf("item retirado = %d \n", tirado.chave);
    remove_fila(&tirado, &jorge);
    printf("item retirado = %d \n", tirado.chave);
    remove_fila(&tirado, &jorge);
    printf("item retirado = %d \n", tirado.chave);


    

    return 0;

}