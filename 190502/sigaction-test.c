#include <stdio.h>
#include <signal.h>
#include <unistd.h>

struct sigaction act_new;
struct sigaction act_old;

void sigint_handler(int signo){
	printf("\nCtrl-C를 누르셨군요?!\n");
	printf("한번 더 누르면 종료됩니다.\n");
	sigaction(SIGINT, &act_old, NULL);
}

int main(void){

	act_new.sa_handler = sigint_handler; //시그널 핸들러 지정
	sigemptyset(&act_new.sa_mask);		 //시그널 처리 중 블럭될 시그널은 없음

	//SIGINT를 지정하면서 act_old에 이전 정보를 구합니다.

	sigaction(SIGINT, &act_new, &act_old);
	
	while(1){
		printf("SIGACTION\n");
		sleep(1);
	}

	return(0);
}

