#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char buf[] = "write to stdout\n";
int main(void){
	pid_t pid;
	if (write(STDOUT_FILENO, buf, strlen(buf)) != strlen(buf)){
		printf("write error");
		exit(EXIT_SUCCESS);
	}
	printf("printf by %d : before fork\n",getpid());

	if((pid = fork())<0){
		perror("fork error");
	} else if(pid == 0){
		printf("printf by %d : hi from child!\n",getpid());
	} else {
		printf("printf by %d : hi from parent!\n",getpid());
	}

	printf("printf by %d : bye\n", getpid());
	exit(EXIT_SUCCESS);
}
