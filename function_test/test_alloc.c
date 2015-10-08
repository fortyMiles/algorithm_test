#include<stdio.h>
#include<stdlib.h>

int main(){
	int * test;
	test = (int *)malloc(0 * sizeof(int));
	test = (int *)realloc(test, 1 * sizeof(int));

	char a = 'a'
	return 0;
}
