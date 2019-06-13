#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int num = 0;

void sigint_handler(int signo){
	printf("알람 발생 %d!!\n",num++);
	alarm(1);
}

int main(void){
	signal(SIGALRM, sigint_handler);
	alarm(1);

	while(1){
	}

	return 0;
}
