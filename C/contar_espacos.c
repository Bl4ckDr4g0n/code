#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int contar_espacos(char*);

int main(void){
	char string[] = "Ola, como vai a vida?  Isto tem muito s es p a c os   ";
	printf("The string has %d spaces\n", contar_espacos(&string[0]));
	return 0;
}

int contar_espacos(char *str){
	int count = 0;
	for(int i = 0; *(str + i) != '\0'; i++){
		if(*(str+i) == ' ')
			count++;
	}
	return count;
}
