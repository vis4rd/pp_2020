#include <stdio.h>
#include <stdlib.h>

void spacje(int ile);

int main(void)
{
	int wysokosc=-1;
	printf("Podaj wysokosc trojkata Pascala: ");
	while(wysokosc<0)
		scanf("%d", &wysokosc);

	long long *tab = (long long*)malloc(sizeof(long long));
	if(tab==NULL)
	{
		printf("alokacja pamieci zakonczona niepowodzeniem\n");
		exit(0);
	}
	tab[0]=1;
	int czyn1=0, czyn2=0;
	for(int wiersz=1; wiersz<wysokosc+1; wiersz++)
	{
		tab=(long long*)realloc(tab, (wiersz+1)*sizeof(long long));

		tab[wiersz]=0;
		czyn1=0;
		spacje(wysokosc-wiersz);

		for(int pozycja=0; pozycja<wiersz; pozycja++)
		{
			czyn2=tab[pozycja];
			tab[pozycja]=czyn1+czyn2;
			czyn1=czyn2;
			printf("%6.lld  ", tab[pozycja]);
		}
		printf("\n");
	}
	free(tab);
}

void spacje(int ile)
{
	for(int i=0; i<(ile/2); i++)
		printf("%6.s  ", "");

	if(ile%2!=0)
		printf("%4.s", "");
}
