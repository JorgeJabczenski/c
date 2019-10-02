#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tad_pilha.h"

#define MAX_ENTRADA 20

void ajuda();

int main(){

    char entrada[MAX_ENTRADA];
    float numero, n1, n2, res, lixo, temp;
    tad_pilha pilha;

    printf("\033[H\033[J"); /* comando para limpar a tela */ 
    inicializa_pilha(&pilha);
    scanf("%s", entrada);

    while(entrada[0] != 'q'){

        /* Caso a entrada seja um número, empilhar*/
        if (isdigit(entrada[0]) || ((entrada[0] == '-') && isdigit(entrada[1]))){
            numero = atof(entrada);
            if (!empilha(numero, &pilha)){
                printf("Pilha cheia!\n<Aperte ENTER para continuar>");
                getchar();
                getchar();
            }

        /* Caso a entrada seja um comando */   
        } else {
            /* Caso seja uma das quatro operações básicas */
            if ((entrada[0] == '+' || entrada[0] == '-' || entrada[0] == '/' || entrada[0] == '*') && (tamanho_pilha(pilha) >= 2)){
                
                desempilha(&n2, &pilha);
                desempilha(&n1, &pilha);

                switch (entrada[0])
                {
                case '+':
                    res = n1 + n2;
                    empilha(res, &pilha);
                    break;

                case '-':
                    res = n1 - n2;
                    empilha(res, &pilha);
                    break;

                case '*':
                    res = n1 * n2;
                    empilha(res, &pilha);
                    break;

                case '/':
                    res = n1 / n2;
                    empilha(res, &pilha);
                    break;

                default:
                    break;

                }

            } else { /* Caso seja um dos comandos adicionais que eu decidi colocar na calculadora */
            switch (entrada[0])
                {
                case 'r': /* reseta o valor da calculadora */
                    inicializa_pilha(&pilha);
                    break;

                case 'd': /* deleta o ultimo valor inserido */
                    if (!pilha_vazia(pilha)){   
                        desempilha(&lixo, &pilha);
                    } else {
                        printf("Pilha Vazia\n");
                    }
                    break;

                case 'c': /* copia o ultimo valor inserido */
                    if (topo(&temp, pilha))
                        if (!empilha(temp, &pilha)){
                            printf("Pilha cheia!\n<Aperte ENTER para continuar>");
                            getchar();
                            getchar();
                        }
                            
                    break;

                case 's': /* troca os ultimos dois valores da pilha */
                    if (tamanho_pilha(pilha) >= 2){
                        desempilha(&n1, &pilha);
                        desempilha(&n2, &pilha);
                        empilha   (n1 , &pilha);
                        empilha   (n2 , &pilha);
                    } else {
                        printf("Comando Inválido\n<Aperte ENTER para continuar>");
                        getchar();
                        getchar();
                    }
                
                    break;

                case 'h': /* copia o ultimo valor inserido */
                    ajuda();      
                    break;
                
                default:
                    printf("Comando Inválido\n<Aperte ENTER para continuar>");
                    getchar();
                    getchar();
                    break;
                }
            }
        }

        printf("\033[H\033[J"); /* comando para limpar a tela */ 
        imprime_pilha(pilha);
        scanf("%s", entrada);

    } /*end while*/
    if (!topo(&res, pilha)){
        res = 0;
    }
    printf("\n\n%0.3f \n\n---Fim do Programa---\n", res);

    return 0;
}

void ajuda(){

    printf("\033[H\033[J"); /* comando para limpar a tela */ 
    printf("\n MENU DE AJUDA\n\n");
    printf(" q : sair do programa\n");
    printf(" r : resetar a pilha\n");
    printf(" c : copia o último valor da pilha\n");
    printf(" d : deleta o último valor da pilha\n");
    printf(" s : troca os últimos dois valores da pilha\n");
    printf(" h : abre o menu de ajuda\n");
    printf("\n<Aperte ENTER para continuar>\n");
    getchar();
    getchar();

}