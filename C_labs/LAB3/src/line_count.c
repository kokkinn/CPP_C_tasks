#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>



int line_count(char *filename){
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Error opening file.\n");
		exit(1);
	}
	int line_num = 1;
	char ch;
	while((ch=fgetc(file))!=EOF) {
     	 if(ch=='\n')
         line_num++;
   }

	fclose(file);
	return line_num;

		
	
			
}
