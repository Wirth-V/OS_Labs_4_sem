#include <ncurses.h>

int main (int argc, char*argv[])
{
	int ch;

        initscr();
        mvaddch (LINES/2, COLS/2, '*');
        refresh();
	while ( (ch = getch()) != 'q'){
		fprintf (stderr, "%x\n", ch);
	}
	endwin();
        return 0;
}
 
