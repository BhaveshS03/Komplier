#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"

int length = 0,pos = 0;
char* input;

int main(){
    FILE *fptr;

    fptr = fopen("example.fr", "rb");
    if(fptr == NULL){
        printf("No file found"); return 0;
    }
    fseek(fptr, 0, SEEK_END);
        length = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    char *buffer = malloc(length + 1);
    if (buffer) {
        fread(buffer, 1, length, fptr);
        buffer[length] = '\0';
        input = buffer;
    }
    fclose(fptr);
    while(pos<length){
        parse(input, &pos);
    }
    if (buffer) {
        free(buffer);
    }

    return 0;
}
