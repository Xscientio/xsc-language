#include <stdio.h>
#include "include/tokenization.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>


int main()
{


char  *ptr_src_data ="int k=5+5; k=45;exit(k);";



core_tokenizer(ptr_src_data);

}







