#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void quadrado(int n);

int main(void){
	int N;
	printf("Enter size: ");
	scanf("%d", &N);
	quadrado(N);
	return 0;
}

void quadrado(int n){
	if(n%2 == 0) return;
	int arr[n][n];
	for(int i = 0; i < n; i++){
		for(int k = 0; k < n; k++){
			arr[i][k] = 0;
//			//printf("%d %d\n", i, k);
		}
	}
	int i = 1, j = 0, k = n/2;
	while(i <= (n*n)){
		if(arr[j][k] == 0){
			arr[j][k] = i++;
			//printf("filling %d %d with %d\n", k, j, i);
			j--;
			k++;
			if(j < 0) j += n;
			if(k >= n) k -= n;
		}
		else{
			//printf("going down...\n");
			j++;
			if(j>= n) j -= n;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}

	printf("\n\nDone!\n");
}

