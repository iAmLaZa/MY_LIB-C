#include<stdio.h>
#include<stdlib.h>
#include "files.h"

int main(){
file myfile;
int x;

myfile=init_file();

if(myfile.tete==NULL)
	printf("files est vide!\n");
	
enfiler(&myfile,5);
enfiler(&myfile,7);
enfiler(&myfile,9);
enfiler(&myfile,4);

x=file_tete(myfile);
printf("%d\n",x);

x=defiler(&myfile);
printf("%d\n",x);
x=defiler(&myfile);
x=defiler(&myfile);
x=file_tete(myfile);
printf("%d\n",x);


return 0;
}
