#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct tnode 
{
  char value;
  struct tnode *next;
}tnode;

void dodaj_na_poczatek(tnode **list, char val);
void dodaj_na_koniec(tnode **list, char var);
void wypisz_list(tnode *list);
void zwolnij(tnode *list);
tnode *reverse_list(tnode *list);
void dodaj_alfabetycznie(tnode **lista, char val);
tnode *usun(tnode **lista, char val);

int main()
{
	tnode *head = NULL; //inicjalizacja listy pustej
	printf("zad 1: \n");
	dodaj_na_poczatek(&head, 'i');
	dodaj_na_poczatek(&head, 'u');
	dodaj_na_poczatek(&head, 'd');
	dodaj_na_poczatek(&head, 'f');
	wypisz_list(head);
	head = reverse_list(head);
	printf("po odwroceniu: ");
	wypisz_list(head);
	zwolnij(head);

	printf("\nzad 2: \n");
	tnode *head2 = NULL;
	dodaj_na_poczatek(&head2, 'z');
	dodaj_na_poczatek(&head2, 'k');
	dodaj_na_poczatek(&head2, 'j');
	dodaj_na_poczatek(&head2, 'a');
	wypisz_list(head2);
	dodaj_alfabetycznie(&head2, 'w');
	printf("po dodaniu 'w': ");
	wypisz_list(head2);
	dodaj_alfabetycznie(&head2, 'a');
	wypisz_list(head2);
	dodaj_alfabetycznie(&head2, 'z');
	wypisz_list(head2);
	dodaj_alfabetycznie(&head2, 'c');
	wypisz_list(head2);
	zwolnij(head2);

	printf("\nzad 3: \n");
	tnode *head3 = NULL;
	dodaj_na_poczatek(&head3, 'a');
	dodaj_na_poczatek(&head3, 'a');
	dodaj_na_poczatek(&head3, 'z');
	dodaj_na_poczatek(&head3, 'A');
	dodaj_na_poczatek(&head3, 'k');
	dodaj_na_poczatek(&head3, 'a');
	dodaj_na_poczatek(&head3, 'j');
	dodaj_na_poczatek(&head3, 'a');
	dodaj_na_poczatek(&head3, 'a');
	wypisz_list(head3);
	tnode *left = usun(&head3, 'a');
	printf("\npo wyluskaniu elementow %c\n", 'a');
	wypisz_list(head3);
	wypisz_list(left);

	zwolnij(left);
	zwolnij(head3);
}
  
void dodaj_na_poczatek(tnode **list, char val)
{
	tnode *wsk = malloc(sizeof(tnode));
	if(!wsk)
	{
		printf("void dodaj_na_poczatek() : alokacja pamieci nieudana\n");
		return;
	}
	wsk->value = val;
	wsk->next = *list;
	*list = wsk;
	return;
}

void dodaj_na_koniec(tnode **list, char var)
{	
	tnode *wsk = malloc(sizeof(tnode));
	if(!wsk)
	{
		printf("void dodaj_na_poczatek() : alokacja pamieci nieudana\n");
		return;
	}
	wsk->value = var;
	wsk->next = NULL;
	
	if(*list ==NULL)
	  *list = wsk;
	else 
	{
		tnode *p = *list; // wskaznikiem p przesuniemy sie na ostatni element listy i dopniemy tam nowy element
		while(p -> next !=NULL) //przesuwamy sie na koniec listy
		     p = p->next;
		p->next = wsk;  //dopinamy
	}
	return;	
}

void wypisz_list(tnode *list)
{
	if(list == NULL)
	{	
	  	printf("void wypisz_list() : Lista jest pusta \n");
      	return;
   	}

	while(list != NULL)
	{
	 	printf("%c   ", list->value);
	 	list = list->next;
   	}
   	printf("\n");
	return;
}

void zwolnij(tnode *list)
{
	tnode *p2 = NULL;
	while(list != NULL)
	{
		p2 = list->next;
		free(list);
		list = p2;
	}
	return;	
}

tnode *reverse_list(tnode *list)
{
	tnode *prev = NULL;
	tnode *cur = list;
	tnode *nast = NULL;
	while(cur != NULL)
	{
		nast = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nast;
	}
	list = prev;
	return list;
}

void dodaj_alfabetycznie(tnode **lista, char val)
{
	tnode *wsk = malloc(sizeof(tnode));
	if(!wsk)
	{
		printf("void dodaj_alfabetycznie() : error1\n");
		return;
	}
	wsk->value = val;

	if(*lista == NULL)//jesli lista pusta
	{
		*lista = wsk;
		wsk->next = NULL;
	}
	else
	{
		tnode *iter = *lista;
		if(wsk->value <= iter->value)
		{
			dodaj_na_poczatek(lista, val);
			free(wsk);
		}
		else
		{
			while(iter->next != NULL)
			{
				if(wsk->value <= iter->next->value)
					break;
				iter = iter->next;
			}
			tnode *temp = iter->next;
			iter->next = wsk;
			wsk->next = temp;
		}
	}
	return;
}

tnode *usun(tnode **lista, char val)
{
	if(*lista == NULL)//lista jest pusta
		return NULL;

	tnode *deleted = NULL;

	tnode *iter = *lista;//iterator
	tnode *hter = NULL;//element poprzedni
	while(iter != NULL)
	{
		if(toupper(val) == iter->value || tolower(val) == iter->value)//znaleziono wartosc
		{
			if(iter == *lista)//pierwszy element
			{
				dodaj_na_poczatek(&deleted, iter->value);//dodajemy do listy usunietych wartosci
				tnode *drugi = iter->next;
				free(iter);
				*lista = drugi;//drugi element staje sie pierwszym
				iter = drugi;//ustawiamy iterator z powrotem (na pierwszy element) zeby kontynuowac 
							 // sprawdzanie
				continue;//jesli sa dwa elementy takie same na poczatku, to zeby przy inkrementacji
						 // wskaznika iter nie pominac nowego pierwszego elementu, robimy continue

				//warunek na istnienie elementu sprawdzany jest przed obiegiem nastepnej petli
				// dlatego taki chwyt jest mozliwy

				//ponadto iter i hter sa w razie czego dobrze ustawione, wiec nie jest wymagana
				// zadna dodatkowa akcja

				//biada tym co probuja to napisac z przepinaniem wskaznikow
			}
			else//inny element
			{
				dodaj_na_poczatek(&deleted, iter->value);
				hter->next = iter->next;
				free(iter);
				iter = hter;//ustawiamy iterator z powrotem zeby kontynuowac sprawdzanie
			}
		}
		if(*lista == NULL)//jest mozliwosc, że pierwszy element byl ostatnim
			break;
		hter = iter;
		iter = iter->next;
	}
	return deleted;
}