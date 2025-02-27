#include "../include/parsing/parsing.h"
#include "../include/token_value/token_value.h"
#include "../include/debug/debug.h"
#include <stdio.h>
#include <string.h>

// Global Variable
int sel_token  =0;



void variable_initilize_parser(){

  
   }


void keyword_distributor(){
    
    for (int i =0; i<size_variable_keywords;i++){
        if(strcmp(tokens[i].value,variable_keywords[i])==0){
            variable_initilize_parser();
        }
    }
}


void core_parser(){
// print_tokens(tokens,token_count);
for (int i =0;i<token_count;i++){
    sel_token++;
    switch (tokens[i].type)
    {
    case KEYWORD:
         keyword_distributor();
        break;
    
    default:
        break;
    }
}

}