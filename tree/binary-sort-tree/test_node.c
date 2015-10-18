#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int value;
} Node;

int main(){
	Node node;
	node.value = 10;

	Node * newNode;
	newNode -> value = 99;
	
	newNode = &node;
	printf("%d\n", newNode -> value);
	return 0;
}
