#include <stdlib.h>
#include <stdio.h>
#include "cal.h"

int sum(double a, double b);
int sub(double a,double b);
double mul(double a,double b);
double nanu(double a,double b);

int main(void){
	double x = 0;
	double y = 0;
	char z = 0;

	printf("Input Operator:");
	scanf("%c",&z);
	printf("Input 'x':");
	scanf("%lf",&x);
	printf("Input 'y':");
	scanf("%lf",&y);

	double rus = 0;
	switch(z){
		case'+':
			rus = sum(x,y);
			break;
		case'-':
			rus = sub(x,y);
			break;
		case'*':
			rus = mul(x,y);
			break;
		case'/':
			rus = nanu(x,y);
			break;
	}

	printf("result:%lf\n",rus);

	return 0;
}
