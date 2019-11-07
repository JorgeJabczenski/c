#include "lib_fila.h"

int main(){

    t_fila aterrisagem[4];
    t_fila decolagem[3];

    int i;

    for (i = 0; i < 4; i++)
        inicializa_fila(&aterrisagem[i]);

    for (i = 0; i < 3; i++)
        inicializa_fila(&decolagem[i]);




    return 0;
}