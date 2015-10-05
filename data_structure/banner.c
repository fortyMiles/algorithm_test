/*
 * Implements banner function by c.
 * Given a capital char, and draw its graphical picture.
 *
 * Author: Minchiuan Gao <mqgao@outlook.com>
 * Date: 2015-Otc-4
 * 
 */

#include<stdio.h>
#include<stdlib.h>

typedef struct Line{
	char * chars;
	int * number;
	int charNumber;
	int numberNumber;
}Line;

void initialLine(Line * linePtr){
	linePtr->charNumber = 0;
	linePtr->numberNumber = 0;
	linePtr->chars = (char *)malloc(linePtr->charNumber * sizeof(char));
	linePtr->number= (int *)malloc(linePtr->numberNumber * sizeof(int));
}

void lineAddAChar(Line * linePtr, char ch){
	linePtr->chars = (char *)realloc(linePtr->chars, (linePtr->charNumber + 1) * sizeof(char));
	linePtr->chars[linePtr->charNumber] = ch;
	linePtr->charNumber++;
}

void lineAddANumber(Line * linePtr, int count){
	linePtr->number = (int *)realloc(linePtr->number, (linePtr->numberNumber + 1) * sizeof(int));
	linePtr->number[linePtr->numberNumber] = count;
//	printf("\n point 1\n");
//	printf(" count == %d\n", count);
//	for(int i = 0; i<=linePtr->numberNumber; i++){
////		printf("%d", linePtr->number[i]);
//	}
//	printf("\nadd count:%d\n", count);
	linePtr->numberNumber++;
}

typedef struct CharGraph{
	char ch;
	Line * lines;
	int lineNumber;
	void (* appendLine)(Line, struct CharGraph *);
	void (* printOneLine)(Line);
	void (* draw)(struct CharGraph *);
}CharGraph;

void appendLine(Line line, CharGraph * charGraph){
	// line is the single line consists char graph.
	charGraph->lines[charGraph->lineNumber-1] = line;
	charGraph->lines = (Line *)realloc(charGraph->lines, (charGraph->lineNumber+1) * sizeof(line));
	charGraph->lineNumber++;
}

void printOneLine(Line line){
	/*
	printf("*******************************************\n");
	for(int i = 0; i < line.charNumber; i++){
		printf("%c", line.chars[i]);
	}
	printf("\n");
	for(int i = 0; i < line.numberNumber; i++){
//		printf("%d", line.number[i]);
	}
	printf("\n");
	*/
	for(int charIndex= 0; charIndex < line.charNumber; charIndex++){
		for(int number = 0; number < line.number[charIndex]; number++){
			printf("%c", line.chars[charIndex]);
		}
	}
	printf("\n"); // change the line
}

void draw(CharGraph * charGraph){
//	printf("begin to draw\n");
	//for(int lineIndex = 0; lineIndex < charGraph->lineNumber; lineIndex++){
	for(int lineIndex = 0; lineIndex < charGraph->lineNumber; lineIndex++){
//		printf("%d\n", lineIndex);
		Line line = charGraph->lines[lineIndex];
		printOneLine(line);
	}
}

void initCharGraph(CharGraph * charGraph, char c){
	charGraph->ch = c;
	charGraph->lineNumber = 1;
	charGraph->lines = (Line *)malloc(charGraph->lineNumber * sizeof(Line));
	charGraph->appendLine = appendLine;
	charGraph->printOneLine = printOneLine;
	charGraph->draw = draw;
}

int isDigital(char ch){
	return ch >= '0' && ch <= '9';
}

int isUpper(char ch){
	return ch >= 'A' && ch <= 'Z';
}

int changeToNumber(char ch){
	int result = ch - '0';
//	printf("result:%d\n", result);
	return ch - '0';
}

int main(){
	typedef char * string;

	/*
	int charGraphNumber = 0;
	CharGraph ** charGraphList = (CharGraph *)malloc(charGraphNumber * sizeof(CharGraph));
	 * not implements the words list. !!
	*/

	string file = "word_graph.data";

	FILE * fp = fopen(file, "r");

	/*
	do{
		char * currentChar;
		fscanf(fp, "%s", currentChar);

		printf("%s", currentChar);
		if(isDigital(currentChar)){
		}
		printf("char:%c\n", currentChar);
		if(currentChar=='\n') printf("line end");
	}while(!feof(fp));
	*/

	char * line_words = NULL;
	size_t readNumber = 0;

	CharGraph charGraph;  // create new char graph of a single char.

	while((readNumber=getline(&line_words, &readNumber, fp)) != -1){
		if(isUpper(line_words[0])){
			char ch = line_words[0];
			initCharGraph(&charGraph, ch); // initial new char graph to represent of 'ch'
			/*
			 charGraphList = (CharGraph *)realloc(charGraphList, (charGraphNumber + 1)* sizeof(CharGraph)); // increase the charGraph list length;
			charGraphList[charGraphNumber] = &charGraph;
			*/
		}else{
			Line line;
			initialLine(&line);
			for(int i = 0; i<readNumber; i++){
				if(line_words[i] == '\n'){ 
//					printOneLine(line);
					charGraph.appendLine(line, &charGraph);
					break; 
				}
				char currentChar = line_words[i];
				if(isDigital(currentChar)){
					lineAddANumber(&line, changeToNumber(currentChar));
				}else{
					lineAddAChar(&line, currentChar);
				}
				int lineNumber = charGraph.lineNumber;
//				printf("lineNumber:%d\n", lineNumber);
			}
		}
//		printf("read number:%zu\n", readNumber);
//		printf("%s", line_words);
	}

//	int lineNumber = charGraph.lineNumber;
/	printf("lineNumber:%d\n", lineNumber);
//	for(int i = 0; i < charGraph.lineNumber; i++){
//		printf("%s", charGraph.lines[i].chars);
//	}
	charGraph.draw(&charGraph);

	return 0;
}
