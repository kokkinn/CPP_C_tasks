#include <time.h>  
#include <stdio.h>  
int print_with_timestamp(char *msg)  
{
 int TIME_STR_LEN = 100;     	
 char buf [TIME_STR_LEN];  
 time_t rawtime;  
 struct tm *timeinfo;  
 time(&rawtime);  
 timeinfo = localtime(&rawtime);  
 if (strftime(buf, TIME_STR_LEN, "%c", timeinfo) == 0)   {  
 return -1;  
 }  
 printf("%s: \"%s\"\n", buf, msg);  
 return 0;  
} 

