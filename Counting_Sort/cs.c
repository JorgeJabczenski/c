#include <stdio.h>

int main(){

	
	int a[] = {2,5,3,0,2,3,0,3};
	int b[8];
	int c[6];

	int i;

	for (i = 0; i < 6; i++){
		c[i] = 0;
	}
	for (i = 0; i < 8; i++){
		c[a[i]]++;
	}
	for (i = 1; i < 6; i++){
		c[i] += c[i-1];
	}
	for (i = 0; i < 8; i++){
		b[c[a[i]]-1] = a[i];
		c[a[i]]--;
	}
	for (i = 0; i < 8; i++){
		printf("%d", a[i]);
	}
	printf("\n");
	for (i = 0; i < 8; i++){
		printf("%d", b[i]);
	}
	printf("\n");
	return 0;
}
