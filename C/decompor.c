#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void decompor(int, int*, int*, int*);

int main(void){
	printf("Total segundos: ");
	int total;
	scanf("%d", &total);
	int horas;
	int mins;
	int segs;
	decompor(total, &horas, &mins, &segs);
	printf("%d:%d:%d\n", horas, mins, segs);
	return 0;
}

void decompor(int total, int *horas, int *mins, int *segs){
	*horas = total/3600;
	*mins = (total%3600)/60;
	*segs = total%60;
}
