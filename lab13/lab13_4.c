#include <stdio.h>
#include <stdlib.h>

typedef struct tnode 
{
   char value;
   struct tnode *next;
}tnode;

void dodaj_na_koniec(tnode **list, char var);
void wypisz_list(tnode *list);
void zwolnij(tnode *list);
tnode *cat_list(tnode **one, tnode **two);

int main(void)
{
	tnode *lista_1 = NULL;
	tnode *lista_2 = NULL;
	dodaj_na_koniec(&lista_1, 'a');
	dodaj_na_koniec(&lista_1, 'k');
	dodaj_na_koniec(&lista_1, 'l');
	dodaj_na_koniec(&lista_1, 'z');
	dodaj_na_koniec(&lista_2, 'a');
	dodaj_na_koniec(&lista_2, 'b');
	dodaj_na_koniec(&lista_2, 'l');
	dodaj_na_koniec(&lista_2, 'n');
	dodaj_na_koniec(&lista_2, 'w');
	printf("lista_1: "); wypisz_list(lista_1);
	printf("lista_2: "); wypisz_list(lista_2);
	tnode *lista = cat_list(&lista_1, &lista_2);
	printf("\n");
	printf("lista finalna: "); wypisz_list(lista);
	printf("lista_1: "); wypisz_list(lista_1);
	printf("lista_2: "); wypisz_list(lista_2);
	zwolnij(lista);
}

void dodaj_na_koniec(tnode **list, char var)
{	
	tnode *wsk = malloc(sizeof(tnode));
	if(!wsk)
	{
		printf("error1\n");
		return;
	}
	wsk->value = var;
	wsk->next = NULL;
	
	if(*list == NULL)
		*list = wsk;
	else 
	{
		tnode *p = *list;
		while(p->next != NULL)
		     p = p->next;
		p->next = wsk;
	}
	return;	
}

void wypisz_list(tnode *list)
{
	if(list == NULL)
	{	
	  	printf("PUSTA \n");
      	return;
   	}

	while(list != NULL)
	{
	 	printf("%c ", list->value);
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

tnode *cat_list(tnode **one, tnode **two)
{
	tnode *result = NULL;

	if(*one==NULL&&*two==NULL)
		return NULL;
	else if(*one==NULL)
	{
		result = *two;
		*two = NULL;
		return result;
	}
	else if(*two == NULL)
	{
		result = *one;
		*one = NULL;
		return result;
	}

	tnode *ptr2 = *two; //iterator po two
	tnode *r; //iterator po result

	r = *one;
	r->next = (*one)->next;
	*one = NULL;
	result = r;

	//lista one przelaczona, teraz trzeba alfabetycznie dodac liste two
	while(ptr2 != NULL)
	{
		r = result;
		while(r != NULL)
		{
			if(r == result && r->value >= ptr2->value)//wstawianie przed pierwszy element w result
			{
				result = ptr2;
				*two = ptr2->next;//drugi element two staje sie pierwszym
				
				result->next = r;
				ptr2 = (*two);
				break;
			}
			else if(r->next->value >= ptr2->value)//wstawianie gdzies w srodku (lub na koncu)
			{
				tnode *temp = r->next;//zapisujemy sobie element, przed ktory wstawimy ptr
				r->next = ptr2;

				*two = ptr2->next;//drugi element two staje sie pierwszym
				ptr2->next = temp;//dolaczamy element temp za dodany element z two
				ptr2 = *two;
				break;
			}
			r = r->next;
		}
		if(*two == NULL)
			break;
	}
	return result;
}