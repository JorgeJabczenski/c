#include <stdio.h>
#include <string.h>

#define MAX 10

int palindromo(char v[], int t)
{
    if (v[0] != v[t-1])
        return 0;

    if (t > 0) 
        if (palindromo(v+1, t-2))
            return 1;
}


int main(){

    char palavra[MAX];
    scanf("%s",palavra);
    int i = strlen(palavra);
    printf("o tamanho é %d\n", i);
   
     if (palindromo(palavra,i))
        printf("a strign é palindroma!\n");
}
