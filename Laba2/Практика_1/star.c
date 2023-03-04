 
#include <ncurses.h>

int main (int argc, char*argv[])
{
    initscr();
        
        curs_set(0); 
    
	    int ch;
        int y = LINES/2;
        int x = COLS/2;

        mvaddch (y, x, '*');
        refresh();
        
        noecho();
        keypad(stdscr, TRUE);
        while ( (ch = getch()) != 'q'){
            
            //
            clear();
            
            if (ch == KEY_DOWN) {
                y +=1;
                mvaddch (y, x, '*');
                refresh();
            }
            
            if (ch == KEY_UP) {
                y -=1;
                mvaddch (y, x, '*');
                refresh();
            }

            if (ch == KEY_LEFT) {
                x -=1;
                mvaddch (y, x, '*');
                refresh();
            }

            if (ch == KEY_RIGHT) {
                x +=1;
                mvaddch (y, x, '*');
                refresh();
            }

        }
        
    endwin();
        return 0;
}
 
