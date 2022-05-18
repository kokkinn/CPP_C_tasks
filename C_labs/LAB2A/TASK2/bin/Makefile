# vpath %.h ../include
# vpath %.c ../src
# VPATH = /../include
VPATH = src:include
program: main.o func.o print.o
	gcc -o result1_make main.o func.o print.o
main.o: main.c defs.h func.h print.h
	gcc -c main.c -o main.o
func.o: func.c func.h
	gcc -c func.c -o func.o
print.o: print.c print.h
	gcc -c -o print.c -o print.o
clean:
	rm *.o
# vpath %.h ../include
# vpath %.c ../src
