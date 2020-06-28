#include <stdio.h>

void wypisz_d (double *poczatek, double *koniec);
double suma (double **tab, int ind, int len);
double *find_tab(double **tab, int n);
double *find_tab_1(double **tab, int n_tab, int n);
void swap(double *one, double *two);
void swap_new(double **one, double **two);

int main(void)
{
	double T_1[4] = {1.0,3.0, 2.0,1.5};
	double T_2[4] = {1.8, 2.0, 1.2, 3.8};
	double T_3[4] = {5.6, 1.0, 3.3, 3.3};
	double T_4[4] = {1.1, 2.1, 6.5, 1.7};
	double T_5[4] = {6.7, 7.8, 9.1, 1.0};

	double *TAB[5]={T_1, T_2, T_3, T_4, T_5};

	for (int i = 0; i<sizeof(TAB)/sizeof(*TAB); i++)
	{
		for (int j = 0; j<4; j++)
	    	printf(" %.2f", TAB[i][j]);
        printf ("\n");
    }	

    printf("\n");
    double **TABLICA = TAB;
    for(int k=0; k<5; k++)
    	wypisz_d(&TABLICA[k][0], &TABLICA[k][4]);

    printf("\nTAB[0]=%.2f\n\n", suma(TAB, 0, sizeof(T_1)/sizeof(double)));
    double *znajdz=find_tab(TAB, 5);
    wypisz_d(znajdz, znajdz+4);
}

void wypisz_d (double *poczatek, double *koniec) 
{ 
	while (poczatek < koniec) 
		printf ("%6.2f", *poczatek++); 
	printf ("\n");    
	return;
}

double suma (double **tab, int ind, int len)
{
	double suma=0;
	for(int k=0; k<len; k++)
		suma+=(double)tab[ind][k];
	return (double)suma;
}

double *find_tab(double **tab, int n)
{
	double min=999999;
	double sum=0;
	double *ptr=NULL;
	for(int i=0; i<n; i++)
	{
		sum=suma(tab, i, 4);
		if(sum<min)
		{
			min=sum;
			ptr=tab[i];
		}
	}
	return ptr;
}

double *find_tab_1(double **tab, int n_tab, int n)//n_tab - liczba tablic podpietych do TAB, n - dlugosc podpietej tablicy
{
	double min=999999;
	double sum=0;
	double *ptr=NULL;
	for(int i=0; i<n_tab; i++)
	{
		sum=suma(tab, i, n);
		if(sum<min)
		{
			min=sum;
			ptr=tab[i];
		}
	}
	return ptr;
}

void swap(double *one, double *two)
{
	double temp;
	temp=*one;
	*one=*two;
	*two=temp;
	return;
}

void swap_new(double **one, double **two)//nietestowane
{
	double *temp;
	temp=*one;
	*one=*two;
	*two=temp;
	return;
}