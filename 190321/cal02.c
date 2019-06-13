#include <stdio.h>
#include <stdlib.h>

int sum(double a, double b){
	int res = 0;
	res = a+b;

	return res;
}
int sub(double a,double b){
	int res = 0;
	res = a-b;

	 return res;
}
double mul(double a,double b){
	double res = 0;
	res  = a*b;

	return res;
}

double nanu(double a,double b){
	double res = 0;
	res = a/b;

	return res;
}

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
