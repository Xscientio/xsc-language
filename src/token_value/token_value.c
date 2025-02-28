#include "../include/token_value/token_value.h"
#include <stdlib.h>

//Sub-Token
char *variable_keywords[]= {"int","str"} ;

//Sub_token sizes

// Tokens  
char *keywords[]= {"int","str"} ;
char *puntuators[]={"(",")",";",".","{","}","[","]",","};
char *operators[]={"=","+","-","*","/"};
char *integers[]={"0","1","2","3","4","5","6","7","8","9"};
char *inbuilt_functions[]={"output","input"};

// Tokens sizes
int size_keywords =sizeof(keywords)/sizeof(keywords[0]);
int size_puntuators =sizeof(puntuators)/sizeof(puntuators[0]);
int size_operators =sizeof(operators)/sizeof(operators[0]);
int size_integers =sizeof(integers)/sizeof(integers[0]);
int size_inbuilt_functions =sizeof(inbuilt_functions)/sizeof(inbuilt_functions[0]);



