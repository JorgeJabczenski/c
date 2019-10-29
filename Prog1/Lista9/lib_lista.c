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

int tamanho_lista(int *tam, t_lista *l){
    *tam = l->tamanho;
    return 1;
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

int insere_ordenado_lista(int item, t_lista *l){

    t_nodo *new, *p;

    new = (t_nodo *) malloc (sizeof(t_nodo));
    if (new == NULL){
        return 0;
    }

    l->fim->chave = item; /* Bota a Sentinela do Fim */

    p = l->ini->prox;
    while(p->chave > item){
        p = p->prox;
    }

    new->chave = item;
    new->prox = p->prev->prox;
    p->prev->prox = new;
    new->prox->prev = new;

    l->tamanho++;

    return 1;
}

int remove_inicio_lista(int *item, t_lista *l){
    
    if (lista_vazia(l)){
        return 0;
    }

    *item = l->ini->prox->chave;

    l->ini->prox = l->ini->prox->prox;
    free(l->ini->prox->prev);
    l->ini->prox->prev = l->ini;

    l->tamanho--;

    return 1;
}

int remove_fim_lista(int *item, t_lista *l){

    if (lista_vazia(l)){
        return 0;
    }

    *item = l->fim->prev->chave; /* Atribui o valor ao item */

    l->fim->prev = l->fim->prev->prev;
    free(l->fim->prev->prox);
    l->fim->prev->prox = l->fim;

    l->tamanho--;

    return 1;
}

int remove_item_lista(int chave, int *item, t_lista *l){

    t_nodo *p;

    if (lista_vazia(l)){
        return 0;
    }

    l->fim->chave = chave;

    p = l->ini;
    while(p->prox->chave != chave){
        p = p->prox;
    }
    
    if(p == l->fim->prev){  /* Chegou na Sentinela sem ter achado o elemento */
        return 0;
    }

    p->prox = p->prox->prox;
    free(p->prox->prev);
    p->prox->prev = p;
    *item = chave;

    l->tamanho--;

    return 1;
}

int pertence_lista(int chave, t_lista *l){

    t_nodo *p;

    p = l->ini;
    
    l->fim->chave = chave;
    
    while(p->prox->chave != chave){
        p = p->prox;
    }
    
    return (p->prox == l->fim) ? 0 : 1;

}

int inicializa_atual_inicio(t_lista *l){
    if (lista_vazia(l)){
        return 0;
    }

    l->atual = l->ini->prox;

    return 1;
}

int inicializa_atual_fim(t_lista *l){
    if (lista_vazia(l)){
        return 0;
    }

    l->atual = l->fim->prev;

    return 1;
}

int incrementa_atual(t_lista *l){
    if (lista_vazia(l) || l->atual == l->fim->prev){
        return 0;
    }

    l->atual = l->atual->prox;

    return 1;
}

int decrementa_atual(t_lista *l){
   
    if (lista_vazia(l) || l->atual == l->ini->prox){
        return 0;
    }

    l->atual = l->atual->prev;

    return 1;
}

int consulta_item_atual(int *item, t_lista *l){
    if (lista_vazia(l)){
        return 0;
    } 

    *item = l->atual->chave;

    return 1;
}

int remove_item_atual(int *item, t_lista *l){
    
    if (lista_vazia(l)){
        return 0;
    } 

    t_nodo *p;

    p = l->atual;

    *item = l->atual->chave;

    l->atual->prev->prox = l->atual->prox;
    l->atual->prox->prev = l->atual->prev;


    if (l->atual->prox == l->fim){
        l->atual = l->atual->prev;
    } else {
        l->atual = l->atual->prox;
    }

    free(p);
    l->tamanho--;
    return 1;
}

void destroi_lista(t_lista *l){

    int lixo, i, tam;

    tam = l->tamanho;

    for (i = 0; i < tam; i++)
        remove_inicio_lista(&lixo, l);


    free(l->ini);
    free(l->fim);

}
