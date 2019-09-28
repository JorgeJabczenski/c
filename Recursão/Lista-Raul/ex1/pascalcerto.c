#include <stdio.h>


int pascal(int l, int c){

    if (l == 0 || c == 0 || l == c)
        return 1;

    return ( pascal(l-1,c) + pascal(l-1,c-1) );
}


int main(){

    int n, termo, soma = 0, contador = 0, l, c;
    
    scanf("%d",&n);

    while(n > soma){
        soma += contador;
        contador++;
    }

    l = contador - 2;
    c = l - (soma - n);

    termo = pascal(l,c);

    printf("O termo %d é %d\n", n, termo);

    return 0;
}
