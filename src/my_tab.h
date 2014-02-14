#ifndef MY_TAB_DEFINE
#define MY_TAB_DEFINE

#include <stdlib.h>

typedef struct my_tab *my_tab;
struct my_tab
{
	int size;
	int count;
	void **tab;
};

#define MY_TAB_INITIAL_SIZE 10

my_tab my_tnew();
int my_tlen(my_tab t);
void my_tadd(my_tab t, void *e);
void* my_tpop(my_tab t);
void* my_tget(my_tab t, int i);
void* my_trmat(my_tab t, int i);
void my_tfree(my_tab t);

#endif
