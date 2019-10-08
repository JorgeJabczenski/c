#include <stdio.h>
#include "mymerge.h"
#include "vetores.h"

#define MAX 10

int main(){

    int vetor[MAX] = {9,8,7,6,5,4,3,2,1,0};

    print_vector(vetor, MAX);
    
    merge_sort(vetor, 0, MAX-1);

    print_vector(vetor, MAX);

    return 0;
}