#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *t_func(void *data){
	int id;
	id = *((int *)data);
	printf("Thrread Start with %d\n", id);
	sleep(5);
	printf("THread end\n"):
}

int main(void){
	pthread_t p_thr;

