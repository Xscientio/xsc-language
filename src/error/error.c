#include <stdio.h>
#include <stdlib.h>
#include "../include/token_value/token_value.h"

void operand_error(int token_position){
      fprintf(stderr, "\n\033[31mOperand Error\033[0m: Expected an operand after \033[32m'%s'\033[0m either integer or identifier at \033[36mline\033[0m \033[31m%d\033[0m,\033[36mcolumn\033[0m \033[31m%d\033[0m\n\n",tokens[token_position].value,tokens[token_position].line,tokens[token_position].column);

    exit(0);

}