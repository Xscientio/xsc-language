#include "../include/parsing/parsing.h"
#include "../include/token_value/token_value.h"
#include "../include/debug/debug.h"
#include <string.h>
#include <stdio.h>
int sel_token =0;
TokensStored* tokens_stored;
int total_tokens;





void variable_initilize_parser(){
     sel_token++;
    if(tokens_stored[sel_token].subtype == USR_IDENTIFIER){
        sel_token++;
        if (tokens_stored[sel_token].subtype == EQUAL){
            sel_token++;
            if(tokens_stored[sel_token].subtype==USR_INTEGER){
                for (int i =sel_token; tokens_stored[i].subtype ==USR_INTEGER;i++){
                        sel_token ++;
                }
                

            }else if (tokens_stored[sel_token].subtype==USR_STRING){
                

            }else if (tokens_stored[sel_token].subtype==USR_IDENTIFIER){

            }
        }else if(tokens_stored[sel_token].subtype==COLON){

        }else{
            printf("Error You missed something");
        }
    }

}


void keyword_distributor(){
    if (tokens_stored[sel_token].subtype == INT || STR){
        variable_initilize_parser();
    }
}



void core_parser(TokensStored* tokens,int token_count){
print_tokens(tokens,token_count);
tokens_stored=tokens;
total_tokens =token_count;
for (int i =0; i<token_count;i++){

    if(tokens_stored[i].type==KEYWORD){
        keyword_distributor();

    }
      
}
sel_token++;

}