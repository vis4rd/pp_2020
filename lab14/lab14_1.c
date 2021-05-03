#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "cycle.h"
//tutaj stdlib.h i stdio.h sa niepotrzebnie wstawione, poniewaz zostaly juz 
// zaimplementowane w cycle.h

int rand_int (int a, int b);

int main(void)
{
	srand(time(NULL));
	tnode *head = NULL;
	tnode *head2 = NULL;

	for(int i=0; i<8; i++)
	{
		tnode *new = malloc(sizeof(tnode));
		new->value = rand_int(50, 80);
		head = add_el(head, new);
	}	
	printf("head: ");
	print_list(head);
	
	for(int i=0; i<1; i++)
	{
		tnode *new = malloc(sizeof(tnode)); 
		new->value = rand_int(50, 80);
		head2 = add_el(head2, new);
	}	
	printf("\nhead2: ");
	print_list(head2);

	del_el(&head, 52);
	print_list(head);

	tnode *polaczone = NULL;
	polaczone = add_list(head, head2);
	printf("\npolaczone: ");
	print_list(polaczone);

	rev_list(polaczone);
	printf("\nodwrocona: ");
	print_list(polaczone);

	tnode *even = NULL;
	even = div_list(&polaczone);
	printf("\nparzyste: ");
	print_list(even);
	printf("\nnieparzyste: ");
	print_list(polaczone);
	
	free_list(&even);
	free_list(&polaczone);

}

int rand_int (int a, int b) 
{
 	return a + rand()%(b-a+1);
}
