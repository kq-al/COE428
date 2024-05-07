#include "mySort.h"

void myMerge(int array[], unsigned int first, unsigned int mid, unsigned int last) {
    int temp[last - first + 1];
    unsigned int left = first;
    unsigned int right = mid + 1;
    unsigned int index = 0;

    while (left <= mid && right <= last) {
        if (myCompare(array[left], array[right]) <= 0) {
            myCopy(&temp[index], &array[left]);
            ++left;
        } else {
            myCopy(&temp[index], &array[right]);
            ++right;
        }
        ++index;
    }

    while (left <= mid) {
        myCopy(&temp[index], &array[left]);
        ++left;
        ++index;
    }

    while (right <= last) {
        myCopy(&temp[index], &array[right]);
        ++right;
        ++index;
    }

    for (unsigned int i = 0; i < index; ++i) {
        myCopy(&array[first + i], &temp[i]);
    }
}

void myMergeSort(int array[], unsigned int first, unsigned int last) {
    if (first < last) {
        unsigned int mid = (first + last) / 2;
        myMergeSort(array, first, mid);
        myMergeSort(array, mid + 1, last);
        myMerge(array, first, mid, last);
    }
}