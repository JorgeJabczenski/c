#include <stdio.h>
#define N 10

int main()
{

	int v[N]={9,8,7,6,5,4,3,2,1,0};
	int limite = N/2;
	printf("limite = %d \n", limite);

	for (int i=0; i < limite; i++){
		int min = i;
		for (int j = i+1; j < N-i-1; j++){
			printf("%d %d \n",i,j);
			if (v[j] < v[min]){
				min = j;
			}
		}

		int a  = v[i];
		v[i]   = v[min];
		v[min] = a;
	}

	for (int i =0 ; i < N-1; i++)
		printf("%d ",v[i]);
	printf("\n");
}
