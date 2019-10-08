#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int len = 2;
	char *buff = (char *) malloc (len * sizeof (char));
	int i = 0;


	if (buff == NULL){
		printf("Sem memória irmão\n");
		return 1;
	}

	scanf("%c", buff+i) ;
	
	while((buff[i] != '\n')) {
		i++;
		if (i == len){
			len *= 2;
			buff = (char *) realloc(buff,len * sizeof (char));
			if (buff == NULL){
				printf("Sem memória irmão\n");
				return 1;
				break;
			}
		}
		
		scanf("%c", buff+i);
	}

	int tam = (int) strlen(buff) - 1;

	i = 0;
	while((buff[i] == buff[tam - i - 1]) && (i < (tam / 2))) {
		printf("%c é igual a %c \n",buff[i],buff[tam - i - 1]);
		i++;
	}

	if (i == (tam/2))
		printf("SIM\n");
	else
		printf("NAO\n");

	free(buff);

	return 0;
}