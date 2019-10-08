#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int tam = 2, i = 0;
	char *buffer = (char *) malloc (tam * sizeof (char));

	if (buffer == NULL){
		printf("Sem memória irmão\n");
		return 1;
	}

	scanf("%c", buffer+i) ;
	
	while((buffer[i] != '\n')) {
		i++;
		if (i == tam){
			tam *= 2;
			buffer = (char *) realloc(buffer,tam * sizeof (char));
			if (buffer == NULL){
				printf("Sem memória irmão\n");
				return 1;
				break;
			}
		}
		scanf("%c", buffer+i);
	}

	tam = (int) strlen(buffer) - 1;

	i = 0;
	while((buffer[i] == buffer[tam - i - 1]) && (i < (tam / 2))) 
		i++;

	if (i == (tam/2))
		printf("SIM\n");
	else
		printf("NAO\n");

	free(buffer);

	return 0;
}