/*
 * Implements the digital segments problem.
 * 
 * Displays a 16-bit positive integer in five seven-segment digits.
 * The output is an array of five bytes; bit i of byte j is one if and only 
 * if hte i^th segment of digit j should be on.
 *
 */

#include<stdio.h>

#define zero "246350"
#define one  "35"
#define two  "24150"
#define three  "24160"
#define four  "3146"
#define five  "23160"
#define six  "231605"
#define seven  "246"
#define eight  "1234560"
#define nine  "12346"
#define true 1
#define false 0
typedef short bool

char * numbers[] = {zero, one, two, three, four, five, six, seven, eight, nine};
char * outputs[5];

void changeNumberToDigital(int index, int number){
	setBits
}

void setBits(char * array, int index, int bitLocation){
	// set bitLocation of array's to one;

}

bool testBit(int bitLocation){

	return false;
}

int main(){
	return 0;
}

