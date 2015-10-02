#include<stdio.h>
#include<stdlib.h>

int main(){
	int * array;
	array = (int *)malloc( 10 * sizeof(int));
	printf("%ld\n", sizeof(array));
	array = (int *)realloc(array, 12 * sizeof(int));
	return 0;
}
