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


// Global variable 
bool is_alnum=false;
bool is_string=false;

int token_count = 0;  
int token_capacity = 20;    
int line_no =1; 
int string_line_no =0;




// Types of tokens
char *list_token_type[8] ={"KEYWORD","PUNTUTATOR","OPERATOR","INTEGERS","STRINGS","INBUILT_FUNCTIONS","IDENTIFIERS","FAULTY"};



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
int tokenize_puntuators(char * ptr_src_data, int i,char* temp_data,bool is_string,int size,TokensStored *tokens){
            for (int k=0 ; k<size_puntuators;k++){
                    if((ptr_src_data[i]==puntuators[k][0])&&!is_string){
                        temp_data =remove_spaces(temp_data);

                           

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=PUNTUATOR;
                         tokens[token_count].line=line_no;
                         tokens[token_count].length=strlen(temp_data);


                        token_count++;
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
                         tokens[token_count].type=INTEGERS;
                         tokens[token_count].line=line_no;
                         tokens[token_count].length=strlen(temp_data);


                        token_count++;
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
int tokenize_operators(char * ptr_src_data, int i,char* temp_data,bool is_string,int size,TokensStored *tokens){
       for (int k=0;k<size_operators;k++){
            if(ptr_src_data[i]==operators[k][0]&&!is_string){
           
                        temp_data =remove_spaces(temp_data);

                       
                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=OPERATOR;
                         tokens[token_count].line=line_no;
                         tokens[token_count].length=strlen(temp_data);


                        token_count++;
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
int tokenize_keywords(char* temp_data,int size,TokensStored *tokens){
       if(is_alnum){
                
                for(int x =0; x<size_keywords;x++){
                    if(strcmp(temp_data,keywords[x])==0){

                      

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=KEYWORD;
                         tokens[token_count].line=line_no;
                         tokens[token_count].length=strlen(temp_data);


                        token_count++;
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
int tokenize_functions(char* temp_data,int size,TokensStored *tokens){
      if(is_alnum){
                
                for(int x =0; x<size_inbuilt_functions;x++){
                    if(strcmp(temp_data,inbuilt_functions[x])==0){
                        

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=INBUILT_FUNCTIONS;
                         tokens[token_count].line=line_no;
                         tokens[token_count].length=strlen(temp_data);
                        

                        token_count++;
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
                         tokens[token_count].type=IDENTIFIERS;
                         tokens[token_count].line=line_no;
                         tokens[token_count].length=strlen(temp_data);


                        token_count++;
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
                         tokens[token_count].type=STRINGS;
                         tokens[token_count].line=string_line_no;
                         tokens[token_count].length=strlen(temp_data);

                    // printf("STRINGS %s\n",temp_data);
                        token_count++;
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
                         tokens[token_count].line=line_no;
                         tokens[token_count].length=strlen(temp_data);


                    // printf("FAULTY TOKENS %s\n",temp_data);
            
                        token_count++;
                        size=0;
                    
                }
        return size;
}

/***************************************************************
 * Function: print_tokens
 * Parameters: 
 *    TokensStored *tokens: Where the tokens will be stored.
 * Return Value: null
 * Description: Just for debugging.
 ***************************************************************/
void print_tokens(TokensStored *tokens){

    for (int i =0;i<token_count;i++)
    {
        printf("Token type:\033[1;33m%s\033[0m\nToken line:\033[1;36m%d\033[0m\nToken Length:\033[1;32m%d\033[0m\nToken value: \033[1;35m%s\033[0m\n---------------------------------\n",list_token_type[tokens[i].type],tokens[i].line,tokens[i].length,tokens[i].value);
    }

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
            line_no++;
            continue;
            }if(is_string){
                
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
    print_tokens(tokens);
    
};

