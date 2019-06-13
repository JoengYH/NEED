#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_handler(int signo){

	printf("Recived!!\n");
}

int main(int argc, char *argv[]){
	sigset_t set;
	struct sigaction act;

	act_new.sa_handler = sig_handler;
	sigaction(SIGUSR1, &act_new, NULL);

	sigfillset(&set);
	sigdelset(&set, SIGUSR1);

	printf("PID : %d, waiting for only SIGUSR1\n",getpid());

	sigsuspend(&set);

	return 0;
}
