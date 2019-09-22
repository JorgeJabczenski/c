#include <stdio.h>
#include "tad_pilha.h"

int main(){

    char elemento, top;
    tad_pilha pilha;

    inicializa_pilha(&pilha);
    printf("O TAMANHO DA PILHA É %d\n",tamanho_pilha(pilha));

    scanf("%c", &elemento);

    while(elemento != '0'){
        if (!topo(&top, pilha))
            top = '0';

        if (elemento == '(' || elemento == '['|| elemento == '{')
            empilha(elemento, &pilha);
        else if (elemento == ')' && top =='(')
            desempilha(&top, &pilha);
        else if (elemento == ']' && top =='[')
            desempilha(&top, &pilha);
        else if (elemento == '}' && top =='{')
            desempilha(&top, &pilha);
        else if (elemento == ')' || elemento == ']'|| elemento == '}'){
            /*empilhar o caso que não deu certo para o tamanho da pilha nao finalizar em 0*/
            empilha(elemento, &pilha);
            break;
        }

        scanf("%c", &elemento);
    }

    printf("O TAMANHO FINAL DA PILHA É %d\n",tamanho_pilha(pilha));
    if (tamanho_pilha(pilha) != 0)
        printf("NAO\n");
    else 
        printf("SIM\n");

return 0;
}
