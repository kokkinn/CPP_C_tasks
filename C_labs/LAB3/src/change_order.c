#include<stdio.h>
#include<stdlib.h>

void change_order(char *filename){
	FILE *file = fopen(filename, "r");
	if (file==NULL){
		printf("Error opening file");
		exit(1);
	}
	fseek(file, 0, SEEK_END);
	int i=0;
	int ft = ftell(file);
	while(i<ft){
		i++;
		fseek(file, -i, SEEK_END);
		char ch = fgetc(file);
		printf("%c", ch);
	}

}
