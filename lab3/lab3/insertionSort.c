#include "mySort.h"

void mySort(int array[], unsigned int first, unsigned int last){
	for (unsigned int i = first + 1; i <= last; i++) {
       		int key = array[i];
       		int j = i - 1;
        	while (j >= (int)first && myCompare(array[j], key) > 0) {
            		myCopy(&array[j], &array[j + 1]);
            		j--;
        	}
        	myCopy(&key, &array[j + 1]);
    	}
}
