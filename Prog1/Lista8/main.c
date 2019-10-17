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

    insere_inicio_lista(10,&lista);

    if (lista_vazia(&lista)) 
        printf("Lista Vazia \n");
    else 
        printf("Tem coisa ai\n");
    
    insere_fim_lista(20,&lista);

    if (lista_vazia(&lista)) 
        printf("Lista Vazia \n");
    else 
        printf("Tem coisa ai\n");


    return 0;
}