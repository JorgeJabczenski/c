#define MAX 10000000

/* Operações com Vetor */
void gera_vetor_aleatorio (int v[], int tam);
void gera_vetor_ordenado  (int v[], int tam);
void embaralha_vetor      (int v[], int tam);
void imprime_vetor        (int v[], int tam);
void copia_vetor          (int voriginal[], int vcopia[], int tam);

/* Funções Auxiliares */
void troca     (int *i, int *j);

void merge  (int v[], int ini, int meio, int fim);
void merge_a(int *a, int *b, int ini, int meio, int fim);
void merge_b(int v[], int ini, int meio, int fim);
void merge_c(int *v,int *vetaux,  int ini, int meio, int fim);

int particiona          (int v[], int ini, int fim);
int particiona_mediana3 (int v[], int ini, int fim);

/* Métodos de Ordenação */
void insertionsort (int v[], int ini, int fim);

void quicksort                    (int v[], int ini, int fim);
void quicksort_mediana3           (int v[], int ini, int fim);
void quicksort_mediana3_insertion (int v[], int ini, int fim);

void mergesort     (int v[], int ini, int fim);
void mergesort_a  (int *a, int *b, int ini, int fim);
void mergesort_b   (int v[], int ini, int fim);
void mergesort_c   (int v[], int va[], int ini, int fim);