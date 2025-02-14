#include "../include/tokenization.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>


bool is_alphabat=false;
bool is_string=false;
bool is_int =false;

int token_count = 0;  
int token_capacity = 20;    


char *keywords[]= {"int"} ;
char *puntuators[]={"(",")",";","."};
char *operators[]={"=","+","-","*","/"};
char *integers[]={"0","1","2","3","4","5","6","7","8","9"};
char *inbuilt_functions[]={"print","printf"};

int size_keywords =sizeof(keywords)/sizeof(keywords[0]);

int size_puntuators =sizeof(puntuators)/sizeof(puntuators[0]);
int size_operators =sizeof(operators)/sizeof(operators[0]);
int size_integers =sizeof(integers)/sizeof(integers[0]);
int size_inbuilt_functions =sizeof(inbuilt_functions)/sizeof(inbuilt_functions[0]);




typedef enum{
    KEYWORD,
    PUNTUATOR,
    OPERATOR,
    INTEGERS,
    STRINGS,
    INBUILT_FUNCTIONS,
    IDENTIFIERS,
    FAULTY,
    
    


}TokensType; 


typedef struct 
{
    TokensType type;
    char *value;
    int *line;
    
}TokensStored;

int compare_desc(const void *a, const void *b) {
        return strlen(*(char**)b) - strlen(*(char**)a); 
}



char *remove_spaces(char *str) {
    int i = 0, j = 0;
    
    // Iterate through the string
    while (str[i] != '\0') {
        // If the character is not a space, copy it to the front
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    
    // Null-terminate the new string
    str[j] = '\0';
    return str;
}


int tokenize_puntuators(char * ptr_src_data, int i,char* temp_data,bool is_string,int size,TokensStored *tokens){
            for (int k=0 ; k<size_puntuators;k++){
                    if((ptr_src_data[i]==puntuators[k][0])&&!is_string){
                        temp_data =remove_spaces(temp_data);

                            if (token_count == token_capacity) {
                          token_capacity *= 2;  // Double the capacity
                        tokens = (TokensStored *)realloc(tokens, token_capacity * sizeof(TokensStored));}

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=PUNTUATOR;

                        token_count++;
                    // printf("PUNTUATORS %s\n",temp_data);

                            size=0;
                    }
                }

               return size; 
}   

int tokenize_integers(char * ptr_src_data, int i,char* temp_data,bool is_string,int size,TokensStored *tokens){
      
        for (int k =0; k<size_integers;k++){

                if(ptr_src_data[i]==integers[k][0]&&!is_string){
                        temp_data =remove_spaces(temp_data);

                        if (token_count == token_capacity) {
                          token_capacity *= 2;  // Double the capacity
                        tokens = (TokensStored *)realloc(tokens, token_capacity * sizeof(TokensStored));}

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=INTEGERS;

                        token_count++;
                    // printf("INTEGERS %s\n",temp_data);

                        size =0;

                }


        }
        return size;
}

int tokenize_operators(char * ptr_src_data, int i,char* temp_data,bool is_string,int size,TokensStored *tokens){
       for (int k=0;k<size_operators;k++){
            if(ptr_src_data[i]==operators[k][0]&&!is_string){
           
                        temp_data =remove_spaces(temp_data);

                        if (token_count == token_capacity) {
                          token_capacity *= 2;  // Double the capacity
                        tokens = (TokensStored *)realloc(tokens, token_capacity * sizeof(TokensStored));}

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=OPERATOR;

                        token_count++;
                    // printf("OPERATORS %s\n",temp_data);

                        size=0;
            
            }
        }
        return size;
}

int tokenize_keywords(char * ptr_src_data,char* temp_data,int size,TokensStored *tokens){
       if(is_alphabat){
                
                for(int x =0; x<size_keywords;x++){
                    if(strcmp(temp_data,keywords[x])==0){

                        if (token_count == token_capacity) {
                          token_capacity *= 2;  // Double the capacity
                         tokens = (TokensStored *)realloc(tokens, token_capacity * sizeof(TokensStored));}

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=KEYWORD;

                        token_count++;
                    // printf("KEYWORDS %s\n",temp_data);

                        size=0;
                        is_alphabat=false;
                    }
                }}
        return size;
}

int tokenize_functions(char * ptr_src_data,char* temp_data,int size,TokensStored *tokens){
      if(is_alphabat){
                
                for(int x =0; x<size_inbuilt_functions;x++){
                    if(strcmp(temp_data,inbuilt_functions[x])==0){
                        if (token_count == token_capacity) {
                          token_capacity *= 2;  // Double the capacity
                        tokens = (TokensStored *)realloc(tokens, token_capacity * sizeof(TokensStored));}

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=INBUILT_FUNCTIONS;

                        token_count++;
                        size=0;
                    // printf("FUNCTIONS %s\n",temp_data);

                        is_alphabat=false;
                    }
                }}
        return size;
}

int tokenize_identifiers(char * ptr_src_data,char* temp_data,int size,TokensStored *tokens){
     if(is_alphabat){
                        temp_data =remove_spaces(temp_data);
                        if (token_count == token_capacity) {
                          token_capacity *= 2;  // Double the capacity
                        tokens = (TokensStored *)realloc(tokens, token_capacity * sizeof(TokensStored));}

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=IDENTIFIERS;

                        token_count++;
                        size=0;
                    // printf("IDENTIFIERS %s\n",temp_data);

                        is_alphabat=false;
                    
                }
        return size;
}


int tokenize_strings(char * ptr_src_data, int i,char* temp_data,int size,TokensStored *tokens){
    if(ptr_src_data[i]=='"'&&ptr_src_data[i-1]!='\\'){
                is_string =!is_string;
                if(!is_string){
                        temp_data =remove_spaces(temp_data);

                    if (token_count == token_capacity) {
                          token_capacity *= 2;  // Double the capacity
                        tokens = (TokensStored *)realloc(tokens, token_capacity * sizeof(TokensStored));}

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=STRINGS;
                    // printf("STRINGS %s\n",temp_data);
                        token_count++;
                        size=0;
                    size=0;
                }
        }
        return size;

}

int tokenize_faulty_tokens(char * ptr_src_data,char* temp_data,int size,TokensStored *tokens){
     if(size!=0&&!is_string){
                        temp_data =remove_spaces(temp_data);
                        if (token_count == token_capacity) {
                          token_capacity *= 2;  // Double the capacity
                        tokens = (TokensStored *)realloc(tokens, token_capacity * sizeof(TokensStored));}

                         tokens[token_count].value = (char *)malloc(strlen(temp_data) + 1); 
                         strcpy(tokens[token_count].value, temp_data); 
                         tokens[token_count].type=FAULTY;
                    // printf("FAULTY TOKENS %s\n",temp_data);
            
                        token_count++;
                        size=0;
                    
                }
        return size;
}


void print_tokens(TokensStored *tokens){

    for (int i =0;i<token_count;i++)
    {
        printf("type %d , value %s\n",tokens[i].type,tokens[i].value);
    }

}

void core_tokenizer(char *ptr_src_data){  

    qsort(keywords, size_keywords, sizeof(keywords[0]), compare_desc);
    qsort(inbuilt_functions, size_inbuilt_functions, sizeof(inbuilt_functions[0]), compare_desc);
    int size =0, capacity=20;
    TokensStored *tokens =malloc(token_capacity * sizeof(TokensStored));

    char *temp_data = malloc(sizeof(char)*capacity);
    for (int i =0; ptr_src_data[i]!='\0';i++){
    // printf("%s\n",temp_data);

        temp_data[size++] =ptr_src_data[i];
        temp_data[size]='\0';

        if(size>=capacity
        ){
            capacity *=2;
            temp_data =realloc(temp_data,sizeof(char)*capacity);
        }
         if(ptr_src_data[i]==' '){
    // printf("%s\n",temp_data);

            size=0;
            continue;
        }
       
      


               
        if(isalnum(ptr_src_data[i])!=8||ptr_src_data[i]!='_'&&!is_alphabat){
     
        
        size=   tokenize_puntuators(ptr_src_data,i,temp_data,is_string,size,tokens);
        size=   tokenize_operators(ptr_src_data,i,temp_data,is_string,size,tokens);
        size=   tokenize_strings(ptr_src_data,i,temp_data,size,tokens);

       }
         if(isalnum(ptr_src_data[i])!=8&&ptr_src_data[i]!='_'&&!is_alphabat&&!is_string&&ptr_src_data[i]!=' '){
           bool is_faulty = false;
    
            char *oper_punt[size_puntuators + size_operators];

            for (int x = 0; x < size_puntuators; x++) {
              oper_punt[x] = puntuators[x];
         }
    
             for (int x = 0; x < size_operators; x++) {
                 oper_punt[size_puntuators + x] = operators[x];
             }
            
             char ptr_src_data[] = "=";  
            
             for (int x = 0; x < size_puntuators + size_operators; x++) {
                 if (ptr_src_data[0] != oper_punt[x][0]) {
                     is_faulty = true;
                 }
             }
            


        
        
        if(is_faulty==true){
            size =tokenize_faulty_tokens(ptr_src_data,temp_data,size,tokens);

        }
        
        }
        if(isdigit(temp_data[0])==2048){
            size=tokenize_integers(ptr_src_data,i,temp_data,is_string,size,tokens);
            continue;
        }
    
        if(!is_string){
        if(isalnum(ptr_src_data[i])==8||ptr_src_data[i]=='_'){        
            if(isalnum(ptr_src_data[i+1])!=8&&ptr_src_data[i+1]!='_'){
                    is_alphabat=true;
     }

            }}
             if(is_alphabat){
           size =tokenize_keywords(ptr_src_data,temp_data,size,tokens);
           size =tokenize_functions(ptr_src_data,temp_data,size,tokens);
           size =tokenize_identifiers(ptr_src_data,temp_data,size,tokens);
 }



    }   


    
    print_tokens(tokens);
    
};

