VPATH= ../include: ../src
FLAGS = -I ../include -I ../src
OBJS = main.o count_files.o
NAME = result
$(NAME): $(OBJS)
	$(CC) -o $@ $^ 
$(OBJS): main.c count_files.c
	gcc -g $(FLAGS) -c $^ 
clean:
	rm $(OBJS) 

