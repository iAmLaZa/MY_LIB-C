#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/**********************************   T R I E    A     B U L L E S *************************************************/
int *TriBulle(int T[], int n)
{
    int i = 0;
    int changement = 1; // changement est vrai
    while (changement == 1)
    {
        changement = 0; // Changement est faux
        for (i = 0; i < n; i++)
        {

            if (T[i] > T[i + 1])
            {
                int tmp = T[i];
                T[i] = T[i + 1];
                T[i + 1] = tmp;
                changement = 1; // changement est vrai
            }
        }
    }
    return T;
}


/**********************************   T R I E    A     B U L L E S       O P T I M I S E E *************************************************/


int *TriBulleOpt(int T[], int n)
{
    int i;
    int m = n - 1;
    int changement = 1; // changement est vrai
    while (changement == 1)
    {
        changement = 0; // Changement est faux
        for (i = 0; i < m; i++)
        {

            if (T[i] > T[i + 1])
            {
                int tmp = T[i];
                T[i] = T[i + 1];
                T[i + 1] = tmp;
                changement = 1; // changement est vrai
            }
        }
        m--;
    }
    return T;
}

/*******************************************************  F O N C T I O N      R A N D O M E  **************************************************************/
int my_rand(void)
{
    return (rand());
}


/***************************************** *************   L E      M A I N         ******************************************************************************/
void main()
{
    // int n = 10;

    int j;
    int i;
    float AllDeltasTrieBulleM[12];
    float AllDeltasTrieBulleP[12];
    float deltaM,deltaP;

    clock_t t1, t2, t3, t4;
    long int ValN[12] = {103, 203, 437, 809,
                         1657, 3211, 6431, 12803,
                         25601, 51209, 102409, 204811};
  




    for(i=0;i<12;i++){


                int k;
                int n=ValN[i];
                
                //printf("\n Je suis N , Ma valeur est %d,je suis la taille du tableau non trier T%d, \n",n,i);
                int T[n];
                int *ex;

                for (k = n; k > 0; k--)
                {
                    T[k] = my_rand();
                }
               // printf("  \n  T r i   a   B u l l e      e n   c o u r s  . . . . . \n");
                t1=clock();
                ex = TriBulle(T, n);
                t2=clock();
                deltaP = (float)(t2 - t1) / CLOCKS_PER_SEC;
                AllDeltasTrieBulleP[i] = deltaP;

               //Le tableau est trié deja
                for (k = 0; k < n; k++)
                {
                    T[k] = k+1;
                }
               // printf("  \n  T r i   a   B u l l e   M e i l l e u r   c a s    e n   c o u r s  . . . . . \n");
                t3=clock();
                ex = TriBulle(T, n);
                t4=clock();
                deltaM = (float)(t4 - t3) / CLOCKS_PER_SEC;
                AllDeltasTrieBulleM[i] = deltaM;
                printf("T(%d)      Meilleur Cas : %f s        Pire Cas : %f s \n",n, deltaM,deltaP);

        }



        printf("\n\n\n");
        printf("\n AllDeltasTrieBulleP:[");

        for (j = 0; j < 12; j++)

        {
            printf("%f,", AllDeltasTrieBulleP[j]);
        }
        printf("]    ");


        printf("\n\n\n");
        printf("\n AllDeltasTrieBulleM:[");

        for (j = 0; j < 12; j++)

        {
            printf("%f,", AllDeltasTrieBulleM[j]);
        }
        printf("]    ");

}
