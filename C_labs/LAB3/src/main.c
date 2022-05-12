#include "line_count.h"
#include "change_order.h"
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char **argv){
	int option;
	int choise=0;
	int line_count_main;
	char *value;
	if (argc < 2){
		printf("%d Arguments passed. At least and maximum one argument excpected. -h for help\n", argc);
		exit(1);
	}
	while((option = getopt(argc, argv, "hf:r:")) != -1)
		switch (option){
			case 'h':
				if (choise == 1){
					printf("H Only one option allowed (-h or -f or -r)\n");
					exit(1);
				}
				choise = 1;
				printf("Only god will help\n");
				break;
			case 'f':	
				if (choise == 1){
                                        printf("F Only one option allowed (-h or -f or -r)\n");
                                        exit(1);}
				choise = 1;
				value = optarg;
				line_count_main = line_count(value);
				printf("There are(is) %d line(s) in file '%s'\n", line_count_main, argv[2]); 
				break;
			case 'r':
				if (choise == 1){
                                        printf("H Only one option allowed (-h or -f or -r)\n");
                                        exit(1);}
				choise = 1;
				value = optarg;
				change_order(optarg);
				break;
			default:
				printf("Error\n");
				exit(1);	
					
			
	return 0;
		}			
		}


