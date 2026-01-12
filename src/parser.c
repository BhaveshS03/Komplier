#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/lexer.h"

// S -> print ( E ) Statement can be identifier = expession
// E -> T E' Expression can be expression or expanstion of a term
// T -> is a Term is an identifer

#define MAX_STACK 100
TokenType stack[MAX_STACK];
int top = -1;
void push(TokenType entry) {stack[++top] = entry;}
TokenType pop() {return stack[top--];}

void parse(char *input, int *pos){
    // create_sym_entry("ab", TYPE_INT, 1, 42);
    int p = 0;
    push(T_END);
    push(VAR_STMT_LIST);
    
    Token next = token_stream(input, pos);
    // SymbolType cet = -1;
    while(top != -1){
        TokenType X = pop();
        printf("%s \n",token_type_to_string(X));
        // Follow all the non-terminals
        if (X >= VAR_STMT_LIST){
            switch(X) {
                case VAR_STMT_LIST:
                    if (next.type == T_PRINT) {
                        push(VAR_STMT_LIST);
                        push(VAR_S); 
                    } 
                    else if (next.type == T_END) {}
                    break;
                case VAR_S:
                    // S -> print ( E )
                    if(next.type == T_PRINT){
                        push(T_CLOSE_P);
                        push(VAR_E);
                        push(T_OPEN_P);
                        push(T_PRINT);
                    } else {
                        printf("Error in S \n"); exit(-1);
                    }
                    break;
                case VAR_E:
                    // E -> T E'
                    if(next.type == T_ID || next.type == T_NUM || next.type == T_CHAR){
                        push(VAR_E_PRIME);
                        push(VAR_T); 
                    } else { 
                        printf("Error in E\n"); exit(1); 
                    } 
                    break;
                case VAR_E_PRIME:
                    // First(E') = { + }
                    if (next.type == T_ADD) {
                        push(VAR_E_PRIME); 
                        push(VAR_T); 
                        push(T_ADD);
                    }
                    // Follow(E') = { ) } -> Epsilon
                    else if (next.type == T_CLOSE_P) {
                    }
                    else { printf("Error in E'\n"); exit(1); }
                    break;

                case VAR_T:
                    // First(T) = { ID }
                    if (next.type == T_ID) {
                        push(T_ID);
                    }
                    // First(T) = { NUM }
                    else if (next.type == T_NUM) {
                        push(T_NUM);
                    } 
                    // First(T) = { CHAR }
                    else if (next.type == T_CHAR) {
                        push(T_CHAR);
                    } else { printf("Error in T\n"); exit(1); }
                    break;
                default: break;
                }
        } else {
            // First all the terminals
            if (X == next.type) {
                printf("Matched: %s\n", token_type_to_string(X));
                if (X != T_END) {
                    next = token_stream(input, pos); // Only advance on match!
                }
            } else {
                printf("Syntax Error: Expected %s, got %s\n", 
                        token_type_to_string(X), token_type_to_string(next.type));
                exit(1);
            }
        }
        
    }

}
