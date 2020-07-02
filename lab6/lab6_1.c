#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *concat(char **tab);

int main(void)
{
	char *strings[ ] = {"The sun did not shine. ","It was too wet to play."," So we sat in the house - ","All that cold, cold, wet day."};
	char *wynik = concat(strings);
	puts(wynik);
	free(wynik);
}

char *concat(char **tab)
{
	int size=0;
	for(int i=0; i<4; i++)
		size+=strlen(tab[i]);
	char *temp = malloc(size*sizeof(char));
	temp[0]='\0';
	for(int i=0; i<4; i++)
		strcat(temp, tab[i]);
	return temp;
}