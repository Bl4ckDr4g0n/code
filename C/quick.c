#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int ternary(int arr[], int, int, int);
void generate(int arr[], int size);
int menor(int arr[], int start, int end);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
int binary(int arr[], int size, int val);
int linear(int arr[], int size, int val);
void printArray(int arr[], int size);

int main(void){
	int sorted = 0, size = 0;
	printf("Enter array size: ");
	scanf("%d", &size);
	int arr[size+1];
	generate(arr, size);
	printf("Array is unsorted. Binary search only availiable after sorting...\n");
	printf("Enter mode (0 to print array, 1 for search, 2 for order, 3 for a new array, 4 for exit): ");
	int mode;
	scanf("%d", &mode);
	while(1){
		if (mode == 0) printArray(arr, size);
		else if(mode == 2){
			printf("Please enter sort mode: \n");
			printf("\tSelection sort: 1\n");
			printf("\tInsertion sort: 2\n");
			printf("\tQuick sort: 3\n");
			int sort;
			scanf("%d", &sort);
			switch(sort){
				case 1:
					selectionSort(arr, size);
					sorted = 1;
					break;
				case 2:
					insertionSort(arr, size);
					sorted = 1;
					break;
				case 3:
					quickSort(arr, 0, size);
					sorted = 1;
					break;
				default:
					printf("Returning...\n");
					break;
			}
			printf("Array is now sorted, binary search availiable!\n");
		}
		else if(mode == 1){
			if(sorted){
				printf("Binary or linear search? 1/2 ");
				int s;
				scanf("%d", &s);
				int value;
				printf("Enter value to search for: ");
				scanf("%d", &value);
				if(s == 1){
					int index = binary(arr, size, value);
					if(index >= 0){
						printf("Found %d at index %d!\n", value, index);
				
					}
					else{
						printf("Not found...\n");
					}
				}
				else if(s == 2){
					int index = linear(arr, size, value);
					if(index >= 0){
						printf("Found element %d at index %d!\n", value, index);
					}
					else{
						printf("Not found...\n");
					}
				}
				else if(s==3){
					int index = ternary(arr, 0, size-1, value);
					if(index >= 0){
						printf("Found element %d at index %d!\n", value, index);
					}
					else
						printf("Not found...\n");
				}
				else{
					printf("Invalid option, returning to menu...\n");
				}
			}
			else{
				printf("Array unsorted, using linear search...\n");
				int value;
				printf("Enter value to search for: ");
				scanf("%d", &value);
				int index = linear(arr, size, value);
				if(index >= 0){
					printf("Found element %d at index %d!\n", value, index);
				}
				else{
					printf("Not found...\n");
				}
			}
		}
		else if(mode == 3){
			generate(arr, size);
			sorted = 0;
			printf("Array unsorted, disabling binary search...\n");
		}
		else if(mode == 4){
			printf("Exiting...\n\n");
			break;
		}
		else{
			printf("Invalid option! XX\n");
		}
		printf("Enter option(0 to print, 1 for search, 2 for sort, 3 for new array, 4 for exit): ");
		scanf("%d", &mode);
	}	
	
	return 0;
}

void generate(int arr[], int size){
	printf("Enter array lower bound: ");
	int lowB;
	scanf("%d", &lowB);
	printf("Enter array upper bound: ");
	int highB;
	scanf("%d", &highB);
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		arr[i] = rand()/(RAND_MAX/(highB - lowB) + 1) + lowB;
	}
}

void selectionSort(int arr[], int size){
	for(int i = 0; i < size; i++){
		int imin = i;
		for(int j = i+1; j < size; j++){
			if(arr[j] < arr[imin]) imin = j;
		}
		if(imin != i){
			int temp = arr[i];
			arr[i] = arr[imin];
			arr[imin] = temp;
		}
	}
}

void insertionSort(int arr[], int size){
	for(int i = 1; i < size; i++){
		int x = arr[i];
		int j = i-1;
		while(j>=0 && arr[j] > x){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = x;
	}
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
	int pivot = arr[end-1], temp;
	int lowI = start, highI = end-1;
	while(highI > lowI){
		if(arr[highI - 1] > pivot){
			arr[highI] = arr[highI-1];
			highI--;
		}
		else{
			temp = arr[highI-1];
			arr[highI-1] = arr[lowI];
			arr[lowI] = temp;
			lowI++;
		}
	}
	arr[highI] = pivot;
	return highI;
}

int binary(int arr[], int size, int val){
	int i, j, k;
	i = 0;
	j = size-1;
	while(i < j){
		k = i + (j-i)/2;
		if(arr[k] == val) return k;
		else if (arr[k] > val){
			j = k - 1;
		}
		else{
			i = k+1;
		}
	}
	if(arr[i] == val) return i;
	else return -1;
}

int linear(int arr[], int size, int val){
	arr[size] = val;
	int i=0;
	while(arr[i] != val){
		i++;
	}
	if(i != size) return i;
	else return -1;
}

void printArray(int arr[], int size){
	if (size < 16){
		for(int i = 0; i < size; i++){
			printf("arr[%d] = %d\n", i, arr[i]);
		}
	}
	else{
		for(int i = 0; i < size; i++){
			printf("%d | ", arr[i]);
		}
		printf("\n");
	}
}

int ternary(int arr[], int l, int r, int val){
	if(r>=1){
		int mid1 = l +(r-l)/3;
		int mid2 = r - (r-l)/3;

		if(arr[mid1] == val)
			return mid1;
		else if(arr[mid2] == val)
			return mid2;
		else if(val<arr[mid1])
			return ternary(arr, l, mid1-1, val);
		else if(val > arr[mid2])
			return ternary(arr, mid2+1, r, val);
		else
			return ternary(arr, mid1+1, mid2-1, val);
	}
	return -1;
}
