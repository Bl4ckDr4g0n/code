#include <stdio.h>

void secretFunction()
{
	printf("Congratulations!\n");
	printf("You have entered the secret function!\n");
}

void echo()
{
	char echo[20];

	printf("Enter some text:\n");
	scanf("%s", echo);
	printf("You entered: %s\n", echo);
}

int main(){
	echo();

	return 0;
}
