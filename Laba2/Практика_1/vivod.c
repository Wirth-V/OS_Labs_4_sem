#include <ncurses.h>

int main (int argc, char*argv[])
{
	initscr();
	mvaddch (0, COLS-1, '*');
	refresh();
	getch();
	endwin();
	return 0;
}
