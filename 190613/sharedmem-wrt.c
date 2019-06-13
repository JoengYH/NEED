#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY_NUM 1720963
#define MEM_SIZE 1024

int main(void){
	int shm_id;
	void *shm_addr;
	int count = 0;

	if(-1 == (shm_id = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT | 0666))) {
		perror("shmget() error");
		return -1;
	}

	if((void *)-1 == (shm_addr = shmat(shm_id, (void *)0, 0))) {
		perror("shmat() error");
		return -1;
	}

	while(1){
		sprintf((char *)shm_addr, "i want to go home");

		sleep(1);
	}
	return 0;
}
