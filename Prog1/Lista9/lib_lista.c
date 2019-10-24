#include "lib_lista.h"

int inicializa_lista(t_lista *l){
    
    t_nodo *first, *last;
    
    first = (t_nodo *) malloc (sizeof(t_nodo));
    if (first == NULL)
        return 0;

    last = (t_nodo *) malloc (sizeof(t_nodo));
    if (last == NULL){
        free(first);
        return 0;
    }
    
    l->ini = first;
    first->prox = last;
    first->prev = NULL;

    l->fim = last;
    last->prox = NULL;
    last->prev = first;
    
    l->atual = NULL;
    
    l->tamanho = 0;

    return 1;
}

int lista_vazia(t_lista *l){
    return ((l->tamanho) ? 0 : 1 );
}

int insere_inicio_lista(int item, t_lista *l){

    t_nodo *new;
    new = (t_nodo *) malloc (sizeof(t_nodo));
    if (new == NULL)
        return 0;


    new->chave = item;
    new->prev = l->ini;
    new->prox = l->ini->prox;
    new->prox->prev = new;

    l->ini->prox = new;

    l->tamanho++;

    return 1;
}

int tamanho_lista(int *tam, t_lista *l){
    *tam = l->tamanho;
    return 1;
}

int insere_fim_lista(int item, t_lista *l){

    t_nodo *new;
    new = (t_nodo *) malloc (sizeof(t_nodo));
    if (new == NULL)
        return 0;

    new->chave = item;

    new->prox = l->fim;
    new->prev = l->fim->prev;
    l->fim->prev->prox = new;
    l->fim->prev = new;

    l->tamanho++;

    return 1;
}

int remove_inicio_lista(int *item, t_lista *l){
    
    if (lista_vazia(l))
        return 0;

    *item = l->ini->prox->chave;
    l->tamanho--;

    l->ini->prox = l->ini->prox->prox;
    
    


    return 1;
}