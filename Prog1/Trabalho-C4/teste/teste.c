#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *nome;
    scanf("%m[^\n]", &nome);
    printf("PORRA %s , seu nome tem %d letras\n", nome , (int) strlen(nome) );
    free(nome);

 return 0;
}