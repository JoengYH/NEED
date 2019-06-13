#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	pid_t pid;
	int i;

	for(i = 0;i<5;i++){
		if((pid = fork())<0){
			printf("fork error");
			exit(EXIT_SUCCESS);
		} else if(pid == 0){
			printf("bye from child %d : %d\n", i, getpid());
			exit(EXIT_SUCCESS);
		}
	}

	sleep(60);
	printf("bye from parent\n");
	exit(EXIT_SUCCESS);
}
