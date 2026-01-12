
// For Symantic Analysis
// typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_FUNC, TYPE_ARRAY, TYPE_STRING } SymbolType;
// typedef struct {
//     char name[10];
//     SymbolType type;
//     int line;
//     int value; // just store int for now
// } Symbol_Entry;

// Symbol_Entry symbol_table[100];
// int sym_cnt = 0;
// void create_sym_entry(char* name, SymbolType type, int line, int val){
//     strcpy(symbol_table[sym_cnt].name, name);
//     symbol_table[sym_cnt].type = type;
//     symbol_table[sym_cnt].line = line;
//     symbol_table[sym_cnt].value = val;
//     sym_cnt++;
// }

// int lookup(char *name) { // will use hashmap
//     for (int i = 0; i < sym_cnt; i++) {
//         if (strcmp(symbol_table[i].name, name) == 0) {
//             return i; // Found index
//         }
//     }
//     return -1; // Not found
// }
