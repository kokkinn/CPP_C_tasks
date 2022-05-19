#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFSIZE 256

int main(){

	int CtS_desc = open("CtS_FIFO", O_WRONLY);
        int StC_desc = open("StC_FIFO", O_RDONLY);

	char buffer[BUFFSIZE];

	printf("Please enter a name of file for counting it's rows : ");
	scanf("%s", buffer);
	printf("You've entered '%s\n'", buffer);
	write(StC_desc, buffer, BUFFSIZE);
	printf("Filename was sent to CtS_FIFO...");
	
	perror("Write:"); //Very crude error check

	char *answer;
	read(StC_desc,answer,sizeof(answer));

   	perror("Read:"); // Very crude error check

   	printf("...received from the server: %s\n",answer);
   	close(CtS_desc);
   	close(StC_desc);

	return 0;
}
