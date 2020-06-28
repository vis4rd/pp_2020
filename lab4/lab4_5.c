#include <stdio.h>
#include <stdlib.h>

float rand_float (float a, float b);
void fill_float(float *T, float a, float b, int s);
void wypisz_f(float *tab, int size);

int main(void)
{
	printf("Podaj rozmiar tablicy: ");
	int rozmiar=-1;
	while(rozmiar<0)
		scanf("%d", &rozmiar);
	float *tab = (float*)malloc(rozmiar*sizeof(float));
	if(tab==NULL)
	{
		printf("alokacja pamieci nieudana\n");
		exit(0);
	}
	fill_float(tab, -1.5f, 1.5f, rozmiar);
	float *negative = (float*)malloc(sizeof(float));
	float *positive = (float*)malloc(sizeof(float));
	if(negative==NULL||positive==NULL)
	{
		printf("alokacja pamieci (*) nieudana\n");
		exit(0);
	}
	int size_pos=0;
	int size_neg=0;
	for(int i=0; i<rozmiar; i++)
	{
		if(tab[i]<0)
		{
			size_neg++;
			negative=realloc(negative, size_neg*sizeof(float));
			if(negative==NULL)
			{
				printf("alokacja pamieci negative nieudana\n");
				exit(0);
			}
			negative[size_neg-1]=tab[i];
		}
		else
		{
			size_pos++;
			positive=realloc(positive, size_pos*sizeof(float));
			if(positive==NULL)
			{
				printf("alokacja pamieci positive nieudana\n");
				exit(0);
			}
			positive[size_pos-1]=tab[i];
		}
	}
	printf("tab: "); wypisz_f(tab, rozmiar);
	printf("\nujemne: "); wypisz_f(negative, size_neg);
	printf("\ndodatnie: "); wypisz_f(positive, size_pos);
	free(tab);
	free(negative);
	free(positive);
}

float rand_float (float a, float b)
{
 	return (a + (rand()/(1.0 * RAND_MAX)) *(b-a));
}

void fill_float(float *T, float a, float b, int s)
{
	for(int i=0; i<s; i++)
		T[i]=(float)rand_float(a, b);
}

void wypisz_f(float *tab, int size)
{
	for(int g=0; g<size; g++)
	{
		if(tab[g]!=0)
			printf("%2.4f ", (float)tab[g]);
	}
	printf("\n");
}