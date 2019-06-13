#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signo){
	int ndx;

	printf("\nCtrl-C를 누르셨군요?!\n");
	printf("10초간 대기하겠습니다. 이떄 Ctrl-Z키를 눌러 주세요.\n");

	for(ndx = 10; 0 < ndx; ndx--){ //10초후에 핸들러 종료
		printf("%d 초 남았습니다\n", ndx);
		sleep(1);
	}
}

int main(void){
	struct sigaction act;

	act.sa_handler = sigint_handler; //시그널 핸들러 지정
	sigfillset(&act.sa_mask);

	sigaction(SIGINT, &act, NULL);

	while(1){
		printf("Registered for SIGINT\n");
		sleep(1);
	}

	return(0);
}
