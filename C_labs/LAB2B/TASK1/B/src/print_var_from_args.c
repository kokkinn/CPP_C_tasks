#include <stdio.h>
#include <stdlib.h>
#include <too_many_args.h>
#include <no_vars.h>
int main(int argc, char **argv, char **envp){
	if (argc > 2 ){
		atexit(too_many_args);
		exit(0);
	}
	for(int i = 1; i < argc; i++){
		if (getenv(argv[i]) == NULL){
			atexit(no_vars);
			exit(0);	
		}
		printf("%s = %s\n", argv[i], getenv(argv[i]));
	}
}
