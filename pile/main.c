#include<stdio.h>
#include<stdlib.h>
#include "pile.h"



int main()
{
	pile_Element *pile;
	int val;

	pile=init_pile();
	if(pile_vide(pile))
		printf("pile est vide !\n");
	empiler(&pile,5);
	empiler(&pile,2);
	empiler(&pile,56);
	empiler(&pile,4);
	val=depiler(&pile);
	printf("%d\n",val );
	val=depiler(&pile);
	val=pile_val(pile);
	printf("%d\n",val );
	if(pile_vide(pile))
		printf("pile est vide !\n");
	else printf("pile est pas vide !\n");
return 0;
}