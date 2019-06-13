#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCK_PATH "echo_socket"

typedef struct{
	int type; //senf or receive
	int operation; // '+' or '-' or '*' or '/'
	double value[2];
} msg;

msg.leng = sizeof(msg.value);

int main(void){
	msg m;
	int s, s2, len;
	unsigned t;
	struct sockaddr_un local, remote;
	char str[100];
	int count = 1;

	if((s = socket(AF_UNIX, SOCK_STREAM, 0)) == -1){
		perror("socket");
		exit(1);
	}

	local.sun_family = AF_UNIX;
	strcpy(local.sun_path, SOCK_PATH);
	unlink(local.sun_path);
	len = strlen(local.sun_path) + sizeof(local.sun_family);

	if(bind(s, (struct sockaddr *)&local, len) == -1){
		perror("bind");
		exit(1);
	}

	if(listen(s, 5) == -1){
		perror("listen");
		exit(1);
	}

	for(;;){
		int done, n;
		printf("Waiting for a connection...\n");
		t = sizeof(remote);

		if((s2 = accept(s, (struct sockaddr *)&remote ,&t)) == -1) {
			perror("accept");
			exit(1);
		}

		printf("[%d]Connected.\n",count);

		count++;
		done = 0;

		do{
			n = recv(s2, &m, sizeof(msg), 0);
			if(n <= 0){
				if(n < 0) perror("recv");
				done = 1;
			}
				

			if(!done){
				if(m.type == 1){
					switch(m.operation){
						case 1:
							m.value[0] = m.value[0] + m.value[1];
						case 2:
							m.value[0] = m.value[0] - m.value[1];
						case 3:
							m.value[0] = m.value[0] * m.value[1];
						case 4:
							m.value[0] = m.value[0] / m.value[1];
					}
					m.type = 2;
				}
				if(send(s2, m, n, 0) < 0) {
					perror("send");
					done = 1;
				}
			}
		}while(!done);


		close(s2);
	}

	return 0;
}
