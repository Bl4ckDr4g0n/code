#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

unsigned long power(long, int);

int main(void){
	long base = 1;
	int expy = 0;
	printf("Enter base: ");
	scanf("%ld", &base);
	printf("Enter exponent: ");
	scanf("%d", &expy);
	printf("Res: %lu\n", power(base, expy));
	printf("Ul: %lu\n", sizeof(unsigned long));
	return 0;
}

unsigned long power(long base, int expy){
	if(expy == 1) {
		printf("Returning base\n");
		return base;
	}
	if(expy == 0) {
		printf("Returning 1\n");
		return 1;
	}
	unsigned long res = power(base, expy/2);
	res *= res;
	if(expy % 2 == 1) res *= base;
	return res;
}
