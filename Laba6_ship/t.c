#include <stdio.h>
#include <ncurses.h>
#include <pthread.h>
#include <malloc.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int count_game = 0;

typedef struct 
{
	int x_ship; 
	int y_ship;
	int x_ammunition[3]; 

	int condition_ammunition[3];


}great_data;

void* ship_move(void *thread_data){

	

	great_data *data = (great_data *)thread_data;

	while(count_game != 1){
		sleep(1);
		pthread_mutex_lock(&mutex);
		data->y_ship++;
		pthread_mutex_unlock(&mutex);
	}

	
}

void* strike(void *thread_data){
	great_data *data = (great_data *)thread_data;

	while(count_game != 1){
		usleep(20000);
		pthread_mutex_lock(&mutex);
		for(int i = 0; i < 3; i++){
			if(data->condition_ammunition[i] == 1){
				if(data->x_ammunition[i] != COLS){
					data->x_ammunition[i]++;
				}
				else{
					data->x_ammunition[i] = 9;
					data->condition_ammunition[i] = 0;
				}
				
				if((data->x_ammunition[i] == (COLS - 1))  && (LINES/2 == (data->y_ship - 1) || 
					LINES/2 == (data->y_ship - 2) || LINES/2 == data->y_ship )){
					
					count_game = 1;
				}


			}

			
		}
		
		
		pthread_mutex_unlock(&mutex);
	}
}

void* render(void *thread_data){

	char game_over[10] = {'G', 'a', 'm', 'e',' ', 'o', 'v', 'e', 'r', '!'};

	great_data *data = (great_data *)thread_data;

	
	while(count_game != 1){
		usleep(50000);
		pthread_mutex_lock(&mutex);
		clear();
		mvaddch(data->y_ship, COLS - 1, '#');
		mvaddch(data->y_ship - 1, COLS - 1, '#');
		mvaddch(data->y_ship - 2, COLS - 1, '#');
		if(data->y_ship == LINES){
			data->y_ship = 0;
			mvaddch(data->y_ship, COLS - 1, '#');
			mvaddch(LINES - 1, COLS - 1, '#');
			mvaddch(LINES - 2, COLS - 1, '#');
		}
		if(data->y_ship == 0){
			mvaddch(LINES - 1, COLS - 1, '#');

		}
		for(int i = LINES/2 - 1; i < LINES/2 + 2; i++){
		mvaddch(i, 10, '|');
		}
		for(int i = 0; i < 10; i++){
			mvaddch(LINES/2 - 1, i, '-');
			mvaddch(LINES/2 + 1, i, '-');
		}
		for(int i = 0; i < 3; i++){
			if(data->x_ammunition[i] != COLS){
				mvaddch(LINES/2, data->x_ammunition[i], '*');
			}

		}
		if(count_game == 1){
			mvaddstr(LINES/2, COLS/2, game_over);
		}
		refresh();
		pthread_mutex_unlock(&mutex);
	}

	
}

int main(){
	pthread_mutex_init(&mutex, NULL);
	int ch;


	initscr();
	curs_set(0);
	noecho();
	keypad(stdscr,TRUE);
	

	pthread_t threads_ship;
	pthread_t threads_render;
	pthread_t threads_strike;
	great_data threadData;

	threadData.x_ship = COLS - 1;
	threadData.y_ship = LINES/2;
	threadData.x_ammunition[0] = 9;
	threadData.x_ammunition[1] = 9;
	threadData.x_ammunition[2] = 9;
	threadData.condition_ammunition[0] = 0;
	threadData.condition_ammunition[1] = 0;
	threadData.condition_ammunition[2] = 0;


	pthread_create(&threads_ship, NULL, ship_move, &threadData);
	pthread_create(&threads_render, NULL, render, &threadData);
	pthread_create(&threads_strike, NULL, strike, &threadData);

	while(1){
		ch = getch();
		if(ch == ' '){
			for(int i = 0; i < 3; i++){
				if(threadData.condition_ammunition[i] != 1){
					threadData.condition_ammunition[i] = 1;
					break;
				}
			}
		}

		if(ch == 'q'){
			pthread_mutex_destroy(&mutex);
			
			refresh();
			endwin();
			return 0;
		}
	}

	pthread_join(threads_ship, NULL);
	pthread_join(threads_render, NULL);
	pthread_join(threads_strike, NULL);	




	

			

		
	

	
}