#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void proc_l(int *tab, int size, int move);
void wypisz_i (int *poczatek, int *koniec);
int rand_int (int a, int b);

int main(void)
{
	int tab_1[5] = {1,2,3,4,5};
	int tab_2 [4][2] = {{10,11},{12,13},{14,15},{16,17}};
	int *end_1 = tab_1+(sizeof(tab_1)/sizeof(int));
	int *end_2 = *tab_2+(sizeof(tab_2)/sizeof(int));
	printf("tab_1:\n");
	wypisz_i(tab_1, end_1);
	proc_l(tab_1, sizeof(tab_1)/sizeof(int), 2);
	wypisz_i(tab_1, end_1);

	printf("\ntab_2:\n");
	for(int i=0; i<4; i++)
		wypisz_i(tab_2[i], tab_2[i]+2);
	proc_l(*tab_2, 4*2, 3);
	printf("\n");
	for(int i=0; i<4; i++)
		wypisz_i(tab_2[i], tab_2[i]+2);

	printf("\ntab_3:\n");
	int **tab_3 = malloc(3*sizeof(int*));
	tab_3[0] = malloc(3*5 *sizeof(int)); //tab_3[3][5]
	for(int i=1; i<3; i++)
		tab_3[i] = tab_3[i-1]+5;

	srand(time(NULL));
	for(int g=0; g<3; g++)
		for(int l=0; l<5; l++)
			tab_3[g][l]=rand_int(0, 14);

	for(int i=0; i<3; i++)
		wypisz_i(tab_3[i], tab_3[i]+5);
	proc_l(*tab_3, 5*3, 2);
	printf("\n");
	for(int i=0; i<3; i++)
		wypisz_i(tab_3[i], tab_3[i]+5);

	free(tab_3[0]);
	free(tab_3);
}

void proc_l(int *tab, int size, int move)
{
	//move - liczba przesuniec
	int temp;
	for(int k=0; k<move; k++)
	{
		temp=tab[0];
		for(int i=0; i<size-1; i++)
		{
			tab[i]=tab[i+1];
		}
		tab[size-1]=temp;
	}

}

void wypisz_i (int *poczatek, int *koniec)
{ 
	while (poczatek < koniec) 
		printf ("%4d", *poczatek++); 
	printf ("\n"); 
	return; 
}

int rand_int (int a, int b)
{
 	return a + rand()%(b-a+1);
}