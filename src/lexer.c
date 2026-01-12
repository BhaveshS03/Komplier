#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/lexer.h"

Token token_stream(char* input, int *pos){
    Token t;
    memset(t.lexeme, 0, 100);
    t.lexeme[0] = '\0';
    while (isspace(input[*pos])) (*pos)++;
    if (input[*pos] == '\0') { t.type = T_END; return t; }
    else if (input[*pos] == '(') { (*pos)++; t.type = T_OPEN_P; strcpy(t.lexeme, "("); return t; }
    else if (input[*pos] == ')') { (*pos)++; t.type = T_CLOSE_P; strcpy(t.lexeme, ")"); return t; }
    else if (input[*pos] == '+') { (*pos)++; t.type = T_ADD; strcpy(t.lexeme, "+"); return t; }

    else if(strncmp(&input[*pos], "print", 5) == 0){
        *pos+=5;
        t.type = T_PRINT;
        strcpy(t.lexeme, "print");
    }

    else if (input[*pos] == '"') {
        (*pos)++;
        int i = 0;
        while (input[*pos] != '"' && input[*pos] != '\0') 
            t.lexeme[i++] = input[(*pos)++];
        t.lexeme[i] = '\0';
        if (input[*pos] == '"') {
            (*pos)++;
        } else {
            printf("Lexical Error: Missing closing quote\n");
        }
        t.type = T_CHAR;
    }

    else if (isalpha(input[*pos])) {
        int i = 0;
        while (isalnum(input[*pos])) t.lexeme[i++] = input[(*pos)++];
        t.lexeme[i] = '\0';
        t.type = T_ID;
    }

    else if (isdigit(input[*pos])) {
        int i = 0;
        while (isdigit(input[*pos])) t.lexeme[i++] = input[(*pos)++];
        t.lexeme[i] = '\0';
        t.type = T_NUM;
    }
    print_token(t);
    return t;   
}

void print_token(Token t) {
    const char* type_str;

    switch (t.type) {
        case T_OPEN_P:  type_str = "OPEN_PAREN"; break;
        case T_CLOSE_P: type_str = "CLOSE_PAREN"; break;
        case T_ADD:     type_str = "PLUS_SIGN";  break;
        case T_PRINT:   type_str = "KEYWORD_PRINT"; break;
        case T_CHAR:    type_str = "STRING_LITERAL"; break;
        case T_ID:      type_str = "IDENTIFIER"; break;
        case T_NUM:     type_str = "NUMBER"; break;
        case T_END:     type_str = "EOF"; break;
        default:        type_str = "UNKNOWN"; break;
    }

    printf("Token: [%-15s] | Lexeme: \"%s\"\n", type_str, t.lexeme);
}



const char* token_type_to_string(TokenType type) {
    switch (type) {
        case T_ID:          return "T_ID";
        case T_PRINT:       return "T_PRINT";
        case T_ADD:         return "T_ADD";
        case T_OPEN_P:      return "T_OPEN_P";
        case T_CLOSE_P:     return "T_CLOSE_P";
        case T_CHAR:        return "T_CHAR";
        case T_NUM:         return "T_NUM";
        case T_END:         return "T_END";
        case VAR_S:         return "VAR_S";
        case VAR_E:         return "VAR_E";
        case VAR_E_PRIME:   return "VAR_E_PRIME";
        case VAR_T:         return "VAR_T";
        case VAR_T_PRIME:   return "VAR_T_PRIME";
        case VAR_F:         return "VAR_F";
        case VAR_STMT_LIST: return "VAR_STMT_LIST";
        default:            return "UNKNOWN_TOKEN";
    }
}