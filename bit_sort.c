/*
 * Implements of Bit Sort
 * Author: Minchiuan Gao <mqgao@outlook.com>
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#define BITSPERWORD 32
#define N 10000000

typedef int bool;
typedef char * string;
#define true 1
#define false 0

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


void bitSort(){
	FILE * fp;
	char * line = NULL;
	size_t len = 0;

	clock_t begin, end;
	double time_spent;

	begin = clock();
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

	result = fopen("result.data", "w");

	for(int i = 0; i < N; i++){
		if(testBit(array, i) == 1){
			fprintf(result, "%d\n", i);
		}
	}

	fclose(fp);
	fclose(result);

	end = clock();
	time_spent = (double)(end - begin)/ CLOCKS_PER_SEC;
	printf("bit sort %f", time_spent);
	//exit(EXIT_SUCCESS);
}


FILE * moveCursorToLastLine(FILE *fp){
	fseek(fp, -1, SEEK_END); // next to last line, last if EOF
	long size = 0;

	char c = fgetc(fp);

	while( c == '\n'){
		fseek(fp, -2, SEEK_CUR);
		c = fgetc(fp);
	}

	while( c != '\n'){
		fseek(fp, -2, SEEK_CUR);
		c = fgetc(fp);
	}

	fseek(fp, 1, SEEK_CUR);
	return fp;
}

int findMaxNumber(FILE *fp){
	// find the larger from a file contains sqenutial number lines.

	fp = moveCursorToLastLine(fp);

	int number = 0;
	fscanf(fp, "%d", &number);
	//printf("%d", number);
	//fclose(fp);
 
	return number;
}


int findMinNumber(FILE *fp){
	// find the smallest from a file contains sqenutial number lines.
	int smallest = 0;
	fscanf(fp, "%d", &smallest);
	//fclose(fp);
	return smallest;
}


int findMissNumber(){
	/*
	 * finds a missed number from a huge number file.
	 */
	
	// first step sort. We can use bit sort.
	
	//bitSort();

	string targetFile = "result.data";

	int mixNumber = 0;
	int lowNumber = 0;
	int highNumber = 0;
	int currentNumber = 0;

	int maxNumber = 0; 
	int minNumber = -1;

	printf("max = %d, min = %d\n", maxNumber, minNumber);
	FILE * fp;

	int number = 0;
	
	while(number++ < 2){
	//while(minNumber < maxNumber){
		fp = fopen(targetFile, "r");

		if(fp == NULL){
			printf("file not found");
			exit(EXIT_FAILURE);
		}else{
			printf("file found");
		}

		minNumber = findMinNumber(fp);
		maxNumber = findMaxNumber(fp);

		int middle = (maxNumber + minNumber) / 2;
		
		printf("max = %d, min = %d, middle = %d", maxNumber, minNumber, middle);
		bool findEqual = false;

		string low = "low.data";
		string high = "high.data";

		FILE * file_low = fopen(low, "w");
		FILE * file_high = fopen(high, "w");

		bool findMix = false;

		rewind(fp);
		do{
			fscanf(fp, "%d", &currentNumber);
			//printf("%d\n", currentNumber);
			//printf("point\n ");
			if (currentNumber < middle){
				// save to low.data
				lowNumber++;
				fprintf(file_low, "%d\n", currentNumber); // write to the low file
			}else if(currentNumber > middle){
				// save to high.data
				if(findEqual){
					highNumber++;
					fprintf(file_high, "%d\n", currentNumber);
				}else{ // if not find equal to middle but jump to currentNumber > middle directly.
					mixNumber = middle;
					findMix = true;
					fprintf(file_low, "%d\n", currentNumber); // write to the low file
				}
			}else{
				findEqual = true; // currentNumber == middle;
			}
		}while(!feof(fp));

		fclose(fp);

		if(findMix){
			break;
		}

		if (lowNumber <= highNumber){
			targetFile = low;
		}else{
			targetFile = high;
		}
	}

	// use binary search to find the miss number.
	return mixNumber;
}


int main(){
	/*
	printf("=========");
	//int missedNumber = findMissNumber();
	//printf("\n%d\n", missedNumber);
	string targetFile = "result.data";
	FILE * fp = fopen(targetFile, "r");
	printf("min = %d\n", findMinNumber(fp));

	rewind(fp);
	int max = findMaxNumber(fp);
	printf("max = %d", max);
	fclose(fp);
	*/
	int missedNumber = findMissNumber();
	printf("\n%d missed \n", missedNumber);
}
