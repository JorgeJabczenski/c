#include <stdio.h>
#include "tad_pilha.h"

int main(){

    char elemento, top, lixo;
    tad_pilha pilha;

    inicializa_pilha(&pilha);

    scanf("%c", &elemento);

    while(elemento != '0'){
        topo(&top, pilha);

        if (elemento == '(' || elemento == '[' || elemento == '{'){
            empilha(elemento, &pilha);
        }
        else if (elemento == ')' && top == '(')
                desempilha(&lixo,&pilha);
        else if (elemento == ']' && top == '[')
                desempilha(&lixo,&pilha);
        else if (elemento == '}' && top == '{')
                desempilha(&lixo,&pilha);
        
        scanf("%c", &elemento);

    }

    if (tamanho_pilha(pilha) != 0)
        printf("NAO\n");
    else 
        printf("SIM\n");

return 0;
}
