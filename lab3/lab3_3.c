#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void wypisz_d (double *poczatek, double *koniec);
void wypelnij (double (*a)[6], int n);
double rand_double (double a, double b);

int main(void)
{
	srand(time(NULL));
	double A_1[8][6];
	double A_2[10][6];
	for(int i=0; i<8; i++)
		for(int j=0; j<6; j++)
			A_1[i][j] = 0.0;
	for(int i=0; i<10; i++)
		for(int j=0; j<6; j++)
			A_2[i][j] = 0.0;
	
	wypelnij(A_1, 8);
	wypelnij(A_2, 10);
	for(int k=0; k<8; k++)
		wypisz_d(&A_1[k][0], &A_1[k][5]);
	printf("\n");
	for(int k=0; k<10; k++)
		wypisz_d(&A_2[k][0], &A_2[k][5]);
}

void wypisz_d (double *poczatek, double *koniec) 
{ 
	while (poczatek < koniec) 
		printf ("%6.2f", *poczatek++); 
	printf ("\n");    
	return;
}

void wypelnij (double (*a)[6], int n)
{
	double start = rand_double(0.0, 3.0);
 	int size = sizeof(*a)/sizeof(**a);
 	for(int i=0; i<n; i++){
 		for(int k=0; k<size; k++){
 			a[i][k] = start += 0.4;
 		}
 		start-=0.4;
 	}
}

double rand_double (double a, double b)
{
 	return (a + (rand()/(1.0 * RAND_MAX)) *(b-a));
}