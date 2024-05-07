#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char nextState(char states[8][3], char currentState, int input) {
	int index = 0; 
	int validate = 0;  

	if (input != 0 && input != 1) {
		printf("Incorrect Value Input\n");
	}

	for (int i=0; i<8; i++){
		if (states[i][0]  == currentState) {
			index = i; 
			break; 
		}
	}
	
	if (states[index][0] == currentState) {
		validate = 1;
	}
	else 
	{
		printf("Error Fetching Next state: Current Index not pointing to inputed Current State");
	}

	if (validate == 1) {
		if (input == 0) {
			return states[index][1];
		}
		else if (input == 1) {
			return states[index][2];
		}
		else
		{
			printf("Error Fetching Next State: Input does not equal 0 or 1"); 
		}
	}
	return ' ';
}

void changeState(char userInput[100], char currentState, char states[][3]) {
	int i;
	for (i=0; i<8; i++) {
		if (states[i][0] == currentState) {
			if (userInput[2] == '0'){
				states[i][i] = userInput[4];
			}
			else if (userInput[2] == '1') {
				states[i][2] = userInput[4];
			}
			break; 
		}
	}
}

void printStates(char states[][3]) {
	for (int i=0; i<8; i++) {
		if (states[i][0] != '-') {
			printf("%c: %c %c\n", states [i][0], states [i][1], states[i][2]);
		}
	}
}

void unreachableStates(char states[][3], int total, char garbage[8]) {
    int c=0;
    int ref=0;
    int g=0;
    
    for (int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
	  if ((states[i][0]==states[j][1])&&(states[i][0]==states[j][2])) {
                ref++;
            }
        }
        if (ref==0) {
            garbage[g]=states[i][0];
            g++;
            c++;
        }
        ref=0;
    }
	

    int sizeG=sizeof(garbage)/sizeof(garbage[0]);
    if (c == 0) {
        printf("Garabage not found");
    }
    else
    {
        for (int i = 0; i < sizeG; i++) {
            if (garbage[i] >= 'A' && garbage[i] <= 'H') {
               printf("Garbage: %c\n", garbage[i]); 
            }        
        }
    }
}


void deleteState(char states[][3], int total, char garbage[8]) {
	int c=0;
        int sizeG=(sizeof(garbage)/sizeof(garbage[0]));

        for (int i = 0; i < sizeG; i++) {
            for (int j = 0; j < 8; j++) {
                if (garbage[i] == states[j][0]) {
                    printf("Deleted:%c\n", states[j][0]);
                    states[j][0] = '-';
                    states[j][1] = '-';
                    states[j][2] = '-';
                    c++;
                }
            }
        }
        total=total-c;
        if(c==0) 
        {
            printf("Garbage is empty");
        }
    }

void deleteTarget(char states[][3], int total, char strInput, char garbage[8]) {
	int c = 0; 
	int sizeG = (sizeof(garbage)/sizeof(garbage[0]));

	for (int i=0; i<sizeG; i++){
		if (garbage[i] == strInput) {
			for (int j=0; j<8; j++) {
				if (garbage[i]==states[j][0]){
					states[j][0] = '-';
					states[j][0] = '-';
					states[j][0] = '-';
					printf("Deleted:%c\n", strInput);
				}
			}
			c++;
		}
	}
	total = total - c; 
	if (c==0) {
		printf("State not deleted");
	}
}

int main(int argc, char* argv[]) {
	int intInput;
   	int total = 8;
    	char garbage[8];
    	memset(garbage, '\0', sizeof(garbage));
    	char strInput[100];
    	char initialState = 'F';
    	char currentState = initialState;
    	char states[8][3] = 
	{
        	{'A','D','G'},
        	{'B','G','E'},
        	{'C','C','H'},
        	{'D','A','C'},
        	{'E','F','A'},
        	{'F','B','D'},
        	{'G','C','E'},
		{'H','B','F'}
    	};

	printf("Your Starting state is: < %c >\n", initialState);
	
	while (1) {
			
        	intInput = 5;
        	strInput[0] = '-';
        	strInput[1] = '-';
        	strInput[2] = '-';
        	strInput[3] = '-';
        	strInput[4] = '-';
        	strInput[5] = '-';

        	while (1) {
			
			printf("\nEnter an Input:");
            		fgets(strInput, 100, stdin);
            
            		if (strInput[0] == '1' && strlen(strInput) == 2) {
                		intInput = 1;
                		break;
            		}
            		else if (strInput[0] == '0' && strlen(strInput) == 2) 
            		{
                		intInput = 0;
                		break;
            		}
            		else if (strInput[0] == 'c' && (strInput[2] == '0' || strInput[2] == '1') && strInput[4] >= 'A' && strInput[4] <= 'H') 
            		{
                		break;
            		}
            		else if (strInput[0] == 'p' && strlen(strInput) == 2) 
            		{
                		break;
            		}
            		else if (strInput[0] == 'd' && (strlen(strInput) == 2 || strlen(strInput) == 3)) 
            		{
                		break;
            		}
            		else if (strInput[0] == 'g' && strlen(strInput) == 2) 
           		{
                		break;
            		}	
            		else if (strInput[0] == 'q' && strlen(strInput) == 2) 
            		{
                		return(0);
            		}
            		else {
                		printf("\nInvalid Input Try Again\n");
            		}
        	}


        	if (intInput == 1) {
			currentState = nextState(states, currentState, 1);
			printf("The Current State is: < %c >\n", currentState);
		}
        	else if (intInput == 0) 
        	{
            		currentState = nextState(states, currentState, 0);
            		printf("The Current State is: < %c >\n", currentState);
        	}
		else if (strInput[0] == 'c') 
        	{
            		changeState(strInput, currentState, states);
        	}
        	else if (strInput[0] == 'p') 
        	{
            		printStates(states);
        	}
        	else if (strInput[0] == 'd') 
        	{
            		if (strlen(strInput) == 2) {
                		deleteState(states, total, garbage);
           		}
            		if (strlen(strInput) == 3) {
                		deleteTarget(states, total, strInput[1], garbage);
            		}
        	}
        	else if (strInput[0] == 'g') 
        	{
            		unreachableStates(states, total, garbage);
        	}
    	}
    	return 0;
}

