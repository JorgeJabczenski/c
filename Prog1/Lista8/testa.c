#include <stdio.h>
#include "lista.h"

#define MAX 5

int testa_insercao_inicio(t_lista *l) {
    int i;

    for (i=1; i<=MAX; i++)
        if (! insere_inicio_lista(2*i,l))
            return 0;
    return 1;
}

int testa_insercao_fim(t_lista *l) {
    int i;

    for (i=1; i<=MAX; i++)
        if (! insere_fim_lista(2*i-1,l))
            return 0;
    return 1;
}

int testa_insercao_ordenada(t_lista *l) {
    if (! insere_ordenado_lista(8,l))  return 0;
    if (! insere_ordenado_lista(10,l)) return 0;
    if (! insere_ordenado_lista(0,l))  return 0;
    if (! insere_ordenado_lista(9,l))  return 0;
    if (! insere_ordenado_lista(12,l)) return 0;
    if (! insere_ordenado_lista(2,l))  return 0;
    if (! insere_ordenado_lista(3,l))  return 0;
    return 1;
}

int cria_listas (t_lista *l, t_lista *m, t_lista *o, t_lista *c) {
    printf("Criando lista l\n");
    if (! cria_lista(l)) {
        printf("Erro: lista l nao foi criada.");
        return 0;
    }

    printf("Criando lista m\n");
    if (! cria_lista(m)) {
        printf("Erro: lista m nao foi criada.");
        return 0;
    }

    printf("Criando lista o\n");
    if (! cria_lista(o)) {
        printf("Erro: lista o nao foi criada.");
        return 0;
    }

    printf("Criando lista c\n");
    if (! cria_lista(c)) {
        printf("Erro: lista c nao foi criada.");
        return 0;
    }
    return 1;
}

int testa_insercoes(t_lista *l, t_lista *m, t_lista *o) {
    printf("Teste: inserir no inicio\n");
    if (! testa_insercao_inicio(l)) {
        printf("Insercao no inicio falhou...");
        return 0;
    }
    printf("l: ");
    imprime_lista(l);
    printf("Teste: inserir no fim\n");
    if (! testa_insercao_fim(m)) {
        printf("Insercao no fim falhou...");
        return 0;
    }
    printf("m: ");
    imprime_lista(m);

    printf("Teste: inserir ordenado\n");
    if (! testa_insercao_ordenada(o)) {
        printf("Insercao ordenada falhou...");
        return 0;
    }
    printf("o: ");
    imprime_lista(o);
    return 1;
}

int testa_copia(t_lista *o, t_lista *c) {

    printf("Teste: copia o em c\n");
    if (! copia_lista(o,c)) {
        printf("copia falhou...");
        return 0;
    }
    printf("c: ");
    imprime_lista(c);

    return 1;
}

int testa_concatencao(t_lista *l, t_lista *m) {
    printf("Concatenando m em l\n");
    if (! concatena_listas(l,m)) {
        printf("concatenacao falhou...");
        return 0;
    }
    printf("l: ");
    imprime_lista(l);
    printf("m:\n");
    imprime_lista(m);
    return 1;
}

int testa_remocoes(t_lista *l, t_lista *o, t_lista *c) {
    int item;

    printf("Teste: remocoes\n");
    printf("Remocao no inicio: remove todos de l\n");
    while (! lista_vazia(l))
        if (! remove_primeiro_lista(&item,l)) return 0;
    printf("l: ");
    imprime_lista(l);
    printf("\n");
    printf("Remocao no final: remove todos de o\n");
    /*while (! lista_vazia(o))*/
    while (o->tamanho)
        if (! remove_ultimo_lista(&item,o)) return 0;
    printf("o: ");
    imprime_lista(o);
    printf("\n");

    printf("Remocao em ordem: remove elementos selecionados de c\n");
    if (remove_item_lista(0,&item,c)) printf("removeu %d\n",0);
    if (remove_item_lista(8,&item,c)) printf("removeu %d\n",8);
    if (remove_item_lista(7,&item,c)) printf("removeu %d\n",7);
    if (remove_item_lista(12,&item,c)) printf("removeu %d\n",12);
    printf("c: ");
    imprime_lista(c);
    return 1;
}

void destroi_todas_listas(t_lista *l, t_lista *m, t_lista *o, t_lista *c) {
    printf("destroi l\n");
    destroi_lista(l);
    imprime_lista(l);
    printf("destroi m\n");
    destroi_lista(m);
    imprime_lista(m);
    printf("destroi o\n");
    destroi_lista(o);
    imprime_lista(o);
    printf("destroi c\n");
    destroi_lista(c);
    imprime_lista(c);
}

void testa_busca(t_lista *c) {
    if (pertence_lista(6,c))
        printf("%d encontrado.\n",6);
    else
        printf("%d nao encontrado.\n",6);
    if (pertence_lista(2,c))
        printf("%d encontrado.\n",2);
    else
        printf("%d nao encontrado.\n",2);
}

int main() {
    t_lista c, l, o, m; 

    if (! cria_listas(&l,&m,&o,&c))   return 1; 
    if (! testa_insercoes(&l,&m,&o))  return 1; 
    if (! testa_copia(&o,&c))         return 1; 
    if (! testa_concatencao(&l,&m))   return 1; 
    if (! testa_remocoes(&l, &o, &c)) return 1; 
    testa_busca(&c);
    destroi_todas_listas(&l, &m, &o, &c);

    return 0;
}