VPATH= ../include: ../src
FLAGS = -I ../includes -I ../src
OBJS = print_var_from_args.o no_vars.o too_many_args.o
NAME = result
$(NAME): $(OBJS)
	$(CC) -o $@ $^ 
$(OBJS): print_var_from_args.c no_vars.c too_many_args.c
	gcc -g $(FLAGS) -c $^ 
clean:
	rm $(OBJS) 
