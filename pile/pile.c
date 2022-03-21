#include<stdio.h>
#include<stdlib.h>
#include "pile.h"

pile_Element *init_pile(){
	return NULL;
}

int pile_val (pile_Element *pile){
	return pile->val;
}

int pile_vide (pile_Element *pile){
	if(pile==NULL)
		return 1;
	return 0;
} 

void empiler (pile_Element **ptr_pile,int val){
	 pile_Element *temp;

	 temp=(pile_Element*)malloc(sizeof(pile_Element));
	 temp->val=val;
	 temp->svt=*ptr_pile;
	 *ptr_pile=temp;

}

int depiler (pile_Element **ptr_pile ){
	pile_Element *temp;
	int val;

	temp=*ptr_pile;
	val=temp->val;      
	*ptr_pile=(*ptr_pile)->svt;
	free(temp);
	return val;
}



