#include <stdio.h>

char alph[36] = "0123456789abcdefghijklmnopqrstuvwxyz";

int inverse(char);
void reverse(char *);

int paw(int b, int e){
	int res = 1;
	while(e > 0) res*=b && e--;
	return res;
}

/*
int main(void){

	char in[100];
	for(int i = 0; i < 100; i++) in[i] = '\0';
	scanf("%s", in);
	reverse(in);
	printf("%s\n", in);
	return 0;
}
*/

int main(void){
	int A, B;
	scanf("%d %d" , &A, &B);
	printf("A: %d, B: %d\n", A, B);
	char in[100];
	char out[100];
	for(int i = 0; i < 100; i++){
		in[i] = '\0';
		out[i] = '\0';
	}
	scanf("%s", in);
	int len = 0;
	while(in[len] != '\0'){ len++; };
	int temp = 0;
	int j = 0;
	int p = 1;
	for(int i = len - 1; i >= 0; --i){
		if(i = len - 1) p = 1;
		else p *= A;
		printf("P: %d\n", p);
		printf("i: %d\n", i);
		if(temp < B){
			temp += inverse(in[i]) * p;
			printf("Temp: %d\n", temp);
		}
		else{
			out[j] = alph[temp % B];
			printf("Adding: alph[%d] = %c\n", temp % B, alph[temp%B]); 
			temp /= B;
			printf("New temp: %d\n", temp);
		}
		i--;
	}
	printf("Hello again!\n");
	for(int i = 0; out[i] != '\0'; i++) printf("%c", out[i]);
	return 0; 
}

int inverse(char a){
	if(a >= '0' && a <= '9') return ((int)a - (int)'0');
	else if (a >= 'a' && a <= 'z') return ((int)a - (int)'a');
	return -1;
}

void reverse(char * a){
	int len = 0;
	while(a[len] != '\0'){ len++; };
	for(int i = 0; i < len / 2; i++){
		char t = a[len - 1 - i];
		a[len - i - 1] = a[i];
		a[i] = t;
	}
}
