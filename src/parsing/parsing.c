#include "../include/parsing/parsing.h"
#include "../include/token_value/token_value.h"
#include "../include/debug/debug.h"
#include "../include/error/error.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int sel_token =0;






void variable_initilize_parser(){
     sel_token++;
    if(tokens[sel_token].subtype == USR_IDENTIFIER){
        sel_token++;
        if (tokens[sel_token].subtype == EQUAL){
            sel_token++;
            if(tokens[sel_token].subtype==USR_INTEGER){
                for(int x =sel_token; tokens[x].subtype!=COLON && x<token_count;x++){
                
                if ( tokens[x].type ==OPERATOR){
                        if(tokens[x+1].type != INTEGER && IDENTIFIER && OPERATOR ){
                            operand_error(x);
                        }else{
                        sel_token ++;

                        }
                }else if(tokens[x].subtype ==USR_INTEGER){
                        sel_token ++;

                }
                else{

                }

               
                }
                

            }else if (tokens[sel_token].subtype==USR_STRING){
                

            }else if (tokens[sel_token].subtype==USR_IDENTIFIER){

            }
        }else if(tokens[sel_token].subtype==COLON){

        }else{ 
            printf("Error You missed something\n");
        }
    }

}


void keyword_distributor(){
    if (tokens[sel_token].subtype == INT || STR){
        variable_initilize_parser();
    }
}



void core_parser(){

for (int i =0; i<token_count;i++){

    if(tokens[i].type==KEYWORD){
        keyword_distributor();

    }
      
}
sel_token++;

}