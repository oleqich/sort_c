NAME
       sort - sort on array

SYNOPSIS
       #include <sort.h>

       void sort(void *a, int len_a, int elemsize,
                        int (comp)(void *,void *), 
				int SORT_METHOD, int SORT_DIRECTION);


DESCRIPTION
       The sort() function sorts an array of a defined size.  The base argument points to the start of the array.
       The contents of the array are sorted in ascending order according to a variable of sort direction and comparison function pointed to by comp, which is called with two arguments that point to the objects being compared.

       The  comparison  function  must  return  an  integer less than, equal to, or greater than zero if the first argument is considered to be respectively less than, equal to, or greater than the second.  If two members compare as
       equal, their order in the sorted array is undefined.

RETURN VALUE
       The sort() functions return no value.

VERSIONS
      sort() was added to system in version 1.0.

EXAMPLE
	int main(){
		int a[] = {1, 7, 4, 0, 9, 4, 8, 8, 2, 4};
		double b[] = {1, 14, 9, 12, 30, 11, 2};

		sort(a, sizeof(a)/sizeof(int), sizeof(int), comp_int, BUBBLE, UP);
		sort(b, sizeof(b)/sizeof(double), sizeof(double), comp_double, HEAP, DOWN);

		for (int i = 0; i < sizeof(a)/sizeof(int); i++){printf("%d ", a[i]);}
		printf("\n");
		for (int i = 0; i < sizeof(b)/sizeof(double); i++){printf("%.1f ", b[i]);}
	}

SEE ALSO
       window_t() func.