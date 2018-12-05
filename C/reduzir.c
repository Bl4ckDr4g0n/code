#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

void reduzir(int*,int*);
int mdc(int,int);

int main(void){
	printf("Enter numerator and denominator: ");
	int num, denom;
	scanf("%d %d", &num, &denom);
	reduzir(&num, &denom);
	printf("Reduced fraction: %d/%d\n", num, denom);
	return 0;
}

void reduzir(int *pnum, int *pdenom){
	int cm = mdc(*pnum, *pdenom);
	*pnum = (*pnum) / cm;
	*pdenom = *pdenom / cm;
}

int mdc(int a, int b){
	if (a==b) return a;
	else if(a > b){
		if(a % b == 0) return b;
		else return mdc(a - (a/b)*b, b);
	}
	else{
		if (b % a == 0) return a;
		else return mdc(b - (b/a)*a, a);
	}
}
