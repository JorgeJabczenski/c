#include <stdio.h>
#include <stdlib.h>
#include <curses.h>




int main(){

	initscr();
	
	printw("hello");
	refresh();

	getch();
	int i,j;

	for (i = 0; i < 20; i++)
		for (j = 0; j < 40; j++)
			mvprintw(j,i,"1");

	getch();

	endwin();

	return 0;
}