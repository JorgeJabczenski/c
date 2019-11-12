#include "lib_fila.h"


int inicializa_fila(t_fila *f){
    
    t_nodo *first, *last;
    
    first = (t_nodo *) malloc (sizeof(t_nodo));
    if (first == NULL)
        return 0;

    last = (t_nodo *) malloc (sizeof(t_nodo));
    if (last == NULL){
        free(first);
        return 0;
    }
    
    f->ini = first;
    first->prox = last;
    first->prev = NULL;

    f->fim = last;
    last->prox = NULL;
    last->prev = first;
    
    f->atual = NULL;
    
    f->tamanho = 0;

    return 1;
}

int fila_vazia(t_fila *f){
    return ((f->tamanho) ? 0 : 1 );
}

int tamanho_fila(t_fila *f){
    return ((f->tamanho) ? (f->tamanho) : -1);
}

int enfileira(int id, int t, t_fila *f){

    t_nodo *new;
    new = (t_nodo *) malloc (sizeof(t_nodo));
    if (new == NULL)
        return 0;

    new->identificacao = id;
    new->tempo = t;

    new->prox = f->fim;
    new->prev = f->fim->prev;
    f->fim->prev->prox = new;
    f->fim->prev = new;

    f->tamanho++;

    return 1;
}

int desenfileira(int id, t_fila *f){
    
    if (fila_vazia(f)){
        return 0;
    }

    id = f->ini->prox->identificacao;

    f->ini->prox = f->ini->prox->prox;
    free(f->ini->prox->prev);
    f->ini->prox->prev = f->ini;

    f->tamanho--;

    return 1;
}

int remove_fila(int id, t_fila *f){
    
    t_nodo *p;

    if (fila_vazia(f)){
        return 0;
    }

    f->fim->identificacao = id;

    p = f->ini;
    while(p->prox->identificacao != id){
        p = p->prox;
    }
    
    if (p == f->fim->prev){  /* Chegou na Sentinela sem ter achado o elemento */
        return 0;
    }

    p->prox = p->prox->prox;
    free(p->prox->prev);
    p->prox->prev = p;

    f->tamanho--;

    return 1;
}

void imprime_fila(t_fila *f, int versao){
    
    int i, item, tamanho, tempo;

    tamanho = tamanho_fila(f);
    
    if (fila_vazia(f))
        return;

    inicializa_atual_inicio(f);

    for(i = 0; i < tamanho; i++){
        consulta_id_atual(&item,f);
        consulta_tempo_atual(&tempo, f);
        if (versao) {
            printf("%d ", item);    
        } else {
            printf("%d(%d) ", item, tempo);
        }
        incrementa_atual(f);
    } 
}

/*=======================================================*/

int inicializa_atual_inicio(t_fila *f){
    if (fila_vazia(f)){
        return 0;
    }

    f->atual = f->ini->prox;

    return 1;
}

int inicializa_atual_fim(t_fila *f){
    if (fila_vazia(f)){
        return 0;
    }

    f->atual = f->fim->prev;

    return 1;
}

int incrementa_atual(t_fila *f){
    if (fila_vazia(f) || f->atual == f->fim->prev){
        return 0;
    }

    f->atual = f->atual->prox;

    return 1;
}

int decrementa_atual(t_fila *f){
   
    if (fila_vazia(f) || f->atual == f->ini->prox){
        return 0;
    }

    f->atual = f->atual->prev;

    return 1;
}

int consulta_id_atual(int *item, t_fila *f){
    if (fila_vazia(f)){
        return 0;
    } 

    *item = f->atual->identificacao;

    return 1;
}

int consulta_tempo_atual(int *item, t_fila *f){
    if (fila_vazia(f)){
        return 0;
    } 

    *item = f->atual->tempo;

    return 1;
}