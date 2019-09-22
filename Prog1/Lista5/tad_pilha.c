#define MAX 5 

#include <stdio.h>

/* aqui vao as declaracoes iniciais e os codigos das funcoes */
/* inicio das suas modificacoes nesta parte                  */
typedef struct tad_pilha
{
	int vetor[MAX];
	int topo;
} tad_pilha;

void inicializa_pilha(tad_pilha *p){
	p->topo = -1;
}

int pilha_vazia(tad_pilha p){
    if (p.topo == -1)
        return 1;
    return 0;
}

int tamanho_pilha(tad_pilha p){
    return (p.topo + 1);
}

int empilha(int x, tad_pilha *p){
    if (p->topo == MAX-1)
        return 0;
    p->topo++;
    p->vetor[p->topo] = x;
    return 1;
}

int desempilha (int *t, tad_pilha *p){
    if (p->topo == -1)
        return 0;
    *t = p->vetor[p->topo];
    p->topo--;
    return 1;
}

int topo(int *t, tad_pilha p){
    if (p.topo == -1)
        return 0;
    *t = p.vetor[p.topo];
    return 1;
}



/* fim das suas modificacoes desta parte                     */

/* O codigo abaixo so pode ser modificado para resolver o    */
/* problema da passagem de endereços como parâmetros!        */
/* Deixe o restante do programa inalterado!!!                */

int main() {
    tad_pilha p; 
    int i,x,t;
    
    inicializa_pilha(&p);
    printf("tamanho inicial da pilha eh: %d\n",tamanho_pilha(p));

    for (i=0; i<=MAX; i++)
        if (! empilha(i,&p)) {
            printf("%d nao inserido: pilha cheia\n",i);
            printf("tamanho da pilha: %d\n",tamanho_pilha(p));
        }
        else {
            printf("%d empilhado\n",i);
            printf("tamanho da pilha: %d\n",tamanho_pilha(p));
        }

    for (i=0; i<=MAX; i++) {
        x = topo(&t,p);
        if (! x)
            printf("pilha vazia, topo nao existe\n");
        else
            printf("topo eh: %d\n",t);

        x = desempilha(&t,&p);
        if (! x)
            printf("nao desempilhou: pilha vazia\n");
        else
            printf("%d desempilhado\n",t);
    }
    
    return 0;
}
