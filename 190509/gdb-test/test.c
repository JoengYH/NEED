#include <stdio.h>
#include <string.h>

void main(int argc, char** argv){
	char buf[16];
	strcpy(buf, argv[1]);
	printf("%s\n",buf);
}
