#include <stdio.h>


int imprimir_R(int n){

    if (n > 1)
        imprimir_R(n-1);
    printf("%d ", n);

return 0;
}

int main(){
    
    int n;

    scanf("%d", &n);

    imprimir_R(n);

    return 0;
}
