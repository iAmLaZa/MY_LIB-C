#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

int cle ( int x, int i){
   int j, q, r;
   j=0;
   q = x ; 
   
   while (j<=i ){
   	r= q % 10;
   	q = q/ 10; 
   	j++;
   }
   return r;
}

void TriAux(long T[], long n, int i){

int j, temp;

   j = 1;
    while( j < n){
	
                  if( cle(T[j],i) >= cle(T[j-1],i))   j++;
                                        else{
		                                       temp=T[j]; 
						                       T[j]=T[j-1];
						                       T[j-1]=temp;
            
                                        if(j > 1)   j--;
                                            }
                }
}

int getMax(long T[], long n) {
  int max = T[0];
  int i;
  for (i = 1; i < n; i++)
    if (T[i] > max)
      max = T[i];
  return max;
}
long getNbDigits(long T[], long n){
		
	int x= getMax(T,n);
	int digits = 0;
	while(x> 0){
		digits++;
		x= x/10;
	}
	return digits;
}

void TriBase(long T[], long n, int k){
	int j;
	for (j=0; j<k; j++){
		TriAux( T, n, j);
	}
}

int main(){
	long  T[100000];
            
	int i;
	long n;
	clock_t t1,t2,t3,t4;
	float t;
	
printf("Veuillez donner la valeur de n:");
 scanf("%d",&n);
            for (i=n;i>0;i--){
  	               T[i]= rand();
                   }
                  printf("  Non Sorted table :\n");
                   for (i=0;i<n;i++){
  	               printf("%d ,",T[i]);
                   }
                   printf("\n");

                   printf("Tri par distribution en cours ....\n");


                   
                 t1 = clock();   
                 int nbdigits = getNbDigits(T, n);
                 TriBase(T,n,nbdigits);

                 printf("Sorted table :\n");
                   for (i=0;i<n;i++){
  	               printf("%d ,",T[i]);
                   }
                   printf("\n");
 
  
     t2 = clock();
	t = (float) (t2-t1)/CLOCKS_PER_SEC;
  printf("Delta = %f",t);



/*
    for (i=0;i<n;i++){
  	               T[i]= i;
                   }
      t3 = clock();   
                 int nbdigitsM = getNbDigits(T, n);
                 TriBase(T,n,nbdigitsM);
 
  
     t4 = clock();
	float tm = (float) (t4-t3)/CLOCKS_PER_SEC;

	printf ("\n T(%ld) :     meilleure cas : %f     pire cas : %f . ",n,tm,t); */
	
}


