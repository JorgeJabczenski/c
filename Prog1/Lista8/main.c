#include <stdio.h>
#include <stdlib.h>

#include "lista.h"


int main(){

    t_lista lista;
    
    cria_lista(&lista);
    if (lista_vazia(&lista)) 
        printf("Lista Vazia \n");
    else 
        printf("Tem coisa ai\n");
    
    int i;
    for (i = 0; i < 10; i++)
        insere_fim_lista(i,&lista);
    for (i = 0; i < 5; i++)
        insere_inicio_lista(i,&lista);

    imprime_lista(&lista);

    int item;
    remove_ultimo_lista(&item, &lista);
    printf("item tirado: %d\n", item);
    imprime_lista(&lista);
    remove_primeiro_lista(&item, &lista);
    printf("item tirado: %d\n", item);
    imprime_lista(&lista);


    if (lista_vazia(&lista)) 
        printf("Lista Vazia \n");
    else 
        printf("Tem coisa ai\n");


    return 0;
}