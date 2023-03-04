\\Для запуска игры, нужносдвинуть танчик с места.
\\ Для завершения игры, нажмите m.

#include <ncurses.h>

int main (int argc, char*argv[])
{
    initscr();
        
        curs_set(0); 
    
	    int i, ch, y[9], x[9], metka;        
        
        y[1] = LINES/2 - 1;
        x[1] = COLS/2 - 1;
        
        y[2] = LINES/2 - 1;
        x[2] = COLS/2;
        
        y[3] = LINES/2 - 1;
        x[3] = COLS/2 + 1;
        
        y[4] = LINES/2;
        x[4] = COLS/2 - 1;
        
        y[5] = LINES/2;
        x[5] = COLS/2;
        
        y[6] = LINES/2;
        x[6] = COLS/2 + 1;
        
        y[7] = LINES/2 + 1;
        x[7] = COLS/2 - 1;
        
        y[8] = LINES/2 + 1;
        x[8] = COLS/2;
        
        y[9] = LINES/2 + 1;
        x[9] = COLS/2 + 1;
        

        mvaddch (y[1], x[1], '*');
        mvaddch (y[2], x[2], '|');
        mvaddch (y[3], x[3], '*');
        mvaddch (y[4], x[4], '*');
        mvaddch (y[5], x[5], '*');
        mvaddch (y[6], x[6], '*');
        mvaddch (y[7], x[7], '*');
        mvaddch (y[8], x[8], ' ');
        mvaddch (y[9], x[9], '*');
        refresh();
        
        noecho();
        keypad(stdscr, TRUE);
        
        while ( (ch = getch()) != 'm'){
            
            if (ch == KEY_DOWN) {
                
                metka = 1;
                
                for(i = 1; i <= 9; i++)
                    y[i] +=1;
                
                for (i = 1; i <= 9; i++ ){
                    if (y[i]== LINES)
                        y[i]= 0;
            
                    if (y[1]== -1)
                        y[1]= LINES - 1;
                }
                
                clear();
                mvaddch (y[1], x[1], '*');
                mvaddch (y[2], x[2], ' ');
                mvaddch (y[3], x[3], '*');
                mvaddch (y[4], x[4], '*');
                mvaddch (y[5], x[5], '*');
                mvaddch (y[6], x[6], '*');
                mvaddch (y[7], x[7], '*');
                mvaddch (y[8], x[8], '|');
                mvaddch (y[9], x[9], '*');
                refresh();
        
            }
            
            if (ch == KEY_UP) {
                
                metka = 1;
                
                for(i = 1; i <= 9; i++)
                    y[i] -=1;
                 
                for (i = 1; i <= 9; i++ ){
                    if (y[i]== LINES)
                        y[i]= 0;
            
                    if (y[i]== -1)
                        y[i]= LINES - 1;
                }
                
                clear();
                mvaddch (y[1], x[1], '*');
                mvaddch (y[2], x[2], '|');
                mvaddch (y[3], x[3], '*');
                mvaddch (y[4], x[4], '*');
                mvaddch (y[5], x[5], '*');
                mvaddch (y[6], x[6], '*');
                mvaddch (y[7], x[7], '*');
                mvaddch (y[8], x[8], ' ');
                mvaddch (y[9], x[9], '*');
                refresh();
            }

            if (ch == KEY_LEFT) {
                
                metka = 2;
            
                for(i = 1; i <= 9; i++)
                    x[i] -=1;
                
                for (i = 1; i <= 9; i++ ){
                    if (x[i] == COLS)
                        x[i] = 0;
            
                    if (x[i] == -1)
                        x[i] = COLS - 1;
                }
                
                clear();
                mvaddch (y[1], x[1], '*');
                mvaddch (y[2], x[2], '*');
                mvaddch (y[3], x[3], '*');
                mvaddch (y[4], x[4], '-');
                mvaddch (y[5], x[5], '*');
                mvaddch (y[6], x[6], ' ');
                mvaddch (y[7], x[7], '*');
                mvaddch (y[8], x[8], '*');
                mvaddch (y[9], x[9], '*');
                refresh();
            }

            if (ch == KEY_RIGHT) {
                
                metka = 2;
                
                for(i = 1; i <= 9; i++)
                    x[i] +=1;
                
                for (i = 1; i <= 9; i++ ){
                    if (x[i] == COLS)
                        x[i] = 0;
            
                    if (x[i] == -1)
                        x[i] = COLS - 1;
                }
                
                clear();
                mvaddch (y[1], x[1], '*');
                mvaddch (y[2], x[2], '*');
                mvaddch (y[3], x[3], '*');
                mvaddch (y[4], x[4], ' ');
                mvaddch (y[5], x[5], '*');
                mvaddch (y[6], x[6], '-');
                mvaddch (y[7], x[7], '*');
                mvaddch (y[8], x[8], '*');
                mvaddch (y[9], x[9], '*');
                refresh();
            } 
            
            if (ch == 'w' || ch == 'W') {
                if (metka == 1) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], '|');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], '*');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], '*');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], ' ');
                        mvaddch (y[9], x[9], '*');
                        refresh();
                }
                
                
                if (metka == 2) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], '|');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], ' ');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], ' ');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], '*');
                        mvaddch (y[9], x[9], '*');
                        refresh();
                }
                
            }
            
            if (ch == 'e' || ch == 'E' ) {
                if (metka == 1) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], ' ');
                        mvaddch (y[3], x[3], '/');
                        mvaddch (y[4], x[4], '*');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], '*');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], ' ');
                        mvaddch (y[9], x[9], '*');
                        refresh();
                }
 
                if (metka == 2) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], '*');
                        mvaddch (y[3], x[3], '/');
                        mvaddch (y[4], x[4], ' ');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], ' ');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], '*');
                        mvaddch (y[9], x[9], '*');
                        refresh();
                }
                
            }
            
            if (ch == 'd' || ch == 'D') {
                if (metka == 1) { 
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], ' ');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], '*');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], '-');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], ' ');
                        mvaddch (y[9], x[9], '*');
                        refresh();
                    
                }
                

                if (metka == 2) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], '*');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], ' ');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], '-');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], '*');
                        mvaddch (y[9], x[9], '*');
                        refresh();
                }
                
            }
            
            if (ch == 'c' || ch == 'C') {
                if (metka == 1) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], ' ');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], '*');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], '*');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], ' ');
                        mvaddch (y[9], x[9], '\\');
                        refresh();
                }
                
  
                if (metka == 2) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], '*');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], ' ');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], ' ');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], '*');
                        mvaddch (y[9], x[9], '\\');
                        refresh();
                }
                
            }
            
            if (ch == 'x' || ch == 'X') {
                if (metka == 1) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], ' ');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], '*');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], '*');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], '|');
                        mvaddch (y[9], x[9], '*');
                        refresh();
                }
                
                
                if (metka == 2) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], '*');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], ' ');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], ' ');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], '|');
                        mvaddch (y[9], x[9], '*');
                        refresh();
                }
                
            }
            
            if (ch == 'z' || ch == 'Z') {
                if (metka == 1) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], ' ');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], '*');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], '*');
                        mvaddch (y[7], x[7], '/');
                        mvaddch (y[8], x[8], ' ');
                        mvaddch (y[9], x[9], '*');
                        refresh();
                }
                
                if (metka == 2) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], '*');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], ' ');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], ' ');
                        mvaddch (y[7], x[7], '/');
                        mvaddch (y[8], x[8], '*');
                        mvaddch (y[9], x[9], '*');
                        refresh();
                }
                
            }
            
            if (ch == 'a'  || ch == 'A') {
                if (metka == 1) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], ' ');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], '-');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], '*');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], ' ');
                        mvaddch (y[9], x[9], '*');
                        refresh();  
                }
                
                if (metka == 2) {
                        mvaddch (y[1], x[1], '*');
                        mvaddch (y[2], x[2], '*');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], '-');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], ' ');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], '*');
                        mvaddch (y[9], x[9], '*');
                        refresh();
                }
                
            }
            
            if (ch == 'q' || ch == 'Q') {
                if (metka == 1) {
                        mvaddch (y[1], x[1], '\\');
                        mvaddch (y[2], x[2], ' ');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], '*');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], '*');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], ' ');
                        mvaddch (y[9], x[9], '*');
                        refresh(); 
                }
                
                if (metka == 2) {
                        mvaddch (y[1], x[1], '\\');
                        mvaddch (y[2], x[2], '*');
                        mvaddch (y[3], x[3], '*');
                        mvaddch (y[4], x[4], ' ');
                        mvaddch (y[5], x[5], '*');
                        mvaddch (y[6], x[6], ' ');
                        mvaddch (y[7], x[7], '*');
                        mvaddch (y[8], x[8], '*');
                        mvaddch (y[9], x[9], '*');
                        refresh();
                }
                
            }

            
            else 
                continue;

        }
        
    endwin();
        return 0;
}
 
