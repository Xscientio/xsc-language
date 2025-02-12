#include "../include/tokenization.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>


bool is_alphabat=false;
bool is_string=false;

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

typedef struct 
{
    char *type;
    char *value;
    
}TokensStored;


typedef enum{
    KEYWORD,
    PUNTUATOR,
    OPERATOR

}TokensType; 





int compare_desc(const void *a, const void *b) {
        return strlen(*(char**)b) - strlen(*(char**)a); 
}

char*  remove_newline(char * src_data){

    bool is_string=false;
    int size =0,capacity=20;
    char* temp_data =malloc(sizeof(char)*capacity);


    for (int i =0 ;src_data[i]!='\0';i++){
        if(size>=capacity){
            capacity *=2;
            temp_data =realloc(temp_data,sizeof(char)*capacity);
        }


        if(src_data[i]=='"'&&src_data[i-1]!='\\'){
            is_string =!is_string;
            temp_data[size++] =src_data[i];


        }else if(src_data[i]=='\n'&& !is_string){

        }else{
            temp_data[size++] =src_data[i];

        }

    }   
    return temp_data;

    

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

int tokenize_puntuators(char * ptr_src_data, int i,char* temp_data,bool is_string,int size){
            for (int k=0 ; k<size_puntuators;k++){
                    if((ptr_src_data[i]==puntuators[k][0])&&!is_string){
                        temp_data =remove_spaces(temp_data);

                            printf("PUNTUATOR %s\n",temp_data);
                            size=0;
                    }
                }

               return size; 
}   

int tokenize_integers(char * ptr_src_data, int i,char* temp_data,bool is_string,int size){
      
        for (int k =0; k<size_integers;k++){

                if(ptr_src_data[i]==integers[k][0]&&!is_string){
                        temp_data =remove_spaces(temp_data);

                        printf("INTEGERS %s\n",temp_data);
                        size =0;

                }


        }
        return size;
}

int tokenize_operators(char * ptr_src_data, int i,char* temp_data,bool is_string,int size){
       for (int k=0;k<size_operators;k++){
            if(ptr_src_data[i]==operators[k][0]&&!is_string){
           
                        temp_data =remove_spaces(temp_data);

                        printf("OPERATOR %s\n",temp_data);
                        size=0;
            
                    


            }
        }
        return size;
}

int tokenize_keywords(char * ptr_src_data,char* temp_data,int size){
       if(is_alphabat){
                
                for(int x =0; x<size_keywords;x++){
                    if(strcmp(temp_data,keywords[x])==0){
                        printf("KEYWORDS %s\n",temp_data);
                        size=0;
                        is_alphabat=false;
                    }
                }}
        return size;
}

int tokenize_functions(char * ptr_src_data,char* temp_data,int size){
      if(is_alphabat){
                
                for(int x =0; x<size_inbuilt_functions;x++){
                    if(strcmp(temp_data,inbuilt_functions[x])==0){
                        printf("FUNCTIONS %s\n",temp_data);
                        size=0;
                        is_alphabat=false;
                    }
                }}
        return size;
}

int tokenize_identifiers(char * ptr_src_data,char* temp_data,int size){
     if(is_alphabat){
                        temp_data =remove_spaces(temp_data);
                        printf("IDENTIFIERS %s\n",temp_data);
                        size=0;
                        is_alphabat=false;
                    
                }
        return size;
}

void core_tokenizer(char *ptr_src_data){  

    qsort(keywords, size_keywords, sizeof(keywords[0]), compare_desc);
    qsort(inbuilt_functions, size_inbuilt_functions, sizeof(inbuilt_functions[0]), compare_desc);

    int size =0, capacity=20;
    char *temp_data = malloc(sizeof(char)*capacity);
    ptr_src_data= remove_newline(ptr_src_data);
    printf("%s\n",ptr_src_data);

    for (int i =0; ptr_src_data[i]!='\0';i++){

        temp_data[size++] =ptr_src_data[i];
        temp_data[size]='\0';

        if(size>=capacity){
            capacity *=2;
            temp_data =realloc(temp_data,sizeof(char)*capacity);
        }
      
               
        if(isalpha(ptr_src_data[i])!=1024||ptr_src_data[i]!='_'){
     

        size=   tokenize_puntuators(ptr_src_data,i,temp_data,is_string,size);
        size=   tokenize_integers(ptr_src_data,i,temp_data,is_string,size);
        size=   tokenize_operators(ptr_src_data,i,temp_data,is_string,size);

        if(ptr_src_data[i]=='"'&&ptr_src_data[i-1]!='\\'){
                is_string =!is_string;
                if(!is_string){
                        temp_data =remove_spaces(temp_data);

                    printf("STRINGS %s\n",temp_data);
                    size=0;
                }
        }
       }
        if(isalpha(ptr_src_data[i])==1024||ptr_src_data[i]=='_'){        
            if(isalpha(ptr_src_data[i+1])!=1024&&ptr_src_data[i+1]!='_'){
                is_alphabat=true;
            }
           size =tokenize_keywords(ptr_src_data,temp_data,size);
           size =tokenize_functions(ptr_src_data,temp_data,size);
           size =tokenize_identifiers(ptr_src_data,temp_data,size);
            }}
    
                
    
};

