#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

float rand_float (float a, float b);
void wyp(float *T);
void quicksort(float *tab, int one, int two);
int partition(float *tab, int one, int two);
void swap (float *a, float *b);
void tabprint(float *T);

int main(void)
{
	srand(time(NULL));
	float tabf[N];
	wyp(tabf);
	tabprint(tabf);
	quicksort(tabf, 0, N-1);
	tabprint(tabf);

}

float rand_float (float a, float b)
{
 	return (a + (rand()/(1.0 * RAND_MAX)) *(b-a));
}

void wyp(float *T)
{
	for(int i=0; i<N; i++)
		T[i]=(float)rand_float(-1.5f, 5.5f);
}

void quicksort(float *tab, int one, int two)
{
	int here;
	if(one<two)
	{
		here = partition(tab, one, two);
		quicksort(tab, one, here);
		quicksort(tab, here+1, two);
	}
}

//UWAGA: W pseudokodzie w zadaniu jest blad, warunki petli while to maja
// byc < i >, a nie <= i >=. W drugim wypadku wychodzimy poza tablice
// i program sie wysypuje
int partition(float *tab, int one, int two)
{
	float x = tab[one];
	int i=one-1;
	int j=two+1;

	while(1)
	{
		do{
			j--;
		}while(tab[j]<x);//mowa o tym warunku

		do{
			i++;
		}while(tab[i]>x);//i tym

		if(i<j)
			swap (tab+i, tab+j);
		else
			return j;
	}
}

void swap (float *a, float *b)
{
	float temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void tabprint(float *T)
{
	static int x=0;
	printf("table %d: ", x);
	for(int i=0; i<N; i++)
		printf("%2.2f ", T[i]);
	x++;
	printf("\n");
}