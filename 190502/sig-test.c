#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void (*old_func)(int);

void sig_handler(int signo){
	printf("\nCtrl + C를 누르셨죠?!\n");
	printf("한번 더 누르면 종료됩니다.\n");
	signal(SIGINT, SIG_DFL);
}

int main(void){
	old_func = signal(SIGINT, sig_handler);

	while(1){
		printf("signal halder registered!\n");
		sleep(1);
	}
	
	return(0);
}
