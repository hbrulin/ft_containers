NAME = test

SRCS_LIST = tests/List_test.cpp
SRCS_VEC = tests/Vector_test.cpp
SRCS_STACK = tests/Stack_test.cpp
SRCS_QUEUE = tests/Queue_test.cpp
SRCS_MAP = tests/Map_test.cpp

CFLAGS = -Wall -Werror -Wextra

all: list
	
list: $(OBJS_L)
	clang++ $(CFLAGS) $(SRCS_LIST) -o $(NAME) -g
	@echo "$(NAME) list created"

vector: $(OBJS_V)
	clang++ $(CFLAGS) $(SRCS_VEC) -o $(NAME) -g
	@echo "$(NAME) vector created"

stack: $(OBJS_S)
	clang++ $(CFLAGS) $(SRCS_STACK) -o $(NAME) -g
	@echo "$(NAME) stack created"

queue: $(OBJS_Q)
	clang++ $(CFLAGS) $(SRCS_QUEUE) -o $(NAME) -g
	@echo "$(NAME) queue created"

map: $(OBJS_M)
	clang++ $(CFLAGS) $(SRCS_MAP) -o $(NAME) -g
	@echo "$(NAME) map created"

clean:
	@/bin/rm -rf tests/*.o
	@echo "Object files deleted"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "binary deleted"

re : 
	@make fclean
	@make all

.PHONY: all, clean, fclean, re, all