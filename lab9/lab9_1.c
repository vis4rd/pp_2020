#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int rand_int(int a, int b);
int char_cmp(const void *a, const void *b);
int str_cmp(const void *a, const void *b);

int main()
{
	srand(time(NULL));
	char tab[20][16];
	int choice;
	for(int i=0; i<20; i++)
	{
		for(int j=0; j<16; j++)
		{
			choice = rand_int(0,1);
			switch(choice)
			{
				case 0: tab[i][j] = rand_int('a', 'z'); break;
				case 1: tab[i][j] = rand_int('A', 'Z'); break;
			}
		}
		tab[i][15]='\0';
	}
	printf("przed sortowaniem znakow: \n");
	for(int k=0; k<20; k++)
		printf("%s\n", tab[k]);

	for(int l=0; l<20; l++)
		qsort(tab[l], 15, sizeof(char), char_cmp);

	printf("\npo sortowaniu znakow: \n");
	for(int k=0; k<20; k++)
		printf("%s\n", tab[k]);

	qsort(tab, 20, 16*sizeof(char), str_cmp);

	printf("\npo sortowaniu wierszy: \n");
	for(int k=0; k<20; k++)
		printf("%s\n", tab[k]);

}

int rand_int(int a, int b) 
{
 	return a + rand()%(b-a+1);
}

int char_cmp(const void *a, const void *b)
{
	const char *x = a;
	const char *y = b;
	int p = tolower(*x);
	int q = tolower(*y);
	if(p==q)
	{
		if(islower(*x))
			p--;
		if(islower(*y))
			q--;
	}

	if(p>q)
		return 1;
	else if(p<q)
		return -1;
	else
		return 0;
}

int str_cmp(const void *a, const void *b)
{
	const char *x = a;
	const char *y = b;
	return strcmp(x, y);
}