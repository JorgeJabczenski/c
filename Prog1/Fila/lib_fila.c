#include "lib_fila.h"


int inicializa_fila(t_fila *l){
    
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

int fila_vazia(t_fila *l){
    return ((l->tamanho) ? 0 : 1 );
}

int tamanho_fila(int *tam, t_fila *l){
    *tam = l->tamanho;
    return 1;
}

int insere_fila(t_item item, t_fila *l){

    t_nodo *new;
    new = (t_nodo *) malloc (sizeof(t_nodo));
    if (new == NULL)
        return 0;

    new->item.chave = item.chave;
    new->item.prioridade = item.prioridade;

    new->prox = l->fim;
    new->prev = l->fim->prev;
    l->fim->prev->prox = new;
    l->fim->prev = new;

    l->tamanho++;

    return 1;
}

int insere_prioridade_fila(t_item item, t_fila *l){

    if (fila_vazia(l))
        return insere_fila(item, l);
    
    t_nodo *new, *p;

    new = (t_nodo *) malloc (sizeof(t_nodo));
    if (new == NULL){
        return 0;
    }

    l->ini->item.prioridade = item.prioridade;

    p = l->fim->prev;
    while(p->item.prioridade > item.prioridade){
        p = p->prev;
    }

    new->item.chave = item.chave;
    new->item.prioridade = item.prioridade;
    
    new->prox = p->prox;
    new->prev = p;
    p->prox->prev = new;
    p->prox = new;

    l->tamanho++;

    return 1;
}

int inicializa_atual_inicio(t_fila *l){
    if (fila_vazia(l)){
        return 0;
    }

    l->atual = l->ini->prox;

    return 1;
}

int inicializa_atual_fim(t_fila *l){
    if (fila_vazia(l)){
        return 0;
    }

    l->atual = l->fim->prev;

    return 1;
}

int incrementa_atual(t_fila *l){
    if (fila_vazia(l) || l->atual == l->fim->prev){
        return 0;
    }

    l->atual = l->atual->prox;

    return 1;
}

int decrementa_atual(t_fila *l){
   
    if (fila_vazia(l) || l->atual == l->ini->prox){
        return 0;
    }

    l->atual = l->atual->prev;

    return 1;
}

int consulta_item_atual(int *item, t_fila *l){
    if (fila_vazia(l)){
        return 0;
    } 

    *item = l->atual->item.chave;

    return 1;
}

void imprime_fila(t_fila *l){
    
    int i, item, tamanho;

    tamanho_fila(&tamanho, l);
    
    if (fila_vazia(l))
        return;

    inicializa_atual_inicio(l);

    for(i = 0; i < tamanho; i++){
        consulta_item_atual(&item,l);
        printf("%d ", item);
        incrementa_atual(l);
    } 
    
    printf("\n");

}

int remove_fila(t_item *item, t_fila *l){
    
    if (fila_vazia(l)){
        return 0;
    }

    item->chave = l->ini->prox->item.chave;

    l->ini->prox = l->ini->prox->prox;
    free(l->ini->prox->prev);
    l->ini->prox->prev = l->ini;

    l->tamanho--;

    return 1;
}