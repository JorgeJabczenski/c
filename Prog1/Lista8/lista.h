
typedef struct t_item t_item;

struct t_nodo {
    int chave;
    struct t_nodo *prox;
};
typedef struct t_nodo t_nodo;

struct t_lista {
    t_nodo *ini;
    int tamanho;
};
typedef struct t_lista t_lista;

int cria_lista(t_lista *l);                              /* done */
int lista_vazia(t_lista *l);                             /* done */
void destroi_lista(t_lista *l);                          /* done */
int insere_inicio_lista(int x, t_lista *l);              /* done */
int insere_fim_lista(int x, t_lista *l);                 /* done */
int insere_ordenado_lista(int x, t_lista *l);            /* done */
void imprime_lista(t_lista *l);                          /* done */
int remove_primeiro_lista(int *item, t_lista *l);        /* done */
int remove_ultimo_lista(int *item, t_lista *l);          /* done */
int remove_item_lista(int chave, int *item, t_lista *l); /*  */
int pertence_lista(int chave, t_lista *l);               /* done */
int concatena_listas(t_lista *l, t_lista *m);            /* done */
int copia_lista(t_lista *l, t_lista *m);                 /* done */
