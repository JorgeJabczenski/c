#include <stdio.h>
#include <stdlib.h>

struct t_item {
    int chave;
    int prioridade;
}; 
typedef struct t_item t_item;

struct t_nodo {
    t_item item;
    struct t_nodo *prox;
    struct t_nodo *prev;
};
typedef struct t_nodo t_nodo;

struct t_fila {
    t_nodo *ini;
    t_nodo *atual;
    t_nodo *fim;
    int tamanho;
};
typedef struct t_fila t_fila;

int inicializa_fila(t_fila *l);

int fila_vazia(t_fila *l);

int tamanho_fila(int *tam, t_fila *l);

int insere_fila(t_item item, t_fila *l);

int insere_prioridade_fila(t_item item, t_fila *l);

int inicializa_atual_inicio(t_fila *l);

int inicializa_atual_fim(t_fila *l);

int incrementa_atual(t_fila *l);

int decrementa_atual(t_fila *l);

int consulta_item_atual(int *item, t_fila *l);

void imprime_fila(t_fila *l);

int remove_fila(t_item *item, t_fila *l);