#include <stdlib.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;

	if (argc ==1) {

	}

   	else if (argc == 2) {
		if (atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0) {
			fprintf(stderr, "Arguments inputed cannot be less than 1, and must be integer value.");
			exit (-1); 
		}
		n = atoi(argv[1]);
    	}
	else if (argc >= 3){	
		if (atoi(argv[2] = atoi(argv[3]) || atoi(argv[1]) <= 0 || atoi(argv[2]) <= 0 || atoi(argv[3]) <= 0) {
			fprintf(stderrm, "Incorrect Arugments, please double check your values: the values cannot be less than 1, and the origin and destination cannot be the same.");
    			exit(-1);
		}
		n = atoi(argv[1]);
		from = atoi(argv[2]);
		dest = atoi(argv[3]);
	}
	else
	{
	fprintf(stderr, "Incorrect arguments inputted");
	exit(-1);
	}


	towers(n, from, dest);
    	exit(0);
}

