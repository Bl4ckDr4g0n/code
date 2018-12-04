#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <climits>

#define fl(i,n) for(int i=0;i<n;i++)
#define pl printf("\n")
#define ps printf(" ")

using namespace std;

int main(void){
	char string[21];
	fl(i,21)
		string[i] = '\0';
	cin >> string;
	cin.clear();
	cin.ignore(INT_MAX, '\n');
	long long unsigned int N;
	cin >> N;
	int len = strlen(string);
	for(int i = 0; i < len - 1; i++)
	{
		int pos = N/(len-(i+1));
		printf("%d-th iteration: pos = %d\n", i, pos);
		if(pos){
			char temp = string[i + pos];
			string[i + pos] = string[i];
			string[i] = temp;
		}
		N %= (len-(i+1));
	}
	printf("Permutation %llu: %s\n", N, string);
	return 0;
}
