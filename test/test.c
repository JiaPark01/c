#include <stdio.h>
#include <stdlib.h>

struct score
{
	char *name;
	int kor;
	int eng;
	int maths;
	int total;
	double avg;
	int rank;
};

int main(void)
{
	FILE *fp = fopen("score.dat", "r");
	
	if (fp == NULL) {
		printf("Unable to open\n");
		exit(1);
	}
	
	char temp[10];
	
	struct score scores[5];
	int counter = 0;
	int total = 0;
	int rank[5] = {0, };
	
	while (fscanf(fp, "%s", temp) != EOF) {
		//printf("%s\n", temp);
		if (counter > 4) {
			int loc = counter / 4 - 1;
			if (counter % 4 == 0) {
				scores[loc].name = temp;
				total = 0;
			} else {
				if (counter % 4 == 1) {
					scores[loc].kor = atoi(temp);
				} else if (counter % 4 == 2) {
					scores[loc].eng = atoi(temp);
				} else {
					scores[loc].maths = atoi(temp);
				}
				total += atoi(temp);
				scores[loc].total = total;
				scores[loc].avg = total / 3.0;
				rank[loc] = total;
			}
		}
		++counter;
	}
	
	int max = 0;
	
	for (int i = 0; i < 5; ++i) {
		printf("%d ", rank[i]);
	}
	
	for(int i = 0; i < 5; ++i) {
		for (int j = 1; j < i; ++j) {
			if (scores[i].total > scores[j].total) {
				max = i;
			}
		}
	}
	printf("\n%d\n", max);
	
	
	printf("Name\tKor\tEng\tMaths\tTotal\tAverage\tRank\n");
	for (int i = 0; i < 5; ++i) {
		printf("%s:\t%d\t%d\t%d\t%d\t%.1lf\t%d\n", scores[i].name, scores[i].kor, scores[i].eng, scores[i].maths, scores[i].total, scores[i].avg, scores[i].rank);
	}
	
	
	/*
	char buffer[1000];
	int len = 0;
	int type = 0;		// 0 = Name, 1 = Kor, 2 = Eng, 3 = Maths
	int status = 0;		// 0 = had no letters, 1 = had letters
	
	if (fp == NULL) {
		printf("Unable to open\n");
		exit(1);
	}
	fread(buffer, 1, 1000, fp);
	
	while (buffer[len] != '\0') {
		if (buffer[len] != '\t' && buffer[len] != '\n') {
			if (status == 0) {
				status = 1;
				++type;
			}
		} else status = 0;
		
		if (type % 4 == 0) {
			scores[i]->name = buffer[len];
		}
		
		++len;
	}
	*/
	
	fclose(fp);
	
	
	return 0;
}
