#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/token_value/token_value.h"

void operand_error(int token_position){
    
    bool token_column_foun = false;
    fprintf(stderr, "\n\033[31mOperand Error\033[0m: Expected an operand after \033[32m'%s'\033[0m at \033[36mline\033[0m \033[31m%d\033[0m,\033[36mcolumn\033[0m \033[31m%d\033[0m either integer or identifier\n\n",
    tokens[token_position].value,tokens[token_position].line,tokens[token_position].column);
    fprintf(stderr,"   %d | ",tokens[token_position].line);
    for (int x =0;x< token_count;x++){
         if(tokens[x].line ==tokens[token_position].line){
             if(x==token_position){
             fprintf(stderr,"\033[31m%s\033[0m ",tokens[x].value);


             }else{
             fprintf(stderr,"%s ",tokens[x].value);          
             }

            
        }
    }
    fprintf(stderr,"\n     | ");
    
    fprintf(stderr,"^");

    fprintf(stderr,"\n\n");

    exit(0);

}