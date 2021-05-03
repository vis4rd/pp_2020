#include "cycle.h"

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
		printf("%d ", list->value);
		list = list->next;
	}while(list != wsk);
	printf("\n");
	return;
}

tnode *add_el(tnode *head, tnode *el)
{
	if(NULL == head)
	{
		head = el;
		el->next = head;
	}
	else 
	{
		tnode *p = head;
		while(1)
		{
			if(p->next == head||p->next==NULL)
				break;
			p = p->next;
		}
		p->next = el;
		el->next = head;
	}
	return head;	
}

void del_el(struct tnode** head, int var)/////////////////////
{
	//pierwszy element jest sprawdzany na koncu
    if (*head == NULL)
    {
        printf("void del_el(): lista jest pusta\n");
        return;
    }

    tnode *cur = *head;
    tnode *prev = cur;
    int count = 0;//dlugosc listy
    while (prev->next != *head) 
    {
        prev = prev->next;
        count++;
    }

    int i = 0;//aktualny element
    while (i <= count)
    {
        if (cur->value == var)//znaleziono element
        {
            if (cur->next != cur)//jesli lista ma wiecej niz jeden element
                prev->next = cur->next;//poprzedni element wskazuje na nastepny
            else
                prev->next = NULL;//lista ma jeden element, ktory zostanie usuniety

            if (cur == *head)//jesli znaleziono pierwszy element
                *head = prev->next;//head ustawiamy na nastepny element

            free(cur);//usuwamy aktualny element

            if (prev != NULL && prev->next != NULL)//jesli po usunieciu istnieje jakis element
                cur = prev->next;//aktualny element ustawiamy na poczatek
            else
                cur = NULL;
        }
        else 
        {
            prev = cur;
        	cur  = cur->next;
        }
        i++;
    }
}

tnode* add_list(tnode* head1, tnode* head2)
{
	if(head1 == NULL && NULL == head2)
	{
		printf("tnode *add_list(): obie listy sa puste\n");
		return NULL;
	}
	if(head1 == NULL)
	{
		printf("tnode *add_list(): lista 1 jest pusta\n");
		return head2;
	}
	if(head2 == NULL)
	{
		printf("tnode *add_list(): lista 2 jest pusta\n");
		return head1;
	}

	tnode *last1 = head1;
	while(last1->next != head1)
		last1 = last1->next;

	last1->next = head2; //ostatni element listy pierwszej wskazuje na pierwszy listy drugiej

	tnode *last2 = head2;
	while(last2->next != head2)
		last2 = last2->next;

	last2->next = head1; //ostatni element listy drugiej wskazuje na pierwszy listy pierwszej
	return head1;
}

tnode *div_list(tnode **original)
{
	if((*original) == NULL)
	{
		printf("void div_list(): lista jest pusta\n");
		return NULL;
	}

	tnode *parzyste = NULL; //ta lista zostanie zwrocona w return
	tnode *evenlast = NULL; //ostatni element parzystej listy

	tnode *last = *original; //szukamy ostatniego elementu zeby tymczasowo rozlaczyc cykl
	while(last->next != (*original))
		last = last->next;
	last->next = NULL;

	tnode *iter = *original;
	tnode *prev = last;
	while(iter != NULL)
	{

		if(iter->value%2 == 0) //znaleziono parzysty element
		{
			prev->next = iter->next;
			if(parzyste == NULL) //pierwszy parzysty element
			{
				parzyste = iter;
				parzyste->next = parzyste;
				evenlast = parzyste;
			}
			else
			{
				evenlast->next = iter;
				iter->next = parzyste;
				evenlast = iter;
			}
			iter = prev;
		}
		prev = iter;
		iter = iter->next;
	}

	last = *original;
	while(last->next != NULL)//ponownie szuakmy ostatniego elementu, aby polaczyc w cykl
		last = last->next;
	last->next = *original;

	return parzyste;
}

void rev_list(tnode *head)
{
	if(head == NULL)
	{
		printf("void rev_list(): lista jest pusta\n");
		return;
	}
	if(head->next == head) //lista jest jednoelementowa
		return;
	
	tnode *last = head;
	while(last->next != head)
		last = last->next;
	last->next = head; //ustawiamy ostatni element w liscie

	tnode *next = last->next;
	while(head->next != last)
	{
		head->next = last;
		last = head;
		head = next;
		next = head->next;
	}

	//head = last;
	//Powyzsza linia jest zakomentowana, poniewaz ma sens tylko jesli przekazujemy
	// do tej procedury wskaznik przez referencje (oryginalny).
	//
	//Z "tnode *head" jako argument funkcji nie da sie przesunac poczatku listy na
	// ostatni element, zeby przy wypisywaniu dobrze sie wyswietlalo.
	//Zeby zadzialalo to jak trzeba, wymagany jest argument "tnode **head".
}

void free_list(tnode **head)
{
	if((*head) == NULL)
	{
		printf("void free_list(): lista jest juz pusta\n");
		return;
	}

	tnode* temp = (*head)->next;
	(*head)->next = NULL;
	(*head) = temp;
    while(temp != NULL)
    {
        temp = (*head)->next;
        free(*head);
        (*head) = temp;
    }
    return;
}