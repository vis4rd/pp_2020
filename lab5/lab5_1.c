#include <stdio.h>
#include <stdlib.h>

#define COLUMN 5
#define ROW 4

void wypisz_i (int *poczatek, int *koniec);

int main(void)
{
	int **array_1 = calloc(ROW, sizeof(int*));
	for(int k=0; k<ROW; k++)
		*(array_1+k) = calloc(COLUMN, sizeof(int));

	for(int g=0; g<ROW; g++)
		wypisz_i(*(array_1+g), *(array_1+g)+COLUMN);

	for(int p=0; p<ROW; p++)
		free(array_1[p]);
	free(array_1);


	int **array_2 = calloc(ROW, sizeof(int*));
	*array_2 = calloc(ROW*COLUMN, sizeof(int));
	for(int i=1; i<ROW; i++)
		*(array_2+i) = *(array_2+i-1)+COLUMN;

	printf("\n");
	for(int i=0; i<ROW; i++)
		wypisz_i(*(array_2+i),*(array_2+i)+COLUMN);

	free(*array_2);
	free(array_2);


	int (*array_3)[COLUMN];
    array_3=calloc(COLUMN*ROW,sizeof(int));

    printf("\n");
    for(int i=0; i<ROW; i++)
        wypisz_i(*(array_3+i),*(array_3+i)+COLUMN);

    free(array_3);
}

void wypisz_i (int *poczatek, int *koniec) 
{
	while (poczatek < koniec)
		printf ("%4d", *poczatek++);
	printf ("\n");
	return;
}