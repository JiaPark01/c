#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[] = "hello";
	
	int len = strlen(str1);		// 5
	printf("len: %d\n", len);
	
	char str2[6];
	strcpy(str2, str1);
	printf("str2: %s\n", str2);
	
	if (strcmp(str1, str2) == 0) {
		printf("str and str2 are equal\n");
	} else {
		printf("str and str2 are not equal\n");
	}
	
	char str3[] = ", world";
	char str4[15];
	strcpy(str4, str1);
	strcat(str4, str3);
	
	printf("%s\n", str4);
	
	return 0;
}
