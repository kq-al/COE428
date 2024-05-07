#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

extern char* pop();
extern void push(char);

int main(int argc, char* argv[])
{
    int ch;
    int last = '    ';
    char tag[100];
    int tagLength = 0;
    while ((ch = getchar()) != EOF) {
        if (last == '<' && ch != '/') {
            tagLength = 0;
            while (isalpha(ch)) {
                tag[tagLength] = ch;
                tagLength++;
                ch = getchar();
            }
            tag[tagLength] = '\0';
            if (ch != '>') {
                fprintf(stderr, "TAG not Valid\n");
                exit(1);
            }
            push(tag[0]);
        }
        else if (last == '<' && ch == '/') {
            tagLength = 0;
            ch = getchar();
            while (isalpha(ch)) {
                tag[tagLength] = ch;
                tagLength++;
                ch = getchar();
            }
            tag[tagLength] = '\0';
            if (ch != '>') {
                fprintf(stderr, "TAG not Valid\n");
                exit(1);
            }
            char start_tag = pop();
            if (start_tag == -1) {
                fprintf(stderr, "Stack is Empty\n");
                exit(1);
            }
            if (start_tag != tag[0]) {
                fprintf(stderr, "TAGs Ummatched\n");
                exit(1);
            }
        }
        last = ch;
    }
    if (!isEmpty()) {
        fprintf(stderr, "TAG not Closed\n");
        exit(1);
    }
    printf("Valid\n");
    exit(0);
}