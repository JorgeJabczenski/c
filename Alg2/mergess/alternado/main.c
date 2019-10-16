#include <stdio.h>
#include <stdlib.h>
#define MAX 32

void merge_a(int *a, int *b, int ini, int meio, int fim){

	int i = ini;
	int j = meio + 1;
	int ind = ini;

    if (a[meio] >= a[meio+1]){
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
    
}

void merge_sort_a(int *a, int *b, int ini, int fim){

	if (ini < fim){
		int meio = (ini + fim) / 2;
		merge_sort_a(b, a, ini, meio);
		merge_sort_a(b, a, meio+1, fim);
		merge_a(a, b, ini, meio, fim);
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

	merge_sort_a(a, b, 0, MAX-1);

	for(i = 0; i < MAX; i++)
		printf("%d ",b[i]);
	printf("\n");

	free(a);
	free(b);


	return 0;
}
