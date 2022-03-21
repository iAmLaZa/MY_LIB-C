#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

/* creer un tableau trié */
double *table_trier(int n)
{
    double *res = malloc(sizeof(double) * n);
    int i;
    for (i = 0; i < n; i++)
    {
        res[i] = i;
    }
    return res;
}
/* créer un tableau inverser */
double *table_inverser(int n)
{
    double *res = malloc(sizeof(double) * n);
    int i;
    for (i = 0; i < n; i++)
    {
        res[i] = n - i;
    }
    return res;
}

/* fonction qui execute le tout */
double execution(double *table, int taille)
{
    // double* res=malloc(sizeof(double)*taille);
    int i = 0;
    double x;
    clock_t t1, t2;
    t1 = clock();
    tri_tas(table, taille);
    t2 = clock();
    x = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("%lf", x);
    return x;
}
//////

/*  tri par tas */

// la fonction insertion dans un tas

inserer_dans_tas(double *tab, int x, int a, int b)
{
    int m;
    for (m = 2 * a; m <= b; m = 2 * a)
    {
        if (m < b)
            if (tab[m] < tab[m + 1])
                m++;
        if (x >= tab[m])
            break;
        else
        {
            tab[a] = tab[m];
            a = m;
        }
    }
    tab[a] = x;
}

// la fonction construir un tas

construir_tas(double *tab, int n)
{
    int i;
    for (i = n / 2; i >= 1; i--)
        // noeud a considerer
        inserer_dans_tas(tab, tab[i], i, n);
    // afficher_tab();
}
// la fonction tri_tas

tri_tas(double *tab, int n)
{
    int i, x;
    construir_tas(tab, n);   // on commence par construir le tas
                             // afficher_tab();
    for (i = n; i >= 1; i--) // on  parcours le tableau
    {
        x = tab[i];                         // on sauve la derniere valeur du tableau
        tab[i] = tab[1];                    // l'element est trié
        inserer_dans_tas(tab, x, 1, i - 1); // on insere x dans le tas
        // afficher_tab();
    }
}
/*  permutation de 2 entiers */
void permutter(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}
//////
int main()
{
    double tab[] = {5 * pow(10, 4), pow(10, 5), 2 * pow(10, 5),
                    4 * pow(10, 5), 8 * pow(10, 5), 1.6 * pow(10, 6),
                    3.2 * pow(10, 6), 6.4 * pow(10, 6), 12.8 * pow(10, 6),
                    25.6 * pow(10, 6), 51.2 * pow(10, 6), 102.4 * pow(10, 6),
                    204.8 * pow(10, 6)};

    double *table1 = malloc(sizeof(double));
    double *table2 = malloc(sizeof(double));
    double *res1 = malloc(sizeof(double));
    double *res2 = malloc(sizeof(double));
    int i;

    for (i = 0; i < 13; i++)
    {
        int taille = (int)tab[i];
        printf("T(%d)\tmeillleur cas : ", taille);
        table1 = table_trier(taille);
        res1[i] = execution(table1, taille);
        printf("\t pire cas : ");

        table2 = table_inverser(taille);
        res2[i] = execution(table2, taille);
        printf("\n");
    }
}
