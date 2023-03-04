#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>
#include <string.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct{
	int x_muz, y_muz;
	int x_ship[5], y_ship[5];
	int x_charge[3], y_charge[3], mach, counter;
	int flag;
}struc;

static void* charge(void *data){

	int i;
	struc *rr = (struc*)data;

	while(rr->flag==0){

	usleep(50000);
	pthread_mutex_lock(&mutex);

	mvaddch(rr->x_charge[0], rr->y_charge[0], ' ');
	rr->y_charge[0]++;	
	if(rr->y_charge[0] == COLS) rr->counter--;
	if(rr->y_charge[0] < COLS) mvaddch(rr->x_charge[0], rr->y_charge[0], '*');
	refresh();

	mvaddch(rr->x_charge[1], rr->y_charge[1], ' ');
	rr->y_charge[1]++;	
	if(rr->y_charge[1] == COLS) rr->counter--;
	if(rr->y_charge[1] < COLS) mvaddch(rr->x_charge[1], rr->y_charge[1], '*');
	refresh();

	mvaddch(rr->x_charge[2], rr->y_charge[2], ' ');
	rr->y_charge[2]++;	
	if(rr->y_charge[2] == COLS) rr->counter--;
	if(rr->y_charge[2] < COLS) mvaddch(rr->x_charge[2], rr->y_charge[2], '*');
	refresh();

	pthread_mutex_unlock(&mutex);
	}
}

static void* ship(void *data) 
{
	int i;
	struc *rr = (struc*)data;
	
	while(rr->flag == 0){

	usleep(50000);
	pthread_mutex_lock(&mutex);

	mvaddch(rr->x_ship[0], rr->y_ship[0], ' ');

	rr->x_ship[0]--;
	if(rr->x_ship[0] == LINES/3) rr->x_ship[0] = rr->x_ship[0] * 2 - 1;
	mvaddch(rr->x_ship[0], rr->y_ship[i], '#');
	refresh();

	rr->x_ship[1]--;
	if(rr->x_ship[1] == LINES/3) rr->x_ship[1] = rr->x_ship[1] * 2 - 1;
	mvaddch(rr->x_ship[1], rr->y_ship[1], '#');
	refresh();

	rr->x_ship[2]--;
	if(rr->x_ship[2] == LINES/3) rr->x_ship[2] = rr->x_ship[2] * 2 - 1;
	mvaddch(rr->x_ship[2], rr->y_ship[2], '#');
	refresh();

	rr->x_ship[3]--;
	if(rr->x_ship[3] == LINES/3) rr->x_ship[3] = rr->x_ship[3] * 2 - 1;
	mvaddch(rr->x_ship[3], rr->y_ship[3], '#');
	refresh();

	rr->x_ship[4]--;
	if(rr->x_ship[4] == LINES/3) rr->x_ship[4] = rr->x_ship[4] * 2 - 1;
	mvaddch(rr->x_ship[4], rr->y_ship[4], '#');
	refresh();
		
	pthread_mutex_unlock(&mutex);
	}
}


static void* account(void *data) {
int i, j;
struc *rr = (struc*)data;

while(rr->flag==0){

	usleep(50000);
	pthread_mutex_lock(&mutex);
	
	for(i = 0; i < 3; i++)
		for(j = 0; j < 5; j++)
			if((rr->x_charge[i] == rr->x_ship[j]) && (rr->y_charge[i] == rr->y_ship[j])) rr->flag++;

		pthread_mutex_unlock(&mutex);
	}
}

int charge_create(void *data) {

struc *rr = (struc*)data;

pthread_mutex_lock(&mutex);

	if(rr->counter != 3) {
		rr->x_charge[rr->mach % 3] = LINES/2;
		rr->y_charge[rr->mach % 3] = 4;
		rr->mach++;
		rr->counter++;
	}

pthread_mutex_unlock(&mutex);
return 0;
}

int main(){

	int i, ch;
	struc a;
	pthread_t x, y,  acc;

	initscr();
	noecho();

	a.x_muz = LINES/2;
	a.y_muz = 3;

	a.mach = 0;
	a.counter = 0;
	a.flag = 0;

	for(i = 0; i < 5; i++){
		a.x_ship[i] = 2*LINES/3  - i - 1;
		a.y_ship[i] = COLS - 1;
	}

	keypad(stdscr, TRUE);
	curs_set(0);
	clear();

	halfdelay(1);

	pthread_create(&(y), NULL, charge, &a);
	pthread_create(&( acc), NULL, account, &a);
	pthread_create(&(x), NULL, ship, &a);

	while((ch = getch()) && a.flag == 0){

		if (ch == ' ') charge_create(&a);

		int n;
		
		pthread_mutex_lock(&mutex);

		for(n = 0; n <= COLS; n++){
			mvaddch(LINES/3, n, '+');
			mvaddch(2*LINES/3, n, '+');
		}
		
		pthread_mutex_unlock(&mutex);

		mvaddch(a.x_muz, a.y_muz, '0');
		mvaddch(a.x_muz, a.y_muz-1, '#');
		mvaddch(a.x_muz, a.y_muz-2, '#');
		mvaddch(a.x_muz, a.y_muz-3, '#');
		mvaddch(a.x_muz-1, a.y_muz-1, '#');
		mvaddch(a.x_muz-1, a.y_muz-2, '#');
		mvaddch(a.x_muz-1, a.y_muz-3, '#');
		mvaddch(a.x_muz+1, a.y_muz-1, '#');
		mvaddch(a.x_muz+1, a.y_muz-2, '#');
		mvaddch(a.x_muz+1, a.y_muz-3, '#');
		refresh();
			
	}

	pthread_join(y, NULL);
	pthread_join(acc, NULL);
	pthread_join(x, NULL);

	if(a.flag == 1){
		clear();
		mvprintw(LINES/2, (COLS-15)/2, "YOU kill them! Clic 'ENTER' for Exit");
		while((ch = getch()) == EOF);
	}

	endwin();
	return 0;
	}