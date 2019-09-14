#include <stdio.h>


int imprimir_R(int n){

    if (n == 0)
        return 0;

    printf("%d ", n);
    imprimir_R(n-1);
return 1;
}

int main(){
    
    int n;

    scanf("%d", &n);

    imprimir_R(n);

    return 0;
}
