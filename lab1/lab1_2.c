#include <stdio.h>

#define N 10

char *sort(char *source, int size);

int main(void)
{
	char tab[N] = { 'z', 'o', 'r', 'R', 'o', 'K', 'O', 'z', 'A', 'k' };

	for(int i=0; i<N; i++)
		printf("%c ", tab[i]);
	printf("\n");

	char *res = sort(tab, N);

	for(int i=0; i<N; i++)
		printf("%c ", res[i]);
	printf("\n");
}

char *sort(char *source, int size)
{
	char temp;
	for(int i=0; i<size; i++)
	{
		for(int k=i+1; k<size; k++)
		{
			if(source[k]<source[i])
			{
				temp = source[i];
				source[i] = source[k];
				source[k] = temp;
			}
		}
	}
	return source;
}