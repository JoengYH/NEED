#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int ncount;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* do_loop(void *data){
	int i;
	int random_time = rand() %5 +1;

	pthread_mutex_lock(&mutex);
	
	for(i=0; i<5; i++){
		printf("th_func1 : %d\n", ncount);
		ncount++;
		sleep(1);
	}
	pthread_mutex_unlock(&mutex);
}

void* do_loop2(void *data){
