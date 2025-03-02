/*************************************************
 * File : tokenization.c
 * Purpose : Convert the source data into individual tokens.
 * Author : Xscientio
 * Date Created : 15-Feb-2025
 * Description : This is where the tokenization is handled all the work
 *               regarding tokenization is handled in this only file.
 ************************************************/

// Built-in libraries
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

// Include files
#include "../include/tokenization/tokenization.h"
#include "../include/token_value/token_value.h"
#include "../include/debug/debug.h"
#include "../include/parsing/parsing.h"


// Global variable 
bool is_alnum=false;
bool is_string=false;

int token_count = 0;  
int token_capacity = 20;    
int line_no =1; 
int string_line_no =0;
int token_reference=0;
int token_column_reference =1;






/***************************************************************
 * Function: compare_length
 * Purpose:  Compare length for qsort
 * Parameters: 
 *    void *a : A length parameter.
 *    void *b : A length parameter.
 * Return Value:
 *    int: Difference between b & a .
 * Description: Thsi function just in simple terms compare value for qsort
 ***************************************************************/
int compare_length(const void *a, const void *b) {
        return strlen(*(char**)b) - strlen(*(char**)a); 
}

/***************************************************************
 * Function: remove_spaces
 * Parameters: 
 *    char *str : It's the data from which spaces are to removed.
 * Return Value:
 *    char * : Without spaces data.
 ***************************************************************/
char *remove_spaces(char *str) {
    int i = 0, j = 0;
    
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
    return str;
}

/***************************************************************
 * Function: tokenize_puntuators
 * Parameters: 
 *    char *ptr_src_data : Is used to check if the selected character is the puntuator.
 *    int i : This is the the position of current character.
 *    char *temp_dara : Is used to store the data as value in TokensStored Struct.
 *    bool is_string : Is for purpose of not interfering with tokenize_strings.
 *    int size : Is the size of temp_data and is used to reset the temP_data for further tokenization
 *    TokensStored *tokens: Where the tokens will be stored.

 * Return Value: 
 *    int : Return size to reset the values.
 ***************************************************************/
TokensSubType puntuators_sub_type(char * temp_data){
    if(strcmp(temp_data,"(")==0){
        return LEFT_PARENTHESIS;
    }else if(strcmp(temp_data,")")==0){
        return RIGHT_PARENTHESIS;

    }else if(strcmp(temp_data,"{")==0){
        return LEFT_CURLY_BRACKETS;

    }
    else if(strcmp(temp_data,"}")==0){
        return RIGHT_CURLY_BRACKETS;

    }else if(strcmp(temp_data,"[")==0){
        return LEFT_SQUARE_BRACKETS;

    }else if(strcmp(temp_data,"]")==0){
        return RIGHT_SQUARE_BRACKETS;

    }else if(strcmp(temp_data,".")==0){
        return DOT;
    }else if(strcmp(temp_data,";")==0){
        return COLON;
    }else if(strcmp(temp_data,",")==0){
        return COMMA;
    }
}
int tokenize_puntuators(char * ptr_src_data, int i,char* temp_data,bool is_string,int size,TokensStored *tokens){
            for (int k=0 ; k<size_puntuators;k++){
                    if((ptr_src_data[i]==puntuators[k][0])&&!is_string){
                        temp_data =remove_spaces(temp_data);

                           

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=PUNTUATOR;
                         tokens[token_count].line=line_no;
                         tokens[token_count].subtype=puntuators_sub_type(temp_data);
                         tokens[token_count].length=strlen(temp_data);
                         tokens[token_count].start_point=token_reference-strlen(temp_data);
                         tokens[token_count].end_point=token_reference-1;
                         tokens[token_count].column=token_column_reference;



                        token_count++;
                        token_column_reference++;
                    // printf("PUNTUATORS %s\n",temp_data);

                            size=0;
                    }
                }

               return size; 
}   
/***************************************************************
 * Function: tokenize_integers
 * Parameters: 
 *    char *ptr_src_data : Is used to check if the selected character is the integers.
 *    int i : This is the the position of current character.
 *    char *temp_dara : Is used to store the data as value in TokensStored Struct.
 *    bool is_string : Is for purpose of not interfering with tokenize_strings.
 *    int size : Is the size of temp_data and is used to reset the temP_data for further tokenization
 *    TokensStored *tokens: Where the tokens will be stored.
 * Return Value: 
 *    int : Return size to reset the values.
 ***************************************************************/

int tokenize_integers(char * ptr_src_data, int i,char* temp_data,bool is_string,int size,TokensStored *tokens){
      
        for (int k =0; k<size_integers;k++){

                if(ptr_src_data[i]==integers[k][0]&&!is_string){
                        temp_data =remove_spaces(temp_data);

                        
                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=INTEGER;
                         tokens[token_count].line=line_no;
                         tokens[token_count].subtype=USR_INTEGER;
                         tokens[token_count].length=strlen(temp_data);
                         tokens[token_count].start_point=token_reference-strlen(temp_data);
                         tokens[token_count].end_point=token_reference-1;
                         tokens[token_count].column=token_column_reference;



                        token_count++;
                        token_column_reference++;

                    // printf("INTEGERS %s\n",temp_data);

                        size =0;

                }


        }
        return size;
}
/***************************************************************
 * Function: tokenize_operators
 * Parameters: 
 *    char *ptr_src_data : Is used to check if the selected character is the operators.
 *    int i : This is the the position of current character.
 *    char *temp_dara : Is used to store the data as value in TokensStored Struct.
 *    bool is_string : Is for purpose of not interfering with tokenize_strings.
 *    int size : Is the size of temp_data and is used to reset the temP_data for further tokenization
 *    TokensStored *tokens: Where the tokens will be stored.
 * Return Value: 
 *    int : Return size to reset the values.
 ***************************************************************/
TokensSubType operators_sub_type(char * temp_data){
    if(strcmp(temp_data,"=")==0){
        return EQUAL;
    }else if(strcmp(temp_data,"+")==0){
        return PLUS;

    }else if(strcmp(temp_data,"-")==0){
        return MINUS;

    }
    else if(strcmp(temp_data,"/")==0){
        return FORWARD_SLASH;

    }else if(strcmp(temp_data,"*")==0){
        return ASTERISK;

    }
}
int tokenize_operators(char * ptr_src_data, int i,char* temp_data,bool is_string,int size,TokensStored *tokens){
       for (int k=0;k<size_operators;k++){
            if(ptr_src_data[i]==operators[k][0]&&!is_string){
           
                        temp_data =remove_spaces(temp_data);

                       
                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=OPERATOR;
                         tokens[token_count].line=line_no;
                         tokens[token_count].subtype=operators_sub_type(temp_data);
                         tokens[token_count].length=strlen(temp_data);
                         tokens[token_count].start_point=token_reference-strlen(temp_data);
                         tokens[token_count].end_point=token_reference-1;
                         tokens[token_count].column=token_column_reference;



                        token_count++;
                        token_column_reference++;

                    // printf("OPERATORS %s\n",temp_data);

                        size=0;
            
            }
        }
        return size;
}
/***************************************************************
 * Function: tokenize_keywords
 * Parameters: 
 *    char *temp_dara : Is used to store the data as value in TokensStored Struct & for matching purpose.
 *    bool is_string : Is for purpose of not interfering with tokenize_strings.
 *    int size : Is the size of temp_data and is used to reset the temP_data for further tokenization
 *    TokensStored *tokens: Where the tokens will be stored.
 * Return Value: 
 *    int : Return size to reset the values.
 ***************************************************************/
TokensSubType keywords_sub_type(char * temp_data){
    if(strcmp(temp_data,"int")==0){
        return INT;
    }else if(strcmp(temp_data,"str")==0){
        return STR;

    }
}
int tokenize_keywords(char* temp_data,int size,TokensStored *tokens){
       if(is_alnum){
                
                for(int x =0; x<size_keywords;x++){
                    if(strcmp(temp_data,keywords[x])==0){

                      

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=KEYWORD;
                         tokens[token_count].line=line_no;
                         tokens[token_count].subtype=keywords_sub_type(temp_data);
                         tokens[token_count].length=strlen(temp_data);
                         tokens[token_count].start_point=token_reference-strlen(temp_data);
                         tokens[token_count].end_point=token_reference-1;
                         tokens[token_count].column=token_column_reference;



                        token_count++;
                        token_column_reference++;

                    // printf("KEYWORDS %s\n",temp_data);

                        size=0;
                        is_alnum=false;
                    }
                }}
        return size;
}
/***************************************************************
 * Function: tokenize_functions
 * Parameters: 
 *    char *temp_dara : Is used to store the data as value in TokensStored Struct & for matching purpose.
 *    bool is_string : Is for purpose of not interfering with tokenize_strings.
 *    int size : Is the size of temp_data and is used to reset the temP_data for further tokenization
 *    TokensStored *tokens: Where the tokens will be stored.
 * Return Value: 
 *    int : Return size to reset the values.
 ***************************************************************/
TokensSubType inbuilt_functions_sub_type(char * temp_data){
    if(strcmp(temp_data,"output")==0){
        return OUTPUT;
    }else if(strcmp(temp_data,"input")==0){
        return INPUT;

    }
}
int tokenize_functions(char* temp_data,int size,TokensStored *tokens){
      if(is_alnum){
                
                for(int x =0; x<size_inbuilt_functions;x++){
                    if(strcmp(temp_data,inbuilt_functions[x])==0){
                        

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=INBUILT_FUNCTION;
                         tokens[token_count].line=line_no;
                         tokens[token_count].subtype=inbuilt_functions_sub_type(temp_data);
                         tokens[token_count].length=strlen(temp_data);
                         tokens[token_count].start_point=token_reference-strlen(temp_data);
                         tokens[token_count].end_point=token_reference-1;
                         tokens[token_count].column=token_column_reference;

                        

                        token_count++;
                        token_column_reference++;

                        size=0;
                    // printf("FUNCTIONS %s\n",temp_data);

                        is_alnum=false;
                    }
                }}
        return size;
}
/***************************************************************
 * Function: tokenize_identifiers
 * Parameters: 
 *    char *temp_dara : Is used to store the data as value in TokensStored Struct & for matching purpose.
 *    bool is_string : Is for purpose of not interfering with tokenize_strings.
 *    int size : Is the size of temp_data and is used to reset the temP_data for further tokenization
 *    TokensStored *tokens: Where the tokens will be stored.
 * Return Value: 
 *    int : Return size to reset the values.
 ***************************************************************/
int tokenize_identifiers(char* temp_data,int size,TokensStored *tokens){
     if(is_alnum){
                        temp_data =remove_spaces(temp_data);
                      

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=IDENTIFIER;
                         tokens[token_count].line=line_no;
                         tokens[token_count].subtype=USR_IDENTIFIER;
                         tokens[token_count].length=strlen(temp_data);
                         tokens[token_count].start_point=token_reference-strlen(temp_data);
                         tokens[token_count].end_point=token_reference-1;
                         tokens[token_count].column=token_column_reference;



                        token_count++;
                        token_column_reference++;

                        size=0;
                    // printf("IDENTIFIERS %s\n",temp_data);

                        is_alnum=false;
                    
                }
        return size;
}

/***************************************************************
 * Function: tokenize_strings
 * Parameters: 
 *    char *ptr_src_data : Is used to check if the selected character is the integers.
 *    int i : This is the the position of current character.
 *    char *temp_dara : Is used to store the data as value in TokensStored Struct.
 *    bool is_string : Is for purpose of not interfering with tokenize_strings.
 *    int size : Is the size of temp_data and is used to reset the temP_data for further tokenization
 *    TokensStored *tokens: Where the tokens will be stored.
 * Return Value: 
 *    int : Return size to reset the values.
 ***************************************************************/
int tokenize_strings(char * ptr_src_data, int i,char* temp_data,int size,TokensStored *tokens){
    if(ptr_src_data[i]=='"'&&ptr_src_data[i-1]!='\\'){
                is_string =!is_string;
                if(!is_string){
                        temp_data =remove_spaces(temp_data);

                    

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=STRING;
                         tokens[token_count].line=string_line_no;
                         tokens[token_count].subtype=USR_STRING;
                         tokens[token_count].length=strlen(temp_data);
                         tokens[token_count].start_point=token_reference-strlen(temp_data);
                         tokens[token_count].end_point=token_reference-1;
                         tokens[token_count].column=token_column_reference;


                    // printf("STRINGS %s\n",temp_data);
                        token_count++;
                        token_column_reference++;

                        size=0;
                    size=0;
                }else{
                    string_line_no =line_no;
                }
        }
        return size;

}
/***************************************************************
 * Function: tokenize_integers
 * Parameters: 
 *    char *temp_dara : Is used to store the data as value in TokensStored Struct.
 *    bool is_string : Is for purpose of not interfering with tokenize_strings.
 *    int size : Is the size of temp_data and is used to reset the temP_data for further tokenization
 *    TokensStored *tokens: Where the tokens will be stored.
 * Return Value: 
 *    int : Return size to reset the values.
 * Description: The purpose is to detect other non-alphnumeric or unlcosed strings.
 ***************************************************************/
int tokenize_faulty_tokens(char* temp_data,int size,TokensStored *tokens){
     if(size!=0&&!is_string){
                        temp_data =remove_spaces(temp_data);
                      

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=FAULTY;
                         tokens[token_count].subtype=USR_FAULT;
                         tokens[token_count].length=strlen(temp_data);
                         tokens[token_count].start_point=token_reference-strlen(temp_data);
                         tokens[token_count].end_point=token_reference-1;
                         tokens[token_count].column=token_column_reference;



                    // printf("FAULTY TOKENS %s\n",temp_data);
            
                        token_count++;
                        token_column_reference++;

                        size=0;
                    
                }
        return size;
}



/***************************************************************
 * Function: core_tokenizer
 * Parameters: 
 *    char *ptr_src_data: .It's the source data
 * Return Value: null
 * Description: This function handles all the core functions of tokenization.
 ***************************************************************/
void core_tokenizer(char *ptr_src_data){  
    

    // Here sorting is done so that keywords or inbuilt functions with identical spelling at start doesn't
    // interfere with actual ones for e.g print & printf if print is before the printf it might detect print
    // and actual function which was suppposed to be detected is missed. 
    qsort(keywords, size_keywords, sizeof(keywords[0]), compare_length); 
    qsort(inbuilt_functions, size_inbuilt_functions, sizeof(inbuilt_functions[0]), compare_length);


    int size =0, capacity=20; // For temp_data dynamic data allocation
    TokensStored *tokens =malloc(token_capacity * sizeof(TokensStored)); // Allocating space for tokens to be stored.

    char *temp_data = malloc(sizeof(char)*capacity); // This is where the tokens are temporally stored for the extraction purposes.
    
    // Looping the data
    for (int i =0; ptr_src_data[i]!='\0';i++){
        // printf("%s\n",temp_data);
        token_reference=i+2;
        if (token_count == token_capacity) {
        token_capacity *= 2;  // Double the capacity
        tokens = (TokensStored *)realloc(tokens, token_capacity * sizeof(TokensStored));}
        temp_data[size++] =ptr_src_data[i]; // Adding data in temp_data
        temp_data[size]='\0';


        // Checks if capacity is not enough for tokens to be stored on temp_data
        if(size>=capacity){ 
            capacity *=2;
            temp_data =realloc(temp_data,sizeof(char)*capacity);
        }


        // Omits spaces
         if(ptr_src_data[i]==' '&&!is_string){
            size=0;
            continue;
        }

        // Gets the line reference for tokens
        if(ptr_src_data[i]=='\n'){
            if(!is_string){
                size=0;
                token_column_reference=1;
            line_no++;
            continue;
            }if(is_string){
                token_column_reference=1;
                
                line_no++;
            }
           
        }

      // Checks if there was a proccess of detecting a string but user forget to close them so a faulty token is created
      if(ptr_src_data[i]!='"'&&is_string&&ptr_src_data[i+1]=='\0'){
        is_string=false;
        size =tokenize_faulty_tokens(temp_data,size,tokens);
        continue;
      }


      // Allows all non-alphanumeric and non-underscore values    
      if(isalnum(ptr_src_data[i])!=8||ptr_src_data[i]!='_'&&!is_alnum){
     
        // Passing the arguments to the tokenization functions
        size=   tokenize_puntuators(ptr_src_data,i,temp_data,is_string,size,tokens);
        size=   tokenize_operators(ptr_src_data,i,temp_data,is_string,size,tokens);
        size=   tokenize_strings(ptr_src_data,i,temp_data,size,tokens);

       }

         // CHecks for faulty tokens   
         if(isalnum(ptr_src_data[i])!=8&&ptr_src_data[i]!='_'&&!is_alnum&&!is_string&&ptr_src_data[i]!=' '){
           bool is_faulty = false; 
    
            char *oper_punt[size_puntuators + size_operators]; // New list of puntuator + operators

            for (int x = 0; x < size_puntuators; x++) {
              oper_punt[x] = puntuators[x];      // Add all puntutators in oper_punt
         }
    
             for (int x = 0; x < size_operators; x++) {
                 oper_punt[size_puntuators + x] = operators[x]; // Add all operators  in oper_punt
             }
            
             char ptr_src_data[] = "=";  
            
             for (int x = 0; x < size_puntuators + size_operators; x++) {
                 if (ptr_src_data[0] != oper_punt[x][0]) {           // Check if tokens exist in oper_punt 
                     is_faulty = true;                 // else is_faulty sets to true
                 }
             }
        
        // If is_faulty is true it sents for tokenization
        if(is_faulty==true){
            size =tokenize_faulty_tokens(temp_data,size,tokens);

          } 
        }
        // If first character in temp_data is digit then is sent for tokenization as integers
        if(isdigit(temp_data[0])==2048){
            size=tokenize_integers(ptr_src_data,i,temp_data,is_string,size,tokens);
            continue;
        }

        // Further tokenization for other remaining ones
        if(!is_string){
        if(isalnum(ptr_src_data[i])==8||ptr_src_data[i]=='_'){  
            // It detects if next characters are not alphanumeric or underscore hence setting the is_alnum to true
            if(isalnum(ptr_src_data[i+1])!=8&&ptr_src_data[i+1]!='_'){
                    is_alnum=true;
     }

            }}
        // if true call tokenization function to tokenize
        if(is_alnum){
           size =tokenize_keywords(temp_data,size,tokens);
           size =tokenize_functions(temp_data,size,tokens);
           size =tokenize_identifiers(temp_data,size,tokens);
 }

    }   
    
    // Debugging purposes
    // print_tokens(tokens,token_count);

    //Sent for parsing
    free(temp_data);
    core_parser(tokens,token_count);
    
};

