#include "../include/parsing/parsing.h"
#include "../include/token_value/token_value.h"
#include "../include/debug/debug.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
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
                for(int x =sel_token; tokens_stored[x].subtype!=COLON && x<total_tokens;x++){
                
                if ( tokens_stored[x].type ==OPERATOR){
                        if(tokens_stored[x+1].type != INTEGER && IDENTIFIER && OPERATOR ){
                            fprintf(stderr, "\n\033[31mOperand Error\033[0m: Expected an operand after \033[32m'%s'\033[0m either integer or identifier at \033[36mline\033[0m \033[31m%d\033[0m,\033[36mcolumn\033[0m \033[31m%d\033[0m\n\n",tokens_stored[x].value,tokens_stored[x].line,tokens_stored[x].column);
                            return;
                        }else{
                        sel_token ++;

                        }
                }else if(tokens_stored[x].subtype ==USR_INTEGER){
                        sel_token ++;

                }
                else{

                }

               
                }
                

            }else if (tokens_stored[sel_token].subtype==USR_STRING){
                

            }else if (tokens_stored[sel_token].subtype==USR_IDENTIFIER){

            }
        }else if(tokens_stored[sel_token].subtype==COLON){

        }else{ 
            printf("Error You missed something\n");
        }
    }

}


void keyword_distributor(){
    if (tokens_stored[sel_token].subtype == INT || STR){
        variable_initilize_parser();
    }
}



void core_parser(TokensStored* tokens,int token_count){
// print_tokens(tokens,token_count);
tokens_stored=tokens;
total_tokens =token_count;
for (int i =0; i<token_count;i++){

    if(tokens_stored[i].type==KEYWORD){
        keyword_distributor();

    }
      
}
sel_token++;

}