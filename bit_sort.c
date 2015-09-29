/*
 * Implements of Bit Sort
 * Author: Minchiuan Gao <mqgao@outlook.com>
 *
 */

#include<stdio.h>
#include<stdlib.h>
#define BITSPERWORD 32
#define N 1000000

void setBit(int A[], int k){
	int pos = k % 32;
	int index = k / 32;
	unsigned int flag = 1; // flag = 0000000000000000000000001
	flag = flag << pos; // flag =	 0000000001000000000000000
	A[index] = A[index] | flag; // set the positino of A[i] to 1
	/* the shorten version
	A[k/32] |= 1 << (k%32); //Set the bit at the k-th position in A[i]
	*/
}

void clearBit(int A[], int k){
	int index = k / 32;
	int pos = k % 32;
	unsigned int flag = 1; // flag = 0000000000000000000001
	flag = flag << pos;   //  flag = 0000000000000100000000
	flag = ~flag;         //  flag = 1111111111111011111111
	A[index] = A[index] & flag; // set the position in A[i] to zero
	/*
	 * the short version
	 *		A[k/32] &= ~(1<< (k%32));
	 */
}

int testBit(int A[], int k){
	int i = k / 32;
	int pos = k % 32;
	unsigned int flag = 1;

	flag = flag << pos;
	if (A[i] & flag){ // 1 and 1 is 1
		return 1;	
	}else{ // 0 and 1 is 0, other and 0 also is 0;
		return 0; 
	}
}

int main(){
	FILE * fp;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	int array[1 + N/BITSPERWORD];

	fp = fopen("number.data", "r");

	if(fp == NULL){
		exit(EXIT_FAILURE);
	}

	/*
	printf(" read begin ");
	while( (read = getline(&line, &len, fp)) != -1){
		printf("%d", line);
	}
	*/
	int number = 0;

	do{
		fscanf(fp, "%d", &number);
		setBit(array, number);
	}while(!feof(fp));

	FILE * result;

	result = fopen("result.data", "w+");

	for(int i = 0; i < N; i++){
		if(testBit(array, i) == 1){
			fprintf(result, "%d\n", i);
		}
	}

	fclose(fp);
	exit(EXIT_SUCCESS);
}

