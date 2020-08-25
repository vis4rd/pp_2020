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
	printf("zad 1: ");
	dodaj_na_poczatek(&head, 'i');
	dodaj_na_poczatek(&head, 'u');
	dodaj_na_poczatek(&head, 'd');
	dodaj_na_poczatek(&head, 'f');
	wypisz_list(head);
	head = reverse_list(head);
	printf("po odwroceniu: ");
	wypisz_list(head);
	zwolnij(head);
	free(head);

	tnode *head2 = NULL;
	dodaj_na_poczatek(&head2, 'z');
	dodaj_na_poczatek(&head2, 'k');
	dodaj_na_poczatek(&head2, 'j');
	dodaj_na_poczatek(&head2, 'a');
	printf("\nzad 2: ");
	wypisz_list(head2);
	dodaj_alfabetycznie(&head2, 'w');
	printf("po dodaniu 'w': ");
	wypisz_list(head2);

	printf("\nzad 3: ");
	tnode *left = usun(&head, 'a');
	printf("\npo wyluskaniu elementow %c\n", 'a');
	wypisz_list(head);
	wypisz_list(left);

	zwolnij(left);
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
	if (*lista == NULL)//jesli lista pusta
		*lista = wsk;
	else
	{
		tnode *cur = *lista;
		tnode *prev = cur;
		while(val > cur->next->value)
			cur = cur->next;
		
		prev = cur->next;
		cur->next = wsk;
		cur->next->next = prev;
	}
	return;
}

tnode *usun(tnode **lista, char val)
{
	tnode *save = *lista;
	tnode *left = NULL;
	if(*lista == NULL)
	{
		printf("tnode *usun() : Glowna lista jest pusta\n");
		return NULL;
	}

	tnode *temp = *lista;
	while((*lista)->next)//PROBLEM Z DWIEMA LITERAMI POD RZAD
	{
		//printf("1\n");
		//wypisz_list(save);
		if(tolower((*lista)->value) == tolower(val)) //HEAD SIE PSUJE PO USUWANIU PIERWSZEGO ELEMENTU
		{
			dodaj_na_koniec(&left, (*lista)->value);
			tnode *bruh = *lista; 
			if( bruh )
			{
				*lista = bruh->next;
				save = *lista;
				free(bruh);
			}
		}
		else if(tolower((*lista)->next->value) == tolower(val))
		{
			dodaj_na_koniec(&left, (*lista)->next->value);
			temp = (*lista)->next;
			(*lista)->next = temp->next;
			free(temp);
			*lista = save;
		}
		(*lista) = (*lista)->next;
	}
	*lista = save;
	return left;
}

//BUILD 4
/*tnode *temp;
while((*lista)->next)//PROBLEM Z DWIEMA LITERAMI POD RZAD
{
	//printf("1\n");
	//wypisz_list(save);
	if(tolower((*lista)->next->value) == tolower(val))
	{
		dodaj_na_koniec(&left, (*lista)->next->value);
		tnode *temp = (*lista)->next;
		//printf("temp = %c\n", temp->value);
		(*lista)->next = temp->next;
		printf("temp = %c , lista->next = %c\n", temp->value, (*lista)->next->value);
		free(temp);
	}
	(*lista) = (*lista)->next;
}*/

//BUILD 7
/*else if(tolower((*lista)->next->value) == tolower(val))
		{
			dodaj_na_koniec(&left, (*lista)->next->value);
			temp = (*lista)->next;
			(*lista)->next = temp->next;
			free(temp);
			*lista = save;
		}
		(*lista) = (*lista)->next;*/