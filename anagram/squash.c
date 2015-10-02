#include<stdio.h>
#include<string.h>
#define WORDMAX 100

int main(){
	char word[WORDMAX], sig[WORDMAX], oldsig[WORDMAX];
	int lineNumber = 0;
	strcpy(oldsig, "");
	while(scanf("%s %s"), sig, word != EOF){
		if(strcmp(oldsig, sig) != 0 && lineNumber > 0) printf("\n");
	}
}
