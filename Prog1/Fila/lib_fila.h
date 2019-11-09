#include <stdio.h>
#include <stdlib.h>

struct t_nodo {
    int identificacao;
    int tempo;
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

int inicializa_fila(t_fila *f);

int fila_vazia(t_fila *f);

int tamanho_fila(t_fila *f);

int enfileira(int id, int t, t_fila *f);

int desenfileira(int *id, int *t, t_fila *f);

int remove_fila(int id, t_fila *f);

void imprime_fila(t_fila *f);

/*=======================================================*/

int inicializa_atual_inicio(t_fila *f);

int inicializa_atual_fim(t_fila *f);

int incrementa_atual(t_fila *f);

int decrementa_atual(t_fila *f);

int consulta_id_atual(int *item, t_fila *f);

int consulta_tempo_atual(int *item, t_fila *f);