VPATH= ../include: ../src
FLAGS = -I ../includes -I ../src
OBJS = main.o line_count.o change_order.o
NAME = result
$(NAME): $(OBJS)
	$(CC) -o $@ $^ 
$(OBJS): main.c line_count.c change_order.c
	gcc -g $(FLAGS) -c $^ 
clean:
	rm $(OBJS) 
