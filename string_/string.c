#include "string.h"

int my_strlen(const char *s)
{
	int c = 0;
	while(*s)
		++c, ++s;
	
	return c;
}

void my_strcpy(char *dest, const char *src)
{
	while(*dest++ = *src++)		// auto assigns '\0' at last
		;
}

int my_strcmp(const char *str1, const char *str2)
{
	while(*str1 || *str2 || *str1 != *str2)
		++str1, ++str2;
		
	return *str1 - *str2;
}

void my_strcat(char *dest, const char *src)
{
	my_strcpy(dest + my_strlen(dest), src);
}

/*
int my_strlen(const char *str)
{
	int counter = 0;
	while(str[counter] != '\0') ++counter;
	
	return counter;
}

void my_strcpy(char *dest, const char *src)
{
	int counter = 0;
	while(src[counter] != '\0') {
		dest[counter] = src[counter];
		++counter;
	}
	dest[counter] = '\0';
	
}

int my_strcmp(const char *str1, const char *str2)
{
	int counter = 0;
	while(str1[counter] != '\0' || str2[counter] != '\0') {
		if (str1[counter] != str2[counter]) break;
		++counter;
	}
	return str1[counter] - str2[counter];
}

void my_strcat(char *dest, const char *src)
{
	my_strcpy(dest + my_strlen(dest), src);
}
*/
