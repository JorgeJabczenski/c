#include <stdio.h>
#include <stdlib.h>

#include "lib_lista_complementar.h"

int main(){

    int item;
    t_lista lista1, lista2, lista3, lista4, lista5;

    inicializa_lista(&lista1);
    inicializa_lista(&lista2);
    inicializa_lista(&lista3);
    inicializa_lista(&lista4);
    inicializa_lista(&lista5);
  
    printf("Insira a Lista 1 terminada em zero\n");
    scanf("%d", &item);
    while(item != 0){
        insere_fim_lista(item, &lista1);
        scanf("%d", &item);
    }

    printf("Insira a Lista 2 terminada em zero\n");
    scanf("%d", &item);
    while(item != 0){
        insere_fim_lista(item, &lista2);
        scanf("%d", &item);
    }

    printf("Lista 1 ->  ");
    imprime_lista(&lista1);

    printf("Lista 2 ->  ");
    imprime_lista(&lista2);

    printf("Copia lista 1 na lista 3\n");
    copia_lista(&lista1, &lista3);
    printf("Lista 1 ->  ");
    imprime_lista(&lista1);
    printf("Lista 3 ->  ");
    imprime_lista(&lista3);

    printf("Copia lista 2 na lista 4\n");
    copia_lista(&lista2, &lista4);
    printf("Lista 2 ->  ");
    imprime_lista(&lista2);
    printf("Lista 4 ->  ");
    imprime_lista(&lista4);

    printf("Concatena Listas 3 e 4\n");
    concatena_listas(&lista3, &lista4);
    printf("Lista 3 -> ");
    imprime_lista(&lista3);
    printf("Lista 4 ->  ");
    imprime_lista(&lista4);
    printf("\n");

    printf("Ordena Lista 3\n");
    ordena_lista(&lista3);
    printf("Lista 3 -> ");
    imprime_lista(&lista3);

    printf("Intercala Listas 1 e 2 na Lista 5\n");
    intercala_listas(&lista1, &lista2, &lista5);
    printf("Lista 1 ->  ");
    imprime_lista(&lista1);
    printf("Lista 2 ->  ");
    imprime_lista(&lista2);
    printf("Lista 5 ->  ");
    imprime_lista(&lista5);

    destroi_lista(&lista1);
    destroi_lista(&lista2);
    destroi_lista(&lista3);
    destroi_lista(&lista5);

    return 0;

}