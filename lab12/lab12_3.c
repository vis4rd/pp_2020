#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
	char value;
	struct tnode *next;
}tnode;

void dodaj_na_poczatek(tnode **lista, char val);
void wypisz_liste(tnode *lista);
void zwolnij_liste(tnode **lista);
void dodaj_na_koniec(tnode **lista, char value);

int main(void)
{
	tnode *head = malloc(sizeof(tnode));
	head = NULL;
	wypisz_liste(head);
	dodaj_na_poczatek(&head, 'a');
	dodaj_na_poczatek(&head, 'c');
	dodaj_na_poczatek(&head, 'v');
	dodaj_na_poczatek(&head, 'f');
	dodaj_na_poczatek(&head, 't');
	wypisz_liste(head);
	zwolnij_liste(&head);

	tnode *head2 = malloc(sizeof(tnode));
	head2 = NULL;
	dodaj_na_koniec(&head2, 'a');
	dodaj_na_koniec(&head2, 'c');
	dodaj_na_koniec(&head2, 'v');
	dodaj_na_koniec(&head2, 'f');
	dodaj_na_koniec(&head2, 't');
	wypisz_liste(head2);
	zwolnij_liste(&head2);

}

void dodaj_na_poczatek(tnode **lista, char val)
{
	tnode *temp = malloc(sizeof(tnode));
	if(!temp)
	{
		printf("error1\n");
		return;
	}
	temp->value = val;
	temp->next = *lista;
	*lista = temp;
	return;
}

void wypisz_liste(tnode *lista)
{
	if(!lista)
		printf("Lista jest pusta!\n");
	else
	{
		printf("LISTA: ");
		while(lista)
		{
			printf("%c ", lista->value);
			lista = lista->next;
		}
		printf("\n");
	}
	return;
}

void zwolnij_liste(tnode **lista)
{
	if(!(*lista))
		printf("Lista jest juz pusta!\n");

	tnode *temp = NULL;

	while(*lista)
	{
		temp = (*lista)->next;
		free(*lista);
		*lista = temp;
	}
	free(lista); //zwalniamy rowniez pamiec samego heada
	printf("Liste oprozniono!\n");
	return;
}

void dodaj_na_koniec(tnode **lista, char val)
{
	if(!(*lista))
	{
		*lista = malloc(sizeof(tnode));
		if(!(*lista))
		{
			printf("error\n");
			return;
		}
		(*lista)->value=val;
		(*lista)->next = NULL;
	}
	else
	{
		tnode *temp = *lista;

		while(temp->next!=NULL)
			temp=temp->next;
		temp->next = malloc(sizeof(tnode));
		if(!temp->next)
		{
			printf("error2\n");
			return;
		}
		temp->next->value = val;
		temp->next->next = NULL;
	}
	return;
}