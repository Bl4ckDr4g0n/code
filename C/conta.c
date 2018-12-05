#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count[26];

int main(void){
  for(int i = 0; i < 26; i++) count[i] = 0;
  char ch = toupper(getchar());
  while( ch != '\0'){
    if(ch >= 'A' && ch <= 'Z') count[(int)ch-'A']++;
  }
  for(int i = 0; i < 26; i++) printf("%c: %d\t", (char)(i + 'A'), count[i]);
  printf("\n");
}
