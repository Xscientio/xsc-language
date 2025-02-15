#include <stdio.h>
#include "include/tokenization.h"
#include "include/read_file.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>




void main(){

char * ptr_src_data =core_read_file("example/main.xsc");
if(strcmp(ptr_src_data,"")!=0){
core_tokenizer(ptr_src_data);

}

}








