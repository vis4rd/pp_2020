#ifndef CYCLE_H
#define CYCLE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
	int value;
	struct tnode *next;
}tnode;

void print_list(tnode *list);
tnode *add_el(tnode *head, tnode *el);
void del_el(struct tnode** head, int var);//////
tnode* add_list(struct tnode* head1, struct tnode* head2);
tnode *div_list(tnode **original);
void rev_list(struct tnode*);
void free_list(struct tnode**);

#endif