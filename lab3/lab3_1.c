#include <stdio.h>

#define ROW 5
#define COL 4

void wypisz_i (int *poczatek, int *koniec);
int suma (int *tab, int len);
void swap (int *a, int *b);

int main(void)
{
	int abc[ROW][COL]={{5,-6,5,-4},
					   {-3,-9,3,9},
					   {-2,-2,4,2},
					   {0,-9,-8,7},
					   {1,-2,-8,9}};
	int which_r=1, which_c=0;
	int *top = NULL, *bottom=NULL;
	for(which_r; which_r-1<5; which_r++)
	{
		top=*abc+(which_r*COL);
		bottom=*abc+(which_c*COL);
		wypisz_i(bottom, top);
		which_c++;
	}
	int suma_abc[ROW]={0,0,0,0,0};
	for(int k=0; k<ROW; k++)
		*(suma_abc+k)+=suma(*(abc+k),COL);

	printf("suma_abc = { ");
	wypisz_i(suma_abc, suma_abc+ROW);
	printf(" }\n");

	int suma_all = suma(*abc, sizeof(abc)/sizeof(int));
	printf("suma_all = %2d\n\n", suma_all);

	printf("macierz abc1:\n");
	int abc1[5][5]={{1,2,3,-5,-1},
						{10,-10,2,2,4},
						{6,8,10,-20,2},
						{4,8,0,-10,-2},
						{9,3,3,-6,-12}};

	suma_all = suma(*abc1, sizeof(abc1)/sizeof(int));
	for(int k=0; k<5; k++)//transponowanie
		for(int p=k+1; p<5; p++)
			swap(*(abc1+p)+k, *(abc1+k)+p);
	
	which_r=1, which_c=0;
	for(which_r; which_r-1<5; which_r++)//wypisywanie
	{
		top=*abc1+(which_r*5);
		bottom=*abc1+(which_c*5);
		wypisz_i(bottom, top);
		which_c++;
	}

	int suma_w_kolumnach[5]={0,0,0,0,0};
	for(int k=0; k<5; k++)
		*(suma_w_kolumnach+k)+=suma(*(abc1+k),5);

	printf("Suma_w_kolumnach = { ");
	wypisz_i(suma_w_kolumnach, suma_w_kolumnach+5);
	printf(" }\n");

	int suma_all_po_kol=0;
	for(int i=0; i<5; i++)
		suma_all_po_kol+=suma_w_kolumnach[i];
	printf("\nsuma_all = %d\tsuma_all_po_kol = %d\n\n", suma_all, suma_all_po_kol);
	
	printf("macierz trojkatna dolna: \n");
	for(int s=0; s<5; s++)//wypisywanie macierzy trojkatnej dolnej
	{
		for(int oj=0; oj<5; oj++)
		{
			if(s>=oj)
				printf("%4d", abc1[s][oj]);
			else
				printf("   0");
		}
		printf("\n");
	}

}

void wypisz_i (int *poczatek, int *koniec) 
{ 
  	while (poczatek < koniec) 
    	printf ("%4d", *poczatek++);   
	printf ("\n");    
	return;
}

int suma (int *tab, int len)
{ 
	int ss = 0;
	for (int i = 0; i < len; i++)  
		ss+= tab[i]; 
	return ss;
}

void swap (int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}