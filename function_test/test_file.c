#include<stdio.h>

typedef char * string;
int main(){
	string name = "name_1";
	printf("%s", name);
	string name2 = name;
	printf("%s", name2);
	
	puts(name);
}
