#define MAX 15

struct pilha_s {
	float vetor[MAX];
	int topo;
}; 

typedef struct pilha_s tad_pilha;

void inicializa_pilha(tad_pilha *);

int pilha_vazia(tad_pilha);

int tamanho_pilha(tad_pilha);

int empilha(float, tad_pilha *);

int desempilha (float *, tad_pilha *);

int topo(float *, tad_pilha);

int imprime_pilha(tad_pilha);
