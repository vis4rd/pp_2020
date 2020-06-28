#include <stdio.h>
#include <stdlib.h>

#define LEN 4

void wypisz_i (int *poczatek, int *koniec);
int **create_table(int *size);

int main(void)
{
	int rozmiar;
	int **tab = create_table(&rozmiar);
	for(int i=0; i<rozmiar; i++)
		wypisz_i(*(tab+i), *(tab+i)+LEN);
	for(int i=0; i<rozmiar; i++)
		free(tab[i]);
	free(tab);
}

int **create_table(int *size)
{
	int **T = calloc(1, sizeof(int*));
	*T = calloc(LEN, sizeof(int));
	int val;
	int **end = T;
	int current=1;
	int iter=0;
	printf("wpisuj wartosci do tablicy:\n");
	while(1)
	{
		scanf("%d", &val);
		if(val==0)
		{
			while(iter<4)
			{
				T[current-1][iter]=0;
				iter++;
			}
			break;
		}
		else
		{
			if(iter==4)
			{
				current++;
				iter=0;
				T = realloc(T, current*sizeof(int*));
				T[current-1] = calloc(LEN, sizeof(int));
			}
			T[current-1][iter]=val;
			iter++;
		}
	}
	*size=current;
	return T;
}

void wypisz_i (int *poczatek, int *koniec) 
{
	while (poczatek < koniec)
		printf ("%4d", *poczatek++);
	printf ("\n");
	return;
}
