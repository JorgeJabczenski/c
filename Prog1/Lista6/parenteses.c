#include <stdio.h>
#include "tad_pilha.h"

int main(){

    char elemento, top;
    tad_pilha pilha;

    inicializa_pilha(&pilha);

    scanf("%c", &elemento);

    while(elemento != '0'){
        if (!topo(&top, pilha))
            top = '0';

        if (elemento == '(' || elemento == '['|| elemento == '{')
            empilha(elemento, &pilha);
        else if ((elemento == ')' && top =='(') || (elemento == ']' && top =='[') || (elemento == '}' && top =='{'))
            desempilha(&top, &pilha);
        else if (elemento == ')' || elemento == ']'|| elemento == '}'){   
            empilha(elemento, &pilha);   /* empilhar o caso que não deu certo para o tamanho da pilha nao finalizar em 0 */
            break;                       /* break opcional, apenas diminui o tempo de execução */
        }

        scanf("%c", &elemento);
    }

    if (tamanho_pilha(pilha) != 0)
        printf("NAO\n");
    else 
        printf("SIM\n");

return 0;
}
