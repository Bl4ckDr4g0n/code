#include <iostream>
#define fl(i,n) for(int i=0;i<n;i++)
#define pl printf("\n")
#define ps printf(" ")
#define getD(a) scanf("%d", &a)

int get(int a, int b, int max){
	int suma = ((max/a + 1)*(max/a))/2;
	suma *= a;
	printf("a: %d | suma: %d\n", a, suma);
	int sumb = ((max/b + 1)*(max/b))/2;
	sumb *= b;
	printf("b: %d | sumb: %d\n", b, sumb);
	int sumab = ((max/(a*b))*(max/(a*b)))/2;
	sumab *= a;
	sumab *= b;
	printf("ab: %d | sumab: %d\n", a*b, sumab);
	return suma + sumb - sumab;
}

int main()
{
	int a,b,max;
	printf("Enter a: ");
	getD(a);
	printf("Enter b: ");
	getD(b);
	printf("Enter max: ");
	getD(max);
	printf("The sum of all multiples of %d or %d up to %d is: %d", a, b, max, get(a,b,max));
	pl;
	return 0;
}
