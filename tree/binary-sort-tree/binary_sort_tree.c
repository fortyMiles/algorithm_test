/*
 *
 * Implements hierarchy traverse and binary sort tree by C
 * Author: Minchiaun Gao <mqgao@outlook.com>
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#define false 0
#define true 1

typedef int bool;

typedef struct Node{
	int value;
	int level;
	struct Node * leftSlide;
	struct Node * rightSlide;
	void (* insetOneNode)(struct Node * this, struct Node newNode);
} Node;

// thes if Node leftSlide is Okay.
void insetOneNode(struct Node * this, struct Node newNode){
	// inset new node to node
	if(newNode.value < this -> value){
		if(this -> leftSlide != NULL){
			this -> insetOneNode(this -> leftSlide, newNode);
		}else{
			this -> leftSlide = &newNode; // this's leftSlide is newNode's address.
		}
	}else{
		if(this -> rightSlide != NULL){
			this -> insetOneNode(this -> rightSlide, newNode);
		}else{
			this -> rightSlide = &newNode;
		}
	}
}

void initNode(Node * this, int value){
	this -> value = value;
	this -> leftSlide = NULL;
	this -> rightSlide = NULL;
	this -> level = 0;
	this -> insetOneNode = insetOneNode;
}


typedef struct Queue{	
	struct Node ** addresses; // save element's address
	int begin;
	int end;
	void (* append)(struct Queue * this, Node * elementsAddress);
	Node *(* pop)(struct Queue *this);
	bool (* isEmpty)(struct Queue this);
} Queue;

void append(struct Queue * this, Node * elements){
	this -> addresses = (Node **)realloc( this -> addresses, ((this -> end) + 1) * sizeof(Node *)); // at the begin, the  end is -1, here add 2, to be 1, give this array one position.

	this -> addresses[this->end] = elements; // set end from -1 to 0;
	// this's end move back one step and assign this element
	// to this position.
	this -> end ++;
}

Node *pop(struct Queue * this){
	printf("pop %d\n", this -> addresses[this -> begin] -> value);
	return this -> addresses[ this -> begin++];
}

bool isEmpty(struct Queue this){
	return this.begin >= this.end;
}

void initQueue(Queue * this){
	this -> begin = 0;
	this -> end = 0;
	this -> addresses = (Node **)malloc(0 * sizeof(Node *));
	this -> append = append;
	this -> pop = pop;
	this -> isEmpty = isEmpty;
}

void traverseHirerachy(Node node){
	Queue queue;
	initQueue(&queue);
	queue. append(&queue, &node);
	int lastLevel = node.level;
	while( !queue. isEmpty(queue)){
		printf("pint 0\n");
		Node * nodeAddress = queue. pop(&queue);
		printf(" get value %d\n", nodeAddress -> value);
		Node node = *nodeAddress;
		printf("pint 1\n");
		if (lastLevel != node.level){
			printf("\n");
			lastLevel = node.level;
		}
		printf("%d  ", node.value);

		if(node.leftSlide != NULL){
			node.leftSlide -> level = node.level + 1;
			queue. append(&queue, node.leftSlide);
		}

		if(node.rightSlide != NULL){
			node.rightSlide -> level = node.level + 1;
			queue. append(&queue, node.rightSlide);
		}
	}
}

int main(){
	int datas[] = {12, 43, 54, 65, 76, 34, 1};

	//datas = (int *)realloc(datas, sizeof(datas)/sizeof(datas[0]) + 1);
	// will get an error, error: array type 'int [7]' is not assignable

	/*
	int * arrays;
	arrays = (int *)malloc(10 * sizeof(int));
	printf("size of datas is %ld\n", sizeof(datas)/sizeof(int));

	printf("size of datas is %ld\n", sizeof(arrays)/sizeof(int));
	// will printer 2, because 8/4 == 2;
	*/
	int value = 30;
	Node root;
	initNode(&root, value);
	for(int i = 0; i < sizeof(datas)/sizeof(datas[0]); i++){
		int value = datas[i];
		Node node;
		initNode(&node, value);
		root. insetOneNode(&root, node);
	}

	traverseHirerachy(root);
}
