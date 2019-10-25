#include <stdio.h>
#include <stdlib.h>

#include "lib_lista.h"
/*#include "lib_lista_complementar.h"*/

int main(){

    t_lista lista;
    int tamanho, item;

    inicializa_lista(&lista);
    
    (lista_vazia(&lista)) ? printf("v a z i a\n") : printf("tem coisa\n");
    insere_fim_lista(10, &lista);
    insere_fim_lista(20, &lista);
    insere_fim_lista(30, &lista);
    (lista_vazia(&lista)) ? printf("v a z i a\n") : printf("tem coisa\n");
    tamanho_lista(&tamanho, &lista);
    printf("Tamanho :  %d\n", tamanho);
    printf("\n");

    if (!remove_inicio_lista(&item, &lista)) printf("Lista Vazia!\n");
    printf("Item removido : %d\n", item);
    tamanho_lista(&tamanho, &lista);
    printf("Tamanho :  %d\n", tamanho);

    if (!remove_inicio_lista(&item, &lista)) printf("Lista Vazia!\n");
    printf("Item removido : %d\n", item);
    tamanho_lista(&tamanho, &lista);
    printf("Tamanho :  %d\n", tamanho);    
    
    if (!remove_inicio_lista(&item, &lista)) printf("Lista Vazia!\n");
    printf("Item removido : %d\n", item);
    tamanho_lista(&tamanho, &lista);
    printf("Tamanho :  %d\n", tamanho);

    insere_ordenado_lista(10, &lista);
    tamanho_lista(&tamanho, &lista);
    printf("Tamanho :  %d\n", tamanho);

    if(!remove_item_lista(10,&item,&lista)) printf("Chave não encontrada\n");
    tamanho_lista(&tamanho, &lista);
    printf("Tamanho :  %d\n", tamanho);

    return 0;

}