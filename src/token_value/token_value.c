#include "../include/token_value/token_value.h"
#include <stdlib.h>
//Sub_keywords
char *variable_keywords[] ={"int"}; 
// Sub_keywords sizes
int size_variable_keywords =sizeof(variable_keywords)/sizeof(variable_keywords[0]);

// Tokens  
char *keywords[]= {"int"} ;
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



