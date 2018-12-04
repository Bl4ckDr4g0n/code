// In need of debugging

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RoundUpDiv(a, b) ((a % b == 0) ? a / b : (a / b) + 1)

// Useful mapping
char b64[64] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Extending to include length information
struct bitArray {
	int len;
	unsigned int * array;
};

struct hexString {
	int len;
	char * hex;
};

struct b64String{
	int len;
	char * B64;
};

// Typedefs for convenience
typedef struct b64String b64String;
typedef struct hexString hexString;
typedef struct bitArray bitArray;

// Function headers
bitArray hex2Raw(hexString h);
unsigned int h2R(char h);
void toLower(char * s, int len);
b64String Raw2B64(bitArray arr);
unsigned int getBit(unsigned int a, int n);
int getString(char ** dest);

int main(void){
	hexString input;
	input.len = getString(&(input.hex));
	toLower(input.hex, input.len);
	bitArray array = hex2Raw(input);
	printf("len: %d\n", array.len);
	for(int i = 0; i < array.len; i++){
		printf("%d\n", array.array[i]);
	}
	b64String output = Raw2B64(array);
	for(int i = 0; i < output.len; i++){
		printf("%c", output.B64[i]);
	}
	printf("\n");
	return 0;
}

bitArray hex2Raw(hexString h){
	bitArray res;
	fprintf(stderr, "h.len: %d\n", h.len);
	res.len = (h.len % 4 == 0) ? h.len / 4 : (h.len / 4) + 1;
	res.array = malloc(sizeof(int) * res.len);
	fprintf(stderr, "Size: %d\n", res.len);
	for(int i = 0; i < res.len; i++){
		for(int j = 0; j < 4; j++){
			fprintf(stderr, "Adding %d to array...\n", ((unsigned int)h2R(h.hex[i*4 + j]) << (unsigned int)4*(unsigned int)j));
			res.array[i] += (h2R(h.hex[i*4 + j]) << 4*j);
		}
		fprintf(stderr, "res.array[%d]: %d\n", i, res.array[i]);	
	}
	return res;
}

unsigned int h2R(char h){
	if((int)h >= 48 && (int)h <= 57){
		fprintf(stderr, "h2R passing: %d\n", ((int)h - 48));
		return ((int)h - 48);
	}
	else if((int)h >= 97 && (int)h <= 102){
		fprintf(stderr, "h2R passing: %d\n", ((int)h - 87));
		return ((int)h - 87);
	}
	else{
		return -1;
	}
}

void toLower(char * s, int len){
	for(int i = 0; i < len; i++){
		if(s[i] >= 65 && s[i] <= 90){
			s[i] += 32;
		}
	}
}

b64String Raw2B64(bitArray arr){
	b64String res;
	res.len = RoundUpDiv((arr.len * 32), 6);
	res.B64 = malloc((res.len + 1) * sizeof(char));
	res.B64[res.len] = '\0';
	long int aux = 0;
	for(int i = 0; i < (arr.len * 32); i++){
		aux += (getBit(arr.array[i/32], i % 32) << (i % 6));
		fprintf(stderr, "aux: %ld | i: %d | i mod 6: %d | i / 32: %d\n", aux, i, i%6, i / 32);
		if (i % 6 == 5){
			res.B64[i/6] = b64[aux];
			aux = 0;
		}
	}
	return res;
}

unsigned int getBit(unsigned int a, int n){
	unsigned int b;
	b = (a >> n) % 2;
	fprintf(stderr, "b: %d\n", b);
	return b;
}

int getString(char ** dest){
	char * aux = malloc(100*sizeof(char));
	int i = 0;
	int max = 100;
	do{
		aux[i] = getchar();
		i++;
		if(max - i <= 2){
			aux = realloc(aux, max*2*sizeof(char));
			max *= 2;
		}	
	} while(aux[i-1] != '\n');
	aux[i-1] = '\0';
	for(int j = 0; j < i; j++){
		fprintf(stderr, "c: %c | i: %d\n", aux[j], j);
	}
	*dest = realloc(aux, (i) * sizeof(char));
	return i - 1;
}
