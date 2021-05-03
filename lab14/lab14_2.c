#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode 
{
	char string[20];
	int count;
	struct tnode *next;
}tnode;

void dodaj_na_poczatek(tnode **list, char *val);
void dodaj_slowo(tnode **lista, char *val);
void wypisz_list(tnode *list);
void zwolnij(tnode *list);

int main(int argc, char *argv[])
{
	tnode *head = NULL;
	char *filename = argv[1];
	FILE *fb = fopen(filename, "r");
	char word[20];
	while(fscanf(fb, "%s", word) == 1)
		dodaj_slowo(&head, word);
	fclose(fb);

	wypisz_list(head);
	zwolnij(head);
}

void dodaj_na_poczatek(tnode **list, char *val)
{
	tnode *wsk = malloc(sizeof(tnode));
	if(!wsk)
	{
		printf("error1\n");
		return;
	}
	wsk->count = 1;
	strcpy(wsk->string, val);

	if(*list == NULL)//pusta lista
	{
		wsk->next = NULL;
	}
	else
	{
		wsk->next = *list;
	}
	*list = wsk;
	return;
}

void dodaj_slowo(tnode **lista, char *val)
{
	if (NULL == *lista) //lista jest pusta
	{
		dodaj_na_poczatek(lista, val);
		return;
	}
	else //lista ma elementy
	{
		tnode *iter = *lista;
		while(iter)
		{
			if(strcmp((char *)iter->string, val)==0)//jesli na liscie jest juz taki element
			{
				(iter->count)++;
				return;
			}
			iter = iter->next;
		}
		//wyjscie z petli oznacza, ze nie znaleziono takiego samego elementu

		iter = *lista;
		tnode *prev = *lista;
		while(iter != NULL)
		{
			if(strcmp(val, (char *)iter->string) <= 0)//przed tym elementem trzeba wstawic nowy
			{
				if(iter == *lista)//jesli wstawic przed pierwszy element
				{
					tnode *el = malloc(sizeof(tnode));//tworzymy element
					strcpy(el->string, val);
					el->count = 1;//wypelniamy dane

					el->next = iter;
					*lista = el;
				}
				else
				{
					tnode *el = malloc(sizeof(tnode));//tworzymy element
					strcpy(el->string, val);
					el->count = 1;//wypelniamy dane

					prev->next = el;//za poprzednim wstawiamy nowy
					el->next = iter;//nowy element wskazuje na obecny
				}
				return;
			}
			else
			prev = iter;
			iter = iter->next;
		}
		//nie znaleziono elementu wiekszego od szukanego, wiec nowy element bedzie ostatnim
		tnode *el = malloc(sizeof(tnode));//tworzymy element
		strcpy(el->string, val);
		el->count = 1;//wypelniamy dane

		prev->next = el;
		el->next = NULL;
	}
	return;
}

void wypisz_list(tnode *list)
{
	if(list == NULL)
	{	
	  	printf("void wypisz_list() : Lista pusta \n");
      	return;
   	}

	while(list != NULL)
	{
	 	printf("%s: %d\n", list->string, list->count);
	 	list = list->next;
   	}
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

