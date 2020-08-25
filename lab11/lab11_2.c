#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void file_copy (FILE *one, FILE *two);
int file_cmp (char *, char *);

int main(void)
{
	FILE *one = fopen("tekst1.txt", "r");
	FILE *two = fopen("tekst2.txt", "w");
	file_copy(one, two);
	
}

void file_copy (FILE *one, FILE *two)
{
	int temp;
	while((temp==fgetc(one))!=EOF)
		fputc(temp, two);

	fclose(one);
	fclose(two);
}

int file_cmp (char *one, char *two)
{
	FILE *jeden = fopen(one, "rb");
	FILE *dwa = fopen(two, "rb");
	int temp1, temp2;

	while(1)
	{
		if(memcmp(jeden, dwa, sizeof(int))!=1)
			return 0;
		fseek(one, 1*sizeof(int), SEEK_CUR);
		fseek(two, 1*sizeof(int), SEEK_CUR);
	}
	return 1;
}