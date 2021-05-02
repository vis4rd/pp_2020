#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void file_copy (FILE *one, FILE *two);
int file_cmp (char *, char *);
void file_cat (char *one, char *two);

int main(void)
{
	FILE *one = fopen("tekst1.txt", "r");
	if(!one)
	{
		printf("blad wczytywania pliku\n");
		exit(0);
	}
	FILE *two = fopen("tekst2.txt", "w");
	if(!two)
	{
		printf("blad wczytywania pliku\n");
		exit(0);
	}
	file_copy(one, two);
	fclose(one);
	fclose(two);

	if(file_cmp("tekst1.txt", "tekst2.txt") == 0)
		printf("Te same.\n");
	else
		printf("Inne.\n");
}

void file_copy (FILE *one, FILE *two)
{
	int temp;
	while((temp=fgetc(one))!=EOF)
		fputc(temp, two);
}

int file_cmp (char *one, char *two)
{
	FILE *jeden = fopen(one, "rb");
	FILE *dwa = fopen(two, "rb");
	if(strcmp(one, two) == 0)
	{
		fclose(jeden);
		fclose(dwa);
		return 0;
	}
	else
	{
		fseek(jeden, 0, SEEK_END);
	    long binSize = ftell(jeden);
	    rewind(jeden);
	    char dane[binSize/sizeof(char)];
	    fread(dane, sizeof(char), binSize/sizeof(char), jeden);

	    fseek(dwa, 0, SEEK_END);
	    long size2 = ftell(dwa);
	    if(binSize != size2)
	    {
	    	fclose(jeden);
			fclose(dwa);
	    	return 1;
	    }
	    rewind(dwa);
	    char dane2[size2/sizeof(char)];
	    fread(dane2, sizeof(char), size2/sizeof(char), dwa);
	    fclose(jeden);
		fclose(dwa);

	    if(memcmp((const void *)dane, (const void *)dane2, (binSize>size2 ? binSize : size2)) == 0)
			return 0;
		else
			return 1;
	}
	
}