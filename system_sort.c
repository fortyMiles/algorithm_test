/*
 * sort 1 million elements in system sort algorithm.
 * Author: Minchuian Gao <mqgao@outlook.com>
 *
 */

#include<stdio.h>
#include<time.h>

int intcomp(int *x, int *y){
	return *x - *y;
}

int main(){
	int N = 10000000;

	clock_t begin, end;
	double time_spent;
	begin = clock();

	int a[N];

	FILE * fp = fopen("number.data", "r");

	int index = 0;
	do{
		fscanf(fp, "%d", &a[index++]);
	}while(!feof(fp));

	qsort(a, N, sizeof(int), intcomp);	

	FILE * result = fopen("result_system.data", "w+"); 
	for(int i = 0; i < N; i++){
			fprintf(result, "%d\n", a[i]);
		}

	fclose(fp);
	fclose(result);

	end = clock();
	time_spent = (double)(end - begin)/ CLOCKS_PER_SEC;
	printf(" system q sort %f", time_spent);

	return 0;
}

