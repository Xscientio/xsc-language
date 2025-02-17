/*************************************************
 * File : read_file.c
 * Purpose : Read the data from source file.
 * Author : Xscientio
 * Date Created : 15-Feb-2025
 * Description : This is where the reading of source file and removing of comment happens.
 ************************************************/

// Inbuilt libraries
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdbool.h>

// Include files
#include "../include/read_file/read_file.h"


/***************************************************************
 * Function: remove_comments
 * Purpose:  Removes comments from the source data
 * Parameters: 
 *    char *ptr_src_data = Source data
 * Return Value:
 *    char *: The source data without any comment.
 ***************************************************************/
char* remove_comments(char * ptr_src_data){

        // Variables
        bool is_comment =false;
        bool is_multi_comment =false;
        bool is_string =false;
        int j=0,size=0,capacity=20;
        char * temp_data =malloc(sizeof(char)*capacity); // temporary storage

        for (int i =0 ; ptr_src_data[i]!='\0';i++){

            // Checks capacity
            if(size>=capacity){
                capacity *=2;
                temp_data =realloc(temp_data,sizeof(char)*capacity);
            }

            // Checks for strings if for first instance set is_string to true and otherwise to false;
            if(ptr_src_data[i] =='"'){
                is_string=!is_string;
            }
            // If single line comment is detected.
            if(!is_string&&ptr_src_data[i]=='/'&&ptr_src_data[i+1]=='/'&&!is_multi_comment){
                is_comment =true;

            }
            
            // If multi-line comment is detected.
            if(!is_string&&ptr_src_data[i]=='/'&&ptr_src_data[i+1]=='*'&&!is_comment&&!is_multi_comment){
                i=i+2;
                is_multi_comment =true;

            }
            // If multi-line finisher is detected.
            if(!is_string&&ptr_src_data[i]=='*'&&ptr_src_data[i+1]=='/'&&!is_comment&&is_multi_comment){
                is_multi_comment=false;
                i=i+2;

            }
            // If single-line finisher is detected.
            if(is_comment&&ptr_src_data[i]=='\n'&&!is_multi_comment){
                is_comment=false;
            }

            // If isn't a comment stores in temp_data
            if(!is_comment&&!is_multi_comment){
               temp_data [size++]=ptr_src_data[i]; 
            }
            temp_data[size]='\0';

            


        }
return temp_data;
}
/***************************************************************
 * Function: core_read_file
 * Purpose:  Read source file
 * Parameters: 
 *    char file_path[] = Path to the source file
 * Return Value:
 *    char *: The source data.
 * Description: Handle all the core function of reading file and un-commenting a file
 ***************************************************************/
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
