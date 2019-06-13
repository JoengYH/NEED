#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){
	double i;
	double j;
	char *bug = malloc(sizeof(int) * 100);
//	char bug1;

//	bug = &bug1;

	for(i=0; i<5; i++){
		printf("loop : %d : ",(int)i);
		j = i/2 +i;
		printf("\tj is %.1lf \n",j);
	}

	strcpy(bug,"hi");
	printf("bug is %s\n",bug);

	return 0;
}

