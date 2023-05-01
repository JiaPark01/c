#include <stdio.h>
#define BOLD		(0x01 << 0)
#define ITALIC		(0x01 << 1)
#define SHADOW		(0x01 << 2)
#define UL			(0x01 << 3)

int main(void)
{
	/*
	int isBold, isItalic, isShadow, isUL;
	char isBold, isItalic, isShadow, isUL;
	
	isBold = 1;
	isItalic = 1;
	isShadow = 1;
	isBold = 0;
	*/
	
	unsigned char attr;
	attr = attr ^ attr; // 0
	attr = attr | BOLD;
	attr = attr | (ITALIC + SHADOW); // or attr | 0x02 | 0x04
	attr = attr & ~BOLD;
	
	printf("attr: 0x%02x\n", attr);
	
	
	return 0;
}
