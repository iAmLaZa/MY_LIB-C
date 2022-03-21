typedef struct arbre arbre;
struct arbre
{
		int val;
		arbre *fg;
		arbre *fd;
};


int arbre_vide(arbre *a);

arbre* FG(arbre *a);

arbre* FD(arbre* a);

int fuille(arbre* a);

void inserer_ord(arbre **a ,int x);

void infixi(arbre *a);
