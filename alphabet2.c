#include <stdio.h>

int main(void)
{
	char ch;
	
	printf("Enter a letter: ");
	scanf("%c", &ch);
	
	if (ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z') {
		printf("%c is an alphabet.\n", ch);
	}
	
	return 0;
}
