#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tnode 
{
  int value;
  struct tnode *next;
}tnode;

void dodaj_na_poczatek(tnode **list, char val);
void wypisz_list(tnode *list);
void zwolnij(tnode *list);
void dodaj_na_koniec(tnode **lista, char val);
int wspolne(tnode *one, tnode *two);

int main(int argc, char *argv[])
{
	tnode *L_1 = NULL;
	tnode *L_2 = NULL;
	int input = -1;
	int mode=1;
	while(input<21)
	{
		scanf("%d", &input);
		if(input>20)
			break;
		if(input == 0 && mode < 3)
			mode = 2;

		if(mode == 1)//mode 1 = dodawanie elementow do obu list
		{
			if(input%2==0)
				dodaj_na_koniec(&L_1, input);
			else if(input%2!=0)
				dodaj_na_koniec(&L_2, input);
		}
		else if(mode == 2)//mode 2 = odpowiednie laczenie drugiej listy
		{
			dodaj_na_koniec(&L_1, input);//dodawanie 0 do konca listy pierwszej
			tnode *temp = L_1;
			tnode *temp2 = L_2;
			while(temp)//wypisywanie listy pierwszej
			{
				printf("(%d) ", temp->value);
				if(temp->value == 0)
					break;
				temp = temp->next;
			}
			printf("\n");
			while(temp2)//wypisywanie listy drugiej
			{
				printf("(%d) ", temp2->value);
				if(temp2->next == NULL)
					break;
				temp2 = temp2->next;
			}
			printf("\n");
			if(temp2)
				temp2->next = temp;//linkujemy koniec listy drugiej do 0 z listy pierwszej
			else
				L_2 = temp;
			mode = 3;
		}
		else if(mode == 3)//mode 3 = dodawanie elementow tylko do listy pierwszej
			dodaj_na_koniec(&L_1, input);
	}
	printf("L_1:  ");wypisz_list(L_1);
	printf("L_2:  ");wypisz_list(L_2);

	if(wspolne(L_1, L_2))
		printf("sa elementy wspolne\n");
	else
		printf("nie ma elementow wspolnych\n");

	//odlaczenie L2 do zwolnienia pamieci
	if(L_1 != NULL && L_2 != NULL)//jesli jest co odlaczac
	{
		tnode *temp = L_2;
		if(temp->value == 0)
			L_2 = NULL;
		while(temp)
		{
			if(temp->next && temp->next->value == 0)
			{
				temp->next = NULL;
				break;
			}
			temp = temp->next;
		}
	}
	zwolnij(L_1);
	zwolnij(L_2);
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

void wypisz_list(tnode *list)
{
	if(list == NULL)
	{	
	  	printf("void wypisz_list() : Lista pusta \n");
      	return;
   	}

	while(list != NULL)
	{
	 	printf("%d ", list->value);
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

int wspolne(tnode *one, tnode *two)
{
	if(one == NULL || two == NULL)
		return 0;
	tnode *temp;
	while(one)
	{
		temp = two;
		while(temp)
		{
			if(one==temp)
				return 1;
			temp = temp->next;
		}
		one = one->next;
	}
	return 0;
}