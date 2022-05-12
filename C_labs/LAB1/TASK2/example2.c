#include <stdio.h>  
#define A 2  
#define B 4  
#define calculate(a,b) (a)*(a) + (b)*(b)  
void plain_dummy()  
{  
 printf("Just a dummy\n");  
}  
static inline justtest()  
{  
 printf("Hi!\n");  
}  
int main(int argc, char *argv[])  
{  
#ifdef TEST  
 justtest();  
#endif  
 printf("%d\n", calculate(A+1,B-3));  
 return 0;  
}  

