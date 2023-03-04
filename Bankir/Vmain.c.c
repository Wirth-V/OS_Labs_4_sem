#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

void
revrite_and_printMatrix(int yUser, char MatrixT[1][4], char MatrixC[4][4], int xUser, char Number, int MatrixTint[1][4],
                        int MatrixCint[4][4], int Numberint, int MatrixCount) {

    if (yUser - LINES / 2 == -5) {
        if (MatrixCount == 0) {
            MatrixT[0][(xUser - COLS / 2 + 26) / 2] = Number;
            mvaddch(yUser, xUser, Number);
            MatrixTint[0][(xUser - COLS / 2 + 26) / 2] = Numberint;
            move (yUser, xUser);
        }
    } else {
        {
            MatrixC[yUser - LINES / 2 + 10][(xUser - COLS / 2 + 26) / 2] = Number;
            mvaddch(yUser, xUser, Number);
            MatrixCint[yUser - LINES / 2 + 10][(xUser - COLS / 2 + 26) / 2] = Numberint;
            move (yUser, xUser);
        }
    }
}

void fill_MatrixA_fromT(char MatrixA[1][4], int MatrixAint[1][4], int MatrixTint[1][4]) {
    for (int i = 0; i < 4; i++) {
        MatrixAint[0][i] = MatrixTint[0][i];
        MatrixA[0][i] = (char) (MatrixAint[0][i] + '0');
    }
}

void MatrixInt_into_Matrix1x4(int Matrixint[1][4], char Matrix[1][4]) {
    for (int i = 0; i < 4; i++) {
        Matrix[0][i] = (char) (Matrixint[0][i] + '0');
    }
}

void MatrixInt_into_Matrix4x4(int Matrixint[4][4], char Matrix[4][4]) {
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {

            Matrix[j][i] = (char) (Matrixint[j][i] + '0');
        }
    }
}

void check_null(int MatrixCint[4][4], int MatrixRint[4][4], int numberRow, int matrixAint[1][4]) {
    int coountnull = 0;
    for (int i = 0; i < 4; i++) {
        coountnull = coountnull + MatrixCint[numberRow][i];

    }
    if (coountnull == 0) {
        for (int i = 0; i < 4; i++) {
            matrixAint[0][i] += MatrixRint[numberRow][i];
            MatrixRint[numberRow][i] = 0;
        }
    }
}

int main() {
    initscr();
    int MatrixCount = 0;
    int ch;
    int y = LINES / 2 - 9;
    int x = (COLS / 2) - 20;
    int rows = 0;
    int coordMatrixA[1][8];
    char MatrixA[1][4] = {'0', '0', '0', '0'
    };
    int MatrixAint[1][4] = {0, 0, 0, 0};
    int coordMatrixT[1][8];
    char MatrixT[1][4] = {'0', '0', '0', '0'
    };
    int MatrixTint[1][4] = {0, 0, 0, 0};
    int coordMatrixR[4][8];
    char MatrixR[4][4] = {'0', '0', '0', '0',
                          '0', '0', '0', '0',
                          '0', '0', '0', '0',
                          '0', '0', '0', '0'
    };
    int MatrixRint[4][4] = {0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0
    };
    int coordMatrixC[4][8];
    char MatrixC[4][4] = {'0', '0', '0', '0',
                          '0', '0', '0', '0',
                          '0', '0', '0', '0',
                          '0', '0', '0', '0'

    };
    int MatrixCint[4][4] = {0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0,
                            0, 0, 0, 0
    };

    mvprintw(y - 1, (COLS / 2) - 30, "R=");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++)
            if (j % 2 == 0) {
                coordMatrixC[i][j] = y - 1 + i;
            } else {
                coordMatrixC[i][j] = x + 1 - j;
            }
    }

    for (int i = 0; i < 4; i++) {
        rows = 4;
        for (int j = 0; j < 8; j = j + 2) {
            rows = rows - 1;
            mvaddch(coordMatrixC[i][j], coordMatrixC[i][j + 1], MatrixC[i][rows]);
        }
    }

    y = y + 5;
    mvprintw(y - 1, (COLS / 2) - 30, "T=");
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 8; j++)
            if (j % 2 == 0) {
                coordMatrixT[i][j] = y - 1 + i;
            } else {
                coordMatrixT[i][j] = x + 1 - j;
            }
    }

    for (int i = 0; i < 1; i++) {
        rows = 4;
        for (int j = 0; j < 8; j = j + 2) {
            rows = rows - 1;
            mvaddch(coordMatrixT[i][j], coordMatrixT[i][j + 1], MatrixT[i][rows]);
        }
    }

    y = y + 2;
    mvprintw(y - 1, (COLS / 2) - 30, "C=");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++)
            if (j % 2 == 0) {
                coordMatrixR[i][j] = y - 1 + i;
            } else {
                coordMatrixR[i][j] = x + 1 - j;
            }
    }
    for (int i = 0; i < 4; i++) {
        rows = 4;
        for (int j = 0; j < 8; j = j + 2) {
            rows = rows - 1;
            mvaddch(coordMatrixR[i][j], coordMatrixR[i][j + 1], MatrixR[i][rows]);
        }
    }

    y = y + 5;
    mvprintw(y - 1, (COLS / 2) - 30, "A=");
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 8; j++)
            if (j % 2 == 0) {
                coordMatrixA[i][j] = y - 1 + i;
            } else {
                coordMatrixA[i][j] = x + 1 - j;
            }
    }
    for (int i = 0; i < 1; i++) {
        rows = 4;
        for (int j = 0; j < 8; j = j + 2) {
            rows = rows - 1;
            mvaddch(coordMatrixA[i][j], coordMatrixA[i][j + 1], MatrixA[i][rows]);
        }
    }
    int yUser = LINES / 2 - 10;
    int xUser = (COLS / 2) - 20;
    move (yUser, xUser);
    refresh();
    noecho();
    keypad(stdscr, TRUE);
    while ((ch = getch()) != 'i') {
        switch (ch) {
            case KEY_UP:
                if (yUser == (LINES / 2 - 10)) {
                    yUser = LINES / 2 - 4;
                }
                yUser = yUser - 1;
                if (yUser == LINES / 2 - 6) {
                    yUser = yUser - 1;
                }
                move (yUser, xUser);
                break;

            case KEY_DOWN:
                if (yUser == (LINES / 2 - 5)) {
                    yUser = LINES / 2 - 11;
                }

                yUser = yUser + 1;
                if (yUser == LINES / 2 - 6) {
                    yUser = yUser + 1;
                }
                move (yUser, xUser);
                break;

            case KEY_LEFT:
                if (xUser == (COLS / 2) - 26) {
                    xUser = (COLS / 2) - 18;
                }
                xUser = xUser - 2;
                move (yUser, xUser);

                break;
            case KEY_RIGHT:
                if (xUser == (COLS / 2) - 20) {
                    xUser = (COLS / 2) - 28;
                }
                xUser = xUser + 2;
                move (yUser, xUser);
                break;

            case '0':
                revrite_and_printMatrix(yUser, MatrixT, MatrixC, xUser, '0', MatrixTint, MatrixCint, 0, MatrixCount);
                break;
            case '1':
                revrite_and_printMatrix(yUser, MatrixT, MatrixC, xUser, '1', MatrixTint, MatrixCint, 1, MatrixCount);
                break;
            case '2':
                revrite_and_printMatrix(yUser, MatrixT, MatrixC, xUser, '2', MatrixTint, MatrixCint, 2, MatrixCount);
                break;
            case '3':
                revrite_and_printMatrix(yUser, MatrixT, MatrixC, xUser, '3', MatrixTint, MatrixCint, 3, MatrixCount);
                break;
            case '4':
                revrite_and_printMatrix(yUser, MatrixT, MatrixC, xUser, '4', MatrixTint, MatrixCint, 4, MatrixCount);
                break;
            case '5':
                revrite_and_printMatrix(yUser, MatrixT, MatrixC, xUser, '5', MatrixTint, MatrixCint, 5, MatrixCount);
                break;
            case '6':
                revrite_and_printMatrix(yUser, MatrixT, MatrixC, xUser, '6', MatrixTint, MatrixCint, 6, MatrixCount);
                break;
            case '7':
                revrite_and_printMatrix(yUser, MatrixT, MatrixC, xUser, '7', MatrixTint, MatrixCint, 7, MatrixCount);
                break;
            case '8':
                revrite_and_printMatrix(yUser, MatrixT, MatrixC, xUser, '8', MatrixTint, MatrixCint, 8, MatrixCount);
                break;
            case '9':
                revrite_and_printMatrix(yUser, MatrixT, MatrixC, xUser, '9', MatrixTint, MatrixCint, 9, MatrixCount);
                break;

            case 'e':
                mvprintw(LINES / 2 - 9, (COLS / 2) + 10, "                                                             ");
                mvprintw(LINES / 2 - 9, (COLS / 2) + 10, "*Sounds of a running program* please wait...");
                if (MatrixCount == 0) {
                    fill_MatrixA_fromT(MatrixA, MatrixAint, MatrixTint);
                    MatrixCount = 1;
                }

                for (int i = 0; i < 1; i++) {
                    rows = 4;
                    for (int j = 0; j < 8; j = j + 2) {
                        rows = rows - 1;
                        mvaddch(coordMatrixA[i][j], coordMatrixA[i][j + 1], MatrixA[i][rows]);
                        refresh();
                    }
                }

                int CountMove1 = 0;
                int CountMove2 = 0;
                int CountMove3 = 0;
                int CountMove4 = 0;

                sleep(2);
                if (((MatrixAint[0][0] < MatrixCint[0][0]) ||
                     (MatrixAint[0][1] < MatrixCint[0][1]) ||
                     (MatrixAint[0][2] < MatrixCint[0][2]) ||
                     (MatrixAint[0][3] < MatrixCint[0][3]))
                    || CountMove1 == 1) {

                } else {
                    for (int i = 0; i < 4; i++) {
                        MatrixRint[0][i] += MatrixCint[0][i];
                    }

                    for (int i = 0; i < 4; i++) {
                        MatrixAint[0][i] = MatrixAint[0][i] - MatrixCint[0][i];
                    }
                    CountMove1 = 1;

                    check_null(MatrixCint, MatrixRint, 0, MatrixAint);

                    MatrixInt_into_Matrix1x4(MatrixAint, MatrixA);
                    for (int i = 0; i < 1; i++) {
                        rows = 4;
                        for (int j = 0; j < 8; j = j + 2) {
                            rows = rows - 1;
                            mvaddch(coordMatrixA[i][j], coordMatrixA[i][j + 1], MatrixA[i][rows]);
                        }
                    }
                    MatrixInt_into_Matrix4x4(MatrixRint, MatrixR);
                    for (int i = 0; i < 4; i++) {
                        rows = 4;
                        for (int j = 0; j < 8; j = j + 2) {
                            rows = rows - 1;
                            mvaddch(coordMatrixR[i][j], coordMatrixR[i][j + 1], MatrixR[i][rows]);
                        }
                    }

                    MatrixCint[0][0] = 0;
                    MatrixCint[0][1] = 0;
                    MatrixCint[0][2] = 0;
                    MatrixCint[0][3] = 0;

                    MatrixInt_into_Matrix4x4(MatrixCint, MatrixC);
                    for (int i = 0; i < 4; i++) {
                        rows = 4;
                        for (int j = 0; j < 8; j = j + 2) {
                            rows = rows - 1;
                            mvaddch(coordMatrixC[i][j], coordMatrixC[i][j + 1], MatrixC[i][rows]);
                        }
                    }
                    refresh();
                }

                //2
                sleep(2);
                if ((MatrixAint[0][0] < MatrixCint[1][0] ||
                     MatrixAint[0][1] < MatrixCint[1][1] ||
                     MatrixAint[0][2] < MatrixCint[1][2] ||
                     MatrixAint[0][3] < MatrixCint[1][3])
                    || CountMove2 == 1) {

                } else {

                    for (int i = 0; i < 4; i++) {
                        MatrixRint[1][i] += MatrixCint[1][i];
                    }

                    for (int i = 0; i < 4; i++) {
                        MatrixAint[0][i] = MatrixAint[0][i] - MatrixCint[1][i];
                    }
                    CountMove2 = 1;

                    check_null(MatrixCint, MatrixRint, 1, MatrixAint);

                    MatrixInt_into_Matrix1x4(MatrixAint, MatrixA);
                    for (int i = 0; i < 1; i++) {
                        rows = 4;
                        for (int j = 0; j < 8; j = j + 2) {
                            rows = rows - 1;
                            mvaddch(coordMatrixA[i][j], coordMatrixA[i][j + 1], MatrixA[i][rows]);
                        }
                    }
                    MatrixInt_into_Matrix4x4(MatrixRint, MatrixR);
                    for (int i = 0; i < 4; i++) {
                        rows = 4;
                        for (int j = 0; j < 8; j = j + 2) {
                            rows = rows - 1;
                            mvaddch(coordMatrixR[i][j], coordMatrixR[i][j + 1], MatrixR[i][rows]);
                        }
                    }

                    MatrixCint[1][0] = 0;
                    MatrixCint[1][1] = 0;
                    MatrixCint[1][2] = 0;
                    MatrixCint[1][3] = 0;
                    MatrixInt_into_Matrix4x4(MatrixCint, MatrixC);
                    for (int i = 0; i < 4; i++) {
                        rows = 4;
                        for (int j = 0; j < 8; j = j + 2) {
                            rows = rows - 1;
                            mvaddch(coordMatrixC[i][j], coordMatrixC[i][j + 1], MatrixC[i][rows]);
                        }
                    }
                    refresh();
                }
//                    //3
                sleep(2);
                if ((MatrixAint[0][0] < MatrixCint[2][0] ||
                     MatrixAint[0][1] < MatrixCint[2][1] ||
                     MatrixAint[0][2] < MatrixCint[2][2] ||
                     MatrixAint[0][3] < MatrixCint[2][3])
                    || CountMove3 == 1) {
                } else {

                    for (int i = 0; i < 4; i++) {
                        MatrixRint[2][i] += MatrixCint[2][i];
                    }

                    for (int i = 0; i < 4; i++) {
                        MatrixAint[0][i] = MatrixAint[0][i] - MatrixCint[2][i];
                    }
                    CountMove3 = 1;

                    check_null(MatrixCint, MatrixRint, 2, MatrixAint);

                    MatrixInt_into_Matrix1x4(MatrixAint, MatrixA);
                    for (int i = 0; i < 1; i++) {
                        rows = 4;
                        for (int j = 0; j < 8; j = j + 2) {
                            rows = rows - 1;
                            mvaddch(coordMatrixA[i][j], coordMatrixA[i][j + 1], MatrixA[i][rows]);
                        }
                    }
                    MatrixInt_into_Matrix4x4(MatrixRint, MatrixR);
                    for (int i = 0; i < 4; i++) {
                        rows = 4;
                        for (int j = 0; j < 8; j = j + 2) {
                            rows = rows - 1;
                            mvaddch(coordMatrixR[i][j], coordMatrixR[i][j + 1], MatrixR[i][rows]);
                        }
                    }

                    MatrixCint[2][0] = 0;
                    MatrixCint[2][1] = 0;
                    MatrixCint[2][2] = 0;
                    MatrixCint[2][3] = 0;

                    MatrixInt_into_Matrix4x4(MatrixCint, MatrixC);
                    for (int i = 0; i < 4; i++) {
                        rows = 4;
                        for (int j = 0; j < 8; j = j + 2) {
                            rows = rows - 1;
                            mvaddch(coordMatrixC[i][j], coordMatrixC[i][j + 1], MatrixC[i][rows]);
                        }
                    }
                    refresh();
                }
                sleep(2);
//                    //4
                if ((MatrixAint[0][0] < MatrixCint[3][0] ||
                     MatrixAint[0][1] < MatrixCint[3][1] ||
                     MatrixAint[0][2] < MatrixCint[3][2] ||
                     MatrixAint[0][3] < MatrixCint[3][3])
                    || CountMove4 == 1) {
                } else {

                    for (int i = 0; i < 4; i++) {
                        MatrixRint[3][i] += MatrixCint[3][i];
                    }

                    for (int i = 0; i < 4; i++) {
                        MatrixAint[0][i] = MatrixAint[0][i] - MatrixCint[3][i];
                    }

                    CountMove4 = 1;

                    check_null(MatrixCint, MatrixRint, 3, MatrixAint);

                    MatrixInt_into_Matrix1x4(MatrixAint, MatrixA);
                    for (int i = 0; i < 1; i++) {
                        rows = 4;
                        for (int j = 0; j < 8; j = j + 2) {
                            rows = rows - 1;
                            mvaddch(coordMatrixA[i][j], coordMatrixA[i][j + 1], MatrixA[i][rows]);
                        }
                    }
                    MatrixInt_into_Matrix4x4(MatrixRint, MatrixR);
                    for (int i = 0; i < 4; i++) {
                        rows = 4;
                        for (int j = 0; j < 8; j = j + 2) {
                            rows = rows - 1;
                            mvaddch(coordMatrixR[i][j], coordMatrixR[i][j + 1], MatrixR[i][rows]);
                        }
                    }
                    MatrixCint[3][0] = 0;
                    MatrixCint[3][1] = 0;
                    MatrixCint[3][2] = 0;
                    MatrixCint[3][3] = 0;

                    MatrixInt_into_Matrix4x4(MatrixCint, MatrixC);
                    for (int i = 0; i < 4; i++) {
                        rows = 4;
                        for (int j = 0; j < 8; j = j + 2) {
                            rows = rows - 1;
                            mvaddch(coordMatrixC[i][j], coordMatrixC[i][j + 1], MatrixC[i][rows]);
                        }
                    }

                    refresh();
                }
                    mvprintw(LINES / 2 - 9, (COLS / 2) + 10, "                                                             ");
                if (CountMove1 != 1 || CountMove2 != 1 || CountMove3 != 1 || CountMove4 != 1) {
                    mvprintw(LINES / 2 - 9, (COLS / 2) + 10, "Block");
                } else {
                    mvprintw(LINES / 2 - 9, (COLS / 2) + 10, "Non-block, press i to exit");
                }
                break;

            default:
                    mvprintw(LINES / 2 - 9, (COLS / 2) + 10, "                                                             ");
                    mvprintw(LINES / 2 - 9, (COLS / 2) + 10, "Press the keys 0-9, arrows, (e to start or i to exit)");
                break;
        }
    }
    endwin();
    return 0;
}