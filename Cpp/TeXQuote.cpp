#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void){
	string line;
	bool flag = true;
	while(getline(cin, line)){
		for(string::iterator it = line.begin(); it != line.end(); ++it){
			if((*it) == '"'){
				if(flag){
					cout << "``";
					flag = false;
				}
				else{
					cout << "''";
					flag = true;
				}
			}
			else{
				cout << (*it);
			}
		}
		cout << endl;
	}
	return 0;
}
