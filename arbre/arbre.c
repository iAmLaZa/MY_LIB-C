#include<stdio.h>
#include<stdlib.h>
#include "arbre.h"
int arbre_vide(arbre *a)
{
	if(a==NULL)
		return 1;
	return 0;
}

arbre* FG(arbre *a)
{
	return a->fg;
}

arbre *FD(arbre *a)
{
	return a->fd;
}

int fuille(arbre *a){
if(a->fg==NULL && a->fd==NULL)
	return 1;
return 0;
}

void inserer_ord(arbre **a ,int x){
arbre *temp;
	if(arbre_vide(*a))
	{
		temp=(arbre*)malloc(sizeof(arbre));
		temp->val=x;
		temp->fg=NULL;
		temp->fd=NULL;
		*a=temp;
	}
	else
	{
		if((*a)->val==x)
			printf("la valeur deja exist\n");
			else if((*a)->val>x)
					if(arbre_vide(FG(*a)))
						{
								temp=(arbre*)malloc(sizeof(arbre));
								temp->val=x;
								temp->fg=NULL;
								temp->fd=NULL;
								(*a)->fg=temp;
						}
					else{
                        temp=FG(*a);
                        inserer_ord(&temp,x);
					}

				else
					if(arbre_vide(FD(*a)))
						{
								temp=(arbre*)malloc(sizeof(arbre));
								temp->val=x;
								temp->fg=NULL;
								temp->fd=NULL;
								(*a)->fd=temp;
						}
					else
						{
						    temp=FD(*a);
                            inserer_ord(&temp,x);
						}
	}


}

void infixi(arbre *a) {

if(!arbre_vide(a))
{
    infixi(a->fg);
    printf("%d ",a->val);
    infixi(a->fd);
}
}
