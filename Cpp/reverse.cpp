#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int reverseLine();

int main(void){
	char ch;
	do{
		ch = getchar();
		char buf[100];
		for(int i = 0; i < 100; i++) buf[i] = 0;
		int i = 0;
		while(ch != ' ' && ch != '\n' && ch != EOF){
			buf[i++] = ch;
			ch = getchar();
		}
		i--;
		while(i >= 0)putchar(buf[i--]);
		if(ch != EOF) putchar(ch);
	} while(ch != EOF);
	return 0;
}


