#include <stdio.h>
#include <string.h>
#include <ctype.h>

void quickSort(char[], int, int);
int partition(char[], int, int);
int normalize(char[], int);

int main(void){
    char buf[100];
    printf("Enter string: ");
    scanf("%[^\n]%*c", buf);
	int size = strlen(buf);
	printf("hello %d\n", (int)size);
	for(int i = 0; i < (int)size; i++) printf("%c", (buf[i]));
    size = normalize(buf, size);
	printf("\n");
    for(int i = 0; i < size; i++) putchar(buf[i]);
    putchar('\n');
    return 0;
}

int normalize(char str[], int size){
	quickSort(str, 0, size);
	printf("\nNormalizing: \n");
	for(int i = 0; i < size; i++) printf("%c", str[i]);
	printf("\n");
	for(int i = 0; i < size;){
		if(!isalpha(str[i])){
			int j = i;
			while(j < size - 1){
				str[j] = str[j+1];
				j++;
			}
			size--;
		}
		else{
			str[i] = tolower(str[i]);
			i++;
		}
	}
	return size;
}

void quickSort(char str[], int start, int end){
    if(end - start <= 1){
        return;
    }
    
    int k = partition(str, start, end);
    
    quickSort(str, start, k);
    quickSort(str, k+1, end);
}

int partition(char str[], int start, int end){
    int lowI = start, highI = end - 1;
    
	int iMed;

	if((int)str[highI] >= (int)str[lowI]){
		if((int)str[highI] >= (int)str[lowI + (highI-lowI)/2]){
			iMed = ((int)str[lowI] >= (int)str[lowI + (highI-lowI)/2]) ? lowI : lowI + (highI-lowI)/2;
		}
		else{
			iMed = highI;
		}
	}
	else{
		if((int)str[lowI] >= (int)str[lowI + (highI-lowI)/2]){
			iMed = ((int)str[highI] >= (int)str[lowI + (highI-lowI)/2]) ? lowI : lowI + (highI-lowI)/2;
		}
		else{
			iMed = lowI;
		}
	}

	if(iMed != highI){
		char aux = str[highI];
		str[highI] = str[iMed];
		str[iMed] = aux;
	}
    int pivot = (int)str[highI];

    while(lowI < highI){
        if((int)str[highI-1] >= pivot){
            str[highI] = str[highI - 1];
            highI--;
        }
        else{
            char temp = str[highI-1];
            str[highI-1] = str[lowI];
            str[lowI] = temp;
            lowI++;
        }
    }
    str[highI] = (char)pivot;
    return highI;
}


