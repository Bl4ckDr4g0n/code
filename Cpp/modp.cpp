#include <iostream>
using namespace std;
long long int exp(long long int a, long long int p, long long int mod)
{
long long int result = 1;
 long long int (p==0)
  return 1;
 long long int (p==1)
  return a;
while(p)
{
	if(p&1)
		result *= a;
	result%=mod;
	p >>=1;
	a*=a;
	a%=mod;
}
return result;
}
int main()
{
	long long int a,p,m;
	m=1;
	cout<<"Enter a, p, and mod : ";
	cin >> a >> p >> m;
	cout << exp(a,p,m) <<'\n';
	return 0;
}
