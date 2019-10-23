#include <stdio.h>
#include <stdlib.h>

#include "lista.h"


int main(){

    int item;
    t_lista lista1, lista2, lista3;
    
    cria_lista(&lista1);
    cria_lista(&lista2);
    cria_lista(&lista3);
    
    /*if (lista_vazia(&lista)) 
        printf("Lista Vazia \n");
    else 
        printf("Tem coisa ai\n");
    
    int i;
    for (i = 0; i < 10; i++)
        insere_fim_lista(i,&lista);
    for (i = 0; i < 5; i++)
        insere_inicio_lista(i,&lista);

    imprime_lista(&lista);

    if (pertence_lista(9, &lista))
        printf("TEM\n");
    else
        printf("NAO TEM\n");

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
*/

    insere_inicio_lista(10, &lista1);
    insere_inicio_lista(20, &lista1);
    insere_inicio_lista(30, &lista1);
    insere_inicio_lista(2, &lista2);
    insere_inicio_lista(1, &lista2);
    insere_inicio_lista(0, &lista2);

    concatena_listas(&lista1, &lista2);
    imprime_lista(&lista1);
    remove_ultimo_lista(&item, &lista1);
    printf("item tirado: %d\n", item);
    remove_primeiro_lista(&item, &lista1);
    printf("item tirado: %d\n", item);
    copia_lista(&lista1, &lista3);
    imprime_lista(&lista1);
    imprime_lista(&lista3);

    return 0;
}