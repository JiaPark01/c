#include <stdio.h>
#include "serial.h"

int main(void)
{
	for (int i = 1; i <= 10; ++i) {
		int serialNumber = getSerialNumber();
		
		printf("HYUNDAI_RAMDA_%010d\n", serialNumber);
	}
	
	return 0;
}
