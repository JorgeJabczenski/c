#include <stdio.h>
#include "tad_pilha.h"

int main(){

    int elemento, top;
    tad_pilha pilha;
    
    inicializa_pilha(&pilha);

    scanf("%lc", &elemento);

    while(elemento != '0'){
       /* Caso a pilha esteja vazia, reseta o valor da variável top */ 
       if (!topo(&top, pilha))
            top = '0';

       /* Validando a entrada */ 
       if (elemento == ')' || elemento == '(' || elemento == ']' || elemento == '[' || elemento == '}' || elemento == '{')
            empilha(elemento, &pilha);
        
       /* Caso o elemento seja o 'fechamento' do topo da pilha, desempilha os dois*/
       if ((elemento == ')' && top =='(') || (elemento == ']' && top =='[') || (elemento == '}' && top =='{')){
            desempilha(&top, &pilha);
            desempilha(&top, &pilha);
       }

        scanf(" %lc", &elemento);
    }

    /* A pilha está equilibrada se a pilha finaliza vazia */
    if (pilha_vazia(pilha))
        printf("SIM\n");
    else 
        printf("NAO\n");

return 0;
}
