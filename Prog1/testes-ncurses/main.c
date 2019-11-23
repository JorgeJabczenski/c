#include <stdio.h>
#include <stdlib.h>
#include <curses.h>

int main(){

	initscr();
	noecho();               /* não mostra os caracteres digitados */
	cursor(stdscr, FALSE);
	
	mvaddch(10,10,ACS_ULCORNER);
	refresh();


	getch();
	endwin();

	return 0;
}
