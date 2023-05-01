#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)		// argument count (numbers), argument vector
{
//	for (int i = 0; i < argc; ++i) {
//		printf("%s\n", argv[i]);
//	}
	
	if (argc != 3) {
		fprintf(stderr, "[usage] ./add 1 2\n");
		exit(1);
	}
	
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	
	printf("%d\n", a + b);
	
	return 0;
}
