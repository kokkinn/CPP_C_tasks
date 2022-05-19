#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include "linecount.h"
#define BUFFSIZE 256

int main(){

	mkfifo("CtS_FIFO", 0666);
	mkfifo("StC_FIFO", 0666);
	printf("FIFOs created\n");
	int CtS_desc = open("CtS_FIFO", O_RDONLY);
	int StC_desc = open("StC_FIFO", O_WRONLY);
	printf("FIFOs\' descriptors created on server\n");
	
	char buffer[BUFFSIZE];

	printf("Server is ON...\nType \'Exit\' for OFF\n");

	while(1)
	{
		read(CtS_desc, buffer, BUFFSIZE);
		
		if (strcmp("Exit", buffer)==0){
			printf("Server is OFF.\n");
			break;
		} 

		else if (strcmp("", buffer) !=0){
			printf("Request \"%s\" recieved, searching for a file...\n", buffer);
			int num = line_count(buffer);
			int *res = &num;
      			if (*res == -1){
                		char message[19] = "Error opening file";
                		write(StC_desc, message, 19);
                		printf("Bad response have been sent through StC FIFO...\n");
				memset(buffer, 0, sizeof(buffer));
				continue;
			}
			
			char message[] = "Rows in following file counted :\n ";
			printf("test\n");
			
			char temp[256];
			sprintf(temp, "%d", num);
			strcat(message, temp);
			write(StC_desc, message, 256);
                        printf("Good response have been sent through StC FIFO...\n");      
			memset(buffer, 0, sizeof(buffer));
			}	
	}

	close(CtS_desc);
   	close(StC_desc);

   	unlink("CtS_FIFO");
   	unlink("StC_FIFO");
	return 0;	
}


