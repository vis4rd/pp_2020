#include <stdio.h>

void eratostenes(int *T,int N);
void wypelnij(int *T, int N);

int main(void)
{

	int val=1;
	do{
		scanf("%d", &val);
	}while((val<=0)||(val>=100000));
	const int P=val;
	int tab[P];
	wypelnij(tab, P);
	/*for(int s=0; s<P; s++)
		printf("%d ", tab[s]);*/
	eratostenes(tab, P);

}

void eratostenes(int *T, int N)
{
	for(int k=2; k<N; k++)
		for(int i=2; k*i<N; i++)
				T[i*k]=1;
	for(int s=0; s<N; s++)
		if(T[s]==0)
			printf("%d\n", s);
}

void wypelnij(int *T, int N)
{
	for(int s=0; s<N; s++)
		T[s]=0;
}

