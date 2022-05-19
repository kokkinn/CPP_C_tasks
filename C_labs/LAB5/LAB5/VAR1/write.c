#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#define BUFFSIZE 256

int main(){

	int CtS_desc = open("CtS_FIFO", O_WRONLY);
        int StC_desc = open("StC_FIFO", O_RDONLY);
	printf("FIFOs\' descriptors were created for client\n");
	char buffer[BUFFSIZE];

	printf("Please enter a name of file for counting it's rows : ");
	scanf("%s", buffer);
	printf("You've entered '%s\n'", buffer);

	write(CtS_desc, buffer, BUFFSIZE);
	printf("Filename was sent to CtS_FIFO...\n");
	perror("Write:"); 

	read(StC_desc,buffer,sizeof(buffer));
	perror("Read:"); 

   	printf("...received from the server: %s\n",buffer);
   	close(CtS_desc);
   	close(StC_desc);

	return 0;
}
