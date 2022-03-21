typedef struct coord coord;
struct coord
{
	int i;
	int j;
};


typedef struct file_Element file_Element;
struct file_Element
{
	coord val;
	file_Element *svt;
};

typedef struct file file;
struct file
{
	file_Element *tete;
	file_Element *queue;
};


file init_file();

coord file_tete (file File);

int file_vide (file File); 

void enfiler (file *File, coord val);

coord defiler (file *File );

