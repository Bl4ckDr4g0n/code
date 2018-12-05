#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
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

