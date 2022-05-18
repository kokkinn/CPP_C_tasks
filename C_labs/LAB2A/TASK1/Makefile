program: main.o func.o print.o
	gcc -o result1_make main.o func.o print.o
main.o: main.c defs.h
	gcc -c main.c
func.o: func.c func.h
	gcc -c func.c
print.o: print.c print.h
	gcc -c print.c
clean:
	rm *.o

