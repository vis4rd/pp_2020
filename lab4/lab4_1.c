#include <stdio.h>
#include <stdlib.h>

float rand_float (float a, float b);
void wypisz(float *T, int size);

int main(void)
{
	int rozmiar=0;
	printf("podaj rozmiar tablicy: ");
	scanf("%d", &rozmiar);
	float *tab = malloc(rozmiar*sizeof(float));
	if(tab==NULL)
	{
		printf("alokacja pamieci zakonczona niepowodzeniem\n");
		exit(0);
	}
	for(int p=0; p<rozmiar; p++)
		tab[p]=(float)rand_float(23.0f,34.0f);
	wypisz(tab, rozmiar);

	int nowyRozmiar=0;
	printf("\n\npodaj nowy rozmiar: ");
	scanf("%d", &nowyRozmiar);
	if(nowyRozmiar>rozmiar)
	{
		tab=(float*)realloc(tab, nowyRozmiar*sizeof(float));
		for(int k=rozmiar; k<nowyRozmiar; k++)
			tab[k]=(float)rand_float(-20.0f, -5.0f);
		wypisz(tab, nowyRozmiar);
	}
	else
		printf("\nnowy rozmiar jest mniejszy od starego\n");
	free(tab);
	printf("\n");
}

float rand_float (float a, float b)
{
 	return (a + (rand()/(1.0 * RAND_MAX)) *(b-a));
}

void wypisz(float *T, int size)
{
	//printf("\n");
	float *iter=T;
	for(iter; iter<T+size;iter++)
		printf("%f  ", *iter);
}