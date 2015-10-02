#include<stdio.h>

void readLastLine(){
	FILE *fp = fopen("result.data", "r");
	char line[1024] = "";
	char c;
	int len = 0;
	fseek(fp, -1, SEEK_END);//next to last char, last is EOF
	c = fgetc(fp);
	while(c == '\n')//define macro EOL
	{
		fseek(fp, -2, SEEK_CUR);
		c = fgetc(fp);
	}
	while(c != '\n')
	{
		fseek(fp, -2, SEEK_CUR);
		++len;
		c = fgetc(fp);
	}
	fseek(fp, 1, SEEK_CUR);
	printf("%d", len);

	if (fgets(line, len, fp) != NULL) 
		puts(line);
	else printf("Error\n");
	fclose(fp);
}


int main(){
	readLastLine();
	return 0;
}
