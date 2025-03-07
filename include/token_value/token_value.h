#pragma once

extern char *variable_keywords[] ;
extern int size_variable_keywords ;


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
    INTEGER,
    STRING,
    INBUILT_FUNCTION,
    IDENTIFIER,
    FAULTY,

}TokensType; 

/***************************************************************
 * Enum: TokensSubType
 * Purpose: To represent the sub token (e.g., RightParenthesis, AssigmentOperator, etc.)
 ***************************************************************/
typedef enum{
    USR_IDENTIFIER,
    USR_STRING,
    USR_INTEGER,
    USR_FAULT,


    COLON,
    RIGHT_PARENTHESIS,
    LEFT_PARENTHESIS,
    LEFT_CURLY_BRACKETS,
    RIGHT_CURLY_BRACKETS,
    LEFT_SQUARE_BRACKETS,
    RIGHT_SQUARE_BRACKETS,
    DOT,
    COMMA,


    FORWARD_SLASH,
    PLUS,
    ASTERISK,
    EQUAL,
    MINUS,


    IF,
    ELSE,
    ELIF,
    WHILE,
    BREAK,
    CONTINUE,
    TRY,
    EXCEPT,


    INT,
    STR,


    OUTPUT,
    INPUT


}TokensSubType; 


/***************************************************************
 * Struct: TokensStored
 * Purpose: To store extracted tokens.
 * Fields:
 *    TokensType type : Type of token being stored it a typedef enum and store as int.
 *    TokensSubType subtype: Sub type of token being stored it a typedef enum and store as int.
 *    char *value: Value of token dynamically allocates the memory.
 *    int line   : To store the line reference of the token.
 *    int length   : To store the length of the token for future purposes.
 ***************************************************************/
typedef struct 
{
    TokensType type;
    TokensSubType subtype;
    char *value;
    int column;
    int line;
    int length ;
    int start_point;
    int end_point;
    
}TokensStored;

