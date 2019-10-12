#define MAX 10000

/* Operações com Vetor */
void gera_vetor_aleatorio (int v[], int tam);
void gera_vetor_ordenado  (int v[], int tam);
void embaralha_vetor      (int v[], int tam);
void imprime_vetor        (int v[], int tam);

/* Funções Auxiliares */
void troca     (int *i, int *j);
void intercala (int v[], int ini, int meio, int fim);
int particiona (int v[], int ini, int fim);

/* Métodos de Ordenação */
void insertionsort (int v[], int ini, int fim);
void quicksort     (int v[], int ini, int fim);
void mergesort     (int v[], int ini, int fim);
