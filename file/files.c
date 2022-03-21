#include<stdio.h> 
#include<stdlib.h>
#include "files.h"

file init_file(){
	file File;
	
	File.tete=NULL;
	File.queue=NULL;
	return File;	
	}

coord file_tete (file File){
	return (File.tete)->val;
	}

int file_vide (file File){
	if(File.tete==NULL)
		return 1;
	return 0;
	}

void enfiler (file *File,coord val){
	file_Element *temp=malloc(sizeof(file_Element));
	temp->val=val;
	temp->svt=NULL;
	if(File->tete==NULL)
		File->tete=temp;
	else
		(File->queue)->svt=temp;
	File->queue=temp;
	}

coord defiler (file *File ){
	coord x;
	file_Element *temp;
	
	x=(File->tete)->val;
	temp=File->tete;
	if(File->tete==File->queue)
	{	
		File->tete=NULL;
		File->queue=NULL;
	}
	else
		File->tete=(File->tete)->svt;
		
	free(temp);
	
	return x;	
}




