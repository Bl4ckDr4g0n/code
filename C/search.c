#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int binary(int [], int, int);
int linear(int [], int, int);

int test[16] = {1, 2, 2, 3, 4, 7, 8,9,9, 12, 12, 13, 15, 18, 32, 52};

int main(void){
	for(int i = 0; i < 16; i++){
		printf("%c[3%dm%d ", 0x1B, i%8, test[i]);	
	}
	printf("%c[0m\n", 0x1B);
	int a, b;
	printf("Enter linear and binary search values: ");
	scanf("%d %d", &a, &b);
	printf("Binary search: %d | Linear search: %d\n", binary(test, 16, a), linear(test,16,b));
	return 0;
}

int binary(int arr[], int size, int val){
	int i = 0, j = size - 1;
	while(i < j){
		int k = i + (j-i)/2;
		if(arr[k] == val) return k;
		else if (arr[k] <= val){
			i = k+1;
		}
		else{
			j = k-1;
		}
	}
	if(arr[i] == val) return i; else return -1;
}

int linear(int arr[], int size, int val){
	arr[size] = val;
	int i = 0;
	while(arr[i] != val){
		i++;
	}
	if(i != size) return i; else return -1;
}
