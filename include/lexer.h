typedef enum {
    T_ID, T_PRINT, T_ADD, T_OPEN_P, T_CLOSE_P, T_CHAR, T_NUM, T_END, T_OPEN_Q, T_CLOSE_Q,
    VAR_STMT_LIST, VAR_S, VAR_E, VAR_E_PRIME, VAR_T, VAR_T_PRIME, VAR_F
} TokenType;

typedef struct {
    TokenType type;
    char lexeme[100];
} Token;

Token token_stream(char* input, int *pos);

const char* token_type_to_string(TokenType type);