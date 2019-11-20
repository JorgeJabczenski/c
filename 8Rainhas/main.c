#include <stdio.h>
#include <stdlib.h>

struct s_pos{
    int x;
    int y;
}; 
typedef struct s_pos pos;


int testa_lin(pos r1, pos r2){
    return (r1.y - r2.y);
}

int testa_col(pos r1, pos r2){
    return (r1.x - r2.x);
}

int testa_diag(pos r1, pos r2){
   return (!((abs(r1.x - r2.x)) == (abs(r1.y - r2.y))));
}

int testa(pos r1, pos r2){
    return (testa_lin (r1,r2) && testa_col (r1,r2) && testa_diag(r1,r2));
}

int rainha(){


}


int main(){

    pos v[8];
    
    v[0].x = 1;
    v[0].y = 0;

    v[1].x = 0;
    v[1].y = 1;

    int i = testa(v[0], v[1]);
    printf("%d\n", i);

    return 0;
}
