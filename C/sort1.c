#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
<<<<<<< HEAD
#include <limits.h>

#define INF INT_MAX;

void mergeSort(int [], int, int);
void merge(int [], int, int, int);

int main(void){
	srand(time(NULL));
	int arr[11];
	for(int i = 0; i < 11; i++) arr[i] = rand()/(RAND_MAX/20 + 1);
	for(int i = 0; i < 11; i++) printf("%d | ", arr[i]);
	printf("\n");
	mergeSort(arr, 0, 10);
	for(int i = 0; i < 11; i++) printf("%d | ", arr[i]);
	printf("\n");
	return 0;
}

void mergeSort(int arr[], int b, int e){
	if(b < e){
		printf("Sub arrays: \n");
		printf("1st:\n");
		int p = b + (e-b)/2;
		for(int i = b; i <= p; i++) printf("%d | ", arr[i]);
		printf("2nd:\n");
		for(int i = p+1; i <= e; i++) printf("%d | ", arr[i]);
		printf("\n");
		mergeSort(arr, b, p);
		mergeSort(arr, p+1, e);
		merge(arr, b, p, e);
		printf("Result: \n");
		for(int i = b; i <= e; i++)printf("%d | ", arr[i]);
		printf("End --------\n\n");
	}
	else{
		return;
	}
}

void merge(int arr[], int b, int e, int q){
	int n1 = q - b + 1;
	int n2 = e - q;
	
	int arr1[n1+1];
	int arr2[n2+1];
	arr1[n1] = INT_MAX;
	arr2[n2] = INT_MAX;
	
	for(int i = 0; i < n1; i++){
		arr1[i] = arr[i+b];
	}
	for(int i = 0; i < n2; i++){
		arr2[i] = arr[i+q+1];
	}
	
	printf("Merging: \n");
	for(int i = 0; i < n1; i++) printf("%d | ", arr1[i]);
	printf("With: \n");
	for(int i = 0; i < n2; i++) printf("%d | ", arr2[i]);
	printf("\n");
	
	for(int i = b, j = 0, k = 0; i <= e; i++){
		if(arr1[j] <= arr2[k]){
			arr[i] = arr1[j++];
		}
		else{
			arr[i] = arr2[k++];
		}
	}
}

=======

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
>>>>>>> 2551ff57b98e7f951fd5644bb942d548e0a77682
