#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 10

int suma(const int *start, const int *end);

int main(void)
{
  srand(time(NULL));
	 
  int tab[N];  //deklaracja tablicy 10 liczb całkowitych, użyj N
  int *p = NULL;//deklaracja wskaźnika p do liczby całkowitej, użyj NULL
  //nie używaj zmiennej int  do indeksowania tablicy
  //przypisz kolejnym elementom tablicy liczby pseudolosowe z przedziału od 7 do 35 i wypisz je na ekran 

  for(p=tab; p<tab+N; p++)
  {
    *p = 7 + rand()%(35-7+1);  // nie korzystaj z tab 
    //oblicz wartość indeksu kolejnych elementów tablicy, 
    //wypisz wartości kolejnych elementów używając p
    printf("p[%ld] = %d\n", p-tab, *p); //uzywamy tutaj %ld, bo teoretycznie adres to long int, a czasami na linuxie gcc sie z tym kloci
  }
  printf("\n");
  //oblicz rekurencyjnie sumę elementów tablicy.
  int su = suma(tab, p);   //nie używaj N

  printf("su=%d\n",su);
  return 0;
}

 //funkcja rekurencyjna liczaca sume elementów tablicy  
int suma (const int *start, const int *end)
{   //nie używaj N 
  if (start<end-1)
    return suma(start+1, end) + *start;
  else
    return *start;
}