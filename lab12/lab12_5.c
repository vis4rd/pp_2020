#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float rand_f(float min, float max);
float **matrix(int rows, int col, FILE *fp);
void wypisz_tab2(float **tab, int x, int y);
void zwolnij(float **tab, int x, int y);

int main(void)
{
	srand(time(0));
    float tab[30];
    int i, x, y; //x i y nie sa uzywane, to pewnie mial byc rozmiar
    //ale wpisuje rozmiary przy wywolaniu funkcji, 
    //poza tym testujemy rozne rodzaje macierzy 
    //i deklaracja np 6 rozmiarow bylaby niepotrzebna
    int var;
    printf ("rozmiar (max 30) = ");
    scanf ("%d", &var);
    for(i=0; i<var; i++)
		tab[i]=rand_f(0.0, 40.0);
 
 	//zapisywanie do pliku binarnego dane_1.dat  zawartosci tablicy tab
 	FILE *f_1 = fopen ("dane_1.dat","wb");
	fwrite (tab,sizeof(float),var, f_1);
	fclose(f_1);

	FILE *f_2 = fopen("dane_1.dat", "rb");
	float **result1 = matrix(10, 3, f_2);
	rewind(f_2);
	float **result2 = matrix(5, 6, f_2);
	rewind(f_2);
	float **result3 = matrix(3, 10, f_2);
	rewind(f_2);
	float **result4 = matrix(4, 6, f_2);
	rewind(f_2);
	float **result5 = matrix(7, 5, f_2);
	fclose(f_2);

	printf("macierz 3x10: \n");
	wypisz_tab2(result1, 10, 3);
	printf("\nmacierz 6x5: \n");
	wypisz_tab2(result2, 5, 6);
	printf("\nmacierz 10x3: \n");
	wypisz_tab2(result3, 3, 10);
	printf("\nmacierz 6x4: \n");
	wypisz_tab2(result4, 4, 6);
	printf("\nmacierz 5x7: \n");
	wypisz_tab2(result5, 7, 5);

	zwolnij(result1, 10, 3);
	zwolnij(result2, 5, 6);
	zwolnij(result3, 3, 10);
	zwolnij(result4, 4, 6);
	zwolnij(result5, 7, 5);
	
	return 0;
} 

float rand_f(float min, float max)
{
  	float r = (float) rand()/RAND_MAX; 
    return  r*(max - min) + min;
}

float **matrix(int rows, int col, FILE *fp)
{
	float **tab = calloc(col, sizeof(float*));
	if(!tab)
	{
		printf("error1\n");
		return NULL;
	}
	for(int i=0; i<col; i++)
	{
		tab[i] = calloc(rows, sizeof(float));
		if(!(tab[i]))
		{
			printf("error2\n");
			return NULL;
		}
	}
	float temp;
	for(int i=0; i<col; i++)
	{
		for(int j=0; j<rows; j++)
		{
			if(fread(&temp, sizeof(float), 1, fp)==1)
				tab[i][j] = temp;
			else//braklo danych
			{
				tab[i][j] = 0.f;
			}
		}
	}
	return tab;
}

void wypisz_tab2(float **tab, int x, int y)
{
	for(int i=0; i<y; i++)
	{
		for(int j=0; j<x; j++)
			printf("%5.2f ", tab[i][j]);
		printf("\n");
	}
	return;
}

void zwolnij(float **tab, int x, int y)
{
	if(!tab)
		return;

	for(int i = 0; i < y; i++)
		free(tab[i]);
	free(tab);
}