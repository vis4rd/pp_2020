#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ROZMIAR 81        //maksymalna dlugość łańcuchów
#define GRAN 20    
       // maksymalna liczba łańcuchów
void sortlan(char *lan[], int num);  //procedura sortująca łancuchy 

int main(void)
{
  char dane[GRAN][ROZMIAR];    //tablica przechowujaca łańcuchy nie dłuzsze niz ROZMIAR znakow nie wiecej niz GRAN
  char **wsklan = calloc(GRAN, sizeof(char*));    //wskaźnik na tablicę wskaźników - rozmiar zależny od ilości wczytanych łańcuchów             
  int licz = 0;                //licznik danych wejsciowych     
  int k;                         
  printf("Podaj maksymalnie %d wierszy \n",GRAN);
  printf("Aby zakonczyc, wcisnij Enter na poczatku wiersza.\n");
 
  while (licz < GRAN && fgets(dane[licz],ROZMIAR,stdin) != NULL && dane[licz][0] != '\n')
  {  
     wsklan[licz] = dane[licz];    //ustaw wskaźnik z tablicy wsklan na wczytany łańcuch     
     licz++;
  }

  puts("\n Wczytano:\n");
  for (k = 0; k < licz; k++)
    printf("%s", wsklan[k]) ;   // z użyciem identyfikataora wsklan
                                //WAZNE: zamienilem puts() na printf() dla czytelnosci outputu
  sortlan(wsklan, licz); // wywłoanie procedury sortującej 

  puts("\n Oto uporzadkowana lista:\n"); 
  for (k = 0; k < licz; k++) 
    printf("%s", wsklan[k]) ;  // z użyciem identyfikataora dane - no niestety z dane[k] nie dziala wiec wrzucilem wsklan[k]
                                //WAZNE: zamienilem puts() na printf() dla czytelnosci outputu
  free(wsklan);

  return 0; 
} 

// procedura sortująca  
void sortlan(char *lan[], int num) 
{ 
  int i=0, j=0; //potrzebne zmienne lokalne 
  for (i; i<num-1; i++)
  {
    for (j=i+1; j<num; j++)
    {
      if (strcmp(lan[i],lan[j]) > 0) 
      { 
        char *temp=lan[i];
        lan[i]=lan[j];
        lan[j]=temp;
      }
    }
  }
} 