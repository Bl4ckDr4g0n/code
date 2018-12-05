//#include <stdio.h>
//#include <stdlib.h>
#include <string>
//#include <ctype.h>
#include <iostream>
#include <sstream>


using namespace std;
void printRes(long int, long int);


int main(void){
    long int min, max;
    string mystr;
    getline(cin, mystr);
    while(mystr.find_first_of("0123456789") != string::npos){
        stringstream(mystr) >> min >> max;
        printRes(min, max);
        getline(cin, mystr);
    }
	return 0;
}

void printRes(long int min, long int max){
    if(min > max){
        int temp = min;
        min = max;
        max = temp;
    }
    int maxC = -3;
    for(int i = min; i <= max; i++){
	    int j = 0;
	    int temp = i;
	    while(temp != 1){
		    if(temp%2 == 0){
			    temp /= 2;
		    }
		    else{
			    temp = temp*3 + 1;
			    j++;
			    temp /= 2;
		    }
		    j++;
	    }
	    j++;
	    if(j > maxC) maxC = j;
    }
    printf("%ld %ld %d\n", min, max, maxC);   
}
