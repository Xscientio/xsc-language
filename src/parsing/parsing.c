#include "../include/parsing/parsing.h"
#include "../include/token_value/token_value.h"
#include "../include/debug/debug.h"
#include "../include/error/syntax_error.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



int variable_initalize_parser_statement(int i){
    
    
    if(tokens[i+1].type== IDENTIFIER){
        i++;
        if(tokens[i+1].subtype ==EQUAL){

        }else if(tokens[i+1].subtype ==COLON){
            i++;
            return i;

        }
        else{
        raw_syntax_error_form(i,"Expected a '=' or ';' after","Missing syntax");

        }
        

    }else{
        raw_syntax_error_form(i,"Expected a valid identifier after","Invalid identifier");

    }
 

return i;
    
}


int keyword_distributor(int i){


if(tokens[i].subtype == INT ||STR){
    variable_initalize_parser_statement(i);
}

return i;
}




void core_parser(){
// print_tokens(tokens,token_count);
for (int i =0; i<token_count;i++){

    if(tokens[i].type==KEYWORD){
      i =  keyword_distributor(i);

    }else if(tokens[i].type==IDENTIFIER){

    }
      
}

}