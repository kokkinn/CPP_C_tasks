VPATH= ../include: ../src
FLAGS = -I ../includes -I ../src
OBJS = main.o bad_exit.o print_env_vars_filter.o
NAME = result
$(NAME): $(OBJS)
	$(CC) -o $@ $^ 
$(OBJS): main.c bad_exit.c print_env_vars_filter.c
	gcc -g $(FLAGS) -c $^ 
clean:
	rm $(OBJS) 

