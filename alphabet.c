#include <stdio.h>

int main(void)
{
	//int code;
	int isAlpha;
	char ch;
	
	//printf("Enter code: ");
	//scanf("%d", &code);
	
	printf("Enter character: ");
	scanf("%c", &ch);
	
	//isAlpha = code >= 'A' && code <= 'Z'; 
	//isAlpha = ch >= 'A' && ch <= 'Z';
	
	isAlpha = (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
	
	//printf("ASCII code: %c\tisAlpha: %d\n", code, isAlpha);
	printf("Character: %c\tisAlpha: %d\n", ch, isAlpha);
	
	return 0;
}
