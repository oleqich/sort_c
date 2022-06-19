#if !defined (_SORT_H_)
#define _SORT_H_

#define BUBBLE 1
#define COMB 2
#define SHELL 3
#define QUICK 4
#define MERGE 5
#define HEAP 6
#define UP 1
#define DOWN -1
int SORT_DIRECTION = UP;
int SORT_METHOD = BUBBLE;


int comp_int(void* x1, void* x2);
int comp_double(void* x1, void* x2);

void sort(void*a, int len_a, int elemsize, int(comp)(void*,void*), int SORT_METHOD, int SORT_DIRECTION);
#endif