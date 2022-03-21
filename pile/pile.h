typedef struct pile_Element pile_Element;
struct pile_Element
{
	int val;
	pile_Element *svt;
};



pile_Element *init_pile();

int pile_val (pile_Element *pile);

int pile_vide (pile_Element *pile);

void empiler (pile_Element **ptr_pile,int val);

int depiler (pile_Element **ptr_pile );




