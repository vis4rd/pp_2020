#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void swap(int*a, int*b);
void swap_tab(int*a, int*b, int size);
void swap_row(int n, int (*a)[n], int x, int y);
void wypisz_i (int *poczatek, int *koniec);

int main(void)
{
	srand(time(NULL));
	int tab_1[4][5] = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4}; //- wymiana wiersza 1 z 3 przy użyciu procedury swap_row
	int tab_11[4][5] = {1,1,1,1,1,2,2,2,2,2,3,3,3,3,3,4,4,4,4,4}; //- wymiana wiersza 0 z 3 przy użyciu procedury swap_tab
	int tab_2 [5][2] = {1,1,2,2,3,3,4,4,5,5};//- wymiana wiersza 0 z 2 przy użyciu procedury swap_row
	int tab_22 [5][2] = {1,1,2,2,3,3,4,4,5,5};//- wymiana wiersza 1 z 2 przy użyciu procedury swap_tab

	//1
	printf("1:\n");
	int *start_1 = NULL;
	int *end_1 = NULL;
	for(int i=0; i<4; i++){
		start_1 = *(tab_1+i);
		end_1 = *(tab_1+i)+5;
		wypisz_i(start_1, end_1);
		//printf("\n");
	}
	swap_row(5, tab_1, 1, 3);
	printf("\n");
	for(int i=0; i<4; i++){
		start_1 = *(tab_1+i);
		end_1 = *(tab_1+i)+5;
		wypisz_i(start_1, end_1);
		//printf("\n");
	}
	//2
	int *start_11 = NULL;
	int *end_11 = NULL;
	printf("\n2:\n");
	for(int i=0; i<4; i++){
		start_11 = *(tab_11+i);
		end_11 = *(tab_11+i)+5;
		wypisz_i(start_11, end_11);
		//printf("\n");
	}
	swap_tab(tab_11[0], tab_11[3], 5);
	printf("\n");
	for(int i=0; i<4; i++){
		start_11 = *(tab_11+i);
		end_11 = *(tab_11+i)+5;
		wypisz_i(start_11, end_11);
		//printf("\n");
	}
	//3
	int *start_2 = NULL;
	int *end_2 = NULL;
	printf("\n3:\n");
	for(int i=0; i<5; i++){
		start_2 = *(tab_2+i);
		end_2 = *(tab_2+i)+2;
		wypisz_i(start_2, end_2);
		//printf("\n");
	}
	swap_row(2, tab_2, 0, 2);
	printf("\n");
	for(int i=0; i<5; i++){
		start_2 = *(tab_2+i);
		end_2 = *(tab_2+i)+2;
		wypisz_i(start_2, end_2);
		//printf("\n");
	}
	//4
	int *start_22 = NULL;
	int *end_22 = NULL;
	printf("\n4:\n");
	for(int i=0; i<5; i++){
		start_22 = *(tab_22+i);
		end_22 = *(tab_22+i)+2;
		wypisz_i(start_22, end_22);
		//printf("\n");
	}
	swap_tab(tab_22[1], tab_22[2], 2);
	printf("\n");
	for(int i=0; i<5; i++){
		start_22 = *(tab_22+i);
		end_22 = *(tab_22+i)+2;
		wypisz_i(start_22, end_22);
		//printf("\n");
	}
	//5 dla tablicy tab_3 - wymiana wiersza 1 z 5
	int **tab_3 = malloc( 6*sizeof(int*));

	for(int i = 0; i < 6; i++)  
		tab_3[i] = malloc(3 * sizeof(int)); //tab3[6][3]

	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 3; j++)
			tab_3[i][j]  =  rand() % 21;

	printf("\n5:\n");
	int *start_3 = NULL;
	int *end_3 = NULL;
	for(int i=0; i<6; i++){
		start_3 = *(tab_3+i);
		end_3 = *(tab_3+i)+3;
		wypisz_i(start_3, end_3);
		//printf("\n");
	}
	swap_tab(tab_3[1], tab_3[5], 3);
	printf("\n");
	for(int i=0; i<6; i++){
		start_3 = *(tab_3+i);
		end_3 = *(tab_3+i)+3;
		wypisz_i(start_3, end_3);
		//printf("\n");
	}

	for(int i=0; i<6; i++)
		free(tab_3[i]);
	free(tab_3);

	//6 dla tablicy tab_33 - wymiana wiersza 2 z 4
	printf("\n6:\n");
	int **tab_33= malloc( 6*sizeof(int*));

	tab_33[0] = malloc(6*3 * sizeof(int)); //tab_33[6][3]
	for(int i = 1; i < 6; i++)  
		tab_33[i] = tab_33[i-1]+3;

	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 3; j++)
			tab_33[i][j]  =  rand() % 21;

	int *start_33 = NULL;
	int *end_33 = NULL;
	for(int i=0; i<6; i++)
	{
		start_33 = *(tab_33+i);
		end_33 = *(tab_33+i)+3;
		wypisz_i(start_33, end_33);
	}
	swap_tab(tab_33[2],tab_33[4], 3);
	printf("\n");
	for(int i=0; i<6; i++)
	{
		start_33 = *(tab_33+i);
		end_33 = *(tab_33+i)+3;
		wypisz_i(start_33, end_33);
	}
	free(tab_33[0]);
	free(tab_33);
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return;
}


void swap_tab(int*a, int*b, int size)
{
//procedura wymieniająca zawartość tablic a i b (o tym samym rozmiarze) przy użyciu procedury swap
// wymieniamy zawartość elementu a[k] z zawartością elementu b[k]
	for(int k=0; k<size; k++)
		swap((a+k), (b+k));
	return;
}


void swap_row(int n, int (*a)[n], int x, int y)
{
//procedura wymieniająca  wiersz  x z wierszem y - wiersze mają tę samą długość
// przy użyciu procedury swap_tab
	swap_tab(a[x], a[y], n);
	return;
}

void wypisz_i (int *poczatek, int *koniec)
{ 
	while (poczatek < koniec) 
		printf ("%4d", *poczatek++); 
	printf ("\n"); 
	return; 
}
