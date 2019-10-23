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

    if (lista_vazia(l)){
        insere_inicio_lista(x, l);
        return 1;
    }
    
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

void imprime_lista(t_lista *l){
    if (l->tamanho == 0)
        return;

    t_nodo *p;
    p = l->ini;

    printf("tam: %d -> ",l->tamanho);
    while(p != NULL){
        printf("%d ",p->chave);
        p = p->prox;
    }
    printf("\n");
}

int remove_primeiro_lista(int *item, t_lista *l){
    
    if (lista_vazia(l)){
        return 0;
    }
    
    *item = l->ini->chave;

    free(l->ini);

    l->ini = l->ini->prox;

    l->tamanho--;

    return 1;

}

int remove_ultimo_lista(int *item, t_lista *l){

    if (lista_vazia(l)){
        return 0;
    }

    /* Se a lista tem apenas um elemento, retirar ele */
    if (l->tamanho == 1){
        *item = l->ini->chave;
        free(l->ini);
        l->tamanho--;
        return 1;
    }

    /* Caso geral */
    t_nodo *p;
    p = l->ini;

    while(p->prox->prox != NULL){
        p = p->prox;
    }

    *item = p->prox->chave;
    free(p->prox);
    p->prox = NULL;
    l->tamanho--;

    return 1;
}

int pertence_lista(int chave, t_lista *l){

    if (l->tamanho == 0)
        return 0;
    
    int i;
    t_nodo *p;

    p = l->ini;

    for (i = 0; i < l->tamanho; i++){
        if (p->chave == chave)
            return 1;
        p = p->prox;
    }

    return 0;
}

int concatena_listas(t_lista *l, t_lista *m){
    t_nodo *new;
    int i;

    /* Caso as duas listas sejam vazias */
    if ((l->ini == NULL) && (m->ini == NULL))
        return 0;
    
    new = (struct t_nodo *) malloc (sizeof (struct t_nodo));
    if (new == NULL)
        return 0;
    new = m->ini;

    for (i = 0; i < m->tamanho; i++){
        insere_fim_lista(new->chave, l);
        new = new->prox;
    }

    return 1;
}

int copia_lista(t_lista *l, t_lista *m){
    t_nodo *new;
    int i;

    /* Caso a lista l seja vaiza */
    if (l->ini == NULL)
        return 0;
    
    new = (struct t_nodo *) malloc (sizeof (struct t_nodo));
    if (new == NULL)
        return 0;
    new = l->ini;

    for (i = 0; i < l->tamanho; i++){
        insere_fim_lista(new->chave, m);
        new = new->prox;
    }

    return 1;
}