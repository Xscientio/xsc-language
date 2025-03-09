#include "../include/parsing/parsing.h"
#include "../include/token_value/token_value.h"
#include "../include/debug/debug.h"
#include "../include/error/error.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>






int variable_initilize_parser(int i){
     i++;
    if(tokens[i].subtype == USR_IDENTIFIER){

        i++;
        if (tokens[i].subtype == EQUAL){

            i++;
            if(tokens[i].subtype==USR_INTEGER){

                for(int x =i; tokens[x].subtype!=COLON && x<token_count;x++){
                if ( tokens[x].type ==OPERATOR){


                        if(tokens[x+1].type != INTEGER && IDENTIFIER && OPERATOR ){

                            operand_error(x);
                        }else{
                        i ++;


                        }
                }else if(tokens[x].subtype ==USR_INTEGER){
                        i ++;

                }
                else{

                }

               
                }
                

            }else if (tokens[i].subtype==USR_STRING){
                

            }else if (tokens[i].subtype==USR_IDENTIFIER){

            }
        }else if(tokens[i].subtype==COLON){

        }else{ 
            printf("Error You missed something\n");
        }
    }
    return i;

}


int keyword_distributor(int i){
    if (tokens[i].subtype == INT || STR){

        variable_initilize_parser(i);
    }
    return i;
}



void core_parser(){

for (int i =0; i<token_count;i++){
    if(tokens[i].type==KEYWORD){
        // printf("%s\n",tokens[i].value);
      i=  keyword_distributor(i);

    }
      
}

}