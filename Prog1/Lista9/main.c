#include <stdio.h>
#include <stdlib.h>

#include "lib_lista.h"
/*#include "lib_lista_complementar.h"*/

int main(){

    t_lista lista;
    int tamanho;

    inicializa_lista(&lista);
    
    (lista_vazia(&lista)) ? printf("v a z i a\n") : printf("tem coisa\n");
    insere_inicio_lista(10, &lista);
    insere_inicio_lista(10, &lista);
    insere_inicio_lista(10, &lista);
    (lista_vazia(&lista)) ? printf("v a z i a\n") : printf("tem coisa\n");
    tamanho_lista(&tamanho, &lista);
    printf("Tamanho :  %d\n", tamanho);

    return 0;

}