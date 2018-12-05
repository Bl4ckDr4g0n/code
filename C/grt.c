#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void){
	int max;
	int min;
	printf("Enter (inclusive) bounds: ");
	scanf("%d %d", &min, &max);
	if(max < min){
		printf("Incorrect bounds.\n");
		return -1;
	}
	int maxC = -3;
	int i;
	for(i = min; i <= max; i++){
		int j = 0;
		int temp = i;
		while(temp != 1){
			if(temp%2 == 0){
				temp /= 2;
			}
			else{
				temp = temp*3 + 1;
			}
			j++;
		}
		j++;
		if(j > maxC) maxC = j;
	}
	printf("%d %d %d\n", min, max, maxC);
	return 0;
}
