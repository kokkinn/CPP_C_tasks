#include<stdio.h>
#include<stdlib.h>

int main(){
        FILE *file = fopen("filee.txt", "a");
        if (file==NULL){
                printf("Error opening file");
                exit(1);
        }
       fseek(file, 0, SEEK_END);
        int i=0;
       printf("PRINTING"); 
      
          
           fprintf(file, "test")   ;  
              exit(0);
        }


