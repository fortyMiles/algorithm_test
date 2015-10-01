/*
 * Rotates an array of n length to left i positions.
 * assume array is <ab>, we need to rotate it to <ba>
 * <ab> => <a^rb> => <a^rb^r> => <a^rb^r>^r = <ba>
 * 
 * Author: Minchuian Gao <mqgao@outlook.com>
 * Date: 2015-Oct-1
 *
 */

#include<stdio.h>
#include<stdlib.h>

void reverse(int array[], int begin, int end){
	// reverses the array from begin to end;
	// arise: when bgein <0 or end > length(array) will array out of index;
	int temp = 0;	

	while(begin < end){
		temp = array[begin];
		array[begin] = array[end];
		array[end] = temp;
		begin++;
		end--;
	}
}

void rotateArray(int array[], int n, int i){
	reverse(array, 0, i-1);
	reverse(array, i, n-1);
	reverse(array, 0, n-1);
}

int main(){
	int n = 0;

	printf("input the array number: \n");
	scanf("%d", &n);

	int i = 3;
	//int * array = (int *)malloc(n * sizeof(int));
	int * array;
	
	array = (int *)realloc(array, (n + 1) * sizeof(int));

	for(int i = 0; i<=n; i++){
		if(i==n){
			array[i] = -1;
		}
		else{
			array[i] = i;
		}
	}

	rotateArray(array, n+1, i);

	for(int i = 0; i<=n; i++){
		printf("%d", array[i]);
	}

	printf("\n");

	return 0;
}
