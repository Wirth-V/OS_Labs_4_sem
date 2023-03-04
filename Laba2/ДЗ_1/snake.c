#include <ncurses.h>

int main (int argc, char*argv[])
{
    initscr();
        
        curs_set(0); 
    
	    int ch;
        
        int y1 = LINES/2;
        int x1 = COLS/2;
        
        int y2 = LINES/2;
        int x2 = COLS/2 - 1;
        
        int y3 = LINES/2;
        int x3 = COLS/2 - 2;
        
        int y4 = LINES/2;
        int x4 = COLS/2 - 3;
        
        int y5 = LINES/2;
        int x5 = COLS/2 - 4;
        

        mvaddch (y1, x1, '*');
        mvaddch (y2, x2, '*');
        mvaddch (y3, x3, '*');
        mvaddch (y4, x4, '*');
        mvaddch (y5, x5, '*');
        refresh();
        
        noecho();
        keypad(stdscr, TRUE);
        
        while ( (ch = getch()) != 'q'){
           
            
            if (ch == KEY_DOWN) {
                y5 = y4;
                y4 = y3;
                y3 = y2;
                y2 = y1;
                y1+=1;
                
                x5 = x4;
                x4 = x3;
                x3 = x2;
                x2 = x1;
                
                if (y1== LINES)
                    y1= 0;
            
                if (y1== -1)
                    y1= LINES - 1;
                
                clear();
                mvaddch (y1, x1, '*');
                mvaddch (y2, x2, '*');
                mvaddch (y3, x3, '*');
                mvaddch (y4, x4, '*');
                mvaddch (y5, x5, '*');
                refresh();
            }
            
            if (ch == KEY_UP) {
                
                y5 = y4;
                y4 = y3;
                y3 = y2;
                y2 = y1;
                y1-=1;
                
                x5 = x4;
                x4 = x3;
                x3 = x2;
                x2 = x1;
                
                if (y1== LINES)
                    y1= 0;
            
                if (y1== -1)
                    y1= LINES - 1;
                
                clear();
                mvaddch (y1, x1, '*');
                mvaddch (y2, x2, '*');
                mvaddch (y3, x3, '*');
                mvaddch (y4, x4, '*');
                mvaddch (y5, x5, '*');
                refresh();
            }

            if (ch == KEY_LEFT) {
                x5 = x4;
                x4 = x3;
                x3 = x2;
                x2 = x1;
                x1 -=1;
                
                y5 = y4;
                y4 = y3;
                y3 = y2;
                y2 = y1;
                
                if (x1 == COLS)
                    x1 = 0;
            
                if (x1 == -1)
                    x1 = COLS - 1;
                
                clear();
                mvaddch (y1, x1, '*');mvaddch (y2, x2, '*');
                mvaddch (y3, x3, '*');
                mvaddch (y4, x4, '*');
                mvaddch (y5, x5, '*');
                
                refresh();
            }

            if (ch == KEY_RIGHT) {
                x5 = x4;
                x4 = x3;
                x3 = x2;
                x2 = x1;
                x1 +=1;
                
                y5 = y4;
                y4 = y3;
                y3 = y2;
                y2 = y1;
    
                if (x1 == COLS)
                    x1 = 0;
            
                if (x1 == -1)
                    x1 = COLS - 1;
                
                clear();
                mvaddch (y1, x1, '*');
                mvaddch (y2, x2, '*');
                mvaddch (y3, x3, '*');
                mvaddch (y4, x4, '*');
                mvaddch (y5, x5, '*');
                refresh();

            }
            
            else 
                continue;
        }
        
    endwin();
        return 0;
}
 
