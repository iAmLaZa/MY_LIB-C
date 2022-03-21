#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

/* creer un tableau trié */
double* table_trier(int n)
{
    double* res=malloc(sizeof(double)*n);
    int i;
    for(i=0;i<n;i++)
    {
        res[i]=i;
    }
    return res;
}
/* créer un tableau inverser */
double* table_inverser(int n)
{
    double* res=malloc(sizeof(double)*n);
    int i;
    for(i=0;i<n;i++)
    {
        res[i]=n-i;
    }
    return res;
}

//////
/*  tri Rapide */
int tri_rapideta(int min,int max,int valeur,int* table)
{
    int i=min;
    int j=max-1;
    int temp;
    while(i<j)
    {
        if(table[i]<valeur)
            i++;
        else
        {
            if(table[j]>valeur)
                j--;
            else
            {
                temp=table[j];
                table[j]=table[i];
                table[i]=temp;
                i++;
                j--;
            }
        }
    }
    return i;
}

void tri_rapide(int min,int max,int* table)
{
    if(min>=max)
        return;
    int pivo=(rand()%(max-min))+min;
    pivo=tri_rapideta(min,max,table[pivo],table);
    tri_rapide(min,pivo,table);
    tri_rapide(pivo+1,max,table);
}
//////
/* fonction qui execute le tout */
double execution(double* table,int taille)
{
    //double* res=malloc(sizeof(double)*taille);
    int i=0;
	double x;
    clock_t t1,t2;
		t1=clock();
		tri_rapide(0,taille,table);
        t2=clock();
        x=(double)(t2-t1)/CLOCKS_PER_SEC;
        printf("%lf",x);
    return x;
}
///////
int main()
{  double tab[]={5*pow(10,4),pow(10,5),2*pow(10,5),4*pow(10,5),8*pow(10,5),1.6*pow(10,6),3.2*pow(10,6),6.4*pow(10,6),12.8*pow(10,6),25.6*pow(10,6),51.2*pow(10,6),102.4*pow(10,6),204.8*pow(10,6)};

	double* table1=malloc(sizeof(double));
	double* table2=malloc(sizeof(double));
	double* res1=malloc(sizeof(double));
	double* res2=malloc(sizeof(double));
    int i;
	for(i=0;i<13;i++)
	{   int taille=(int)tab[i];
        printf("T(%d)\tmeillleur cas : ",taille);
		table1=table_trier( taille );
		res1[i]=execution( table1,taille );
		printf("\t pire cas : ");

		table2=table_inverser( taille );
		res2[i]=execution(table2,taille);
		printf("\n");
	}
}
