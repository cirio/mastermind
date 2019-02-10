/*
@(#)File:           Utility.h
@(#)Author:         Andrea Cirioni
*/

#include <stdlib.h>
#include <time.h>

typedef enum { false, true } bool;

int GetRandomNumberInRange(int lower, int upper){
    return (rand() % (upper - lower + 1)) + lower;
}

int SplitIntToArrayInt(int *arrToCompare, unsigned long n) {
	int index = 0;
	if (n>9) { 
        index = SplitIntToArrayInt(arrToCompare, n/10); 
    }
    arrToCompare[index] = n % 10;
	return index + 1;
}

   






