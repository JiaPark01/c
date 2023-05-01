#include <stdio.h>

int main(void)
{
	char name[21];
	
	/*
	OR
	char buf[21];
	char *name;
	name = buf;
	*/
	scanf("%20s", name);		// no spaces. OR use fgets(); %20s means only 20 char
	
	printf("%s\n", name);
	
	return 0;
}
