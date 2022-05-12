#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int print_env_vars_filter(int arg, char **envp, int names_only){
	int count=0;
	if (names_only == 1) {
		printf("\nNames Only chosen\n");
    		while(*envp!=NULL){ 
		char * len = strchr(*envp, '=');
		if ((len - *envp) > arg){
	 		count++;
         		printf("%.*s\n", len - *envp, *envp);
	 		}
		envp++;
		}
	}
	else {
		printf("\nNOT Names Only chosen\n");
    		for (int i = 0; envp[i] != NULL; i++){
                	if ((strlen(envp[i])) > arg){
				printf("Len is %d\n", strlen(envp[i]));
                        	count++;
                        	printf("%s\n\n", envp[i]);
			}
		}	
	}
return count;
}

 
