#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
extern int heapSize();
extern int heapDelete();
extern void addHeap(int);
extern int buildHeap();
extern int printXML();
extern int pop();
extern void push(int);



int main(int argc, char * argv[])
{
	int key;
	int value;
	while (scanf("\n%d\n", &value) != EOF) {
		addHeap(value);
	}
	buildHeap();
	printXML(0);
	printf("\n");
	int s = heapSize();
	for(int i = 0; i < s; i++){
		key = heapDelete();
		printf("%d\n", key);
		push(key);
	}
	printf("Reverse Print:\n");
	for(int i = 0; i < s; i++){
		printf("%d\n", pop());
	}
	exit(0);
}