
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void bulle(int *tableau, int p)
{
    int i_b = p;
    while ((i_b > 0) && (tableau[i_b] < tableau[i_b - 1]))
    {
        int t = tableau[i_b - 1];
        tableau[i_b - 1] = tableau[i_b];
        tableau[i_b] = t;
        i_b--;
    }
}

void tri_gnome(int *tableau)
{
    int i_i;
    for (i_i = 0; i_i < 20; i_i++)
        bulle(tableau, i_i);
}

int my_rand(void)
{
    return (rand());
}
int main(int argc, char *argv[])
{  
    float AllDeltasTrieGnome[12];
    float deltaP,deltaM;

    clock_t t1, t2,t3,t4;

    long int ValN[12] = {103, 203, 437, 809,
                         1657, 3211, 6431, 12803,
                         25601, 51209, 102409, 204811};
    int i;
    /*printf("n=");
    scanf("%d", &n);*/
    // int tableau[11] = {4, -1, 8, 100, 12, -6, 23, 2, 28, 24, 33};

     for(i=0;i<12;i++){
                
                int k;
                int n=ValN[i];
                
                //printf("\n Je suis N , Ma valeur est %d,je suis la taille du tableau non trier T%d, \n",n,i);
                int T[n];
                for (k = n; k > 0; k--)
                {
                    T[k] = my_rand();
                }
               // printf("  \n  T r i   a   G n o m e    e n   c o u r s  . . . . . \n");
                int i_i;
                int i_b,t;
                t1 = clock();
                for (i_i = 0; i_i < n; i_i++)
                {
                     i_b = i_i;
                    while ((i_b > 0) && (T[i_b] < T[i_b - 1]))
                    {   
                        t = T[i_b - 1];
                        T[i_b - 1] = T[i_b];
                        T[i_b] = t;
                        i_b--;
                    }
                }
                t2 = clock();
                deltaP = (float)(t2 - t1) / CLOCKS_PER_SEC;
                AllDeltasTrieGnome[i] = deltaP;
                //printf("Delta %f", deltaP);

                for (k = n; k > 0; k--)
                {
                    T[k] =k;
                }

                //printf("  \n  T r i   a   G n o m e    M e i l e u r   c a s     e n   c o u r s  . . . . . \n");
                t3 = clock();
                for (i_i = 0; i_i < n; i_i++)
                {
                    int i_b = i_i;
                    while ((i_b > 0) && (T[i_b] < T[i_b - 1]))
                    {  
                        int t = T[i_b - 1];
                        T[i_b - 1] = T[i_b];
                        T[i_b] = t;
                        i_b--;
                    }
                }
                t4 = clock();
                deltaM = (float)(t4 - t3) / CLOCKS_PER_SEC;
                AllDeltasTrieGnome[i] = deltaM;
                //printf("Delta %f", deltaM);

                 printf("");
                printf("T(%d)      Meilleur Cas : %f s        Pire Cas : %f s \n",n, deltaM,deltaP);


     }

    return 0;
}
