#include "count_files.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char** argv){
	int h_p;
	int o_p;

	char *value;
	int res1;
	int option;
	printf("Vars declared\n");
	while((option = getopt(argc, argv, "o:h")) != -1)
		switch (option){
			case 'h':
				printf("-o with required arg for conting number of files\n-h for help\n");
			case 'o':
				printf("Case O\n");
				value = optarg;
				printf("Argument passed\n");
				res1 = countfiles(value);
				if (res1 == 0)
					return 0;
				printf("There are(is)  %d file(s) in directory %s\n", res1, value);
				break;
			default:
				printf("It is so sad\n");
				return 0;
		}
	return 0;
}
