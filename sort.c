#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

typedef enum{
    ILLEGAL_LEN = 1, ILLEGAL_ELEMSIZE,
    ILLEGAL_METHOD, ILLEGAL_DIRECTION
} ErrorCode;
static ErrorCode err;

int comp_int(void* x1, void* x2){
    if ( *(int*)x1 < *(int*)x2 ) return -1;
    else if ( *(int*)x1 > *(int*)x2 ) return 1;
    else return 0;
}

int comp_double(void* x1, void* x2){
    if ( *(double*)x1 < *(double*)x2 ) return -1;
    else if ( *(double*)x1 > *(double*)x2 ) return 1;
    else return 0;
}

void move(void*a, void*b, int elemsize){
    memcpy(a,b, elemsize);
}
/*    BUBBLE SORT    */
void bubble_sort(void*a, int len_a, int(comp)(void*,void*), int elemsize, int SORT_DIRECTION){
    void *temp = malloc(elemsize);
    int r = len_a-1, swapped = 1;
    int i = 0;
    while (r > 0 && swapped){
        swapped = 0;
        for (i = 0; i < r; i++){
            if (comp(a+i*elemsize, a+(i+1)*elemsize) == SORT_DIRECTION){
                swapped = 1;
                move(temp, a+i*elemsize, elemsize);
                move(a+i*elemsize, a+(i+1)*elemsize, elemsize);
                move(a+(i+1)*elemsize, temp, elemsize);
            }
        }
        r--;
    }
}

/*    COMB SORT    */
void comb_sort(void*a, int len_a, int(comp)(void*,void*), int elemsize, int SORT_DIRECTION){
    void *temp = malloc(elemsize);
    int i, h = len_a;
    double shrink = 1.33;
    while (h > 1){
        h = h / shrink;
        if (h <= 1) break;
        for (i = 0; i + h < len_a; i++){
            if (comp(a+i*elemsize, a+(i+h)*elemsize) == SORT_DIRECTION){
                move(temp, a+i*elemsize, elemsize);
                move(a+i*elemsize, a+(i+h)*elemsize, elemsize);
                move(a+(i+h)*elemsize, temp, elemsize);
            }
        }
    }
    bubble_sort(a, len_a, comp, elemsize, SORT_DIRECTION);
}

/*    SHELL SORT    */

void shell_sort(void*a, int len_a, int(comp)(void*,void*), int elemsize, int SORT_DIRECTION){
    void *temp = malloc(elemsize);
    int i, j, h;
    double shrink = 1.88;
    for(h = len_a/shrink; h > 0; h/=shrink) {
        for(i = h; i < len_a; i ++){
            move(temp, a+i*elemsize, elemsize);
            for(j=i; j>=h; j-=h){
                if (comp(a+(j-h)*elemsize, temp) == SORT_DIRECTION){
                    move(a+j*elemsize, a+(j-h)*elemsize, elemsize);
                }
                else break;
            }
            move(a+j*elemsize, temp, elemsize);
        }
    }
}


/*    QUICK SORT    */
int partition(void* a, int len_a, int(comp)(void*,void*), int elemsize, int SORT_DIRECTION){
	void* x;
    void* temp;
    move(x, a+(len_a/2)*elemsize, elemsize);
	int i = 0, j = len_a - 1;
	while (1){
		while (comp(a+i*elemsize, x) == SORT_DIRECTION) {
			i++;
		}
		while (comp(x, a+j*elemsize) == SORT_DIRECTION) {
			j--;
		}
		if (i >= j) break;
        move(temp, a+i*elemsize, elemsize);
        move(a+i*elemsize, a+j*elemsize, elemsize);
        move(a+j*elemsize, temp, elemsize);
		i++;
		j--;
	}
	return i;
}
void quick_sort(void* a, int len_a, int(comp)(void*,void*), int elemsize, int SORT_DIRECTION){
	if (len_a < 2) return;
	int i = partition(a, len_a, comp, elemsize, SORT_DIRECTION);
	quick_sort(a, i, comp, elemsize, SORT_DIRECTION);
	quick_sort(a + i, len_a - i, comp, elemsize, SORT_DIRECTION);
}


/*    MERGE SORT fake   */
void merge_sort(void*a, int len_a, int(comp)(void*,void*), int elemsize, int SORT_DIRECTION){
    void *temp = malloc(elemsize);
    int r = len_a-1, swapped = 1;
    int i = 0;
    while (r > 0 && swapped){
        swapped = 0;
        for (i = 0; i < r; i++){
            if (comp(a+i*elemsize, a+(i+1)*elemsize) == SORT_DIRECTION){
                swapped = 1;
                move(temp, a+i*elemsize, elemsize);
                move(a+i*elemsize, a+(i+1)*elemsize, elemsize);
                move(a+(i+1)*elemsize, temp, elemsize);
            }
        }
        r--;
    }
}

/*    HEAP SORT fake  */
void heap_sort(void*a, int len_a, int(comp)(void*,void*), int elemsize, int SORT_DIRECTION){
    void *temp = malloc(elemsize);
    int r = len_a-1, swapped = 1;
    int i = 0;
    while (r > 0 && swapped){
        swapped = 0;
        for (i = 0; i < r; i++){
            if (comp(a+i*elemsize, a+(i+1)*elemsize) == SORT_DIRECTION){
                swapped = 1;
                move(temp, a+i*elemsize, elemsize);
                move(a+i*elemsize, a+(i+1)*elemsize, elemsize);
                move(a+(i+1)*elemsize, temp, elemsize);
            }
        }
        r--;
    }
}

void sort(void*a, int len_a, int elemsize, int(comp)(void*,void*), int SORT_METHOD, int SORT_DIRECTION){
    if(len_a > 0); else {err = ILLEGAL_LEN; exit(0);}

    if(elemsize == sizeof(int) || elemsize == sizeof(double)); 
    else {err = ILLEGAL_ELEMSIZE; exit(0);}

    if(SORT_METHOD == BUBBLE || SORT_METHOD == COMB || SORT_METHOD == SHELL || SORT_METHOD == QUICK ||
    SORT_METHOD == MERGE || SORT_METHOD || HEAP); 
    else {err = ILLEGAL_METHOD; exit(0);}

    if(SORT_DIRECTION == UP || SORT_DIRECTION == DOWN);
    else {err = ILLEGAL_DIRECTION; exit(0);}

    switch (SORT_METHOD)
    {
    case BUBBLE:
        bubble_sort(a, len_a, comp, elemsize, SORT_DIRECTION);
        break;
    case COMB:
        comb_sort(a, len_a, comp, elemsize, SORT_DIRECTION);
        break;
    case SHELL:
        shell_sort(a, len_a, comp, elemsize, SORT_DIRECTION);
    case QUICK:
        heap_sort(a, len_a, comp, elemsize, SORT_DIRECTION);
        break;
    case MERGE:
        merge_sort(a, len_a, comp, elemsize, SORT_DIRECTION);
        break;
    case HEAP:
        heap_sort(a, len_a, comp, elemsize, SORT_DIRECTION);
        break;
    default:
        break;
    }
}

