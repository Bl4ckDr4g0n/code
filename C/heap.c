#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

#define fl(i,n) for(int i=0;i<n;i++)
#define pl printf("\n")
#define ps printf(" ")
#define getD(a) scanf("%d", &a)

int left(int);
int right(int);
int parent(int);
void heapSort(int[], int);
void buildMaxHeap(int [], int);
void heapify(int[], int, int);

int main(void){
	srand(time(NULL));
	int N;
	printf("Enter array size: ");
	getD(N);
	int arr[N];
	fl(i,N){
		arr[i] = rand()/(RAND_MAX/100000 + 1);
		printf("%d | ", arr[i]);
	}
	pl;
	heapSort(arr, N);
	fl(i,N)
		printf("%d -> ", arr[i]);
	pl;
	return 0;
}

int left(int index){
	return index*2 + 1;
}

int right(int index){
	return (index+1)*2;
}

int parent(int index){
	return (index-1)/2;
}

void heapify(int arr[], int i, int max){
	int leftC, rightC, index;

	while(i < max){
		index = i;
	
		leftC  = left(i);
		rightC = right(i);

		if(leftC < max && arr[leftC] > arr[index]){
			index = leftC;
		}
	
		if(rightC < max && arr[rightC] > arr[index]){
			index = rightC;
		}
	
		if(index == i){
			return;
		}

		int temp = arr[index];
		arr[index] = arr[i];
		arr[i] = temp;

		i = index;
	}
}

void buildMaxHeap(int arr[], int size){
	int i = size/2 - 1;

	while(i >= 0){
		heapify(arr, i, size);
		i--;
	}
}

void heapSort(int arr[], int size){
	buildMaxHeap(arr, size);

	int lastElement = size-1;

	while(lastElement > 0){
		int temp = arr[lastElement];
		arr[lastElement] = arr[0];
		arr[0] = temp;
	
		heapify(arr, 0, lastElement);
	
		lastElement--;
	}
	
}
