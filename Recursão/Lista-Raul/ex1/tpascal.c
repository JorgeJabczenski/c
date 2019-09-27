#include <stdio.h>
#include <stdlib.h>

int fat(int n){
    if (n == 0)
        return 1;
    return (n*fat(n-1));
}

void combinacao(int n, int p){
    if ((n >= p) && (n >= 0)){
        printf("%d ",fat(n)/(fat(p)*fat(n-p)));
        combinacao(n,p+1);
    }
}

int t_pascal(int n){
    if (n > 0)
        t_pascal(n-1);

    combinacao(n,0);
    printf("\n");
}

int main (){

    int n;
    scanf("%d", &n);
    t_pascal(n);
    return 0;
}