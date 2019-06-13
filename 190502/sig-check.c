#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main(void){
	sigset_t set;

	sigemptyset(&set); //sigset을 초기화
	sigaddset(&set, SIGINT);

	switch(sigismember(&set, SIGINT)){
		case 1 : printf("SIGINT는 포함되어 있습니다.\n");
				 break;
		case 0 : printf("SIGINT는 없습니다.\n");
				 break;
		default : printf("sigismember() 호출을 실패했습니다.\n");
	}
	switch(sigismember(&set, SIGSYS)){
		case 1 : printf("SIGSYS는 포함되어 있습니다.\n");
				 break;
		case 0 : printf("SIGSYS는 없습니다.\n");
				 break;
		default : printf("sigismember() 호출을 실패했습니다.\n");
	}

	exit(EXIT_SUCCESS);
}
