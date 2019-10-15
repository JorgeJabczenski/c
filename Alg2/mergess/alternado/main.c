#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void merge_a(int *a, int ini, int meio, int fim, int *b){

	int i = ini;
	int j = meio + 1;
	int ind = ini;

	while(i <= meio && j <= fim){
		if (a[i] < a[j])
			b[ind++] = a[i++];
		else 
			b[ind++] = a[j++];
	}

	while(i <= meio)
		b[ind++] = a[i++];

	while(j <= fim)
		b[ind++] = a[j++];

}


void merge_sort_a(int *b, int ini, int fim, int *a){

	if (ini < fim){
		int meio = (ini + fim) / 2;
		merge_sort_a(b, 0, meio, a);
		merge_sort_a(b, meio+1, fim, a);
		merge_a(a, ini, meio, fim, b);
	}

}

int main(){

	int *a, *b;
	a = malloc(MAX*sizeof(int));
	b = malloc(MAX*sizeof(int));

	int i;
	for (i = MAX-1; i >= 0; i--){
		a[MAX-1-i] = i;
		b[MAX-1-i] = i;
	}

	for(i = 0; i < MAX; i++)
		printf("%d ",a[i]);
	printf("\n");

	merge_sort_a(a, 0, MAX-1, b);

	for(i = 0; i < MAX; i++)
		printf("%d ",a[i]);
	printf("\n");
	for(i = 0; i < MAX; i++)
		printf("%d ",b[i]);
	printf("\n");

	free(a);
	free(b);


	return 0;
}