#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/token_value/token_value.h"

void operand_error(int token_position){
    
    bool token_column_foun = false;
    fprintf(stderr, "\n\033[31mOperand Error\033[0m: Expected a valid operand after \033[32m'%s'\033[0m at \033[36mline\033[0m \033[31m%d\033[0m,\033[36mcolumn\033[0m \033[31m%d\033[0m\n\n",
    tokens[token_position].value,tokens[token_position].line,tokens[token_position].column);
    fprintf(stderr,"   %d | ",tokens[token_position].line);
    for (int x =0;x< token_count;x++){
         if(tokens[x].line ==tokens[token_position].line){
             if(x==token_position){
             fprintf(stderr,"\033[31m%s\033[0m ",tokens[x].value);


             }else if(x==token_position+1){
             fprintf(stderr,"\033[35m%s\033[0m ",tokens[x].value);

             }
             else{
             fprintf(stderr,"%s ",tokens[x].value);          
             }

            
        }
    }
    fprintf(stderr,"\n     | ");
    for (int i =0; i<token_position;i++){
        if(tokens[i].line ==tokens[token_position].line){
            for (int x =0 ; x< tokens[i].length;x++){
                fprintf(stderr," ");

            }
                fprintf(stderr," ");

            
        }
    }
    fprintf(stderr,"  \033[35m^\033[0m");
    fprintf(stderr,"\n     | ");
    for (int i =0; i<token_position;i++){
        if(tokens[i].line ==tokens[token_position].line){
            for (int x =0 ; x< tokens[i].length;x++){
                fprintf(stderr," ");

            }
                fprintf(stderr," ");

            
        }
    }
    fprintf(stderr,"  \033[35m|\033[0m");
fprintf(stderr,"\n     | ");
    for (int i =0; i<token_position;i++){
        if(tokens[i].line ==tokens[token_position].line){
            for (int x =0 ; x< tokens[i].length;x++){
                fprintf(stderr," ");

            }
                fprintf(stderr," ");

            
        }
    }
    fprintf(stderr,"  \033[35m~~ Invalid operand\033[0m");

    fprintf(stderr,"\n\n");

    exit(0);

}