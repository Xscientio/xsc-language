#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>
#include "../include/read_file.h"

char* remove_comments(char * ptr_src_data){
        bool is_comment =false;
        bool is_string =false;
        int j=0,size=0,capacity=20;
        char * temp_data =malloc(sizeof(char)*capacity);

        for (int i =0 ; ptr_src_data[i]!='\0';i++){
            if(size>=capacity){
                capacity *=2;
                temp_data =realloc(temp_data,sizeof(char)*capacity);
            }

            if(ptr_src_data[i] =='"'){
                is_string=!is_string;
            }

            if(!is_string&&ptr_src_data[i]=='/'&&ptr_src_data[i+1]=='/'){
                is_comment =true;
            }

            if(is_comment&&ptr_src_data[i]=='\n'){
                is_comment=false;
            }

            if(!is_comment){
               temp_data [size++]=ptr_src_data[i];
               
            }
            temp_data[size]='\0';

            


        }
return temp_data;
}

char *  core_read_file(char file_path[]){
    
    FILE *ptr_file = fopen(file_path, "r");

    if (ptr_file == NULL) {
        perror("Error opening file");
        return ""; 
    }

    char ch;
    int size =0, capacity =20;
    char * temp_data =malloc (sizeof(char)*capacity);
    while ((ch = fgetc(ptr_file)) != EOF) {
        temp_data[size++]=ch;


        if(size>=capacity){
            capacity*=2;
            temp_data = realloc(temp_data,sizeof(char)*capacity);

        }
    }

    fclose(ptr_file);

    temp_data = remove_comments(temp_data);
    return temp_data;



    
}
