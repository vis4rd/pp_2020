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
	printf("\nlista_2: "); wypisz_list(lista_2);
	tnode *lista = cat_list(&lista_1, &lista_2);
	printf("\nlista finalna: "); wypisz_list(lista);
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
	if(*one==NULL&&*two==NULL)
		return NULL;
	else if(*one==NULL)
		return *two;
	else if(*two == NULL)
		return *one;

	tnode *result=NULL;
	tnode *save = malloc(sizeof(tnode));
	save = result;
	tnode *save_1 = malloc(sizeof(tnode));
	tnode *save_2 = malloc(sizeof(tnode));
	save_1 = *one;
	save_2 = *two;

	if(result==NULL)
	{
		if((*one)->value > (*two)->value)
		{
			(*one)->next = result;
			result = (*one);
			printf("1(%c)\n", result->value);
		}
		else
		{
			(*two)->next = result;
			result = (*two);
			printf("2(%c)\n", result->value);
		}
	}

	while(*one && *two)
	{
		if((*one)->value > (*two)->value)
		{
			printf("--(%c)\n", (*two)->value);
			printf("---(%c)\n", result->value);
			result->next = (*two);
			(*two) = (*two)->next;
		}
		else
		{
			printf("++(%c)\n", (*one)->value);
			result->next = (*one);
			(*one) = (*one)->next;
		}
		result = result->next;
	}
	while(*one)
	{
		result->next = *one;
		*one = (*one)->next;
		result = result->next;
	}
	while(*two)
	{
		result->next = *two;
		*two = (*two)->next;
		result = result->next;
	}
	

	printf("\nfinished\n");
	*one = save_1;
	*two = save_2;
	zwolnij(*one);
	zwolnij(*two);
	free(save_1); 
	free(save_2);
	result = save;
	return result;
}