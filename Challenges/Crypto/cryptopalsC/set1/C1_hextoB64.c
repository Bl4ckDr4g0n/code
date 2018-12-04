#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BetweenI(a,b,c) (a >= b && a <= c) ? 1 : 0

char b64[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int hex2int(char h){
	if(BetweenI((int)h, 48, 57)){
		return ((int)h - 48);
	}
	else if(BetweenI((int)h, 97, 102)){
		return ((int)h - 87);
	}
	else{
		return -1;
	}
	
}

char * hex2B64(char*,int);
char * hex2B64aux(char*);


int main(void){
	char *h = malloc(100*sizeof(char));
	char *b;
	for(int i = 0; i < 100; i++){
		h[i] = '\0';
	}
	scanf("%s", h);
	b = hex2B64(h, strlen(h));
	printf("%s\n", b);
	return 0;
}

char * hex2B64(char * h, int len){
	char * res = malloc(len * sizeof(char));
	for(int i = 0; i < len; i++){
		res[i] = '\0';
	}
	//int aux = 0;
	char * auxo;
	char * auxi = malloc(3 * sizeof(char));
	for(int i = 0; i < (len/3)*3; i += 3){
		for(int j = 0; j < 3; j++){
			auxi[j] = h[i+j];
		}
		auxo = hex2B64aux(auxi);
		for(int j = 0; j < 2; j++){
			res[(i/3)*2 + j] = auxo[1 - j];
		}
		free(auxo);
	}
	free(auxi);
	if (len % 3 == 2){
		char auxy[3];
		char * auxw = malloc(2 * sizeof(char));
		auxy[2] = h[len - 1];
		auxy[1] = h[len - 2];
		auxy[0] = '0';
		auxw = hex2B64aux(auxy);
		res[(len/3)*2 + 1] = auxw[0];
		res[(len/3)*2 + 2] = auxw[1];
		free(auxw);
	}
	else if (len % 3 == 1){
		res[(len/3)*2 + 1] = h[len-1];
	}
	return res;

}

char * hex2B64aux(char * h){
	char * res = malloc(2 * sizeof(char));
	int aux = 0;
	for(int i = 0; i < 3; i++){
	//	fprintf(stderr, "%c", h[i]);
		aux += hex2int(h[i]);
		if(i != 2) aux = aux << 4;
	}
	//fprintf(stderr, "\naux: %d\n", aux);
	res[0] = b64[aux % 64];
	res[1] = b64[aux / 64];
	//for(int i = 0; i < 2; i++){
	//	fprintf(stderr, "%c", res[i]);
	//}
	//fprintf(stderr, "\n");
	
	return res;
}
