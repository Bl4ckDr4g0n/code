#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <climits>

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
	int consts[11];
};

typedef struct array array;

//void printArray(array);
void initialize(array *);
int address(array, int[]);


int main(void){
	int N, R;
	scanf("%d %d", &N, &R);
	array * arrays = (array*)malloc((N+1)*sizeof(array));
	fl(i,N){
		cin >> (arrays+i)->name >> (arrays+i)->base_adr >> (arrays+i)->size >> (arrays+i)->D;
		fl(j,(arrays+i)->D){
			cin >> (arrays+i)->lowerBound[j] >> (arrays+i)->upperBound[j];
		}
	}
	fl(i,N){
		//pl;
		initialize((arrays+i));
//		printArray(*(arrays+i));
	}
	fl(i,R){
		char name[10] = "";
		cin >> name;
		//printf("Name : %s\n", name);
		int j = 0;
		while(j < N){
			if(!strcmp(name, (arrays+j)->name))
				break;
			else
				j++;
		}
		//printf("j : %d\n", j);
		int temp[(arrays+j)->D];
		fl(k,(arrays+j)->D){
			cin >> temp[k];
			//printf("%d-th index: %d\n", k, temp[k]);
		}
		printf("%s[", (arrays+j)->name);
		fl(k,(arrays+j)->D - 1)
			printf("%d, ", temp[k]);
		printf("%d] = %d", temp[(arrays+j)->D - 1], address(*(arrays + j), temp));
		//pl;
		pl;
		cin.clear();
		cin.ignore(INT_MAX, '\n');
	}
	return 0;
}

void initialize(array * arr){
	arr->consts[arr->D] = arr->size;
	int sum = 0;
	for(int i = arr->D - 1; i > 0; i--){
		arr->consts[i] = (arr->consts[i+1])*(arr->upperBound[i] - arr->lowerBound[i] + 1);
		sum += arr->lowerBound[i-1]*arr->consts[i];
		//printf("%s: %d-th const: %d\n", arr->name, i, arr->consts[i]);
	}
	sum += arr->lowerBound[arr->D - 1]*arr->size;
	arr->consts[0] = arr->base_adr - sum;
}

int address(array arr, int index[]){
	int addr = arr.consts[0];
	//printf("addr: %d\n", addr);
	for(int i=0; i<arr.D; i++){
		addr += arr.consts[i+1]*index[i];
	}
	//printf("Returning addr: %d\n", addr);
	return addr;
}

//void printArray(array arr){
//	printf("---------------------->\n");
//	printf("Name: %s\n", arr.name);
//	printf("Base Address: %u\n", arr.base_adr);
//	printf("Element size: %d\n", arr.size);
//	printf("Dimensions: %d\n", arr.D);
//	fl(i,arr.D){
//		printf("Dimension %d\n", i);
//		printf("\tUpper Bound: %d\n", arr.upperBound[i]);
//		printf("\tLower Bound: %d\n", arr.lowerBound[i]);
//	}
//	printf("---------------------->\n");
//}
