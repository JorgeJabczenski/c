
#include <stdio.h>

int print_vector(int v[], int t){
    int i;
    for (i = 0; i < t; i++)
        printf("%d ", v[i]);
    printf("\n");
    return 1;
}