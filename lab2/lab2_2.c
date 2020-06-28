#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int*b);
int *find_max_wsk(int *x, int *y);
void sort (int *tab, int n);

int main(void)
{
	int tab_A[] = {3,5,33,1,7,9,55,1,11,22,12,6,8,4,44,6,42,2,8,26,64,80,16};
	const int A = sizeof(tab_A)/sizeof(int);
	int *top_A=tab_A+A-1;
	int *niep=tab_A+9;

	sort(tab_A, 9);
	sort(niep, 14);

	for(int i=0; i<A; i++)
		printf("%d ", tab_A[i]);

}

void swap(int *a, int*b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int *find_max_wsk(int *x, int *y)
{
	int i=0;
	int max=-99;
	int *wsk=NULL;
	if(*x==*y)
		return x;
	while((x+i)!=y)
	{
		if(*(x+i)>max)
		{
			max=*(x+i);
			wsk=(x+i);
		}
		i++;
	}
	return wsk;
}

void sort (int *tab, int n)
{
	int *top=tab+n;
	int *tutaj = tab;
	for(tutaj; tutaj<tab+n; tutaj++)
	{
		if(*(tutaj)<=*find_max_wsk(tutaj, top))
			swap(tutaj, find_max_wsk(tutaj, top));
	}
}