/*
 * Implements of Bit Map
 * 
 * Author: Minchiuan Gao <mqgao@outlook.com>
 *
 *  The simpest implements of bit map is to write in char(because char only is one byte), but still waste 7/8 of the memory spacce.
 *  This programming will implement it by ** array of int **
 *  
 *  If we have a bit array A, A[0] will contain 4 bytes which are 32 bits.
 *  
 *  So if we need a bitmap which length of 10, 000, 000, which apporiximatly is 1M, 2^20, so we need a length is 2^20 / 2^5 = 2^15 = 2 ^ 5 * 2 ^ 10 = 
 *  10 * 1k = 10k ~= 10, 000. It means we need an A[30000]
 *  
 *  Elements with index * k * in the bit map is :
 *		+ bit position k % 32
 *		+ array elements with index A[k/32]
 */

void setBit(int A[], int k){
	int pos = k % 32;
	int index = k / 32;
	unsigned int flag = 1; // flag = 0000000000000000000000001
	flag = flag << pos; // flag =	 0000000001000000000000000
	A[i] = A[i] | flag; // set the positino of A[i] to 1
	/* the shorten version
	A[k/32] |= 1 << (k%32); //Set the bit at the k-th position in A[i]
	*/
}

void clearBit(int A[], int k){
	int index = k / 32;
	int pos = k % 32;
	unsigned int flag = 1; // flag = 0000000000000000000001
	flag = flag << pos;   //  flag = 0000000000000100000000
	flag =~ flag;         //  flag = 1111111111111011111111
	A[i] = A[i] & flag; // set the position in A[i] to zero
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
