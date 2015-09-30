#include<stdio.h>

void testReadBackwords(){
	FILE * fp = fopen("result.data", "r");
	fseek(fp, -1, SEEK_END); // next to last line, last if EOF
	long size = 0;
	size = ftell(fp);
	printf("file pointer position is %ld", size);

	char c = fgetc(fp);
	printf("%c\n", c);


	while( c == '\n'){
		fseek(fp, -2, SEEK_CUR);
		c = fgetc(fp);
		size = ftell(fp);
		printf("file pointer position is %ld", size);
		printf("%c\n", c);
	}

	printf("***********************");

	while( c != '\n'){
		fseek(fp, -2, SEEK_CUR);
		c = fgetc(fp);
		size = ftell(fp);
		printf("file pointer position is %ld", size);
		printf("%c\n", c);
	}

	fseek(fp, 1, SEEK_CUR);

	int number = 0;
	fscanf(fp, "%d", &number);
	fclose(fp);
	printf("resutl is %d\n", number);
}

int main(){
	testReadBackwords();
}
