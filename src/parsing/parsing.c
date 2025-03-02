#include "../include/parsing/parsing.h"
#include "../include/token_value/token_value.h"
#include "../include/debug/debug.h"
#include <string.h>
#include <stdio.h>
int sel_token =0;
TokensStored* tokens_stored;
int total_tokens;




void variable_initilize_parser(){

        if (tokens_stored[sel_token].type==KEYWORD){

        }
}


void keyword_distributor(){
    // print_tokens(tokens_stored,total_tokens);
    for (int i =0 ;i<size_variable_keywords;i++){
    if(strcmp(tokens_stored[sel_token].value,variable_keywords[i])==0 ){
        variable_initilize_parser();
    }
    }
}



void core_parser(TokensStored* tokens,int token_count){
print_tokens(tokens,token_count);
tokens_stored=tokens;
total_tokens =token_count;
for (int i =0; i<token_count;i++){
    if(tokens[i].type==KEYWORD){
        keyword_distributor();
    }
}
sel_token++;

}