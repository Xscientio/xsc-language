#pragma once

extern char *keywords[] ;
extern char *puntuators[];
extern char *operators[];
extern char *integers[];
extern char *inbuilt_functions[];

extern int size_keywords ;
extern int size_puntuators ;
extern int size_operators ;
extern int size_integers ;
extern int size_inbuilt_functions;

/***************************************************************
 * Enum: TokensType
 * Purpose: To represent the type of token (e.g., keyword, operator, etc.)
 ***************************************************************/
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


/***************************************************************
 * Struct: TokensStored
 * Purpose: To store extracted tokens.
 * Fields:
 *    TokensType : Type of token being stored it a typedef enum and store as int.
 *    char *value: Value of token dynamically allocates the memory.
 *    int line   : To store the line reference of the token.
 *    int length   : To store the length of the token for future purposes.
 ***************************************************************/
typedef struct 
{
    TokensType type;
    char *value;
    int line;
    int length ;
    
}TokensStored;

