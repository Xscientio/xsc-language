/*************************************************
 * File : main.c
 * Purpose : Handles the core task of compiling.
 * Author : Xscientio
 * Date Created : 15-Feb-2025
 * Description : This is the start of compiling process all the funtctions 
 *               with the keyword "core" in it are handled in the this file
 *               it has only one func "main".
 ************************************************/

// Built-in libraries
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Include files
#include "include/tokenization/tokenization.h"
#include "include/read_file/read_file.h"

 

// This is the starting point this where the journey began
void main(int argc, char *argv[]){


for (int i =0; i<argc ; i++){

    printf("Argument %d: %s\n", i, argv[i]);

}

clock_t start_time = clock();

char * ptr_src_data =core_read_file("example/main.xsc");  // Reading the data from the source file


core_tokenizer(ptr_src_data); // Passing extracted source data for tokenization as a pointer
free(ptr_src_data);

  clock_t end_time = clock();

    // Calculate the time taken
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Print the result
    printf("Time taken: %f seconds\n", time_taken);
}








