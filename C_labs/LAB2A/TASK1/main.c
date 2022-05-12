#include "func.h"  
#include "print.h"  
#include "defs.h"  
#include <stdio.h>  
int main ()  
{  
 char str[MAX_STRING_SIZE];  
 // чтение строки со словами(разделители – пробел,   // знак табуляции, точка и запятая)  
 fgets(str, MAX_STRING_SIZE, stdin);  
 char ** words;  
 words = split(str," \t,.");  
 //  
 printwords(words);  
 return 0;  
  
}  
