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
    char *list_token_type[8] ={"KEYWORD","PUNTUTATOR","OPERATOR","INTEGERS","STRINGS","INBUILT_FUNCTIONS","IDENTIFIERS","FAULTY"};


    for (int i =0;i<token_count;i++)
    {
        printf("Token type:\033[1;33m%s\033[0m\nToken line:\033[1;36m%d\033[0m\nToken Length:\033[1;32m%d\033[0m\nToken value: \033[1;35m%s\033[0m\n---------------------------------\n",list_token_type[tokens[i].type],tokens[i].line,tokens[i].length,tokens[i].value);
    }

}