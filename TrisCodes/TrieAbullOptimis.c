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
int main()
{
    // int n = 10;

    int j;
    int i;
    float AllDeltasTrieBulleOptM[12];
    float AllDeltasTrieBulleOptP[12];
    float deltaOptM,deltaOptP;

    clock_t t1, t2, t3, t4;
    long int ValN[12] = {103, 203, 437, 809,
                         1657, 3211, 6431, 12803,
                         25601, 51209, 102409, 204811};


    for(i=0;i<12;i++){


                int k;
                int n=ValN[i];
                
                // T R I   A U    P I R E    C A S   :   T A B L E A  U   N O N   T R I é 
                int T[n];
                int *ex;

                for (k = n; k > 0; k--)
                {
                    T[k] = my_rand();
                    //T[k] = k;
                }
                //printf("  \n  T r i   a   B u l l e    O p t    e n   c o u r s  . . . . . \n");
                t1=clock();
                ex = TriBulleOpt(T, n);
                t2=clock();
                deltaOptP = (float)(t2 - t1) / CLOCKS_PER_SEC;
                AllDeltasTrieBulleOptP[i] = deltaOptP;

                // T R I   A U   M E I L L E U R   C A S   :   T A B L E A U    D E J A   T R I é    D A N S   L ' O R D R E     C R O I S S A N T 
                for (k = 0; k < n; k++)
                {
                    T[k] = k;
                }
                //printf("  \n  T r i   a   B u l l e    O p t    e n   c o u r s  . . . . . \n");
                t3=clock();
                ex = TriBulleOpt(T, n);
                t4=clock();
                deltaOptM = (float)(t4 - t3) / CLOCKS_PER_SEC;
                AllDeltasTrieBulleOptM[i] = deltaOptM;

                printf("T(%d)      Meilleur Cas : %f s        Pire Cas : %f s \n",n, deltaOptM,deltaOptP);

        }



        printf("\n\n\n");
        printf("\n AllDeltasTrieBulleOptP:[");

        for (j = 0; j < 12; j++)

        {
            printf("%f,", AllDeltasTrieBulleOptP[j]);
        }
        printf("]    ");


        printf("\n\n\n");
        printf("\n AllDeltasTrieBulleOptM:[");

        for (j = 0; j < 12; j++)

        {
            printf("%f,", AllDeltasTrieBulleOptM[j]);
        }
        printf("]    ");
return 0;
}
