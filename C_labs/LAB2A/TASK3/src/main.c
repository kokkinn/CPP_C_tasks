#include "func.h" 
#include "print.h"  
#include "defs.h"  
#include "word_func.h"
#include <string.h>
#include <stdio.h>  
int main ()  
{  
 char str[200];
 printf("Enter a word\n"); 
 fgets(str, 200, stdin);
char str2[200];
strcpy(str2, str);
 char ** words;  
words = split(str," \t,.");    
printwords(words);
 printf("Enter a value. Words that have more characters than a value, will be outputted\n"); 
 int val;
 scanf(" %d", &val);
 word_func(str2, val);
 return 0;  
  
}  
