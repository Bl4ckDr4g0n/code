#include <stdio.h>
#include <stdlib.h>

int comparar(char *str1, char *str2);

int main(void){
	char buf[100], buf2[100];
	printf("Enter first string: ");
	scanf("%s", &buf[0]);
	printf("Enter second string: ");
	scanf("%s", &buf2[0]);
	if(comparar(&buf[0], &buf2[0]))
		printf("Strings match.\n");
	else
		printf("Strings don't match.\n");

	return 0;
}

int comparar(char *str1, char *str2){
	int i;
	for(i = 0; *(str1 + i) != '\0' && *(str2 + i) != '\0'; i++){
		if(*(str1 + i) != *(str2 + i)) return 0;
	}
	if(*(str1 + i) != *(str2 + i)) return 0;
	return 1;
}
