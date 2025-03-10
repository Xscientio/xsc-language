#include "../include/parsing/parsing.h"
#include "../include/token_value/token_value.h"
#include "../include/debug/debug.h"
#include "../include/error/syntax_error.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int  func_use_parse(int i){




}




int variable_initalize_parser_statement(int i){
    
    if(tokens[i+1].type== IDENTIFIER){
        i++;
        if(tokens[i+1].subtype ==EQUAL ){
            i++;
            if(tokens[i+1].type==STRING||tokens[i+1].type==IDENTIFIER||tokens[i+1].type==INTEGER){
                for (int k=i;k<token_count;k++){
                if(tokens[i+1].type==INTEGER ||tokens[i+1].type==STRING ){
                    i++;
                }
                else if(tokens[i+1].type==COLON){
                    break;
                    i++;
                    return i;
                } else if(tokens[i+1].type==OPERATOR){
                    
                     i++;
                    if(tokens[i+1].type!=INTEGER && tokens[i+1].type!=IDENTIFIER&&tokens[i+1].type!=STRING){
                         raw_syntax_error_form(i,"Expected an operand after");
                        
                    }

                } else{
                    i++;
                }

                }
          }
            else{
            raw_syntax_error_form(i,"Missing or invalid expression after");

            }
            

        }else if(tokens[i+1].subtype ==COLON){
            i++;

        }
        else{
        raw_syntax_error_form(i,"Expected a '=' or ';' after");

        }
        

    }else{
        raw_syntax_error_form(i,"Expected a valid identifier after");

    }
 

return i;
    
}


int keyword_distributor(int i){


if(tokens[i].subtype == INT ||tokens[i].subtype ==STR){
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