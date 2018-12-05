#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int find(int[], int, int);
int findA(int[], int, int);
int binFind(int[], int, int);

int main(void){
  int N;
  printf("Please enter array size: ");
  scanf("%d", &N);
  int arr[N];
  printf("Please enter %d values: \n", N);
  for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
  int val;
  printf("Please enter value to scan for: ");
  scanf("%d", &val);
  printf("Find: %d\nFindA: %d\n", find(arr, val, N), findA(arr, N, val));
  printf("Binary search results: %d", binFind(arr, val, N));
  return 0;
}

int binFind(int vec[], int x, int len){
  int i = 0, j = len - 1;
  while(i < j){
    int k = i + (j-i)/2;
    if(vec[k] == x) return k;
    else if (x > vec[k]) i = k+1;
    else j = k-1;
  }
  if(vec[i] == x) return i; else return -1;
}

int find(int vec[], int x, int len){
  vec[len] = x;
  int i = 0;
  while(vec[i] != x) i++;
  if(i == len) return -1;
  else return i;
}

int findA(int vec[], int n, int x){
  int i = 0;
  vec[n] = x;

  while(vec[i] != x) i++;

  if(i < n) return i;
  else return -1;
}
