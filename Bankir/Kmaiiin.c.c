#include <stdio.h>
#include <ncurses.h>

int print_matrix(int matrix[4][4], int x, int y);
int print_vector(int *vector, int x, int y);
int print_cursor(int curs_x, int curs_y);
int print_matrix(int matrix[4][4], int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
         for (int j = 0; j < 4; ++j)
        {
            mvprintw(y + j, x + 2*i, "%d", matrix[i][j]);
        }
    }
}

int print_vector(int *vector, int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        mvprintw(y, x + 2*i, "%d", vector[i]);
    }
}
int print_cursor(int curs_x, int curs_y)
{
    int abs_x = curs_x*2;
    int abs_y = curs_y;
    abs_x += (abs_y == 0) ? 2: 15;
    abs_y += (abs_y == 0) ? 2: 14;
    
    mvprintw(abs_y, abs_x, "&");
}

int main(int argc, char**argv)
{   
    int ch;
    int T[4];
    int A[4];
    int matrix_C[4][4];
    int matrix_R[4][4];
    int curs_x = 0;
    int curs_y = 0;

    for (int i = 0; i < 4; ++i)
    {
        T[i] = 0;
        A[i] = 0;
        for (int j = 0; j < 4; ++j)
        {
            matrix_C[i][j] = 0;
            matrix_R[i][j] = 0;
        }
    }

    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    noecho();

    print_vector(T, 2, 2);
    print_matrix(matrix_C, 2, 15);
    print_vector(A, 15, 2);
    print_matrix(matrix_R, 15, 15);
    print_cursor(0,0);

    while ((ch = getch())!= 'p' )
    {
        int activate_curs = 1;
        if(ch == KEY_RIGHT)
        {
            if (curs_x == 3)
            {
                curs_y = (curs_y + 1)%5;
                curs_x = 0;
            }
            else
            {
                curs_x += 1;
            }
        }
        if(ch == KEY_DOWN)
        {
            curs_y = (curs_y + 1)%5;
        }
        if(ch == KEY_LEFT)
        {
            if(curs_x == 0)
            {
                curs_x = 3;
                curs_y = curs_y == 0 ? 4 : (curs_y - 1);
            }
            else
            {
                curs_x -= 1;
            }
        }
         if(ch == KEY_UP)
        {
            curs_y = curs_y == 0 ? 4 : (curs_y - 1);
        }

        if (ch >= '0' && ch <= '9')
        {
            activate_curs = 0;
            if (curs_y == 0)
            {
                T[curs_x] = ch - '0';
            }
            else 
            {
                matrix_R[curs_x][curs_y - 1] = ch - '0';
            }
        }

        clear();
        print_vector(T, 2, 2);
        print_matrix(matrix_C, 2, 15);
        print_vector(A, 15, 2);
        print_matrix(matrix_R, 15, 15);
        if(activate_curs)
            print_cursor(curs_x, curs_y);
        refresh();
    }
    
    for (int i = 0; i < 4; ++i)
    {
        A[i] = T[i];
    }
    endwin();
    return 0;
    
} 
