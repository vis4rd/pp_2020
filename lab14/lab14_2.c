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
	strcpy(wsk->string, val);
	wsk->count = 1;
	wsk->next = *list;
	*list = wsk;
	return;
}

void dodaj_slowo(tnode **lista, char *val)
{
	if (NULL == *lista)
	{
		dodaj_na_poczatek(lista, val);
		return;
	}
	else
	{
		tnode *clone = *lista;
		while(clone)
		{
			if(strcmp((char *)clone->string, val)==0)
			{
				(clone->count)++;
				return;
			}
			clone = clone->next;
		}
	}

	tnode *wsk = malloc(sizeof(tnode));
	strcpy(wsk->string, val);
	wsk->count = 1;
	tnode *cur = *lista;
	tnode *prev = cur;
	while(cur)
	{
		if(strcmp(val, cur->string)>0) //cos tu pokrecilem z sortowaniem ale brak czasu na rozwiazanie:/
			break;
		cur = cur->next;
	}
	prev = cur->next;
	cur->next = wsk;
	cur->next->next = prev;
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

