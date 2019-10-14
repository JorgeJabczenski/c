#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <ctype.h>

int ctoi(char c){
    return c - '0';
}


/* Tentar implementar com loop around | (x + i + linhas) % linhas | (y + j + colunas) % colunas */
int conta_vizinhos(){

    int soma = 0;

    return soma;
}

void copia_matrizes(){

}

void ler_geracao(int **m){

    char ling1, colg1; /* Linhas e colunas da Geração 1 */
    printw("Vá inserindo a linha e a coluna dos elementor vivod da geração 1 , quando quiser encerrar digite (p)ronto\n");
    

    scanw("%c %c", &ling1, &colg1);
    
    while(ling1 != 'p'){
        if (isdigit(ling1) && isdigit(colg1)) {
           int l = ctoi(ling1);
           int c = ctoi(colg1);
           m[l][c] = 1;
        } else {
            if (ling1 != 'p')
                printw("Entrada Inválida\n");
        }

        scanw("%c %c", &ling1, &colg1);
    }       


 
}

void imprime_matriz(int **m, int lin, int col){
    
    int i,j;

    for (i = 0; i < lin; i++)
        for (j = 0; j < col; j++)
			mvprintw(j,i,"%d", m[lin][col]);

}

int **aloca_matrizes(int lin, int col){
   
    int **m;
    int i;
    
    m = (int **) malloc (lin * sizeof(int*));

    for (i = 0; i < lin; i++)
        m[i] = (int *) malloc (col * sizeof(int));

    return m;
}


int main(int argc, char **argv ){

	initscr();
    clear();

    int **geracaoAntiga, **geracaoNova;
    int linhas  = atoi(argv[1]);
    int colunas = atoi(argv[2]);

    geracaoAntiga = aloca_matrizes(linhas, colunas);
    geracaoNova   = aloca_matrizes(linhas, colunas);

    int c,k;
    for (c = 0; c < linhas; c++){
        for (k = 0; k < colunas; k++){
            geracaoAntiga[c][k] = k % 10;
            mvprintw(k,c,"%d", geracaoAntiga[c][k]);
        }
    }

    getch();

    ler_geracao(geracaoAntiga); /* Le e coloca as jogadas da geraçao 1 */

    imprime_matriz(geracaoAntiga, linhas, colunas);

    getch();

    int i,j;

	for (i = 0; i < 20; i++)
		for (j = 0; j < 20; j++)
			mvprintw(j,i,"~");

	refresh();
	getch();

	endwin();

	return 0;
}
