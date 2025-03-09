#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/token_value/token_value.h"

void raw_syntax_error_form(int token_position ,char *message ,char *submessage){
    fprintf(stderr, "\n\033[31mSyntax Error\033[0m: %s \033[32m'%s'\033[0m at \033[36mline\033[0m \033[31m%d\033[0m,\033[36mcolumn\033[0m \033[31m%d\033[0m\n\n",
    message,tokens[token_position].value, tokens[token_position].line, tokens[token_position].column);

fprintf(stderr, "   %d | ", tokens[token_position].line);

// Print tokens for the line
for (int x = 0; x < token_count; x++) {
    if (tokens[x].line == tokens[token_position].line) {
        if (x == token_position){
            for (int k=0; k<tokens[x].spaces_before;k++){
            fprintf(stderr, " ");
        }
            fprintf(stderr, "\033[31m%s\033[0m", tokens[x].value); }// Error token in red
        else if (x == token_position + 1){
             for (int k=0; k<tokens[x].spaces_before;k++){
            fprintf(stderr, " ");
        }
            fprintf(stderr, "\033[35m%s\033[0m", tokens[x].value); }// Next token in purple
        else{
             for (int k=0; k<tokens[x].spaces_before;k++){
            fprintf(stderr, " ");
        }
            fprintf(stderr, "%s ", tokens[x].value); }// Regular token
    }
}


fprintf(stderr, "\n\n%s",submessage);  // Show the error message
fprintf(stderr, "\n\n");
exit(0);


}
