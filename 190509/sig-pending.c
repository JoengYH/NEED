#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void){
	sigset_t set;
	sigset_t pset;
	int ndx = 0;

	sigfillset(&set);
	sigprocmask(SIG_SETMASK, &set, NULL);

	while(1){
		printf("Count : %d\n", ndx++);
		sleep(1);
		if(0 == sigpending(&pset)){
			if(sigismember(&pset, SIGINT)){
				printf("Ctrl-C를 누르셨죠. 무한루프를 종료합니다.\n");
				break;
			}
		}
	}

	return 0;
}
