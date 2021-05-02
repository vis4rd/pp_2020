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
	tnode *list;

	tnode *new = malloc(sizeof(tnode));
	new->value = 4;
	list = add_first(list, new);

	tnode *new2 = malloc(sizeof(tnode));
	new->value = 3;
	list = add_first(list, new);

	tnode *new3 = malloc(sizeof(tnode));
	new->value = 9;
	list = add_last(list, new);

	tnode *new4 = malloc(sizeof(tnode));
	new->value = 5;
	add_sort(&list, new);

	print_list(list);

	tnode *even = div_list(&list);
	print_list(list);
	print_list(even);

	free_list(&list);
	free_list(&even);
}

void print_list(tnode *list)
{
    if(!list)
    {
    	printf("print_list(): Lista jest pusta\n");
    	return;
    }

    tnode *temp = list;
    while(temp->next)
    {
        printf("address: %p, value: %d, previous: %p, next: %p\n", temp, temp->value, temp->prev, temp->next);
        temp = temp->next;
    }
    printf("\n");
    return;
}

tnode *add_first(tnode* head, tnode* el)
{
	el->next = head;
	el->prev = NULL;

	if(head!=NULL)
		head->prev = el;

	head = el;
	return head;
}

tnode* add_last(tnode* head, tnode* el)
{
	tnode *temp = head;
	el->next = NULL;

	if(head == NULL)
	{
		el->prev = NULL;
		head = el;
		return head;
	}
	while(temp->next != NULL)
		temp = temp->next;

	temp->next = el;
	el->prev = temp;
	return head;
}

tnode* del_el(tnode** head, int var)
{
	tnode *temp = *head;
	while(temp->next)
	{
		if(temp->value == var)
			break;
		temp = temp->next;
	}
	tnode *tail = temp->prev;
	tnode *nose = temp->next;
	tail->next = nose;
	nose->prev = tail;
	temp->next = NULL;
	temp->prev = NULL;
	return temp;
}

void add_sort(tnode** head, tnode* el)
{
	if(NULL == *head)
		*head = el;

	if((*head)->value >= el->value)
	{
		el->next = *head;
		el->next->prev = el;
		*head = el;
	}

	if((*head)->value < el->value)
	{
		tnode *temp;
		temp = *head;

		while(temp->next)
		{
			if(temp->next->value < el->value)
				break;
			temp = temp->next;
		}

		el->next = temp->next;
		if(temp->next)
			el->next->prev = el;

		temp->next = el;
		el->prev = temp;
	}
	return;
}

tnode* div_list(tnode** head)
{
	tnode *even = malloc(sizeof(tnode));
	even->prev = NULL;
	even->next = NULL;
	tnode *temp = *head;
	while(1)
	{
		if(NULL==temp)
			break;
		if((temp->value)%2==0)
			add_first(even, del_el(head, temp->value));
		temp = temp->next;
	}
	return even;
}

void sort(tnode** head)
{

}

void free_list(tnode **head)
{
	if((*head) == NULL)
	{
		printf("void free_list(): lista jest juz pusta\n");
		return;
	}
	tnode *del = NULL;
	do
    {
        del=(*head)->next;
        free(*head);
        (*head)=del;
    }while(*head);
    return;
}