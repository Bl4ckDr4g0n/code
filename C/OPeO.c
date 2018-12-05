#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int linear(int [], int, int);
int binary(int [], int, int);
void insertionSort(int [], int);
void selectionSort(int [], int);

int main(void){
  srand((unsigned)time(NULL));
  int N;
  printf("Enter array size: ");
  scanf("%d", &N);
  int low, high;
  printf("Enter low bound: ");
  scanf("%d", &low);
  if(low < 0){
    low = 1;
    high = RAND_MAX;
  }
  else{
    printf("Enter high bound: ");
    scanf("%d", &high);
  }
  int arr[N];
  for(int i = 0; i < N; i++) arr[i] = low + (rand() % (high + 1 - low));
  for(int i = 0; i < N; i++) printf("arr[%d] = %d\n", i, arr[i]);
  printf("Enter value to scan for: ");
  int val;
  scanf("%d", &val);
  printf("Linear search results: %d\n", linear(arr, N, val));
  printf("Insertion or selection sort? ");
  int scantype;
  scanf("%d", &scantype);
  if(scantype == 0) selectionSort(arr, N);
  else if (scantype == 1) insertionSort(arr, N);
  else {
    printf("Scan type not supported\n");
    return -1;
  }
  for(int i = 0; i < N; i++) printf("%d ", arr[i]);
  printf("\n");
  printf("Enter value for binary search: ");
  int binval;
  scanf("%d", &binval);
  printf("Binary search result: %d\n", binary(arr, N, binval));
  return 0;
}

int linear(int arr[], int size, int val){
  arr[size] = val;
  int i = 0;
  while(arr[i] != val) i++;
  if(i != size) return i; else return -1;
}

int binary(int arr[], int size, int val){
  int i = 0, j = size - 1;
  while(i < j){
    int k = i + (j-i)/2;
    if(arr[k] == val) return k;
    else if (arr[k] > val) j = k - 1;
    else i = k + 1;
  }
  if(arr[i] == val) return i; else return -1;
}

void selectionSort(int arr[], int size){
  for(int i = 0; i < size; i++){
    int minj = i;
    for(int j = i + 1; j < size; j++){
      if(arr[j] < arr[minj]) minj = j;
    }
    if(i != minj){
      int temp = arr[i];
      arr[i] = arr[minj];
      arr[minj] = temp;
    }
  }
}

void insertionSort(int arr[], int size){
  int i, j;
  for(i = 0; i < size; i++){
    j = i - 1;
    int x = arr[i];
    while(j >= 0 && arr[j] > x){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = x;
  }
}
