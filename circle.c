#include <stdio.h>
#define PI 3.141592

int main()
{
	// int radius;
	double radius;
	double area;
	
	printf("Enter radius: ");
	//scanf("%d", &radius);
	scanf("%lf", &radius);
	
	area = radius * radius * PI;
	
	printf("\nArea: %.2f\n", area);
	
	return 0;
}
