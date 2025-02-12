#include <stdio.h>
#include "include/tokenization.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>


int main()
{


char  src_data[] ="int(5+5);";
char *ptr_src_data =src_data;



core_tokenizer(ptr_src_data);

}







