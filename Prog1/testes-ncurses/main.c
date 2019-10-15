#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main(){

	initscr();
	//noecho();               /* não mostra os caracteres digitados */

	//char k = getch();

	char k;
	scanf("%c", &k);

	printw("%c\n",k);

	refresh();

	getch();
	endwin();

	return 0;
}