#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

#define fl(i,n) for(int i = 0;i<n;i++)
#define pl printf("\n")
#define ps printf(" ")

using namespace std;

struct array {
	char name[10] = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'};
	unsigned int base_adr;
	int size;
	int D;
	int upperBound[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int lowerBound[10] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
};

typedef struct array array;

void printArray(array arr);

int main(void){
	int N, R;
	scanf("%d %d", &N, &R);
	array * arrays = (array*)malloc((N+1)*sizeof(array));
	fl(i,N){
		cin >> (arrays+i)->name >> (arrays+i)->base_adr >> (arrays+i)->size >> (arrays+i)->D;
		fl(j,(arrays+i)->D){
			cin >> (arrays+i)->upperBound[j] >> (arrays+i)->lowerBound[j];
		}
	}
	fl(i,N){
		pl;
		printArray(*(arrays+i));
	}
	return 0;
}

//int address(array arr, int indexes[], int dims){
//	
//}

void printArray(array arr){
	printf("---------------------->\n");
	printf("Name: %s\n", arr.name);
	printf("Base Address: %u\n", arr.base_adr);
	printf("Element size: %d\n", arr.size);
	printf("Dimensions: %d\n", arr.D);
	fl(i,arr.D){
		printf("Dimension %d\n", i);
		printf("\tUpper Bound: %d\n", arr.upperBound[i]);
		printf("\tLower Bound: %d\n", arr.lowerBound[i]);
	}
	printf("---------------------->\n");
}
