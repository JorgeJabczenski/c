#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX  128

int ehpalindromo(char *palavra){

	int i, t;
	t = strlen(palavra) - 1;
	
	for (i = 0; i < t/2; i++)
		if (palavra[i] != palavra[t-1-i])
			return 0;

	return 1;
}


int main(){

	unsigned int  tam = MAX, i = 0;
	char *buffer = (char *) malloc (tam * sizeof (char)); /* Aloca um vetor de tamanho MAX */

	if (buffer == NULL){
		printf("Sem memória irmão\n");
		return 1;
	}

	scanf("%c", buffer+i) ;
	
	while((buffer[i] != '\n')) {
		i++;
		if (i == tam){ /* Se ainda existem elementos para serem inseridos no buffer e a string nao terminou, dobrar o tamanho do buffer e realoca-lo */
			tam *= 2;
			buffer = (char *) realloc(buffer,tam * sizeof (char));
			if (buffer == NULL){
				printf("Sem memória irmão\n");
				return 1;
			}
		}
		scanf("%c", buffer+i);
	}

	

	if (ehpalindromo(buffer))
		printf("SIM\n");
	else
		printf("NAO\n");

	free(buffer);

	return 0;
}