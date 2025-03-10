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
    bool parenthesis_detected =false;
    if(tokens[i+1].type== IDENTIFIER){
        i++;
        if(tokens[i+1].subtype ==EQUAL ){
            i++;
            if(tokens[i+1].type==STRING||tokens[i+1].type==IDENTIFIER||tokens[i+1].type==INTEGER){
                for (int k=i;k<token_count;k++){
                if(tokens[i+2].type==FAULTY){
                         raw_syntax_error_form(i+1,"Faulty token after");

                }
                if(tokens[i+1].type==STRING ){
                     i++;
                    if(tokens[i+1].type==STRING || tokens[i+1].type ==OPERATOR ||tokens[i+1].type ==PUNTUATOR ){

                         if(tokens[i+1].subtype==EQUAL){
                         raw_syntax_error_form(i,"Invalid operator after");
                   
                    } if (parenthesis_detected){
                         if(tokens[i+1].subtype!=COMMA &&tokens[i+1].subtype!= RIGHT_PARENTHESIS){
                          raw_syntax_error_form(i,"Expected a ',' or ')' after");

                        }
                        
                    } 
                    }else if(tokens[i+1].subtype==EQUAL &&tokens[i+1].subtype==DOT){
                         raw_syntax_error_form(i,"Invalid operator after");

                        
                    }else{
                       
                    
                         raw_syntax_error_form(i,"Expected ';' or ',' after");
                        
                    }
                }else if(tokens[i+1].type==INTEGER){
                    i++;
                    if(tokens[i+1].type==INTEGER || tokens[i+1].type ==OPERATOR ){

                         if(tokens[i+1].subtype==EQUAL){
                         raw_syntax_error_form(i,"Invalid operator after");
               
                    }
                    }else if(parenthesis_detected&&tokens[i+1].subtype!=COMMA &&tokens[i+1].subtype!= RIGHT_PARENTHESIS){
                         raw_syntax_error_form(i,"Expected a ',' or ')' after");

                    }else{
                        
                         raw_syntax_error_form(i,"Expected ';' or ',' after");

                    
                    }
                }
                else if(tokens[i+1].subtype==COLON){
                    i++;

                    if(parenthesis_detected ){
                         raw_syntax_error_form(i,"Expected closing parenthesis before");

                    }else{
                       return i;

                    }
                }  else if(tokens[i+1].subtype==COMMA){

                    if(parenthesis_detected&& tokens[i+1].type!=INTEGER&& tokens[i+1].type!=STRING&& tokens[i+1].type!=IDENTIFIER&&tokens[i+1].subtype!=COMMA){
                         raw_syntax_error_form(i,"Expected an argument after");

                    }else if(tokens[i+1].type==INTEGER|| tokens[i+1].type==STRING||  tokens[i+1].type==IDENTIFIER){ 
                      i++;
                       

                    }else if (!parenthesis_detected){
                         raw_syntax_error_form(i,"Comma not allowed after");

                    }else if(parenthesis_detected&&tokens[i].subtype==COMMA){
                         raw_syntax_error_form(i,"Expected an argument or ')' after");

                    }
                }else if(tokens[i+1].subtype==DOT){

                    i++;
                }else if(tokens[i+1].type==OPERATOR){

                     i++;
                    if(tokens[i+1].type!=INTEGER && tokens[i+1].type!=IDENTIFIER&&tokens[i+1].type!=STRING){
                         raw_syntax_error_form(i,"Expected an operand after");
                        
                    }else if(parenthesis_detected&&tokens[i+1].type==OPERATOR){
                         raw_syntax_error_form(i,"Operators not allowed after");

                        }

                } else if(tokens[i+1].type==IDENTIFIER){
                        i++;
                       
                }else if(tokens[i+1].subtype==LEFT_PARENTHESIS  ){
                        i++;
                        parenthesis_detected =true;
                }else if(tokens[i+1].subtype==RIGHT_PARENTHESIS){
                        if(!parenthesis_detected){
                         raw_syntax_error_form(i,"Error no opening parenthesis before");

                        }
                        i++;
                        parenthesis_detected=false;

                }else if(tokens[i+1].type==PUNTUATOR){
                    if(tokens[i+1].subtype!=RIGHT_PARENTHESIS&&tokens[i+1].subtype!=LEFT_PARENTHESIS&&tokens[i+1].subtype!=DOT&&tokens[i+1].subtype!=COMMA&&tokens[i+1].subtype!=COLON){
                         raw_syntax_error_form(i,"Invalid puntuator after");

                }
                }

                }
          }
            else{
                 if(tokens[i+1].type==FAULTY){
                         raw_syntax_error_form(i,"Faulty token after");

                }
            raw_syntax_error_form(i,"Missing or invalid expression after");

            }
            

        }else if(tokens[i+1].subtype ==COLON){
            i++;

        }
        else{
             if(tokens[i+1].type==FAULTY){
                         raw_syntax_error_form(i,"Faulty token after");

                }
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