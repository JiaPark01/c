#include <stdio.h>

int main(void)
{
	int male, female;
	double ratioM, ratioF;
	
	printf("Enter the number of males and females: ");
	scanf("%d %d", &male, &female);
	
	//ratioM = 1.0 * male / (male + female) * 100;
	ratioM = (double)male / (male + female) * 100;
	ratioF = 100 - ratioM; 
	
	printf("Male: %.2lf%%, Female: %.2lf%%\n", ratioM, ratioF);
	
	return 0;
}
