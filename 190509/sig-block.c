#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(void){
	sigset_t set;
	int ndx;

	sigemptyset(&set);
	sigaddset(&set, SIGINT);
	sigprocmask(SIG_BLOCK, &set, NULL);

	for(ndx = 3; 0 < ndx; ndx--) {
		printf("count down : %d\n", ndx);
		sleep(1);
	}

	printf("Ctrl-c에 대한 블락을 해제합니다.\n");
	sigprocmask(SIG_UNBLOCK, &set, NULL);
	printf("카운트 다운중에 Ctrl-c키를 누르셨다면, 이 문장도 출역이 안됩니다.\n");

	while(1);

	return 0;
}
