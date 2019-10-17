#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

int cria_lista(t_lista *l){
    l->ini = NULL;
    l->tamanho = 0;
    return 1;
}

int lista_vazia(t_lista *l){
    if (l->tamanho)
        return 0;
    return 1;
}

void destroi_lista(t_lista *l){
    
}

int insere_inicio_lista(int x, t_lista *l){
    t_nodo *p;
    p = malloc(sizeof(struct t_nodo));
    if (p == NULL) 
        return 0;
    p->chave = x;
    p->prox = l->ini;
    l->ini = p;
    l->tamanho++;

    return 1;
}

int insere_fim_lista(int x, t_lista *l){

    t_nodo *p, *q;
    q = malloc(sizeof(struct t_nodo));
    if (q == NULL)
        return 0;

    p = l->ini;
    if (p != NULL)
        while(p->prox != NULL)
            p = p->prox;
    p->prox = q;
    q->prox = NULL;
    q->chave = x;
    l->tamanho++;
    
    return 1;
}