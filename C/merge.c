#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

void fillArray(int [], int, int);
void printArray(int [], int);
void mergeSort(int[], int, int);
void merge(int[], int, int, int);

int main(void){
	int N;
	printf("Enter array size: ");
	scanf("%d", &N);
	int arr[N];
	fillArray(arr, N, 100);
	printArray(arr, N);
	mergeSort(arr, 0, N-1);
	printf("%c[92m%c[40m", 0x1B, 0x1B);
	printArray(arr, N);
	printf("%c[0m\n", 0x1B);
	return 0;
}

void fillArray(int arr[], int size, int max){
	for(int i = 0; i < size; i++)
		arr[i] = rand()/(RAND_MAX/max + 1);
}

void printArray(int arr[], int size){
	for(int i = 0; i < size; i++)
		printf("%d | ", arr[i]);
	printf("\n");
}

void mergeSort(int arr[], int l, int r){
	if (l < r){
		int m = l + (r-l)/2;

		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

void merge(int arr[], int l, int m, int r){
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(i = 0; i < n1; i++)
		L[i] = arr[l+i];
	for(j = 0; i < n2; i++)
		R[i] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;
	while(i < n1 && j < n2){
		if(L[i] <= R[j]){
			arr[k] = L[i];
			i++;
		}
		else{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while ( i < n1 ) {
		arr[k] = L[i];
		i++;
		j++;
	}

	while ( j < n2 ) {
		arr[k] = R[j];
		j++;
		k++;
	}
}	
