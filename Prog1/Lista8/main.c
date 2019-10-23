#include <stdio.h>
#include <stdlib.h>

#include "lista.h"


int main(){

    int item;
    t_lista lista;
    
    cria_lista(&lista);
    
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

    insere_inicio_lista(10, &lista);
    insere_inicio_lista(20, &lista);
    imprime_lista(&lista);
    remove_ultimo_lista(&item, &lista);
    printf("item tirado: %d\n", item);
    remove_primeiro_lista(&item, &lista);
    printf("item tirado: %d\n", item);

    return 0;
}