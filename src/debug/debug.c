#include <stdio.h>

#include "../include/debug/debug.h"

/***************************************************************
 * Function: print_tokens
 * Parameters: 
 *    TokensStored *tokens: Where the tokens will be stored.
 * Return Value: null
 * Description: Just for debugging.
 ***************************************************************/
void print_tokens(TokensStored *tokens,int token_count){
    // Types of tokens
    const char *list_token_type[8] ={"KEYWORD","PUNTUTATOR","OPERATOR","INTEGERS","STRINGS","INBUILT_FUNCTIONS","IDENTIFIERS","FAULTY"};
    const char* list_token_sub_type[] = {
    "USR_IDENTIFIER",
    "USR_STRING",
    "USR_INTEGER",
    "USR_FAULT",

    "COLON",
    "RIGHT_PARENTHESIS",
    "LEFT_PARENTHESIS",
    "LEFT_CURLY_BRACKETS",
    "RIGHT_CURLY_BRACKETS",
    "LEFT_SQUARE_BRACKETS",
    "RIGHT_SQUARE_BRACKETS",
    "DOT",
    "COMMA",

    "FORWARD_SLASH",
    "PLUS",
    "ASTERISK",
    "EQUAL",
    "MINUS",

    "IF",
    "ELSE",
    "ELIF",
    "WHILE",
    "BREAK",
    "TRY",
    "EXCEPT",

    "INT",
    "STR",

    "OUTPUT",
    "INPUT"
};

    for (int i =0;i<token_count;i++)
    {
        printf("Token type:\033[1;33m%s\033[0m\nToken Sub type:\033[1;31m%s\033[0m\nToken Column No:\033[1;36m%d\033[0m\nToken Start:\033[1;36m%d\033[0m\nToken End:\033[1;36m%d\033[0m\nToken line:\033[1;36m%d\033[0m\nToken Length:\033[1;32m%d\033[0m\nToken value: \033[1;35m%s\033[0m\n---------------------------------\n",list_token_type[tokens[i].type],list_token_sub_type[tokens[i].subtype],tokens[i].column,tokens[i].start_point,tokens[i].end_point,tokens[i].line,tokens[i].length,tokens[i].value);
    }

}