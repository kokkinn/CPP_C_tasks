#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <ctype.h>

#include "print_env_vars_filter.h"
#include "bad_exit.h"

int main(int argc, char **argv, char **envp){
	int option;	
	char *value;
	int arg;
	int count=0;
	int filter = 1;
	int names_only = 0;

	while((option = getopt(argc, argv, "h0p:sy:k")) != -1) 
		switch (option){
			case 'h':
				printf("Usage: %s [-h0p]\n", argv[0]);
				break;
			case '0':
				printf("Kokkin George, course 3, PM\n");
				break;
			case 'p':
				filter = 0;
				value = optarg;
				printf("\"%s\" optarg_recieved\n", value);
				if (getenv(value)==NULL){
					printf("No such env variable (%s) found\n", value);
					count = 0;
					break;
					
				}
				printf("%s\n", getenv(value));
				count = 1;
				break;
			case 's':
				if (filter == 0){
					atexit(bad_exit_func);
					exit(0); 
				}	
				names_only = 1;	 
				 //print_env_vars(envp);
				 break;
			case 'y':
				 if (filter == 0){
                                 	atexit(bad_exit_func);
				 	exit(0);
				 }
				 arg  = atoi(optarg);
				 printf("Arg recieved, function is called...");
				 count = print_env_vars_filter(arg, envp, names_only);
				 printf("COUNT RECIEVED\n");
				 break;
			case 'k':
				 printf("Number of filtered env vars is %d\n", count);
				 break;
			default:
				atexit(bad_exit_func);
				return 0;
		}
}
