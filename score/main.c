#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM 10

typedef struct {
	char name[21];
	int kor;
	int eng;
	int maths;
	int sum;
	double avg;
	int rank;
} Student;

int main(void)
{
	FILE *fin, *fout;
	
	fin = fopen("score.dat", "r");
	
	if (fin == NULL) {
		printf("Cannot open input file\n");
		exit(1);
	}
	
	fout = fopen("score.out", "w");
	
	if (fout == NULL) {
		printf("Cannot open output file\n");
		exit(1);
	}
	
	Student students[10];
	
	for (int i = 0; i < NUM; ++i) {
		fscanf(fin, "%s %d %d %d", students[i].name, &students[i].kor, 
		&students[i].eng, &students[i].maths);
		
		students[i].sum = students[i].kor + students[i].eng + students[i].maths;
		students[i].avg = (double)students[i].sum / 3.0;
		students[i].rank = 1;
	}
	
	for (int i = 0; i < NUM; ++i) {
		for (int j = 0; j < NUM; ++j) {
			if (students[i].sum < students[j].sum) ++students[i].rank;
		}
	}
	
	for (int i = 0; i < NUM; ++i) {
		for (int j = i + 1; j < NUM; ++j) {
			if (students[i].rank == students[j].rank) {
				if (strcmp(students[i].name, students[j].name) < 1)
					++students[j].rank;
				else ++students[i].rank;
			}
		}
	}
	
	// sorting by name
	
	for (int i = 0; i < NUM - 1; ++i) {
		for (int j = i + 1; j < NUM; ++j) {
			if (strcmp(students[i].name, students[j].name) > 0) {
				Student temp = students[i];
				students[i] = students[j];
				students[j] = temp;
			}
		}
	}
	
	
	fprintf(fout, "        Name        Kor Eng Math Sum  Avg   Rank\n");
	fprintf(fout, "------------------------------------------------\n");
	for (int i = 0; i < NUM; ++i) {
		fprintf(fout, "%-20s %3d %3d %3d %3d %6.2lf %3d\n", students[i].name, 
		students[i].kor, students[i].eng, students[i].maths, students[i].sum, 
		students[i].avg, students[i].rank);
	}
	
	fclose(fin);
	fclose(fout);
	
	return 0;
}
