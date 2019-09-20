#include "tad_pilha.h" 

void inicializa_pilha(tad_pilha *p){
	(*p).topo = 0;
}

int pilha_vazia(tad_pilha p){
	if (p.topo == 0) 
		return 1;
	else 
		return 0;
}

int tamanho_pilha(tad_pilha p){
	return p.topo;
}

int empilha(int x, tad_pilha *p){
	if ((*p).topo >= MAX)
		return 0;
	(*p).vetor[(*p).topo] = x;
	(*p).topo += 1;
	return 1;
}

int desempilha (int *t, tad_pilha *p){
	if (pilha_vazia(*p))
		return 0;
	(*p).topo--;
	*t = (*p).vetor[(*p).topo];
	return 1;
}

int topo(int *t, tad_pilha p){
	if (pilha_vazia(p))
		return 0;
	*t = p.vetor[p.topo - 1];	
	return 1;
}