#include "../include/tokenizer.h"
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

char *keywords[]= {"int"} ;

char *puntuators[]={"(",")",";","."};
char *operators[]={"=","+","-","*","/"};
char *integers[]={"0","1","2","3","4","5","6","7","8","9"};
char *functions[]={"print","printf"};

int size_keywords =sizeof(keywords)/sizeof(keywords[0]);

int size_puntuators =sizeof(puntuators)/sizeof(puntuators[0]);
int size_operators =sizeof(operators)/sizeof(operators[0]);
int size_integers =sizeof(integers)/sizeof(integers[0]);
int size_functions =sizeof(functions)/sizeof(functions[0]);

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
        return strlen(*(char**)b) - strlen(*(char**)a); // Compare based on length, in reverse order
 // To sort in descending order
}



char*  remove_spaces(char * src_data){

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

void core_tokenizer(char *ptr_src_data){  



    qsort(keywords, size_keywords, sizeof(keywords[0]), compare_desc);
    qsort(functions, size_functions, sizeof(functions[0]), compare_desc);


    // for (int i =0;i<size_functions;i++){
    //     printf("%s\n",functions[i]);
    // }
    int size =0, capacity=20;
    char *temp_data = malloc(sizeof(char)*capacity);
    ptr_src_data= remove_spaces(ptr_src_data);
    bool is_string =false;
    bool is_alpahabet =false;
    int chosen_one =0;
    bool found_keyword =false;             

    printf("%s\n",ptr_src_data);






    for (int i =0; ptr_src_data[i]!='\0';i++){

        temp_data[size++] =ptr_src_data[i];
        temp_data[size]='\0';

        if(size>=capacity){
            capacity *=2;
            temp_data =realloc(temp_data,sizeof(char)*capacity);
        }

      
                  
       


        if(isalpha(ptr_src_data[i])==0&&ptr_src_data[i]!='_'){
        for (int k=0 ; k<size_puntuators;k++){
                    if((ptr_src_data[i]==puntuators[k][0])&&!is_string){
                            printf("PUNTUATOR %s\n",temp_data);
                            size=0;
                    }
                }

        if(ptr_src_data[i]=='"'&&ptr_src_data[i-1]!='\\'){
                is_string =!is_string;
                if(!is_string){
                    printf("STRINGS %s\n",temp_data);
                    size=0;
                }
        }
        
        for (int k =0; k<size_integers;k++){

                if(ptr_src_data[i]==integers[k][0]&&!is_string){
                        printf("INTEGERS %s\n",temp_data);
                        size =0;

                }


        }

        for (int k=0;k<size_operators;k++){
            if(ptr_src_data[i]==operators[k][0]&&!is_string){
           

                        printf("OPERATOR %s\n",temp_data);
                        size=0;
            
                    


            }
        }}
        
                
       

    }


};

