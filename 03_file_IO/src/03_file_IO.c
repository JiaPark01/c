/*
 ============================================================================
 Name        : 03_file_IO.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char buffer[1000];
	FILE* fp_r = NULL;		// 파일 디스크립터
	FILE* fp_w = NULL;
	fp_r = fopen("/home/jiap01/eclipse-workspace/03_file_IO/src/input.txt", "r");
	fp_w = fopen("/home/jiap01/eclipse-workspace/03_file_IO/src/output.txt", "a");

	if (fp_r == NULL) {
		printf("읽기 파일을 열 수 없습니다.\n");
		exit(1);
	}

	if (fp_w == NULL) {
		printf("쓰기 파일을 열 수 없습니다.\n");
		exit(1);
	}

	fread(buffer, 1, 1000, fp_r);


	int len = 0;
	while ('\0' != buffer[len]) {
		fwrite(buffer[len], 1, 1, fp_w);

		++len;
	}


	//fwrite(buffer, 1, len, fp_w);
	printf("%d", len);


	//printf("%s", buffer);

	fclose(fp_r);
	fclose(fp_w);
	/*
	char txt[64];
	while (EOF != fscanf(fp, "%s", txt)) {
		printf("%s\n", txt);
	}

	fclose(fp);
	*/

	return 0;
}
