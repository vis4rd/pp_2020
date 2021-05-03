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
void del_el(tnode** head, int var);//invalid read gdy jedeny element do usuniecia
tnode* add_list(tnode* head1, struct tnode* head2);
tnode *div_list(tnode **original);
void rev_list(tnode *head);/////zle odwraca
void free_list(tnode**);////zle zwalnia

#endif