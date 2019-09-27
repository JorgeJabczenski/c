#define MAX 15

struct pilha_s {
	char vetor[MAX];
	int topo;
}; 

typedef struct pilha_s tad_pilha;

void inicializa_pilha(tad_pilha *);

int pilha_vazia(tad_pilha);

int tamanho_pilha(tad_pilha);

int empilha(int, tad_pilha *);

int desempilha (int *, tad_pilha *);

int topo(int *, tad_pilha);
