#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>

#define fl(i,n) for(int i=0;i<n;i++)
#define pl printf("\n")
#define ps printf(" ")

using namespace std;

int main(void){
	int n, m, c;
	int j = 0;
	while(++j){
		cin >> n >> m >> c;
		if(n == 0 && m == 0 && c == 0)
			break;
		int power[n];
		int on[n];
		int max = 0;
		int current = 0;
		//printf("Max current: %d\n", c);
		fl(i,n){
			cin >> power[i];
		//	cout << "Power: " << power[i] << endl;
			on[i] = 0;
		}
		fl(i,m){
			int temp;
			cin >> temp;
			temp--;
			if(!on[temp]){
				current += power[temp];
		//		cout << "Turning on: " << temp << endl << "Total consumption now: " << current << endl;
				on[temp] = 1;
				if(current > max)
					max = current;
			}
			else{
				current -= power[temp];
		//		cout << "Turning off: " << temp << endl << "Total consumption now: " << current << endl;
				on[temp] = 0;
			}
		}
		printf("Sequence %d\n", j);
		if(max > c)
			printf("Fuse was blown.\n");
		else{
			printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n", max);
		}
		pl;
	}
}
