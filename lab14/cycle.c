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
	if((*head) == NULL)
	{
		printf("void del_el(): lista jest pusta\n");
		return;
	}
	tnode *temp = (*head);
	tnode *prev = NULL;
	while(temp->next!=(*head))
	{
		prev = temp->next;
		if(temp->value == var)
		{
			free(temp);
			temp = prev;
		}
		temp = temp->next;
	}

	if((*head)->value == var)
	{
		tnode *last = *head;
		while(last->next!=(*head))
			last = last->next;
		prev = (*head)->next;
		free(*head);
		(*head) = prev;
		last->next = (*head);
	}
}

tnode* add_list(struct tnode* head1, struct tnode* head2)
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
	tnode *start = head1;
	tnode *start2 = head2;

	while(head1->next!=start)
		head1 = head1->next;
	head1->next = head2;
	head1=start;

	while(head2->next!=start2)
		head2 = head2->next;
	head2->next = start;
	return head1;
}

tnode *div_list(tnode **original)
{
	if((*original) == NULL)
	{
		printf("void div_list(): lista jest pusta\n");
		return NULL;
	}
	tnode *start = (*original);
	tnode *parzyste = NULL;
	while((*original)->next!=NULL)
	{
		if((*original)->value%2 == 0)
		{
			tnode *new = malloc(sizeof(tnode));
			new->value = (*original)->value;
			parzyste = add_el(parzyste, new);
		}
	}
	(*original) = start;
	return parzyste;
}

void rev_list(tnode *list)
{
	if(list == NULL)
	{
		printf("void rev_list(): lista jest pusta\n");
		return;
	}
	tnode *start = list;
	tnode *prev = NULL;
	tnode *cur = list;
	tnode *nast = NULL;
	while(nast != start)
	{
		nast = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nast;
	}
	list = prev;
	start->next = list;
	return;
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