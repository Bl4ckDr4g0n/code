#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int linear(int arr[], int size, int val);
int binary(int arr[], int size, int val);
void selectSort(int arr[], int size);
void insertionSort(int arr[], int size);

int main(void){
  int N;
  printf("Enter array size: ");
  scanf("%d", &N);
  printf("Enter %d values...", N);
  int arr[N];
  for(int i = 0; i < N; i++) {
    printf("#%d: ", i);
    scanf("%d", &arr[i]);
  }
  printf("Enter value to search for: ");
  int val;
  scanf("%d", &val);
  printf("Linear search: %d\n", linear(arr, N, val));
  insertionSort(arr, N);
  for(int i = 0; i < N; i++) printf("%d ", arr[i]);
  printf("\n");
  
  return 0;
}

int linear(int arr[], int size, int val){
  arr[size] = val;
  int i = 0;
  while(arr[i] != val) i++;
  if(i == size) return -1;
  else return i;
}

int binary(int arr[], int size, int val){
  int i = 0, j = size-1;
  while(i < j){
    int k = i + (j-i)/2;
    if(arr[k] == val) return k;
    else if (arr[k] > val) j = k-1;
    else i = k+1;
  }
  if(arr[i] == val) return i; else return -1;
  
}

void selectSort(int arr[], int size){
  for(int i = 0; i < size; i++){
    int minj = i;
    for(int j = i+1; j < size; j++){
      if(arr[j] < arr[minj]){
	minj = j;
      }
    }
    if (minj != i) {
      int temp = arr[i];
      arr[i] = arr[minj];
      arr[minj] = temp;
    }
  }
}

void insertionSort(int arr[], int size){
  int i, j;
  for(i = 1; i < size; i++){
    int x = arr[i];
    j = i-1;
    while(j>= 0 && arr[j] > x) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = x;
  }
}
