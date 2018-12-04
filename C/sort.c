#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

void countingSort(int[], int, int);
void quickSort(int[], int, int);
void insertionSort(int[], int);
void selectionSort(int[], int);
void bucketSort(int[], int, int, int);
int partition(int[], int, int);

int main(void){
	int arr[16];
	srand(time(NULL));
	for(int j = 0; j < 5; j++){
		for(int i = 0; i < 16; i++){
			int num = rand()/(RAND_MAX/50 + 1);
			printf("%d | ", num);
			arr[i] = num;
		}
		switch(j){
			case 0:
				quickSort(arr, 0, 16);
				break;
			case 1:
				insertionSort(arr, 16);
				break;
			case 2:
				selectionSort(arr, 16);
				break;
			case 3:
				bucketSort(arr, 16, 51, 10);
				break;
			case 4:
				countingSort(arr, 16, 51);
				break;
		}
		printf("\n%c[38;5;10m%c[48;5;232m", 0x1B, 0x1B);
		for(int i = 0; i < 16; i++) printf("%d | ", arr[i]);
		printf("%c[0m\n\n", 0x1B);
	}
	printf("Done!\n");
	return 0;
	
}

void quickSort(int arr[], int start, int end){
	if(end - start <= 1){
		return;
	}

	int k = partition(arr, start, end);

	quickSort(arr, start, k);
	quickSort(arr, k+1, end);
}

int partition(int arr[], int start, int end){
	int lowI = start, highI = end-1;
	int pivot = arr[end-1];
	while(lowI < highI){
		if(arr[highI-1] >= pivot){
			arr[highI] = arr[highI-1];
			highI--;
		}
		else{
			int temp = arr[highI-1];
			arr[highI-1] = arr[lowI];
			arr[lowI] = temp;
			lowI++;
		}
	}
	arr[highI] = pivot;

	return highI;
}

void insertionSort(int arr[], int size){
	for(int i = 1; i < size; i++){
		int j = 0;
		while(arr[j] < arr[i]) j++;
		int k = i-1, temp = arr[i];
		while(k >= j){
			arr[k+1] = arr[k];
			k--;
		}
		arr[k+1] = temp;
	}
}

void selectionSort(int arr[], int size){
	for(int i = 0; i < size; i++){
		int mi = i;
		for(int k = i; k < size; k++){
			if(arr[k] < arr[mi]) mi = k;
		}
		if(mi != i){
			int temp = arr[i];
			arr[i] = arr[mi];
			arr[mi] = temp;
		}
	}
}

void bucketSort(int arr[], int size, int max, int n){
	int buckets[n][size];
	int index[n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < size; j++){
			buckets[i][j] = 0;
		}
		index[i] = 0;
	}
	for(int i = 0; i < size; i++){
		int indx = arr[i] / (max/n);
		buckets[indx][index[indx]] = arr[i];
		index[indx]++;
	}
	int i = 0;
	int k = 0, l = 0;
	while(i < size && l < n){
		if(buckets[l][k] == 0 || k >= size){
			k = 0;
			l++;
		}
		else{
			arr[i] = buckets[l][k];
			i++;
			k++;
		}
	}
	insertionSort(arr, size);		
}

void countingSort(int arr[], int size, int max){
	int count[max];
	for(int i = 0; i < max; i++){
		count[i] = 0;
	}
	for(int i = 0; i < size; i++){
		count[arr[i]] += 1;
	}
	int i = 0, j = 0;
	while(i < size && j < max){
		if(count[j] == 0){
			j++;
		}
		else{
			arr[i] = j;
			count[j] -= 1;
			i++;
		}
	}
}
