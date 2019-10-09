#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int palindromo(char v[], int t){

    if (v[0] != v[t-1])
        return 0;
    
    palindromo(v+1, t-2);

    return 1;
}


int main(){

	int tam = 2, i = 0;
	char *buffer = (char *) malloc (tam * sizeof (char)); /* Aloca um vetor de tamanho 2 */

	if (buffer == NULL){
		printf("Sem memória irmão\n");
		return 1;
	}

	scanf("%c", buffer+i) ;
	
	while((buffer[i] != '\n')) {
		i++;
		if (i == tam){ /* Se ainda existem elementos no buffer, dobrar o tamanho do buffer e realoca-lo */
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

	if (palindromo(buffer,tam))
        printf("SIM\n");
    else
    {
        printf("NÃO\n");
    }
    
	return 0;
}