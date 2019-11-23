#include <stdio.h>

int counting_sort(int a[], int tam, int range, int exp){

	int b[tam];
	int c[range];
	int i;

	for (i = 0; i < range; i++){
		c[i] = 0;
	}
	for (i = 0; i < tam; i++){
		c[(a[i]/exp)%10]++;
	}
	for (i = 1; i < range; i++){
		c[i] += c[i-1];
	}
	for (i = tam-1 ; i >= 0; i--){
		b[c[((a[i]/exp)%10)]-1] = a[i];
		c[(a[i]/exp)%10]--;
	}
	for (i = 0; i < tam; i++){
		a[i] = b[i];
	}
	printf("\n");
	for (i = 0; i < tam; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

}


int main(){

	
	int a[] = {329,457,657,839,436,720,355};
	int b[7];
	int d = 3;
	int exp = 1;
	int i;

	for (i = 0; i < 7; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

	for (i = 0; i < d; i++)
	{
		counting_sort(a, 7, 10, exp);
		exp *= 10;
	}

	return 0;
}
