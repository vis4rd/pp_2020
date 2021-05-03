#include <stdio.h>
#include <stdlib.h>


typedef struct tnode 
{
	int value;
	struct tnode *next;
	struct tnode *prev;
}tnode;

void print_list(tnode *list);
tnode* add_first(tnode* head, tnode* el);
tnode* add_last(tnode* head, tnode* el);
tnode* del_el(tnode** head, int var);
void add_sort(tnode** head, tnode* el);
tnode* div_list(tnode** head);
void sort(tnode** head);
void free_list(tnode**);

int main(void)
{
	tnode *list = NULL;

	tnode *new = malloc(sizeof(tnode));
	new->value = 7;
	list = add_first(list, new);

	tnode *new2 = malloc(sizeof(tnode));
	new2->value = 3;
	list = add_first(list, new2);

	tnode *new3 = malloc(sizeof(tnode));
	new3->value = 9;
	list = add_last(list, new3);

	print_list(list);

	tnode *deleted = del_el(&list, 9);
	print_list(deleted);
	free(deleted);

	print_list(list);

	tnode *new4 = malloc(sizeof(tnode));
	new4->value = 4;
	add_sort(&list, new4);

	new4 = malloc(sizeof(tnode)); new4->value = 8; add_sort(&list, new4);
	new4 = malloc(sizeof(tnode)); new4->value = 1; add_sort(&list, new4);
	new4 = malloc(sizeof(tnode)); new4->value = 0; add_sort(&list, new4);
	new4 = malloc(sizeof(tnode)); new4->value = 3; add_sort(&list, new4);
	new4 = malloc(sizeof(tnode)); new4->value = 5; add_sort(&list, new4);

	print_list(list);

	tnode *even = div_list(&list);
	print_list(list);
	print_list(even);

	printf("\nsortowanie parzystych: ");
	sort(&even);
	print_list(even);

	tnode *iter = even;
	tnode *next = iter->next;
	while(iter != NULL)
	{
		list = add_first(list, iter);
		if(next == NULL)
			break;
		iter = next;
		next = iter->next;
	}
	printf("\npolaczenie list: ");
	print_list(list);

	printf("\nsortowanie calej listy: ");
	sort(&list);
	print_list(list);

	free_list(&list);
}

void print_list(tnode *list)
{
	if(list==NULL)
	{
		printf("print_list(): lista jest pusta\n");
		return;
	}

	tnode *wsk = list;
	do
	{
		printf("%d ", wsk->value);
		wsk = wsk->next;
	}while(wsk != NULL);
	printf("\n");
	return;
}

tnode *add_first(tnode* head, tnode* el)
{
	if(head != NULL)
	{
		el->next = head;
		el->prev = NULL;
		head->prev = el;
		return el; //zwracany jest nowy pierwszy element
	}
	else //lista jest pusta
	{
		el->next = NULL;
		el->prev = NULL;
		return el;
	}
	
}

tnode* add_last(tnode* head, tnode* el)
{
	el->next = NULL;
	
	tnode *iter = head;
	while(iter->next != NULL)//szukamy ostatniego elementu
		iter = iter->next;

	iter->next = el;
	el->prev = iter;
	return head;
}

tnode* del_el(tnode** head, int var)
{
	tnode *iter = *head;
	while(iter != NULL)
	{
		if(iter->value == var)//znaleziono element
		{
			if(iter->prev == NULL)//jest to pierwszy element
			{
				if(iter->next == NULL && iter->prev == NULL)//jest to jedyny element
				{
					*head = NULL;
					return iter;
				}
				else
				{
					*head = iter->next;//poczatek listy przesuwamy o jeden
					iter->next->prev = NULL;//rozlaczamy wskazniki
				}
			}
			else if(iter->next == NULL)//jest to ostatni element
			{
				iter->prev->next = NULL;//rozlaczamy wskazniki
			}
			else//jest to element w srodku
			{
				iter->prev->next = iter->next;//laczymy poprzedni element z nastepnym
				iter->next->prev = iter->prev;//laczymy nastepny element z poprzednim
			}
			iter->next = NULL;//rozlaczamy niepotrzebne wskazniki
			iter->prev = NULL;
			return iter;
		}
		iter = iter->next;
	}
	return NULL;
}

void add_sort(tnode** head, tnode* el)
{
	if(NULL == *head) //lista jest pusta
	{
		el->next = NULL;
		el->prev = NULL;
		*head = el;
	}
	else
	{
		tnode *iter = *head;
		while(1)
		{
			if(el->value < iter->value)//znaleziono miejsce przed koncem
			{
				if(iter->prev == NULL)//wstawiamy przed pierwszy element
				{
					el->prev = NULL;
					el->next = *head;
					iter->prev = el;
					*head = el;
				}
				else /*if(iter->next == NULL)//wstawiamy przed ostatni element*/
				{
					el->prev = iter->prev;
					el->next = iter;
					iter->prev->next = el;
					iter->prev = el;
				}
				return;
			}
			if(iter->next != NULL)
				iter = iter->next;
			else
				break;
		}
		//wyjscie z petli oznacza, ze nie znaleziono wiekszego elementu, wiec dodajemy na koniec
		iter->next = el;
		el->prev = iter;
		el->next = NULL;
	}
}

tnode* div_list(tnode** head)
{
	tnode *parzyste = NULL; //ta lista bedzie zwracana

	tnode *iter = *head;
	tnode *next; //del_el() rozlacza wszystkie wskazniki, wiec potrzebny jest nastepny element
	while(iter != NULL)
	{
		next = iter->next;
		if(iter->value%2 == 0)
			parzyste = add_first(parzyste, del_el(head, iter->value));
		iter = next;
	}
	return parzyste;
}

void sort(tnode** head)
{
	tnode *parzyste = div_list(head);
	tnode *iter = parzyste;
	tnode *next = iter->next;
	while(iter->next != NULL)
	{
		add_sort(head, iter);
		iter = next;
		next = iter->next;
	}
	add_sort(head, iter);
	//z zalozenia nie dziala to jak powinno, ale "we will get them next time!"
}

void free_list(tnode **head)
{
	if((*head) == NULL)
	{
		printf("void free_list(): lista jest juz pusta\n");
		return;
	}

	tnode *temp = *head;
	while(temp->next != NULL)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	free(*head);
	*head = NULL;
    return;
}