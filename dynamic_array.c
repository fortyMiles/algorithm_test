/*
 * Implements the dynamic array.
 * Author: Minchuian Gao <mqgao@outlook.com>
 * Date: 2015-Sep-30
 *
 */

#include<stdio.h>

typedef struct{
	int *array;
	size_t size;
	size_t used;
} Array;


void initArray(Array *a, size_t initialSize){
	a->array = (int *)malloc(initialSize * sizeof(int));
	a->used = 0;
	a->size = initialSize;
}


void insertArray(Array *a, int element){
	if(a->used == a->size){
		a->size *= 2;
		a->array = (int *)realloc(a->array, a->size * sizeof(int));
	}
	a->array[a->used++] = element;
}

void freeArray(Array *a){
	free(a->array);
	a->array = NULL;
	a->used = a->size = 0;
}


int main(){
	Array a;
	int i;
	initArray(&a, 5);
	for(i = 0; i<100; i++){
		insertArray(&a, i);
	}
	printf("%d\n", a.array[9]);
	printf("%d\n", a.used);
	freeArray(&a);
	return 0;
}
